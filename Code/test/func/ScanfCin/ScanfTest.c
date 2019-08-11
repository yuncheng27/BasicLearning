#if 0
#include<ctime>
#include<cstdio>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using namespace std;
#endif
#include<stdio.h>
#include<time.h>
#include<unistd.h>
const int num = 1000;

int main()
{
    freopen("data", "r", stdin);
    int i, n, start, end;
    start = clock();
    for (i = 0; i < num - 2; i++)
    scanf("%d", &n);
    end = clock();
    //printf("%f\n", float(end - start)/CLOCKS_PER_SEC);
    printf("%d\n",end-start);
    sleep(1);
    return 0;
}
