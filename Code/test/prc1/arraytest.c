#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void Check(char *a, char *b, int(*cmp)(const char *, const char *));  //check函数的第三个参数是函数指针，可以根据具体情况传入不同的处理函数

int CompValues(const char *a, const char *b); 
 
int main()
{
    char s1[80], s2[80]; 
    printf("please enter two string:\n");
    fgets(s1,100,stdin);
    fgets(s2,100,stdin);
    if(isdigit(*s1))  //如果是数字，则用函数指针传入数字比较函数进行处理
     {
        printf("Testing value for equality.\n");
        Check(s1, s2, CompValues);
    }
    else
    {
        printf("Testing string for equality.\n");
        Check(s1, s2, strcmp); 
    }
    return 0;
}

void Check(char *a, char *b, int(*cmp)(const char *, const char *))
{
    if ((*cmp)(a, b) == 0)    //表达式(*cmp)(a, b)调用strcmp,由cmp指向strcmp(),a,b作为调用函数的参数
    {
            printf("Equal!\n");
        }
    else    
    {
            printf("Not Equal!\n");
        }
}

int CompValues(const char *a, const char *b)
{
    if(atoi(a) == atoi(b))
    {
        return 0;
    }
    else
    {
        return 1;
    }
} 

#if 0
#include<stdio.h>
#include<string.h>
void Check(char *a, char *b, int(*cmp)(const char *, const char *));

int main()
{
    char s1[80], s2[80];
    int (*p)(const char *, const char *);
    p = strcmp;   //将库函数strcmp的地址赋给函数指针p
    printf("please enter two string:\n");
    fgets(s1,100,stdin);
    fgets(s2,100,stdin);
    Check(s1, s2, p);
    return 0;
}

void Check(char *a, char *b, int(*cmp)(const char *, const char *))
{
    if ((*cmp)(a, b) == 0)    //表达式(*cmp)(a, b)调用strcmp,由cmp指向strcmp(),a,b作为调用函数的参数
    {
        printf("Equal!\n");
    }
    else
    {
        printf("Not Equal!\n");
    }
}
#endif

#if 0
#include<stdio.h>

#define GET_MAX 1
#define GET_MIN 0

int GetMax(int i,int j)
{
    return i>j?i:j;
}

int GetMin(int i, int j)
{
    return i>j?j:i;
}

int Compare(int i, int j,int flag)
{
    int ret;
    int (*p)(int,int);
    if(flag == GET_MAX)
    {
        p = GetMax;
    }
    else
    {
        p = GetMin;
    }
    ret = p(i, j);
    return ret;
}

int main()
{
    int i = 22, j = 49, ret;
    ret = Compare(i, j, GET_MAX);
    printf("the max is:%d\n",ret);
    ret = Compare(i, j, GET_MIN);
    printf("the min is:%d\n",ret);
    return 0;
}
#endif
