#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

DListNode *BuyListNode(DLDataType x)    //给新节点赋值，并返回新节点的位置
{
	DListNode *pNewNode = (DListNode *)malloc(sizeof(DListNode));
	assert(pNewNode);
	pNewNode->_data = x;
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	return pNewNode;
}

void ListInit(DList* plist)    //只有一个头结点
{
	assert(plist);
	plist->_pHead = BuyListNode(0);     //头结点置零
	plist->_pHead->_pNext = plist->_pHead;
	plist->_pHead->_pPre = plist->_pHead;
}

void ListDestory(DList* plist)
{
	assert(plist);
	DListNode *pCur = plist->_pHead->_pNext;
	DListNode *pNew;
	while (pCur != plist->_pHead)
	{
		pNew = pCur->_pNext;
		free(pCur);
		pCur = pNew;
	}
	free(plist->_pHead);
	plist->_pHead = NULL;
}

void ListPushBack(DList* plist, DLDataType x)
{

}


void ListPopBack(DList* plist);


void ListPushFront(DList* plist, DLDataType x);


void ListPopFront(DList* plist);


DListNode* ListFind(DList* plist, DLDataType x);

// 在pos的前面进行插入
void ListInsert(DListNode* pos, DLDataType x);

// 删除pos位置的节点
void ListErase(DListNode* pos);

void ListRemove(DList* plist, DLDataType x);

void ListPrint(DList* plist);


void TestDList1()
{
	DList dl;
	ListDestory(&dl);
}

#if 0
void ListInit(List *plist)
{
	assert(plist);
	plist->head = BuyListNode(0);
	plist->head->_next = plist->head;
	plist->head->_prev = plist->head;
}

void ListDestory(List *plist)
{
	assert(plist);
	ListNode *cur = plist->head->_next;
	ListNode *next;
	while (cur != plist->head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->head);
	plist->head = NULL;
}

void ListPushBack(List *plist, LTDataType x)
{
	assert(plist);

	/*ListNode *newNode = BuyListNode(x);
	ListNode *head = plist->head;
	ListNode *tail = head->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = head;
	head->_prev = newNode;*/
	ListInsert(plist->head, x);
}

void ListPopBack(List *plist)
{
	assert(plist);

	/*ListNode *head = plist->head;
	ListNode *tail = head->_prev;
	ListNode*prev = tail->_prev;

	prev->_next = head;
	head->_prev = prev;
	free(tail);
	tail = NULL;*/

	ListErase(plist->head->_prev);
}

void ListPushFront(List *plist, LTDataType x)
{
	assert(plist);

	/*ListNode *head = plist->head;
	ListNode *next = head->_next;
	ListNode *newNode = BuyListNode(x);

	head->_next = newNode;
	newNode->_prev = head;
	newNode->_next = next;
	next->_prev = newNode;*/

	ListInsert(plist->head->_next, x);
}

void ListPopFront(List *plist)
{
	assert(plist);

	/*ListNode *head = plist->head;
	ListNode *next = head->_next;
	ListNode *nextNext = next->_next;

	head->_next = nextNext;
	nextNext->_prev = head;
	free(next);
	next = NULL;*/

	ListErase(plist->head->_next);
}

void ListInsert(ListNode *pos, LTDataType x)
{
	assert(pos);

	ListNode *prev = pos->_prev;
	ListNode *newNode = BuyListNode(x);

	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}

void ListErase(ListNode *pos)
{
	assert(pos);

	ListNode *prev = pos->_prev;
	ListNode *next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

ListNode * ListFind(List *plist, LTDataType x)
{
	assert(plist);

	ListNode *head = plist->head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListPrint(List *plist)
{
	ListNode *head = plist->head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("<->\n");
}

void ListTest()
{
	List lt;
	ListInit(&lt);
	ListPushBack(&lt, 1);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4);
	ListPopBack(&lt);
	ListPopFront(&lt);
	ListPrint(&lt);
}
#endif