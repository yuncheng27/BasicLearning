/*  共享内存的基本操作：
 *      创建：shmget
 *      映射：shmat
 *      操作：内存操作即可
 *      解除：shmdt
 *      删除：shmctl
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#define IPC_KEY 0x12345678
int main()
{
    //key_t ftok(const char *pathname, int proj_id);
    //  pathname:   文件名
    //  proj_id：   自定义数字
    //  通过文件的inode节点号与proj_id合在一起生成一个key值
    //
    //int shmget(key_t key, size_t size, int shmflg);
    //  key:    共享内存在操作系统中的标识符
    //  size：  共享内存大小
    //  shmflg：IPC_CREAT IPC_EXCL
    //  返回值：进程对共享内存的操作句柄 失败：-1
    int shmid = shmget(IPC_KEY, 32, IPC_CREAT | 0664);
    if (shmid < 0) {
        perror("shmget error");
        return -1;
    }
    //将共享内存映射到虚拟地址空间
    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    //  shmid:  共享内存的操作句柄
    //  shmaddr：用户指定共享内存映射在虚拟地址空间的首地址
    //          通常置空，让操作系统分配
    //  shmflg：如果被指定为SHM_RDONLY--只读   0
    //  返回值：映射首地址  失败:-1
    void *shm_start = shmat(shmid, NULL, 0);
    if (shm_start == (void*)-1) {
        perror("shmat error");
        return -1;
    }

    while(1) {
        printf("please input: ");
        fflush(stdout);
        char buff[1024] = {0};
        scanf("%s", buff);
        memcpy(shm_start, buff, strlen(buff));
    }
    //int shmdt(const void *shmaddr);
    //  shmaddr: 映射首地址
    shmdt(shm_start);
    //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    //  shmid:  映射首地址
    //  cmd:    对共享内存的操作
    //          IPC_RMID    删除共享内存
    //  buf：   用于获取共享内存的状态信息
    //  删除共享内存，并不会直接删除而是等待映射链接数为0，并且在
    //  等待期间，拒绝新的映射链接
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
