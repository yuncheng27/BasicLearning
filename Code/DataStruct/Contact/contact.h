#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define AddrMAX 50
#define NameSize 20
#define GenSize 10
#define NumSize 12    //��Ϊscanf������ַ�����Ĭ�ϼ�'\0',Ϊ��ʹ��strcmp����������Ҫ������
#define InitCapa 1000
#define FILEPATH "D:\\bite\\code\\Contact\\Contact\\contact.txt"

#include<stdio.h>
#include<windows.h>
#include<string.h>


//�������Ա����䡢�绰��סַ
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
	Infom list[InitCapa];    //�ܹ��ܴ������ϵ��
	int count;     //��¼��ϵ�˸���
}Contact;


//��ӡ����
void PrintContact(Contact *p);

//��ʼ��
void InitContact(Contact *p);

//1.�����ϵ����Ϣ
void AddContact(Contact *p);

//2.ɾ��ָ����ϵ����Ϣ
void DeleteContact(Contact *p);

//3.����ָ����ϵ����Ϣ
void FindContact(Contact *p);

//4.�޸�ָ����ϵ����Ϣ
void ModifContact(Contact *p);

//5.��ʾ������ϵ����Ϣ
void ShowContact(Contact *p);

//6.���������ϵ��
void EmptyContact(Contact *p);

//7.����������������ϵ��
void SortContact(Contact *p);

//8.������ϵ�˵��ļ�
void SaveContact(Contact *p);

//9.������ϵ��
void LoadContact(Contact *p);

#endif // !__CONTACT_H__