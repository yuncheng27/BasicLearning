/* 线程的终止与等待
 *  return    pthread_exit    pthread_cancel
 *
 *  int pthread_detach(pthread_t thread); 分离线程
 *  
 *  int pthread_join(pthread_t thread, void **retval);
 *  等待指定的线程退出，并且获取返回值
 *  thread：指定线程
 *  retval：获取返回值
 *  EINVAL：thread is not a joinable thread
 *
 *  void pthread_exit(void *retval); 终止调用线程
 *
 *  int pthread_cancel(pthread_t thread);  取消其它线程   线程退出，并可以返回一个数据
 */

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
void *thr_start(void *arg)
{
    char ptr[] = "test";
    sleep(3);
    pthread_exit("test");
    while(1) {
        printf("i am child!!\n");
        sleep(1);
    }
    return "hhh";
}

int main()
{
    pthread_t tid;
    pthread_t mtid = pthread_self();
    int ret = pthread_create(&tid, NULL, thr_start, (void *)mtid);
    if (ret != 0) {
        printf("thread create error!\n");
        return -1;
    }
    pthread_detach(tid);  //分离线程
    char *ptr;
    pthread_cancel(tid);  //线程被取消，则返回值不能作为标准结果，返回值是-1
    ret = pthread_join(tid,(void **)&ptr);
    if (ret == EINVAL) {
        printf("thread is not joinable thread\n");       
    }
    printf("child thread retval:%ld\n", (long)&ptr);
//int的长度为4，char*的长度为8 若写成printf("child thread retval:%d\n", (int)&ptr); 
//这样的类型转换会报错 cast from pointer to integer of different size
    
    while(1) {
        printf("i am main\n");
        sleep(1);
    }
    return 0;
}
