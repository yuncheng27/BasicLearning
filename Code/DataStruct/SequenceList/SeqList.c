#define _CRT_SECURE_NO_WARNINGS 1
#include "SXB.h"

//��ʼ��˳���
void SeqListInit(SeqList *ps)
{
	assert(ps);
	ps->_pData = (DataType *)malloc(sizeof(DataType) * Init_Size);
	if (NULL != ps->_pData)
	{
		ps->_size = 0;
		ps->_capacity = Init_Size;
	}
	else
	{
		exit(0);
	}
}

//��������˳���Ŀռ�ĺ���
int AddCapacity(SeqList *ps)
{
	DataType *New_space = (DataType *)malloc(ps, sizeof(DataType) * (ps->_capacity + Init_Size));
	if (NULL == New_space)
	{
		printf("�ڴ�ռ��������޷����䣡\n");
		return false;
	}
	ps->_pData = New_space;
	ps->_capacity += Init_Size;
	return true;
	/*assert(ps);
	SeqList *New_space = (SeqList *)malloc(ps,sizeof(DataType) * Init_Size * 2);
	if (NULL != New_space)
	{
		memcpy(New_space, ps, sizeof(DataType) * Init_Size);
		free(ps);
		ps = New_space;
		ps->_capacity = sizeof(DataType) * Init_Size;
		return true;
	}
	return false;*/
}


//��˳���β������һ��Ԫ��data  
void SeqListPushBack(SeqList *ps, DataType data)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		if (AddCapacity(ps))
		{
			ps->_pData[ps->_size] = data;
			ps->_size++;
		}
		else
		{
			printf("˳����������������ʧ�ܣ�\n");
			return;
		}
	}
	else
	{
		ps->_pData[ps->_size] = data;
	}
	ps->_size++;
}

//ɾ��˳��������һ��Ԫ��
void SeqListPopBack(SeqList *ps)
{
	assert(ps);
	if (0 == ps->_size)
	{
		printf("˳���Ϊ�գ��޷�ɾ����\n");
		return;
	}
	ps->_size--;
}

//��˳���ͷ������Ԫ��data 
void SeqListPushFront(SeqList *ps, DataType data)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		if (AddCapacity(ps))
		{
			for (int i = ps->_size; i > 0; i--)
			{
				ps->_pData[i] = ps->_pData[i - 1];
			}
			ps->_pData[0] = data;
			ps->_size++;
		}
		else
		{
			printf("˳����������������ʧ�ܣ�\n");
			return;
		}
	}
	for (int i = ps->_size - 1; i > 0; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_pData[0] = data;
	ps->_size++;
}


//ɾ��˳����ͷ��Ԫ��
void SeqListPopFront(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("˳����ѿգ��޷���ɾ��Ԫ�أ�\n");
		return;
	}
	for (int i = 0; i < ps->_size - 1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

//��˳����posλ�ò���Ԫ��data 
void SeqListInsert(SeqList *ps, int pos, DataType data)
{
	if (pos < 0 || pos > ps->_size)
	{
		printf("�����λ�ò��Ϸ����޷�����Ԫ��\n");
		return;
	}
	if (ps->_size >= ps->_capacity && !AddCapacity(ps))
	{
		printf("˳����������޷�����Ԫ�أ�\n");
		return;
	}
	for (int i = ps->_size - 1; i > pos; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_pData[pos] = data;
	ps->_size++;
}

//ɾ��˳�����pos��Ԫ��
void SeqListErase(SeqList *ps, int pos)
{
	if (pos >= ps->_size || pos < 0)
	{
		printf("����λ�÷Ƿ����޷�ɾ��Ԫ�أ�\n");
		return;
	}
	for (int i = pos; i < ps->_size - 1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

//��˳������ҳ�dataԪ�ص�һ�γ��ֵ�λ��
int SeqListFind(SeqList *ps, DataType data)
{
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (data == ps->_pData[i])
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

//ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemove(SeqList *ps, DataType data)
{
	int pos = SeqListFind(&ps, data);
	if (-1 == pos)
	{
		printf("����û�����Ԫ�أ��޷�ɾ����\n");
		return;
	}
	SeqListErase(&ps, pos);
}

//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList *ps)
{
	return ps->_size;
}

//��ȡ˳��������
int SeqListCapacity(SeqList *ps)
{
	return ps->_capacity;
}

//��ȡ˳����е�һ��Ԫ��
DataType SeqListFront(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("˳����ѿգ�\n");
		return;
	}
	return ps->_pData[0];
}

//��ȡ˳��������һ��Ԫ��
DataType SeqListBack(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("˳����ѿգ�\n");
		return;
	}
	return ps->_pData[ps->_size];
}

//���˳�������ЧԪ��
void SeqListClear(SeqList *ps)
{
	ps->_size = 0;
}


//����˳���
void SeqListDestroy(SeqList *ps)
{
	free(ps->_pData);
	ps->_pData = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

//ɾ��˳���������ֵΪdata��Ԫ��
void SeqListRemoveAll(SeqList *ps, DataType data)
{
	int count = 0;
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (data == ps->_pData[i])
		{
			count++;
			ps->_pData[i] = ps->_pData[i + count];
		}
	}
	ps->_size -= count;
}

//��ð������ķ���������Ԫ�ؽ�������
void BubbleSort(SeqList *ps)
{
	for (int i = 0; i < ps->_size - 1; i++)
	{
		for (int j = 0; j < ps->_size - 1 - i; j++)
		{
			if (ps->_pData[j] > ps->_pData[j + 1])
			{
				DataType tmp = ps->_pData[j];
				ps->_pData[j] = ps->_pData[j + 1];
				ps->_pData[j + 1] = tmp;
			}
		}
	}
}

//�����������
void TestSeqList(SeqList *ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}
//��������˳���
void SeqListReverse(SeqList *ps)
{
	if (0 == ps->_size || 1 == ps->_size)
	{
		return;
	}
	int low = 0, high = ps->_size - 1;
	while (low < high)
	{
		DataType tmp = ps->_pData[low];
		ps->_pData[low] = ps->_pData[high];
		ps->_pData[high] = tmp;
		high--;
		low++;
	}
}

#if 0
//��ȡ˳�������ЧԪ�صĸ���
int SeqListSize(SeqList *ps)
{
	int count = 0;
	SeqList *pCur = ps;
	while (pCur)
	{
		pCur = pCur->_pData;
		count++;
	}
	return count;
}
#endif
