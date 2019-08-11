#include <iostream>
#include <stdlib.h>
#include "../LinearList.h"

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
    //SeqList<T> operator=(SeqList<T>& L);  //表整体赋值
};




template <class T>
SeqList<T>::SeqList(int sz) {
//构造函数，通过指定参数sz定义数组的长度
  if(sz > 0) {
    maxSize = sz; 
    last = -1;     //置表的实际长度为空
    data = new T[maxSize];    //创建顺序表存储数组
    if(data == NULL) {
      std::cerr << "存储分配错误！" << std::endl;  //c++中输出通常信息的函数为cout,在异常处理机制中则使用cerr来输出错误信息。区别在于：重定向操作只影响cout，而不影响cerr；cerr对象仅用于错误消息。因此，如果将程序输出重定向到文件，并且发生了错误，则屏幕上仍然会出现错误消息。
      exit(1);
    }
  }
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L) {
//复制构造函数，用参数表中给出的已有顺序表初始化新建的顺序表
  maxSize = L.Size();
  last = L.Length() - 1;
  T value;
  data = new T[maxSize];     //初始化顺序表存储数组
  if(data == NULL) {
    std::cerr << "存储分配错误！" << std::endl;
    exit(1);
  }
  for(int i = 1; i <= last+1; i++) {
    L.getData(i, value);
    data[i - 1] = value;
  }
}

template <class T>
void SeqList<T>::reSize(int newSize) {
//私有函数：扩充顺序表的存储数组空间大小，新元素的个数为newSize
  if(newSize <= 0) {
    std::cerr << "无效的数组大小" << std::endl;
    return;
  }
  if(newSize != maxSize) {
    T* newarray = new T[newSize];   //建立新数组
    if(newarray == NULL) {
      std::cerr << "存储分配错误" << std::endl;
      exit(1);
    }
    int n = last + 1;
    T* srcptr = data;    //原数组首地址
    T* desptr = newarray;   //目的数组首地址
    while(n--)
      *desptr++ = *srcptr++;
    delete []data;
    data = newarray;
    maxSize = newSize;
  }
}

template <class T>
int SeqList<T>::Search(T& x)const {
//搜索函数：在表中顺序搜索与给定值x匹配的表项，找到则函数返回该表项是第几个元素;否则函数返回0表示搜索失败
  for(int i = 0; i <= last; i++) {
    if(data[i] == x)
      return i + 1;    //顺序搜索
  }
  return 0;   //搜索失败
}

template <class T>
int SeqList<T>::Locate(int i)const {
//定位函数：函数返回第i(1<= i <= last +1)个表项的位置，否则返回0表示定位失败
  if(i >= 1 && i <= last + 1)
    return i;
  else 
    return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T& x) {
//将新元素x插入到表中第i个表项之后，返回插入成功的信息
  if(last == maxSize - 1)
    return false;   //表满，不能插入
  if(i < 0 || i > last + 1)
    return false;   //参数不合理，不能插入
  for(int j = last; j >= i; j--)
    data[j + 1] = data[j];    //依次后移，空出第i号位置
  data[i] = x;
  last++;    //最后的位置加1
  return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T& x) {
//从表中删除第i个表项，通过引用型参数x返回删除的元素值
  if(last == -1)
    return false;   //空表，不能删除
  if(i < 1 || i > last + 1)
    return false;
  x = data[i - 1];
  for(int j = i; j <= last; j++)
    data[j - 1] = data[j];
  last--;
  return true;
}

template <class T>
void SeqList<T>::input() {
//从标准输入逐个数据输入，建立顺序表
  std::cout << "开始建立顺序表，请输入表中元素个数：";
  while(1) {
    std::cin >> last;
    if (last <= maxSize - 1)
      break;
    std::cout << "表中元素个数输入有误，范围不能超过" << maxSize - 1 << ":";
  }
  for(int i = 0; i <= last; i++) {
    std::cin >> data[i];
    std::cout << i + 1 << std::endl;
  }
}


template <class T>
void SeqList<T>::output() {
//将顺序表全部输出到屏幕上
  std::cout << "顺序表当前元素最后位置为：" << last << std::endl;
  for(int i = 0; i <= last; i++)
    std::cout << "#" << i + 1 << ":" << data[i] << std::endl;
}


#if 0
template <class T> 
SeqList<T> SeqList<T>::operator=(SeqList<T>& L) {
//重载操作：顺序表整体赋值。若当前调用此操作的对象为L1，代换形参L的表对象为L2，则使用方式为L1 = L2
    
}
#endif
