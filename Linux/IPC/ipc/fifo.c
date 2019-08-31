/*  命名管道的基本使用
 *      int mkfifo(const char *pathname, mode_t mode);
 *      命名管道可以用于同一机器上任意进程间通信
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
    umask(0);
    //int mkfifo(const char *pathname, mode_t mode);
    //  功能：创建一个命名管道文件
    //  pathname:   命名管道文件路径名
    //  mode：      权限
    //  返回值：成功：0 ，失败：-1
    int ret = mkfifo("./test.fifo", 0664);
    if (ret < 0) {
        if (errno != EEXIST) {
            perror("mkfifo error");
            return -1;
        }
    }
    int fd = open("./test.fifo", O_RDONLY);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    printf("open fifo success!!\n");
    while(1) {
        char buff[1024] = {0};
        read(fd, buff, 1023);
        printf("read buff:[%s]\n", buff);
    }
    close(fd);
    return 0;
}
