/*  修改信号的处理方式：
 *      signal
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction oldact;
void sigcb(int signo)
{
    printf("recv signo:%d\n", signo);
    //sigaction(signo, &oldact, NULL);
    signal(signo, SIG_DFL);
}
int main()
{
    //sighandler_t signal(int signum, sighandler_t handler);
    //typedef void (*sighandler_t)(int);
    //  handler:
    //      SIG_IGN     忽略处理
    //      SIG_DFL     默认处理
    //修改信号的处理函数
    //signal(SIGINT, sigcb);
    //signal(SIGQUIT, sigcb);
    //int sigaction(int signum, const struct sigaction *act,
    //                     struct sigaction *oldact);
    //  为信号重新自定义新的行为，并且将原有行为保存在oldact中
    //  signum: 信号值
    //  act：   信号新行为
    //  oldact：保存信号原有行为
    struct sigaction act;

    act.sa_handler = sigcb;
    act.sa_flags = 0;//若被指定为SA_SIGINFO则回调应该为sa_sigaction
    //int sigemptyset(sigset_t *set);
    //  清空指定的信号集合
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, &oldact);
    sigaction(SIGHUP, &act, &oldact);
    while(1) {
        printf("--------\n");
        sleep(1);
    }
    return 0;
}
