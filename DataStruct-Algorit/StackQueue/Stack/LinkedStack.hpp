#include <iostream>
#include "../../LinearList/SingleSeqList/SingSeqList.hpp"
#include "SeqStack.hpp"


template <class T>
class LinkedStack:public Stack<T> {    //链式栈类定义
  public:
    LinkedStack() : top(NULL) {}     //构造函数，置空栈
    ~LinkedStack(){
      makeEmpty();                   //析构函数
    };
    void Push(const T& x);      //进栈
    bool Pop(T& x);     //退栈
    bool getTop(T& x)const;    //读取栈顶元素
    bool IsEmpty()const {
      return (top == NULL) ? true : false;
    }
    int getSize()const;   //求栈的元素个数
    void makeEmpty();      //清空栈的内容
    friend std::ostream& operator<<(std::ostream& os, SeqStack<T>& s);    //输出栈中元素的重载操作<<
  private:
    LinkNode<T> *top;     //栈顶指针，即链头指针
};


template <class T>
void LinkedStack<T>::makeEmpty() {
//逐次删去链式栈中的元素直至栈顶指针为空
  LinkNode<T> *p;
  while(top != NULL) {   //逐个节点释放
    p = top;
    top = top->link;
    delete p;
  }
};


template <class T>
void LinkedStack<T>::Push(const T& x) {
//将元素值x插入到链式栈的栈顶，即链头
  top = new LinkNode<T>(x, top);    //创建新的含x节点
  assert(top != NULL);     //创建新节点失败退出
};

template <class T>
bool LinkedStack<T>::Pop(T& x) {
//删除栈顶节点，返回被删栈顶元素的值
  if(IsEmpty() == true)
    return false;     //若栈空则不退栈， 返回
  LinkNode<T> *p = top;    //否则暂存栈顶元素
  top = top->link;    //栈顶指针退到新的栈顶位置
  x = p->data;
  delete p;     //释放节点，返回退出元素的值
  return true;
};


template <class T>
bool LinkedStack<T>::getTop(T& x)const {
//返回栈顶元素的值
  if(IsEmpty() == true)
    return false;    //若栈空则返回false
  x = top->data;   //栈不空则返回栈顶元素的值
  return true;
};


template <class T>
int LinkedStack<T>::getSize() const {
  LinkNode<T> *p = top;
  int k = 0;
  while(top != NULL) {
    top = top->link;
    k++;
  }
  return k;
};


template <class T>
std::ostream& operator<<(std::ostream& os, LinkedStack<T>& s) {
//输出栈中元素的重载操作<<
  os << "栈中元素个数=" << s.getSize() << std::endl;   //输出栈中元素个数
  LinkNode<T> *p = s.top;
  int i = 0;     //逐个输出栈中元素的值
  while(p != NULL) {
    os << ++i << ":" << p->data << std::endl;
    p = p->link;
  }
  return os;
};
