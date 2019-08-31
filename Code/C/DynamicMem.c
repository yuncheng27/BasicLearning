#if 0
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num = 0;
    scanf("%d",&num);
    int *p = calloc(10, sizeof(int));
    if (NULL != p)
    { 
        int i = 0;
        for(; i < num; i++)
        {
            *(p + i) = i;
            printf("%d\n",p[i]);
            printf("%p\n",p+i);
        }
    }
    free(p);
    p = NULL;
    return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Test(void)
{
    char *str = NULL;
    str = (char *)malloc(100);
    strcpy(str,"hello,world!\n");
    printf(str);
    free(str);
    str = NULL;
}

int main()
{
    Test();
    return 0;
}
#endif
#if 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num = 0;
    scanf("%d",&num);
    int *ptr = malloc(100);
    int *p = realloc(ptr, 1000);
    if(NULL != p)
    {
        int i = 0;
        for(; i < num; i++)
        {
            *(p + i) = i;
            printf("%d\n",p[i]);
            printf("%p\n",p+i);
        }
    }
    free(p);
    p = NULL;
    free(ptr);
    ptr = NULL;
    return 0;
}
#endif
