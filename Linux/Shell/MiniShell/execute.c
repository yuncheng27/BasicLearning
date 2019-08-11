#include "execute.h"
#include "def.h"
#include "externs.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>

//执行命令，通过输入输出文件是否为空来判断是否有重定向命令要执行
//通过命令个数来判断是否有管道符来决定直接执行命令(标准输入输出)，还是执行管道命令

void execute_disk_command(void) {
  if(cmd_count == 0)
    return;  //没有命令只有换行就不执行，除BUG

  //解析执行带输入输出重定向命令.
  //cat < test.txt | grep -n public > test2.txt &
  if(infile[0] != '\0')  // < 输入重定向 
  {
    cmd[0].infd = open(infile, O_RDONLY);
  }

  if(outfile[0] != '\0') {  // > 或者 >> 输出重定向只能是最后一条命令
    if(append) //追加方式
    {
      umask(0);
      cmd[cmd_count - 1].outfd = open(outfile, O_WRONLY|O_CREAT|O_APPEND, 0666);
    } else {
      umask(0);
      cmd[cmd_count - 1].outfd = open(outfile, O_WRONLY|O_CREAT|O_TRUNC, 0666);
    }
  }

  //后台作业，忽略掉SIGCHLD信号，防止僵尸进程
  //后台作业不会调用wait等待子进程退出
  if(backgnd == 1) {
    signal(SIGCHLD, SIG_IGN);  //下个命令之前需要还原，忽略了退出信号。无法再backgnd == 0时等待 
  } else signal(SIGCHLD, SIG_DFL);  //如果不还原。例如刚执行了一个 wc & 那么后台进程会使SIGCHLD被忽略，前台进程父进程才要wait。执行ls前台进程时，如果不将SIGCHLD处理函数还原就会使得while(wait(NULL) != lastpid)
    //只带管道的话 例如：ls | grep init | wc -w*/
   int i = 0;
   int fd;
   int fds[2];
   //ls | grep init | wc -w    cmd[0]:ls   cmd[1]:grep   cmd[2]:wc 
   for(i = 0; i < cmd_count; i++) {
     if(i < cmd_count-1) {  //不是最后一条命令。如果cmd_count=1那么就没有管道符就不用创建管道符
        pipe(fds);  //创建管道 cmd[i]的输出为 cmd[i+1]的输入。所以把cmd[i]的输出置为管道的写端,管道的读端作为cmd[i+1]的输入
        cmd[i].outfd = fds[1];  //将当前命令的输出定向到管道的写端
        cmd[i+1].infd = fds[0]; //将下一条命令的输入重定向到管道的读端
     }
     forkexec(i);  //fork子进程执行命令，传入结构体指针cmd结构体数组
     if((fd=cmd[i].infd) != 0) //进程执行完，还原
       close(fd);
     if((fd=cmd[i].outfd) != 1) //标准输出
       close(fd);
   } 

   //后台作业控制，backgnd==1不需要等待，需要防止产生僵尸进程
   if(backgnd == 0) {  //前台作业0
      //前台作业，需要等待管道中最后一个命令退出
      while(wait(NULL) != lastpid);
      //等待最后一个进程结束。如果不等待，那么父进程可能先退出，重新开始循环等待输入命令，先打印出[minishell$]。子进程再输出结果
   }
}

void forkexec(int i) {
  pid_t pid;
  pid = fork();
  if(pid == 1) 
    ERR_EXIT("fork error");
  if(pid > 0) {
    //父进程
    if(backgnd == 1) 
      printf("%d\n", pid);  //打印后台进程的进程ID
    lastpid = pid;  //保存最后一个进程ID
  }
  else if(pid == 0) {
    // ls | wc -c
    // backgnd == 1，将第一条简单命令的infd重定向到 /dev/null 
    // 当第一条命令试图从标准输入获取数据的时候，立即返回EOF
    // 这样就不用考虑作业控制了
    if(cmd[i].infd == 0 && backgnd == 1) //输入描述符等于0，肯定是第一条命令
      cmd[i].infd = open("/dev/null", O_RDONLY);
    //将第一个简单命令进程作为进程组组长，信号发给当前整个进程组，父进程不再收到
    if(i == 0) {
      //将第一个简单命令进程单独设置为一个进程组，那么信号SIGINT只会发给这个进程组。不会发给父进程minishell这样就不会打印两次minishell$
      setpgid(0, 0);
    }
    
    //子进程
    if(cmd[i].infd != 0) {  //输入不是标准输入，命令从管道输入
      //等价于dup2(cmd[i].infd, 0)
      close(0);
      dup(cmd[i].infd);  //将命令输入描述符也就是管道读端,置位命令的标准输入
    } 
    if(cmd[i].outfd != 1) {  //命令的输出不是标准输出，那么命令的输出就是输出到管道。
      close(1);
      dup(cmd[i].outfd);
    }
    int j;
    for(j = 3; j < sysconf(_SC_OPEN_MAX); j++)
      close(j);   //关闭3以上的文件描述符
    if(backgnd == 0) {  //前台作业恢复信号
      signal(SIGINT, SIG_DFL);  //前台作业需要将信号还原，不然ctrl+c会调用init中的信号处理函数打印两次minishell$
      signal(SIGQUIT, SIG_DFL);
    }
    
    /*
      实现I/O重定向
     
      调用exec后，原来打开的文件描述符仍然是打开的。利用这一点可以实现I/O重定向。 
      先看一个简单的例子，把标准输入转成大写然后打印到标准输出：
     
      例大小写转换源码upper.c：
      #include <stdio.h>
     
      int main(void)
      {
        int ch;
        while((ch = getchar()) != EOF) {
          putchar(toupper(ch));
        }
        return 0;
      }
     
      程序wrapper.c：
      #include <unistd.h>
      #include <stdlib.h>
      #include <stdio.h>
      #include <fcntl.h>
      
      int main(int argc, char *argv[])
      {
        int fd;
        if (argc != 2) {
          fputs("usage: wrapper file\n", stderr);
          exit(1);
        }
     
        fd = open(argv[1], O_RDONLY);
        if(fd<0) {
          perror("open");
          exit(1);
        }
     
        dup2(fd, STDIN_FILENO);
        close(fd);
     
        execl("./upper", "upper", NULL);
        perror("exec ./upper");
        exit(1);
      }
     
      wrapper程序将命令行参数当作文件名打开，将标准输入重定向到这个文件，然后调用exec执行upper程序，这时原来打开的文件描述符仍然是打开的，upper程序只负责从标准输入读入字符转成大写，并不关心标准输入对应的是文件还是终端。
     */ 
    execvp(cmd[i].args[0], cmd[i].args);
    //替换失败就到这行
    exit(EXIT_FAILURE);
  }
}
