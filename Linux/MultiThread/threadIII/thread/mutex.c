/*  一个基本的黄牛抢票程序
 *  其实就是一个变量来表示有多少票
 *  线程表示黄牛
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

volatile int ticket = 100;
pthread_mutex_t mutex;

void* thr_scalper(void *arg)
{
    int id = (int)arg;
    while(1) {
        //应该在对临界资源访问之前加锁
        //int pthread_mutex_lock(pthread_mutex_t *mutex);
        //int pthread_mutex_trylock(pthread_mutex_t *mutex);
        //lock--阻塞加锁，
        //trylock--非阻塞加锁
        pthread_mutex_lock(&mutex);
        if (ticket > 0) {
            usleep(100);
            printf("scalper %d-%p get a ticket:%d\n", id, 
                    pthread_self(), ticket);
            ticket--;
        }else {
            //在加锁之后，任何有可能退出的地方都要解锁
            pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }
        //解锁
        //int pthread_mutex_unlock(pthread_mutex_t *mutex);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main()
{
    pthread_t tid[4];
    int i, ret;
    //初始化互斥锁
    //int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    //    const pthread_mutexattr_t *restrict attr);
    //pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    //mutex：   互斥锁变量
    //attr：    互斥锁属性，通常置NULL
    //成功：0   失败：errno
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 4; i++) {
        ret = pthread_create(&tid[i],NULL, thr_scalper, (void*)i);
        if (ret != 0) {
            printf("create thread error\n");
            return -1;
        }
    }
    for (i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
    //int pthread_mutex_destroy(pthread_mutex_t *mutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}
