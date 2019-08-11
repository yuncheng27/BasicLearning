#if 0
#include<stdio.h>

void ChangePointer(char **c)
{
    **c = 200;
}

void ChangePointer2(char *d)
{
    *d = 100;
}

int main()
{
    char *a = NULL;
    char **b = NULL;
    b = &a;
    ChangePointer(&a);
    printf("%d\n",a);
    ChangePointer2(a);
    printf("%d\n",a);
    return 0;
}
#endif
#if 0
#include<stdio.h>
#include<stdlib.h>

struct info
{
    int a;
    float b;
};

int main()
{
    struct info myinfo;
    printf("%d, %f\n",myinfo.a = 19,myinfo.b = 19.19);
    struct info *p1 = &myinfo;
    printf("%d, %f\n", (*p1).a = 20, (*p1).b = 20.2);
    printf("%d, %f\n", p1 -> a = 20, p1 -> b = 20.2);
    
    struct info *p2 = (struct info *)malloc(sizeof(struct info));
    printf("%d, %f\n", (*p2).a = 21, (*p2).b = 21.21);
    printf("%d, %f\n", p2 -> a = 21, p2 -> b = 21.21);
    free(p1);
    free(p2);
    p1 = NULL;
    p2 = NULL;
    return 0;
}
#endif

#if 0
#include<stdio.h>

int main()
{
    int i = 0;
    int str[10] = {1,2,3,4,5,6,7,8,9,0};
    int *ptr = str;
    for(;i < 10; i++)
    {
        printf("str[%d] = %d\n",i,str[i]);
    } 
    return 0;
}
#endif

#if 0
#include<stdio.h>

void print(int *p, int sz)
{
    int i = 0;
    for(; i < sz; i++)
    {
        printf("%d ",*(p + i));
    }
    printf("\n");
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int *p =arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(p,sz);
    return 0;
}
#endif

#if 0
#include<stdio.h>

int main()
{
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    char *str3 = "hello bit.";
    char *str4 = "hello bit.";
    
    if(str1 == str2) 
            printf("1 & 2 are same\n");
    else
            printf("1 & 2 are not same\n");
    if(str3 == str4)
            printf("3 & 4 are same\n");
    else
            printf("3 & 4 are not same\n");
    return 0;
}
#endif
