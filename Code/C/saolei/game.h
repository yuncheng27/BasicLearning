#ifndef __GAME_H__
#define __GAME__H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define row 12
#define col 12
#define COUNT 98  //棋盘中雷的总数
extern char show_mine[row][col];  //展示数组
extern char real_mine[row][col];  //布雷数组


void menu(); 
void init_mine();
void set_mine();
int count_mine(int x, int y);
void print_player();
void print_mine();
int sweep_mine();
void safe_mine();
void open_mine(int x, int y);
int count_show_mine();

#endif  //__GAME_H__