/*  匿名管道接口的基本使用
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    //int pipe(int pipefd[2]);
    //  pipefd: 用于获取管道的操作描述符、
    //  pipefd[0] 用于从管道中读取数据
    //  pipefd[1] 用于向管道中写入数据
    //  返回值：成功-0 失败：-1
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret < 0) {
        perror("pipe error");
        return -1;
    }

    int  pid = fork();
    if (pid < 0) {
        return -1;
    }else if (pid == 0) {
        //子进程--读取管道中的数据
        close(pipefd[1]);
        close(pipefd[0]);
        /*
        int i = 2;
        while(i-- > 0) {
            char buff[1024] = {0};
            if (read(pipefd[0], buff, 1023) == 0) {
                printf("all write close!!\n");
                break;
            }
            printf("buff:%s--%d-%d\n", buff, pipefd[0], pipefd[1]);
        }
        */
    }else {
        close(pipefd[0]);
        sleep(3);
        //父进程--向管道中写入数据
        char *ptr = "hot!!!===sleep!";
        write(pipefd[1], ptr, strlen(ptr));
        while(1) {
            printf("------------\n");
            sleep(1);
        }
    }
    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}
