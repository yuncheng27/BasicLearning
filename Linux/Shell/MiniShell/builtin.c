#include "builtin.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
//内部命令解析，返回1表示内部命令，返回0不是内部命令

void do_exit();
void do_cd();
int builtin(void) {
  if(check("exit"))
    do_exit();
  else if(check("cd"))
    do_cd();
  else 
    return 0;
  return 1;
}

void do_exit() {
  printf("exit");
  exit(EXIT_SUCCESS);
}

void do_cd() {
  printf("do_cd...\n");
}
