#include "../../LinearList/SingleSeqList/SingSeqList.hpp"    //链式队列是基于单链表的一种存储
#include <iostream>
#include "Queue.h"

template <class T>
class LinkedQueue: public Queue<T> {   //链式队列类定义
  public:
    LinkedQueue(): rear(NULL), front(NULL) {}    //构造函数，建立空队列
    ~LinkedQueue(){makeEmpty();};
    bool EnQueue(const T& x);     //将x加入到队列中
    bool DeQueue(T& x);     //删除队头元素，x返回其值
    bool getFront(T& x)const;     //查看队头元素的值
    void makeEmpty();     //置空队列
    bool IsEmpty()const {
      return (front == NULL) ? true : false;    //判队列空否
    }
    int getSize()const;    //求队列元素的个数
    friend std::ostream& operator<<(std::ostream& os, LinkedQueue<T>& Q);    //输出队列中元素的重载操作<<
  protected:
    LinkNode<T> *front, *rear;     //队头，队尾指针
};


template <class T>
void LinkedQueue<T>::makeEmpty() {
//置空队列，释放链表中所有节点
  LinkNode<T> *p;
  while(front != NULL) {    //逐个删除队列中的节点
    p = front; 
    front = front->link;
    delete p;
  }
};

template <class T>
bool LinkedQueue<T>::EnQueue(const T& x) {
//将新元素x插入到队列的队尾(链式队列的队尾)
  if(front == NULL) {
    front = rear = new LinkNode<T>(x);    //空队列时，新节点成为队列的第一个节点，既是队头又是队尾
    if(front == NULL)
      return false;
  } else {
    rear->link = new LinkNode<T>(x);    //非空队列时，在链尾追加新的节点并更新队尾指针
    if(rear->link == NULL)
      return false;    //分配节点失败
    rear = rear->link;
  }
  return true;
};


template <class T>
bool LinkedQueue<T>::DeQueue(T& x){
//如果队列不为空，将队头节点从链式队列中删去，函数返回true，否则返回false
  if(IsEmpty() == true)
    return false;    //队列空则返回false
  LinkNode<T> *p = front;   //队列不空，暂存队头节点
  x = front->data;
  front = front->link;
  delete p;    //队头修改，释放原队头节点
  return true;
};


template <class T>
bool LinkedQueue<T>::getFront(T& x)const{
//若队列不空，则函数返回队头元素的值及true
  if(IsEmpty() == true)
    return false;     //队列空则返回false
  x = front->data;   //取队头元素中的数据值
  return true;
};


template <class T>
int LinkedQueue<T>::getSize()const {
//求队列元素个数
  LinkNode<T> *p = front;
  int k = 0;
  while(p != NULL) {
    p = p->link;
    k++;
  }
  return k;
};


template <class T>
std::ostream& operator<<(std::ostream& os, LinkedQueue<T>& Q) {
//输出队列中元素的重载操作<<
  os << "队列中元素个数" << Q.getSize() << std::endl;
  LinkNode<T> *p = Q.front;
  int i = 0;
  while(p != NULL) {
    os << ++i << ":" << p->data << std::endl;
    p = p->link;
  }
  return os;
};
