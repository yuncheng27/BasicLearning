#include<stdio.h>
#include<unistd.h>
#include<wait.h>
int main(void)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        fork();
        printf("-\n");
    }
    wait(NULL);
    wait(NULL);
    return 0;
}
