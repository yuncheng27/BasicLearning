/*  非阻塞io体验
 *  fcntl
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
void setnonblock(int fd)
{
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}
int main()
{
    char buf[1024] = {0};

    //int fcntl(int fd, int cmd, ... /* arg */ );
    //  fd:文件描述符
    //  cmd:
    //      F_GETFL     获取属性状态 （通过返回值返回当前属性）
    //      F_SETFL     设置属性状态 （替换原有属性为当前arg属性）
    //  arg：   要设置的属性信息
    //      O_NONBLOCK  设置描述符为非阻塞`
    //  返回值：F_GETFL：当前属性   F_SETFL：成功：0 失败：-1
    setnonblock(STDIN_FILENO);
    while(read(STDIN_FILENO, buf, 1024) < 0) {
        if (errno == EINTR || errno == EAGAIN) {
            sleep(1);
            printf("stdin buffer have no data\n");
            continue;
        }
        return -1;
    }
    printf("buf:[%s]\n", buf);
    return 0;
}
