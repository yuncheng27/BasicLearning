#include<stdio.h>
<<<<<<< HEAD

union Check
{
    char ch;
    int a;
}c;

int CheckSystem(void)
{
    c.a =1;
    return(c.ch == 1);
}

int main(int argc, char *argv[])
{
    if(CheckSystem() == 0)
    {
        printf("This is Big_endian system!\n");
    }
    else
    {
        printf("This is Little_endian system!\n");
    }
    return 0;
}



#if 0
#include<stdio.h>

enum WeekDay
{
    Monday = 1,     //1
    Tuesday,        //2
    Wednesday,      //3
    Thursday,       //3 
    Friday = 10,    //10
    Saturday,       //11
    Sunday          //12
}a, b, c, d;

int main(int argc, char *argv[])
{
    a = Monday;
    b = Friday;
    c = Saturday;
    d = 11;   //在c中编译通过，在C++中编译出错
    printf("%p, %p, %p, %p\n", &a, &b, &c, &d);
    printf("%d, %d, %d, %d\n", a, b, c, d);
    return 0;
}
#endif

#if 0
#include<stdio.h>

union state
{
    char a;
    short b;
    int c;
}s;

int main(int argc, char *argv[])
{
    s.c = 0x12345678;
    printf("sizeof(s) = %d\n", sizeof(s));
    printf("%p %p %p\n", &s.a, &s.b, &s.c);
    printf("%x %x %x\n", s.a, s.b, s.c);
    return 0;
}
#endif

#if 0
#include<stdio.h>
=======
>>>>>>> origin/master
#include<string.h>

char *SortArray(char **arr,int size)   //排序函数
{
    int i = 0;
    int j = 0;
    int *tmp = NULL;
    for(i = 0; i < size; i++)
    {
        for(j = 1; j < size; j++)
        {
            if(strcmp(arr[i],arr[j]) > 0)
            {
                *tmp = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = *tmp;
            } 
        }
    }
    return *arr;
}

void PrintArray(char **arr, int size)
{
    int i = 0;
    for(; i < size; ++i)
    {
        printf("%s",**(arr + i));
    }
}

int main()
{
    char *arr[] = {"aaaaa","bbbbb","ccccc","dddddd"};
    int size = sizeof(arr)/sizeof(arr[0]);
    SortArray(arr,size);
    PrintArray(arr,size);
    return 0;
}
<<<<<<< HEAD
#endif
=======
>>>>>>> origin/master
