#ifndef DATALIST_H
#define DATALIST_H 

#include <iostream>
const int DefaultSize = 100;
template <class T>
class Element {    //数据表元素定义
  public:
    T key;     //排序码
    field otherdata;      //其他数据成员
    Element<T>& operator = (Element<T>& x){    //元素x的值赋给this
      key = x.key;
      otherdata = x.otherdata;
      return this;
    }
    bool operator == (Element<T>& x) {return key == x.key;}   //判*this与x相等
    bool operator <= (Element<T>& x) {return key <= x.key;}   //判*this小于或等于x
    bool operator > (Element<T>& x) {return key >= x.key;}   //判*this大于x
    bool operator < (Element<T>& x) {return key < x.key;}    //判*this小于x
};

template <class T>
class dataList {
  public:
    dataList(int maxSz = DefaultSize) : maxSize(maxSz), currentSize(0) {
      Vector = new Element<T>[maxSize];    //构造函数
    }
    void Swap(Element<T>& x, Element<T>& y) {   //交换x, y
      Element<T> temp = x;
      x = y;
      y = temp;
    }
    int Length() {return currentSize;}   //取表长度
    Element<T>& operator[](int i){return Vector[i];}   //取第i个元素
    int Partition(const int low, const int high);    //快速排序划分
  private:
    Element<T> *Vector;    //存储排序元素的向量
    int maxSize;    //向量中最大元素个数
    int currentSize;  //当前元素个数
};

template <class T>
void InsertSort(dataList<T>& L, const int left, const int right) {
//依次将元素L.Vector[i]按其排序码插入到有序表L.Vector[left], .., L.Vector[i - 1]中，使得L.Vector[left]到L.Vector[i]有序
  Element<T> temp; 
  int i, j;
  for(i = left + 1; i <= right; i++)
    if(L[i] < L[i - 1]) {
      temp = L[i];
      j = i - 1;
      do {
        L[j + 1] = L[j];
        j--;
      }while(j >= left && temp < L[j]);
      L[j + 1] = temp;
    }
};

template <class T>
void BinaryInsertSort(dataList<T>& L, const int left, const int right) {
//利用折半搜索，按L.Vector[i].key在L.Vector[left]到L.Vector[i - 1]中查找L.Vector[i]应插入的位置，再空出这个位置进行插入
  Element<T> temp; int i, low, high, middle, k;
  for(i = left + 1; i <= right; i++) {
    temp = L[i];
    low = left;
    high = i - 1;
    while(low <= high) {   //利用折半搜索插入位置
      middle = (low + high)/2;    //取中点
      if(temp < L[middle])    //插入值小于中点值
        high = middle - 1;
      else 
        low = middle + 1;    //否则，向右缩小区间
    }
    for(k = i - 1; k >= low; k--)
      L[k + 1] = L[k];   //成块移动，空出插入位置
    L[low] = temp;   //插入
  }
};

#endif 
