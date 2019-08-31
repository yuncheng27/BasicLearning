#pragma once
#ifndef __SXB_H__
#define __SXB_H__
#define false 0
#define true 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define Init_Size 10   //初始化大小

typedef int DataType;

//动态顺序表的结构
typedef struct SeqList
{
	DataType *_pData;    //空间的首地址
	int _capacity;       //空间的总大小
	int _size;            //空间元素的个数
}SeqList, *PSeqList;

//初始化顺序表
void SeqListInit(SeqList *ps);

//在顺序表尾部插入一个元素data  
void SeqListPushBack(SeqList *ps, DataType data);

//删除顺序表中最后一个元素
void SeqListPopBack(SeqList *ps);

//在顺序表头部插入元素data 
void SeqListPushFront(SeqList *ps, DataType data);

//删除顺序表的头部元素
void SeqListPopFront(SeqList *ps);

//在顺序表的pos位置插入元素data 
void SeqListInsert(SeqList *ps, int pos, DataType data);

//删除顺序表中pos的元素
void SeqListErase(SeqList *ps, int pos);

//在顺序表中找出data元素第一次出现的位置
int SeqListFind(SeqList *ps, DataType data);

//删除顺序表中值为data的元素
void SeqListRemove(SeqList *ps, DataType data);

//获取顺序表中有效元素的个数
int SeqListSize(SeqList *ps);

//获取顺序表的容量
int SeqListCapacity(SeqList *ps);

//获取顺序表中第一个元素
DataType SeqListFront(SeqList *ps);

//获取顺序表中最后一个元素
DataType SeqListBack(SeqList *ps);

//清空顺序表中有效元素
void SeqListClear(SeqList *ps);

//销毁顺序表
void SeqListDestroy(SeqList *ps);

//检测容量
//void CheckCapacity(SeqList *ps);
//用于扩充顺序表的空间的函数
int AddCapacity(SeqList *ps);

//删除顺序表中所有值为data的元素
void SeqListRemoveAll(SeqList *ps, DataType data);

//用冒泡排序的方法对所有元素进行排序
void BubbleSort(SeqList *ps);

//////////////////////////////////////////////////////////////////
//用于输出测试
void TestSeqList(SeqList *ps);

//逆置整个顺序表
void SeqListReverse(SeqList *ps);

#endif //__SEQLIST_H__
