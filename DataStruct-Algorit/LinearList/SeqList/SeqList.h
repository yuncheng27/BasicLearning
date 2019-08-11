#include <iostream>
#include <stdlib.h>
#include "LinearList.h"

const int defaultSize = 100;
template <class T>
class SeqList:public LinearList<T> {
  protected:
    T* data;   //存放数组
    int maxSize;   //最大可容纳表项的项数
    int last;     //当前已知表项的最后位置
    void reSize(int newSize);   //改变data数组空间大小
  public:
    SeqList(int sz = defaultSize);     //构造函数
    SeqList(SeqList<T>& L);         //复制构造函数
    ~SeqList(){delete[] data;}      //析构函数
    int Size()const{return maxSize;}  //计算表最大可容纳表项个数
    int Length()const{return last+1;}  //计算表长度   const放在函数参数表后面，函数体的前面起到了一种保护作用。表明他不能改变操作它的对象的数据成员的值。另外，const成员函数执行时不能调用非const成员函数
    int Search(T& x)const;    //搜索x在表中位置，函数返回表项序号
    int Locate(int i)const;   //定位第i个表项，函数返回表项序号
    bool getData(int i, T& x)const   //取第i个表项的值 
    {
      if(i > 0 && i <= last + 1){
        x = data[i - 1];
        return true;
      } else {
        return false;
      }
    }
    void setData(int i, T& x) {    //用x修改第i个表项的值
      if(i > 0 && i <= last + 1)
        data[i - 1] = x;
    }
    bool Insert(int i, T& x);
    bool Remove(int i, T& x); 
    bool IsEmpty() {
      return (last == -1) ? true : false;
    }
    bool IsFull() {
      return (last == maxSize - 1) ? true : false;
    }
    void input();
    void output();
    SeqList<T> operator=(SeqList<T>& L);  //表整体赋值
};
