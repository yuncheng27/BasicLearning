#ifndef __NHSXLB_H__
#define __NHSXLB_H__

typedef int SLDataType;
typedef struct SListNode
{
	struct SListNode* _pNext;
	SLDataType _data;
}SListNode;


// 不带头节点的单链表 
void SListInit(SListNode** pHead);
void SListPushBack(SListNode** pHead, SLDataType data);
void SListPopBack(SListNode** pHead);
void SListPushFront(SListNode** pHead, SLDataType data);
void SListPopFront(SListNode** pHead);
SListNode* SListFind(SListNode* pHead, SLDataType data);
void SListInsert(SListNode* pos, SLDataType data);
void SListErase(SListNode** pHead, SListNode* pos);
void SListDestroy(SListNode** pHead);
int SListSize(SListNode* pHead);
int SListEmpty(SListNode* pHead);
SLDataType Front(SListNode* pHead);
SLDataType Back(SListNode* pHead);
void SListRemove(SListNode* pHead, SLDataType data);
void SListRemoveAll(SListNode* pHead, SLDataType data);
void SlistBubbleSort(SListNode* pHead);

////////////////////////////////////////////// 
void TestList();

#endif // !__NHSXLB_H__