/*  演示信号软件条件产生的几种方式
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    //int kill(pid_t pid, int sig);
    //向指定进程发送指定信号
    //kill(getpid(), SIGSEGV);
    //int raise(int sig);
    //给自己发送一个信号
    //raise(SIGHUP);
    //void abort(void);
    //给自己发送SIGABRT信号
    //abort();
    //unsigned int alarm(unsigned int seconds);
    //在seconds秒之后向自身发送SIGALRM信号
    //覆盖上一个定时器，并返回上一个定时器剩余时间
    //alarm(3);
    //int sigqueue(pid_t pid,  int  sig,  const  union  sigval
    //       value);
    //  向指定进程发送一个信号并且可以携带一个参数
    //sigqueue(getpid(), SIGKILL, (union sigval)999);
    sleep(1);
    int ret = alarm(5);
    printf("ret:%d\n", ret);
    while(1) {
        printf("-------\n");
        sleep(1);
    }
    return 0;
}
