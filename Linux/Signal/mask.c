/*  信号的阻塞演示
 *      sigprocmask
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void sigcb(int signo)
{ 
    printf("recv signo:%d\n", signo);
}
int main()
{
    //int  sigprocmask(int  how, const sigset_t *set, sigset_t *oldset);
    //  how:    对blocked集合要做的操作
    //      SIG_BLOCK       将set集合中信号添加到blocked中
    //      SIG_UNBLOCK     将set集合中信号从blocked中移除
    //      SIG_SETMASK     使用set中信号替换blocked中的信号
    struct sigaction action;
    action.sa_flags = 0;
    action.sa_handler = sigcb;
    //清空信号集
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
    sigaction(40 , &action, NULL);

    sigset_t block;
    sigset_t old;
    sigemptyset(&block);
    //int sigfillset(sigset_t *set);
    //向集合中添加所有信号
    //int sigaddset(sigset_t *set, int signum);
    //向集合中添加一个指定的信号
    //int sigdelset(sigset_t *set, int signum);
    //从集合中移除一个指定的信号
    sigfillset(&block);
    sigprocmask(SIG_BLOCK, &block, &old);
    //在没有按回车之前，信号会一直被阻塞
    getchar();
    //int sigpending(sigset_t *set);
    //获取未决信号
    sigset_t pending;
    sigpending(&pending);
    int i = 1;
    for (i = 1; i < 32; i++) {
        //判断信号集合中是否有指定的信号
        if (sigismember(&pending, i)) {
            printf("1 ");
        }else  {
            printf("0 ");
        }
    }
    fflush(stdout);
    //按回车之后，信号解除阻塞
    sigprocmask(SIG_UNBLOCK, &block, NULL);
    //sigprocmask(SIG_SETMASK, &old, NULL);
    while(1) {
        printf("-----------\n");
        sleep(10);
    }
    return 0;
}
