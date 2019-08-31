#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void sigcb() {
}
void sigcb1() {
    sleep(10);
}
int my_sleep(int nsec)
{
    signal(SIGALRM, sigcb);
    alarm(nsec);
    sigset_t set, old;
    sigfillset(&set);
    sigdelset(&set, SIGALRM);

    //sigprocmask(SIG_BLOCK, &set, &old);
    //int sigsuspend(const sigset_t *mask);
    //临时使用mask集合替换block集合，并且陷入休眠，被没有被阻塞的信
    //号唤醒之后，将block集合还原回去
    sigsuspend(&set);
    //sigprocmask(SIG_SETMASK, &old, NULL);
    return 0;
}
int main()
{
    my_sleep(3);
    while(1) {
        printf("-----\n");
        sleep(1);
    }
    return 0;
}
