#include "parse.h"
#include <stdio.h>
#include "def.h"
#include "externs.h" //声明外部变量
#include "init.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "builtin.h"
#include "execute.h"

void get_command(int i);
void getname(char *name);
void print_command();
/*
 * shell 循环
 * */
void shell_loop(void)
{

  while(1)
  {

    //初始化环境
    init();//每次循环前初始化cmdline和COMMOND
    //读取命令
    if(read_command()==-1)
      break;
    //解析命令
    parse_command();

    //print_command();//打印命令
    //执行命令
    execute_command();


  }
  printf("\nexit\n");

}
/*
 * 读取命令，成功返回0，失败或者读到文件结束符返回-1
 * */
int read_command(void)
{
  /* 按行读取命令,cmdline中包含\n字符  */
  if(fgets(cmdline,MAXLINE,stdin)==NULL)//利用extern来引用全局变量，将所有的extern引用声明放入头文件
    return -1;
  return 0;

}
/*
 * 解析命令：成功返回解析到的命令个数，失败返回-1
 * 例如： cat < test.txt | grep -n public > test2.txt &这个命令
 * cat 先解析出来cmd[0] 以及参数cmd[0].args
 * 然后 <输入重定向 将test.txt保存
 * 然后 |管道  再解析命令grep到 cmd[1] 以及两个参数到cmd[1].args...
 * */
int parse_command(void)
{    
  //开始就检测到\n
  if (check("\n"))
    return 0;
  /*先判定是否内部命令并执行它*/
  if(builtin())
    return 0;//内部命令直接执行，不用解析
  //cmd  [< filename] [| cmd]...[or filename] [&]:方括号表示可选，省略号表示前面可以重复0次或多次
  //or 可以是 > 或者 >> 输出重定向清除文件或者追加到文件尾部方式
  //&是否由后台处理
  //例如：cat < test.txt | grep -n public > test2.txt &

  if(check("\n"))
    return 0;//一开始回车
  /*第一步：解析第一条简单语句*/
  get_command(0);
  /*第二步：判定是否有输入重定向符*/
  if(check("<"))
    getname(infile);//解析文件名字，check成功时,lineptr移动过所匹配的字符串
  /*第三步：判定是否有管道*/
  int i;    
  for(i=1;i<PIPELINE;i++)
  {
    if(check("|"))
      get_command(i);
    else
      break;
  }
  /*第四步：判定是否有输出重定向符*/
  if(check(">"))
  {
    //连续两个>
    if(check(">"))
    {
      append=1;//以追加的方式打开
    }
    getname(outfile);//获取后面文件名，解析到全局变量outfile中
  }
  /*第五步：判定是否有后台作业&*/
  if(check("&"))
    backgnd=1;
  /*第六步：判定命令结束'\n'*/
  if(check("\n"))
  {
    cmd_count=i;//总的命令个数 cat grep...
    return cmd_count;
  }
  //解析失败
  else
  {
    fprintf(stderr,"Command line systax error\n");
    return -1;
  }
  return 0;
}
/*
   执行命令：成功返回0，失败返回-1
   */
int execute_command(void)
{    


  /*执行外部命令*/
  execute_disk_command();
  return 0;
}




//例如cmd[]      ls | wc -w \n
//    avline[]   ls \0 wc \0 -w \0  参数列表数组
//COMMAND cmd[PIPELINE]; cmd[i]是第i条命令,cmd[i].args[j]:是第i条命令的第j个参数
//解析命令至cmd[i],提取cmdline命令参数到avline数组中,并且将COMMAND结构中的args[]中的每个指针指向avline对应参数字符串
void get_command(int i)
{
  int j=0;
  int inword;//针对cat 之后有无参数。如果无参数直接遇到<，inword就不会置1.那么switch遇到<直接args[1]为NULL
  //cat < test.txt | grep -n public > test2.txt &
  while(*lineptr!='\0')
  {
    //lineptr指向cmdline
    while(*lineptr==' '||*lineptr=='\t')
      lineptr++;
    if(*lineptr=='\n'||*lineptr=='\0')
      break;
    //将第i条命令第j个参数指向avptr
    cmd[i].args[j]=avptr;//例如 agrs[0]指向cat  args[1]应该指向空，所以引入inword
    while(*lineptr!='\0'&&*lineptr!='\n'&&*lineptr!='<'&&*lineptr!='|'
        &&*lineptr!='>'&&*lineptr!='&'&&*lineptr!=' '&&*lineptr!='\t')
    {
      *avptr++=*lineptr++;//参数提取至avptr指针指向的数组avline。
      inword=1;
    }
    *avptr++='\0';
    switch(*lineptr)
    {
      //解析到下一个参数。break回来继续。
      case ' ':
      case '\t':
        inword=0;
        j++;
        break;
        //这条命令提取结束
      case '<':
      case '>':
      case '|':
      case '&':
      case '\n':
        if(inword==0)  cmd[i].args[j]=NULL;
        return ;//只解析第i条语句。完了函数就返回
        //  for \0
      default:
        return ;        
    }
  }
}
void print_command()
{
  int i;
  int j;
  printf("cmd_count=%d\n",cmd_count);
  if(infile[0]!='\0')
    printf("infile=[%s]\n",infile);
  if(outfile[0]!='\0')
    printf("outfile=[%s]\n",outfile);
  for(i=0;i<cmd_count;i++)
  {
    j=0;
    while(cmd[i].args[j]!=NULL)
    {
      printf("[%s] ",cmd[i].args[j]);
      j++;
    }
    printf("\n");
  }

}
/*
   将lineptr中的字符串与str进行匹配
   成功返回1,失败返回0,成功时lineptr移过所匹配的字符串。失败时lineptr不变
   */
int check(const char*str)
{
  //lineptr指向cmd 遇到<  >  | & 会返回
  char *p;
  while(*lineptr==' '||*lineptr=='\t')
    lineptr++;
  p=lineptr;

  while(*str!='\0'&&*str==*p)
  {
    str++;
    p++;
  }
  //*str==\0 或者*str!=*p
  if(*str=='\0')//str中字符都匹配完了，之前的全部一致
  {
    lineptr=p;//移动lineptr.
    return 1;
  }
  //未解析到则不用移动
  return 0;
}
void getname(char *name)
{
  while(*lineptr==' '||*lineptr=='\t')
    lineptr++;
  while(*lineptr!='\0'&&*lineptr!='\n'&&*lineptr!='<'&&*lineptr!='|'
      &&*lineptr!='>'&&*lineptr!='&'&&*lineptr!=' '&&*lineptr!='\t')
  {
    *name++=*lineptr++;
  }    
  *name='\0';
}
