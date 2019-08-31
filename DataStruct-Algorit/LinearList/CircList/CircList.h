#include "../LinearList.h"
#include <iostream>
#ifndef __CIRCIST__H__ 
#define __CIRCIST__H__ 

template <class T>
struct CircLinkNode{    //链表节点类定义
  T data;
  CircLinkNode<T> *link;
  CircLinkNode(CircLinkNode<T> *next = NULL):link(next){}
  CircLinkNode(T d, CircLinkNode<T> *next = NULL):data(d), link(next){}
};

template <class T>
class CircList:public LinearList<T> {    //链表类定义
  public:
    CircList(const T& x);     //构造函数
    CircList(CircList<T>& L);    //复制构造函数
    ~CircList();
    int Length()const;    //计算循环链表长度
    bool IsEmpty() {
      return first->link == first ? true : false;
    }

    CircLinkNode<T> *getHead()const;   //返回头结点地址
    void setHead(CircLinkNode<T> *p); //设置头结点地址
    CircLinkNode<T> *Search(T x);     //搜索含数据x的元素
    CircLinkNode<T> *Locate(int i);   //搜索第i个元素的地址
    T *getData(int i);      //取出第i个元素的值
    void setData(int i, T& x);     //用x修改第i个元素的值
    bool Insert(int i, T& x);    //在第i个元素后插入x
    bool Remove(int i, T& x);    //删除第i个元素，x返回该元素的值
  private:
    CircLinkNode<T> *first, *last;   //头指针，尾指针
};
#endif
