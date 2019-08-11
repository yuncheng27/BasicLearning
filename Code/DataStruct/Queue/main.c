#include"queue.h"

void QueueInit(Queue* pq)
{
    q->_front = q->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
}
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq)
{
    
    pCur->_data = data;
    pCur->_next = NULL;
    if(NULL == q->_front)
    {
        q->_front = q->_back = pCur;
    }
    else
    {
        q->_back->_next = pCur;
        q->_Back = pCur;
    }
}
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq)
{
    return q->_back->_data;
}
int QueueEmpty(Queue* pq)
{
    return NULL = q->_front;
}
int QueueSize(Queue* pq)
{
    int count = 0;
}
void TestQueue();
