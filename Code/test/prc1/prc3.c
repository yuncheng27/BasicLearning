#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;
    char filename1[] = "prc1.c";
    char filename2[] = "prcs.c";   

    fp1 = fopen(filename1, "r");    //以只读打开
    fp2 = open(filename2, "w");    //以只写打开
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("can't open file!");
        exit(1);      //<stdlib.h>
    }
    ch = fgetc(fp1);
    {
        putchar(ch);
        ch = fgetc(fp1);    //读取下一个字符
    }
    rewind(fp1);     //将文件A的位置重新指向文件头
    ch = fgetc(fp1);
    while(ch != EOF)
    {
        fputc(ch, fp2);     //将文件A读取到的字符复制到文件B中
        ch = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

