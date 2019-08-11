#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main()
{
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0, &read_fds);  //当只检测文件描述符0(标准输入)时，因为输入条件只有在有输入信息的时候，才成立，所以一直不输入，就会产生超时信息
    for (;;) {
        printf("> ");
        fflush(stdout);
        /* int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
         *  nfds：最大描述符+1
         *  readfds：可读事件的监控集合   writefds     exceptfds
         *  timeout：超时等待时间
         *  NULL：没有描述符就永久等待
         *  返回值：-1错误，0超时
         */
        int ret = select(1, &read_fds, NULL, NULL, NULL);
        if (ret < 0) {
            perror("select error");
            continue;
        }
        if (FD_ISSET(0, &read_fds)) {
            char buf[1024] = {0};
            read(0, buf, sizeof(buf) - 1);
            printf("input: %s", buf);
        } else {
            printf("error! invaild fd\n");
            continue;
        }
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);
    }
    return 0;
}
