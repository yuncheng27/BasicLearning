//头文件声明宏
#ifndef _DEF_H_
#define _DEF_H_ 

#include <stdio.h>
#include <stdlib.h>

#define ERR_EXIT(m)\
  do\
  {\
    perror(m);\
    exit(EXIT_FAILURE);\
  }while(0);
#define MAXLINE 1024 //输入行最大长
#define MAXARG 20  //每个简单命令参数最多个数
#define PIPELINE 5 //一个管道行简单命令最多个数
#define MAXNAME 100 //IO重定向文件名最大个数

typedef struct command {
  char *args[MAXARG + 1];  //参数解析出来放到args中，参数列表
  int infd;  //输入描述符
  int outfd; //输出描述符
}COMMAND;

#endif 
