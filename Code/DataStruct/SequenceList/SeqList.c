#define _CRT_SECURE_NO_WARNINGS 1
#include "SXB.h"

//初始化顺序表
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

//用于扩充顺序表的空间的函数
int AddCapacity(SeqList *ps)
{
	DataType *New_space = (DataType *)malloc(ps, sizeof(DataType) * (ps->_capacity + Init_Size));
	if (NULL == New_space)
	{
		printf("内存空间已满，无法分配！\n");
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


//在顺序表尾部插入一个元素data  
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
			printf("顺序表已满，数据添加失败！\n");
			return;
		}
	}
	else
	{
		ps->_pData[ps->_size] = data;
	}
	ps->_size++;
}

//删除顺序表中最后一个元素
void SeqListPopBack(SeqList *ps)
{
	assert(ps);
	if (0 == ps->_size)
	{
		printf("顺序表为空，无法删除！\n");
		return;
	}
	ps->_size--;
}

//在顺序表头部插入元素data 
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
			printf("顺序表已满，数据添加失败！\n");
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


//删除顺序表的头部元素
void SeqListPopFront(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("顺序表已空，无法再删除元素！\n");
		return;
	}
	for (int i = 0; i < ps->_size - 1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

//在顺序表的pos位置插入元素data 
void SeqListInsert(SeqList *ps, int pos, DataType data)
{
	if (pos < 0 || pos > ps->_size)
	{
		printf("输入的位置不合法！无法插入元素\n");
		return;
	}
	if (ps->_size >= ps->_capacity && !AddCapacity(ps))
	{
		printf("顺序表已满，无法插入元素！\n");
		return;
	}
	for (int i = ps->_size - 1; i > pos; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_pData[pos] = data;
	ps->_size++;
}

//删除顺序表中pos的元素
void SeqListErase(SeqList *ps, int pos)
{
	if (pos >= ps->_size || pos < 0)
	{
		printf("输入位置非法，无法删除元素！\n");
		return;
	}
	for (int i = pos; i < ps->_size - 1; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

//在顺序表中找出data元素第一次出现的位置
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

//删除顺序表中值为data的元素
void SeqListRemove(SeqList *ps, DataType data)
{
	int pos = SeqListFind(&ps, data);
	if (-1 == pos)
	{
		printf("表中没有这个元素，无法删除！\n");
		return;
	}
	SeqListErase(&ps, pos);
}

//获取顺序表中有效元素的个数
int SeqListSize(SeqList *ps)
{
	return ps->_size;
}

//获取顺序表的容量
int SeqListCapacity(SeqList *ps)
{
	return ps->_capacity;
}

//获取顺序表中第一个元素
DataType SeqListFront(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("顺序表已空！\n");
		return;
	}
	return ps->_pData[0];
}

//获取顺序表中最后一个元素
DataType SeqListBack(SeqList *ps)
{
	if (0 == ps->_size)
	{
		printf("顺序表已空！\n");
		return;
	}
	return ps->_pData[ps->_size];
}

//清空顺序表中有效元素
void SeqListClear(SeqList *ps)
{
	ps->_size = 0;
}


//销毁顺序表
void SeqListDestroy(SeqList *ps)
{
	free(ps->_pData);
	ps->_pData = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

//删除顺序表中所有值为data的元素
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

//用冒泡排序的方法对所有元素进行排序
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

//用于输出测试
void TestSeqList(SeqList *ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_pData[i]);
	}
	printf("\n");
}
//逆置整个顺序表
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
//获取顺序表中有效元素的个数
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
