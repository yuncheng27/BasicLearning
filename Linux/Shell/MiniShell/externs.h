#ifndef _EXTERNS_H_
#define _EXTERNS_H_ 

#include "def.h"
extern char cmdline[MAXLINE+1];
extern COMMAND cmd[PIPELINE];
extern char avline[MAXLINE+1];
extern char *lineptr;  //指向cmdline数组
extern char *avptr;  //指向avline数组
extern int cmd_count;
extern int backgnd;
extern char infile[MAXNAME+1];
extern char outfile[MAXNAME+1];
extern int lastpid;
extern int append;

#endif 
