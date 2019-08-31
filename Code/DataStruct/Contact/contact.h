#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define AddrMAX 50
#define NameSize 20
#define GenSize 10
#define NumSize 12    //因为scanf输入的字符串会默认加'\0',为了使用strcmp函数，数组要多申请
#define InitCapa 1000
#define FILEPATH "D:\\bite\\code\\Contact\\Contact\\contact.txt"

#include<stdio.h>
#include<windows.h>
#include<string.h>


//姓名、性别、年龄、电话、住址
typedef struct Information
{
	char name[NameSize];
	char gender[GenSize];
	int age;
	char number[NumSize];
	char addr[AddrMAX];
}Infom;

typedef struct Contact
{
	Infom list[InitCapa];    //总共能存多少联系人
	int count;     //记录联系人个数
}Contact;


//打印函数
void PrintContact(Contact *p);

//初始化
void InitContact(Contact *p);

//1.添加联系人信息
void AddContact(Contact *p);

//2.删除指定联系人信息
void DeleteContact(Contact *p);

//3.查找指定联系人信息
void FindContact(Contact *p);

//4.修改指定联系人信息
void ModifContact(Contact *p);

//5.显示所有联系人信息
void ShowContact(Contact *p);

//6.清空所有联系人
void EmptyContact(Contact *p);

//7.以名字排序所有联系人
void SortContact(Contact *p);

//8.保存联系人到文件
void SaveContact(Contact *p);

//9.加载联系人
void LoadContact(Contact *p);

#endif // !__CONTACT_H__