#if 1
//exit()
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("using exit----\n");
    printf("This is the content in buffer");
    exit(0);
}
#endif
#if 0
//_exit()
#include<stdio.h>
#include<unistd.h>

int main(void)
{
    printf("using exit----\n");
    printf("This is the content in buffer");
    _exit(0);
}
#endif
