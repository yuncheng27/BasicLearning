#include"Heap.h"

void HeapPrint(Heap *hp)
{
    int i;
    for (i = 0; i < hp->_capacity; i++)
    {
        printf("%d ", hp->_a[i]);
    }
    printf("\n");
}

void HeapInit(Heap *hp, int n)
{
    assert(hp);
    hp->_a = (HPDataType *)malloc(n * sizeof(HPDataType));
    if (NULL == hp->_a)
    {
         printf("allocate error!\n");
         exit(1);
    }
    hp->_capacity = 0;
    hp->_size = InitSize;
}

void HeapPush(Heap *hp, HPDataType x)
{
   int i;
   if(hp->_size == hp->_capacity) //容量已满
   {
        HPDataType *p;
        p = realloc(hp->_a, 2 * hp->_size * sizeof(HPDataType));
        if(!p)
        {
            printf("无法开辟新空间！\n");
            exit(1);
        }
        printf("空间已扩充两倍！\n");
        hp->_a = p;
        hp->_size *= 2;
   }
    hp->_a[hp->_capacity] = x;
    hp->_capacity++;
    i = hp->_capacity - 1;
    while(0 != i)    //当i != 0时，此时必然有至少两个节点，因此需要比较父节点和子节点的大小，创建小堆
    {
        int j = (i - 1)/2;
        if(hp->_a[j] < x)
        {
            break;
        }
        hp->_a[i] = hp->_a[j];
        i = j;
    }
    hp->_a[i] = x;      //把新元素调整到最终的i位置
}
#if 1
void AdjustDown(Heap *hp, int start, int end)
{
    int i;
    HPDataType tmp = hp->_a[start];
    for (i = 2*start + 1; i <= end; i++)
    {
        if (i < end && hp->_a[i] > hp->_a[i + 1])
        {
            i++;     //记录较小的孩子坐标
        }
        if (tmp < hp->_a[i])
        {
            break;    //不需要调整
        }
        hp->_a[start] = hp->_a[i];
        start = i;
    }
    hp->_a[start] = tmp;
}
void HeapPop(Heap *hp)
{
    HPDataType tmp;
    //交换首尾元素的值
    tmp = hp->_a[hp->_capacity - 1];
    hp->_a[hp->_capacity - 1] = hp->_a[0];
    hp->_a[0] = tmp;
    hp->_capacity--;
    //采用向下调整的方法
    AdjustDown(hp, 0, hp->_capacity - 1);
}
#endif
HPDataType HeapTop(Heap *hp)
{
    return hp->_a[0];
}

int HeapSize(Heap *hp)
{
    return hp->_capacity;
}

void HeapDestroy(Heap *hp)
{
    if (NULL != hp->_a)
    {
        free(hp->_a);
        hp->_capacity = 0;
        hp->_size = 0;
        hp->_a = NULL;
    }
}
int HeapEmpty(Heap *hp)
{
    hp->_size = 0;
    return 0;
}
void swap(Heap *hp, int start, int end)
{
    HPDataType tmp;
    //交换首尾元素的值
    tmp = hp->_a[end];
    hp->_a[end] = hp->_a[0];
    hp->_a[0] = tmp;
}

//heap sort
void HeapSort(Heap *hp)
{
    int i;
    for (i = hp->_capacity - 1; i > 0; --i )
    {
        swap(hp, 0, i);
        AdjustDown(hp, 0, i - 1);
    }
}

int main()
{
    int i, n;
    Heap hp;
    int arr[] = {3, 7, 9, 4, 6, 0, 1, 8, 5, 2};
    n = sizeof(arr)/sizeof(arr[0]);
    HeapInit(&hp, n);
    //把数组中的元素向堆中添加
    for (i = 0; i < n; i++)
    {
        HeapPush(&hp, arr[i]);
    }
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapSort(&hp);
    HeapPrint(&hp);
    return 0;
}
