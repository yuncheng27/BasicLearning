#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#define InitSize 40

typedef int HPDataType;

typedef struct Heap
{
    HPDataType *_a;
    int _capacity;     //用于保存初始化时动态开辟空间的大小
    int _size;           //数组的大小
}Heap;

void HeapInit(Heap *hp, int n);
void HeapDestroy(Heap *hp); //销毁树
int HeapEmpty(Heap *hp);  //置空的意思是树为空树
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);    //堆每次都只能删除堆顶元素
HPDataType HeapTop(Heap *hp);   //返回树的根节点
int HeapSize(Heap *hp);
//heap sort
void HeapSort(Heap *hp);

void TestHeap();

#endif //__HEAP_H__
