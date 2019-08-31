#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>

typedef int STDataType;
typedef struct Stack
{
    STDataType *_array;
    int _top;         //栈顶
    int _capacity;    //容量
}Stack;
void StackInit(Stack *p);
void StackDestory(Stack *p);
void StackPush(Stack *p, STDataType data);
void StackPop(Stack *p);
STDataType StackTop(Stack *p);
int StackEmpty(Stack *p);
int StackSize(Stack *p);

void TestStack();

#endif // !__STACK_H__
