/*  演示线程的创建
 *  pthread_create
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void *thr_start(void *arg)
{
    pthread_t tid = pthread_self();

    while(1) {
        printf("i am common thread!! %p\n", tid);
        sleep(1);
    }
    return  NULL;
}
int main()
{
    //int pthread_create(pthread_t *thread, pthread_attr_t *attr,
    //  void *(*start_routine) (void *), void *arg);
    //  thread: 输出型参数,用于获取用户态线程id
    //  attr：  线程属性，通常置NULL
    //  start_routine： 线程的入口函数
    //  arg：   通过线程的入口函数，传递给线程的参数
    //  返回值：成功-0  失败-非0
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, thr_start, (void*)999);
    if (ret != 0) {
        printf("pthread create error\n");
        return -1;
    }
    printf("common thread id:%p\n", tid);
    while(1) {
        printf("i am main thread!!\n");
        sleep(1);
    }
    return 0;
}
