#ifndef __LINEARLIST_H__
#define __LINEARLIST_H__ 
#include <iostream>

//enum BOOL {xfalse = 0, xtrue = 1};  //bool, false, true这些关键字都不能用，否则报错

template <class T>
class LinearList {
  public:
    LinearList();
    ~LinearList();
    virtual int Size()const = 0;   //求表的最大体积
    virtual int Length()const = 0; //求表的长度
    virtual int Search(T& x)const = 0;  //在表中搜索给定的值
    virtual int Locate(int i)const = 0;  //在表中定位第i个元素的位置
    virtual bool getData(int i, T& x)const = 0;  //取第i个表项的值
    virtual void setData(int i, T& x) = 0;   //修改第i个表项的值为x
    virtual bool Insert(int i, T& x) = 0;  //在第i个表项之后插入x
    virtual bool Remove(int i, T& x) = 0;  //删除第i个表项，通过x返回
    virtual bool IsEmpty()const = 0; 
    virtual bool IsFull()const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
    //virtual LinearList<T> operator=(LinearList<T>& L) = 0;  //赋值
};
#endif
