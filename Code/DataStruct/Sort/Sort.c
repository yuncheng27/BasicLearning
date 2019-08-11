#include<stdio.h>

void PrintSort(int array[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *array, int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void DirectInsertSort(int array[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        int *pCur = &array[i];
        for (j = i - 1; j >=0; --j)
        {
            int *end = &array[j];
            if (*pCur < *end)
            {
                 swap(array, pCur, end);
            }
            pCur--;
        }
    }
}

void ShellSort(int array[], int n)
{
    int i, j, gap = 3;
    while(gap)
    {
        for (i = 1; i < n; i += gap)
        {
            int *pCur = &array[i];
            for (j = i - 1; j >=0; j -= gap)
            {
                int *end = &array[j];
                if (*pCur < *end)
                {
                     swap(array, pCur, end);
                }
                pCur -= gap;
            }
        }
        gap--;
    }
}

void SelectSort(int array[], int n)
{
    int i, j = 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int *max = &array[j], *min = &array[j];
        for (i = j; i < n - j; ++i)
        {
            if (array[i] > *max)
            {
                max = &array[i];
            }
            if (array[i] < *min)
            {
                min = &array[i];
            }
        }
        if (left == right - 1)
        {
            swap(array, max, &array[right]);
        }
        else
        {
            swap(array, max, &array[right]);
            swap(array, min, &array[left]);
        }
        j++;
        left++;
        right--;
    }
}

//void HeapSorts(Heap *hp, int n);      //"/home/pyvip/code/DataStruct/BinaryTree/Heap/Heap.h"
void BubbleSorts(int array[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(array, &array[j], &array[j + 1]);
            }
        }
    }
}

//划分方式(递归法，非递归法)：前后指针交换， 挖坑法
//优化方法：三数取中法，小区间优化法
int partion(int array[], int left, int right)//第三种方法
{
    while (cur < right)
    {
        if (array[cur] < key && ++prev != cur)
            swap(array, array[cur], array[prev]);
        cur++;
    }
}


int partion(int array[], int left, int right)//挖坑法
{
    int tmp = array[left];
    if (left >= right)
        return -1;
    while (left != right)
    {
        while (left < right && array[right] >= tmp)
        {
            right--;
            if (right > left)
                array[left] = array[right];
        }
        while (left < right && array[left] <= tmp)
        {
            left++;
            if (left < right)
                array[right] = array[left];
        }
    }
    array[left] = tmp;
    return left;
}

void FastSort(int array[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partion(array, low, high);
        FastSort(array, low, pivot - 1);
        FastSort(array, pivot + 1, high);
    }
}

void MergeSort();

int main()
{
    int array[] = {3, 6, 1, 8, 0, 6, 2, 7, 9, 5, 1, 4};
    int n = sizeof(array)/sizeof(array[0]);
    //PrintSort(array, n);
    //DirectInsertSort(array, n);
    //PrintSort(array, n);
    //ShellSort(array, n);
    //PrintSort(array, n);
    //SelectSort(array, n);
    //PrintSort(array, n);
    //BubbleSorts(array, n);
    PrintSort(array, n);
    FastSort(array, 0, n - 1);
    PrintSort(array, n);
    return 0;
}
