#include"stack.h"

#if 0
typedef int STDataType;
typedef struct Stack
{
    STDataType *_array;
    int _top;         //栈顶
    int _capacity;    //容量
}Stack;
#endif

void StackInit(Stack *p);
void StackDestory(Stack *p);
void StackPush(Stack *p, STDataType data);
void StackPop(Stack *p);
STDataType StackTop(Stack *p);
int StackEmpty(Stack *p);
