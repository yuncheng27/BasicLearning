#ifndef __DBLLIST_H__
#define __DBLLIST_H__ 

#include "../LinearList.h"
#include <iostream>

template <class T>
struct DblNode{     //链表节点类定义
  T data;     //链表节点数据
  DblNode<T> *lLink, *rLink;   //链表前驱(左链)，后继(右链)指针
  DblNode(DblNode<T> *left = NULL, DblNode<T> *right = NULL)
    :lLink(left), rLink(right) {}     //构造函数
  DblNode(T value, DblNode<T> *left = NULL, DblNode<T> *right = NULL)
    :data(value), lLink(left), rLink(right) {}   //构造函数
};

template <class T>
class DblList:public LinearList<T> {
  public:
    DblList(T uniqueVal);     //构造函数：建立头结点
    ~DblList();      //析构函数：释放所用存储
    int Length()const;    //计算双链表的长度
    bool IsEmpty() {
      return first->rlink == first;    
    }
    DblNode<T> *getHead()const {
      return first;     //取头结点地址
    }
    void setHead(DblNode<T> *ptr) {
      first = ptr;      //设置头结点地址
    }
    DblNode<T> *Search(const T& x);      //在链表中沿后继方向寻找等于给定值x的节点
    DblNode<T> *Locate(int i, int d);    //在链表中定位序号为i(>=0)的节点， d=0 按前驱方向， d!=0按后继方向
    bool Insert(int i, const T& x, int d);   //在第i个节点后插入一个包含有值x的新节点，d=0按前驱方向，d!=0按后继方向
    bool Remove(int i, T& x, int d);     //删除第i个节点，x返回其值, d=0按前驱方向，d!=0按后继方向

  private:
    DblNode<T> *first;
};

template <class T>
DblList<T>::DblList(T uniqueVal) {    //构造函数：建立双向循环链表的头结点，它包含了一个用于某些特定情况的值
  first = new DblNode<T>(uniqueVal);
  if(first == NULL) {
    std::cerr << "存储分配出错!" << std::endl;
    exit(1);
  }
  first->rLink = first->lLink = first;
};

template <class T>
int DblList<T>::Length()const {
  //计算带头结点的双向循环链表的长度，通过函数返回
  DblNode<T> *current = first->rLink;
  int count = 0;
  while(current != first) {
    current = current->rLink;
    count++;
  }
  return count;
};


template <class T>
DblNode<T> *DblList<T>::Search(const T& x) {
  //在带头结点的双向循环链表中寻找其值等于x的节点，若找到，则函数返回该节点地址，否则返回NULL
  DblNode<T> *current = first->rLink ;
  while(current != first && current->data != x)
    current = current->rLink;
  if(current != first)
    return current;    //搜索成功
  else 
    return NULL;       //搜索失败
};


template <class T>
DblNode<T> *DblList<T>::Locate(int i, int d) {
  //在带头结点的双向循环链表中按d所指方向寻找第i个节点的地址。若d=0，在前驱方向寻找第i个节点，若d!=0，在后继方向寻找第i个节点
  if(first->rlink == first || i == 0)
    return first;
  DblNode<T> *current;
  if(d == 0)
    current = first->lLink;    //搜索方向
  else 
    current = first->rLink;
  for(int j = 1; j < i; j++)   //逐个节点检测
  {
    if(current == first)
      break;
    else if(d == 0)
      current = current->lLink;
    else 
      current = current->rLinnk;
  }
  if(current != first)
    return current;   //搜索成功
  else 
    return NULL;    //搜索失败
};

template <class T>
bool DblList<T>::Insert(int i, const T& x, int d) {
//建立一个包含有值x的新节点，并将其按d指定的方向插入到第i个节点之后
  DblNode<T> *current = Locate(i, d);   //查找第i个节点
  if(current == NULL)
    return false;      //i不合理，插入失败
  DblNode<T> *newNode = new DblNode<T>(x);
  if(newNode == NULL) {
    std::cerr << "存储分配失败!" << std::endl;
    exit(1);
  }
  if(d == 0)   //前驱方向插入
  {
    newNode->lLink = current->lLink;
    current->lLink = newNode;
    newNode->lLink->rLink = newNode;
    newNode->rLink = current;
  }
  else {    //后继方向插入
    newNode->rLink = current->rLink;
    current->rLink = newNode;
    newNode->rLink->lLink = newNode;
    newNode->lLink = current;
  }
  return true;
};

template <class T>
bool DblList<T>::Remove(int i, T& x, int d) {
//在带头结点的双向循环链表中按照d所指方向删除第i个节点
  DblNode<T> *current = Locate(i, d);     //查找第i个节点
  if(current == NULL)
    return false;     //i不合理，删除失败
  current->rLink->lLink = current->lLink;   //从lLink链中摘下
  current->lLink->rLink = current->rLink;   //从rLink链中摘下
  x = current->data;
  delete current;    //删除
  return true;
};


#endif
