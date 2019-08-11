#include <iostream>
#include <assert.h>

template  <class T>
class SeqQueue {   //循环队列
  private:
    int *elements;     //存放队列元素的数组
    int rear, front;   //队尾指针和队头指针
    int maxSize;       //队列可容纳的最大元素个数

  public:
    SeqQueue(int sz);     //构造函数
    ~SeqQueue() {
      delete []elements;    //析构函数
    }
    bool EnQueue(const int& x);    //进队函数
    bool DeQueue(int& x);     //出队函数
    void makeEmpty() {
      front = rear = 0;     //把队置空
    }
    bool isEmpty(){
      return (front == rear) ? true : false;    //判断队空
    }
    bool isFull() {
      return ((rear + 1) % maxSize == front) ? true : false;    //判断队满
    }
    int getSize() {
      return (rear - front + maxSize) % maxSize;   //求队中元素个数
    }
    int& getFront() {
      return front;    //取队头下标
    }
    int& getRear() {
      return rear;    //取队尾下标
    }
    int& getMaxSize() {
      return maxSize;    //取maxSize
    }
    int*& getElements() {
      return elements;    //取数组指针
    }
};

template <class T>
SeqQueue<T>::SeqQueue(int sz): rear(0), front(0), maxSize(sz) {
  elements = new int[maxSize];
  assert(elements != NULL);    //断言机制：如果不满足括号内条件将终止程序执行
}

template <class T>
bool SeqQueue<T>::EnQueue(const int& x) {
  if(isFull()) 
    return false;
  else 
    elements[rear] = x;
  rear = (rear + 1)%maxSize;    //加1取余是为了rear指向队列最后一个元素
  return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(int& x) {
  if(isEmpty())
    return false;
  else 
    x = elements[front];
  front = (front + 1) % maxSize;
  return true;
}
