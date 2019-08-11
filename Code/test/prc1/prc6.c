//对顺序表中的子列L->r[low..high]做快速排序

void QSort(SeqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(L, low, high);            //把r[low..high]一分为二，并找到中枢值pivot
        QSort(L, low, pivot - 1);             //对低子表递归排序
        QSort(L, pivot + 1, high);            //对高子表递归排序
    }
}

//对快速排序的优化
#define MAX_LENGTH_INSERT_SORT 7    //数组长度阈值
//对顺序表中的子列L->r[low..high]做快速排序

void QSort(SeqList *L, int low, int high)
{
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT)    //当high - low大于常数时选用快速排序
    {
        pivot = partition(L, low, high);            //把r[low..high]一分为二，并找到中枢值pivot
        QSort(L, low, pivot - 1);             //对低子表递归排序
        QSort(L, pivot + 1, high);            //对高子表递归排序
    }
    else
    {
        InsertSort(L);        //否则采用插入排序
    }
}

//快速排序非递归
void QuickSortNonR(int *a, int right, int left)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, left);
    StackPush(&st, right);

    while (StackEmpty(&st) != 0)
    {
        int end = StackTop(&st);
        StackPop(&st);
        int begin = StackTop(&st);
        StackPop(&st);
        int div = PartSort1(a, begin, end);
        if (begin < div - 1)
        {
            StackPush(&st, begin);
            StackPush(&st, div - 1);
        }
        if (div + 1 < end)
        {
            StackPush(&st, div + 1);
            StackPush(&st, end);
        }
    }
}
