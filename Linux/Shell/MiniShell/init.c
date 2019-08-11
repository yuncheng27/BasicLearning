#include "init.h"
#include "externs.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>

void sigint_handler(int sig) {
  printf("\n[minishell]$ ");
  fflush(stdout);  //没有(\n)
}

void setup(void) {
  signal(SIGINT, sigint_handler);
  signal(SIGQUIT, SIG_IGN);
}

void init(void) {
  memset(cmd, 0, sizeof(cmd));
  int i = 0;
  for(i = 0; i < PIPELINE; i++) {
    cmd[i].infd=0;  //初始命令的输入  默认标准输入0
    cmd[i].outfd=1;  //初始化所有输出  默认标准输出1
  }
  memset(&cmdline, 0, sizeof(cmdline));
  lineptr = cmdline;
  avptr = avline;
  memset(avline, 0, sizeof(avline));
  memset(infile, 0, sizeof(infile));
  memset(outfile, 0, sizeof(outfile));
  cmd_count = 0;
  backgnd = 0;
  lastpid = 0;
  append = 0;
  printf("[minishell]$ ");
  fflush(stdout); //无\n
}
