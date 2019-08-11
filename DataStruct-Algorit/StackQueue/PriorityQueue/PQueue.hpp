#include <assert.h>
#include <iostream>
#include <stdlib.h>
const int DefaultPQSize = 50;    //优先级队列数组的默认长度

template <class T>
class PQueue{        //优先级队列的类定义
  public:
    PQueue(int sz = DefaultPQSize);
    ~PQueue(){
      delete []pqelements;
    }
    bool Insert(const T& x);    //将新的元素插入到队尾
    bool RemoveMin(T& x);      //将队头元素删去
    bool getFront(T& x)const;    //读取队头(具最小优先权)的值
    void makeEmpyt(){
      count = 0;     //置优先级队列为空
    }
    bool IsEmpty() const {
      return (count == 0) ? true :false;
    }
    bool IsFull() const {
      return (count == maxSize) ? true : false;
    }
    int getSize() const {
      return count;       //求优先级队列中元素个数
    }
  protected:
    T *pqelements;    //优先级队列数组
    int count;   //当前元素个数(长度)
    int maxSize;    //队列最大可容纳元素个数
    void adjust();     //队列调整
};


template <class T>
PQueue<T>::PQueue(int sz): maxSize(sz), count(0) {
//构造函数：建立一个最大具有maxSize个元素的空优先级队列
  pqelements = new T[maxSize];    //创建队列空间
  assert(pqelements != NULL);    //断言：动态存储分配成功与否
};


template <class T>
bool PQueue<T>::Insert(const T& x) {
//若优先级队列不满，则将元素x插入到该队列的队尾
  if(count == maxSize)
    return false;
  pqelements[count++] = x;    //插入x到队尾
  adjust();    //按优先权进行调整
};

template <class T>
void PQueue<T>::adjust() {
//将队尾元素按其优先权大小调整到适当位置，保持所有元素按优先权从小到大有序
  T temp = pqelements[count - 1];
  int j;
  for(j = count - 2; j >= 0; j--) {
    if(pqelements[j] <= temp)
      break;    //发现有比temp更小或相等的pqelements，跳出循环
    else 
      pqelements[j + 1] = pqelements[j];   //比temp大的元素pqelements[j]后移
  }
  pqelements[j + 1] = temp;    //插入到适当位置
};

template <class T>
bool PQueue<T>::RemoveMin(T& x) {
//若优先级队列不空则函数返回该队列具最大优先权(值最小)元素的值，同时将该元素删除
  if(count == 0)
    return false;  //若队列空，则返回false
  x = pqelements[0];
  for(int i = 1; i < count; i++)
    pqelements[i - 1] = pqelements[i];
  count--;     //优先级队列元素个数减一
  return true;
};


template <class T>
bool PQueue<T>::getFront(T& x) const{
//若优先级队列不空则函数返回队列具最小优先权元素的值
  if(count == 0)
    return false;    //若队列空，函数返回 
  else {
    x = pqelements[0];
    return true;    //返回具最小优先权元素的值
  }
};
