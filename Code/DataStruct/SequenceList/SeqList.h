#pragma once
#ifndef __SXB_H__
#define __SXB_H__
#define false 0
#define true 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define Init_Size 10   //��ʼ����С

typedef int DataType;

//��̬˳���Ľṹ
typedef struct SeqList
{
	DataType *_pData;    //�ռ���׵�ַ
	int _capacity;       //�ռ���ܴ�С
	int _size;            //�ռ�Ԫ�صĸ���
}SeqList, *PSeqList;

//��ʼ��˳���
void SeqListInit(SeqList *ps);

//��˳���β������һ��Ԫ��data  
void SeqListPushBack(SeqList *ps, DataType data);

//ɾ��˳��������һ��Ԫ��
void SeqListPopBack(SeqList *ps);

//��˳���ͷ������Ԫ��data 
void SeqListPushFront(SeqList *ps, DataType data);

//ɾ��˳����ͷ��Ԫ��
void SeqListPopFront(SeqList *ps);

//��˳����posλ�ò���Ԫ��data 
void SeqListInsert(SeqList *ps, int pos, DataType data);

//ɾ��˳�����pos��Ԫ��
void SeqListErase(SeqList *ps, int pos);

//��˳������ҳ�dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(SeqList *ps, DataType data);

//ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemove(SeqList *ps, DataType data);

//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList *ps);

//��ȡ˳��������
int SeqListCapacity(SeqList *ps);

//��ȡ˳����е�һ��Ԫ��
DataType SeqListFront(SeqList *ps);

//��ȡ˳��������һ��Ԫ��
DataType SeqListBack(SeqList *ps);

//���˳�������ЧԪ��
void SeqListClear(SeqList *ps);

//����˳���
void SeqListDestroy(SeqList *ps);

//�������
//void CheckCapacity(SeqList *ps);
//��������˳���Ŀռ�ĺ���
int AddCapacity(SeqList *ps);

//ɾ��˳���������ֵΪdata��Ԫ��
void SeqListRemoveAll(SeqList *ps, DataType data);

//��ð������ķ���������Ԫ�ؽ�������
void BubbleSort(SeqList *ps);

//////////////////////////////////////////////////////////////////
//�����������
void TestSeqList(SeqList *ps);

//��������˳���
void SeqListReverse(SeqList *ps);

#endif //__SEQLIST_H__
