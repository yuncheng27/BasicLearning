#include<stdio.h>
#include<assert.h>

void Fun2(int N)
{
    int count = 0;
    int k = 0;
    for(k = 0; k < 2 * N; k++)
    {
        ++count;
    }
    int M = 10;
    while(M--)
    {
        ++count;
    }
    printf("%d\n", count);
}

void Fun3(int M, int N)
{
    int count = 0;
    int i = 0;
    for(;i < M; i++)
    {
        ++count;
    }
    for(i = 0; i < N; i++)
    {
        ++count;
    }
    printf("%d\n", count);
}

void Fun4(int N)
{
    int count = 0;
    int k = 0;
    for(; k < 100; k++)
    {
        ++count;
    }
    printf("%d\n", count);
}

void BubbleSort(int *a, int n)
{
    assert(a);
    size_t end;
    for(end = n; end > 0; --end)
    {
        int exchange = 0;
        size_t i = 0;
        for(i = 1; i < end; ++i)
        {
            if(a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                exchange = 1;
            }
        }
        if(exchange == 0)
        {
            break;
        }
    }
}

int BinarySearch(int *a, int n, int x)
{
    assert(a);
    int begin = 0;
    int end = n - 1;
    while(begin < end)
    {
        int mid = begin + ((end - begin) >> 1);
        if(a[mid] < x)
        {
            begin = mid + 1;
        }
        else if(a[mid] > x)
        {
            end = mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

long long *Fibonacci(size_t n)
{
    if(0 == n)
    {
        return NULL;
    }
    long long *fibArray = new long long[n + 1];
    fibArray[0] = 0;
    fibArray[1] = 1;
    int i = 0;
    for(i = 2; i <= n; ++i)
    {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
    return fibArray;
}

int main()
{
    //Fun2(10);
    //Fun3(10,20);
    //Fun4(10000);
    //BubbleSort();
    //BinarySearch();
    Fibonacci();
    return 0;
}
