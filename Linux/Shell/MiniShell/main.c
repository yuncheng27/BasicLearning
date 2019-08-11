/* minishell实现的功能：简单命令解析、管道行解析、输入输出重定向解析、一些内置命令实现、简单的信号处理功能
 * 未实现的功能：语法分析、别名处理、路径扩展、通配处理、算术处理、变量处理、作业控制
 * shell_loop {
 *  read_command //读
 *  parse_command //解析
 *  execute_command //执行
 * }
 */ 

#include "parse.h"
#include "init.h"
#include "def.h"

char cmdline[MAXLINE+1];//定义全局变量存放读取的命令
char avline[MAXLINE+1];//保存解析出来的参数
char *lineptr;//初始指向cmdline数组
char *avptr;//初始指向avline数组

char infile[MAXNAME+1];//输入文件名，用于保存输入重定向文件名
char outfile[MAXNAME+1];//输出文件名
COMMAND cmd[PIPELINE];//参数列表

int cmd_count;//命令个数
int backgnd;//是否是后台操作
int lastpid;//这是最后一个子进程退出

int append;
int main()
{

  setup();//安装信号，划分到初始化模块
  shell_loop();//进入shell循环
  return 0;

}
