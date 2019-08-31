#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#ifndef __DLIST_H__
#define __DLIST_H__

#include<stdio.h>
#include<windows.h>

// ��ͷ���ѭ��˫������
typedef int DLDataType;

typedef struct DListNode
{
	struct DListNode* _pNext;   //
	struct DListNode* _pPre;
	DLDataType _data;
}DListNode;

typedef struct DList
{
	struct DListNode* _pHead;   //ͷ���
}DList;

DListNode *BuyListNode(DLDataType x);
void ListInit(DList* plist);
void ListDestory(DList* plist);
void ListPushBack(DList* plist, DLDataType x);
void ListPopBack(DList* plist);
void ListPushFront(DList* plist, DLDataType x);
void ListPopFront(DList* plist);

DListNode* ListFind(DList* plist, DLDataType x);

// ��pos��ǰ����в���
void ListInsert(DListNode* pos, DLDataType x);

// ɾ��posλ�õĽڵ�
void ListErase(DListNode* pos);

void ListRemove(DList* plist, DLDataType x);

void ListPrint(DList* plist);

void TestDList1();



#endif // !__DLIST_H__