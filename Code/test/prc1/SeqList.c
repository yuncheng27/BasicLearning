//动态链表的结构
typedef struct SeqList
{
    DataType* _pData;  //空间的首地址
    int _capacity;  //空间的总大小
    int _size;   //有效元素的个数
}SeqList;


void SeqListInit(PSwqLIst ps,int capacity)
{
    assert(ps);
    ps->_pData = (DataType*);
    if(NULL == ps -> _pData)
    {
        
    }
    ps->_capacity = capacity;
    ps->_size = 0;
}

//在顺序表尾插入元素data
void SeqListPushBack(PSeqList ps, DataType data)
{
    ps->_pData[ps->_size++] = data;    
}

//删除顺序表中最后一个元素
void SeqListPushBack()
{
    assert(ps);
    if(ps->_size)
        ps->_size--;

}

//获取顺序表中有效元素的个数
int SeqListSize(PSeqList ps)

void PrintSeqList()
{
    for(int i = 0; i < ps->_size; ++i)
    {
        printf("%d ",ps->_pData[i]);
    }
    printf("\n");
}

//在顺序表的头部插入元素data
void SeqListPushFront(PSeqList ps)
{
    assert(ps);
    if(0 == ps->_size)
        return;
     for(int i = 0;;)
}

//Init/PushBack/PopBack
void TestSeqList1()
{
    SeqList a;

}

