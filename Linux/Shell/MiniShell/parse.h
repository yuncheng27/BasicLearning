#ifndef _PARSE_H_
#define _PARSE_H_ 

//定义函数接口
void shell_loop(void);  //shell循环
int read_command(void);
int parse_command(void);
int execute_command(void);
int check(const char*str);
#endif 
