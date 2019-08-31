#ifndef __SINGSEQLIST_H__
#define __SINGSEQLIST_H__

#include "../LinearList.h"
#include <iostream>
//单链表类的定义：通常使用两个类，即链表的节点(linknode)类和链表(list)类，协同表示单链表
//一个链表包含了零个或多个节点，因此一个类型为List的对象包含有零个或多个类型为LinkNode的对象。这种关系叫做聚合关系，或整体-部分关系。
//有四种方法：
#if 0
//    1. 复合类：在LinkNode中声明友元类
class List;     //List类的前视声明

class LinkNode {
  friend class List;   //声明List为友元类 注意：友元函数不是类的成员，不会传给它this指针；静态成员函数也不能得到传送的this指针
private:
  int data;          //数据元素域
  LinkNode* link;    //链指针域
};

class List{
  public:

  private:
    LinkNode* first;    //链表头指针
};


//    2. 嵌套类：在List内部对LinkNode类进行定义
class List {
  public:

  private:
    class LinkNode{
      public:
        int data;
        LinkNode* link;
    };
    LinkNode* first;
};


//    3. 基类和派生类：把LinkNode类声明为基类，List类声明为派生类
class LinkNode{
  protected:
    int data;
    LinkNode* link;
};

class List:public LinkNode {
  private:
    LinkNode* first;
  public:

};
#endif

//带头结点的单链表类的定义
//    4. 用struct定义LinkNode类
template <class T>
struct LinkNode {   //链表节点类的定义
  T data;     //数据域
  LinkNode<T>* link;     //链指针域
  LinkNode(LinkNode<T>* ptr = NULL) {
    link = ptr;     //仅初始化指针成员的构造函数
  }
  LinkNode(const T& item, LinkNode<T>* ptr = NULL) {
    data = item;
    link = ptr;     //初始化数据与指针成员的构造函数
  }
};

template <class T>
class List:public LinearList<T> {    //单链表类的定义，不用继承也可以实现
  public:
    List(){
      first = new LinkNode<T>;    //构造函数
    }
    List(const T& x) {
      first = new LinkNode<T>(x);   //构造函数
    }
    List(List<T>& L);      //拷贝构造函数
    ~List(){
      makeEmpty();
    }
    void makeEmpty();      //将链表置为空表
    int Length()const;     //计算链表的长度
    LinkNode<T> *getHead()const{
      return first;       //返回头结点的地址
    }
    LinkNode<T> *Search(T x);  //搜索含数据x的元素
    LinkNode<T> *Locate(int i);   //搜搜第i个元素的地址
    bool GetData(int i, T& x);    //取出第i个元素的值
    void SetData(int i, T& x);    //用x修改第i个元素的值
    bool Insert(int i, T& x);     //在第i个元素后插入x
    bool Remove(int i, T& x);     //删除第i个元素，x返回该元素的值
    bool IsEmpty()const {
      return first->link == NULL ? true : false;
    }
    bool IsFull()const {
      return false;      //判断空否，不满则返回false
    }
    void Sort();
    void input();
    void output();
    List<T>& operator=(List<T>& L);    //重载函数：赋值
  protected:
    LinkNode<T>* first;
};



template <class T>
List<T>::List(List<T>& L) {
  //复制构造函数
  T value;
  LinkNode<T> *srcptr = L.getHead();     //被复制表的附加头结点地址
  LinkNode<T> *desptr = first = new LinkNode<T>;
  while(srcptr->link != NULL) {      //逐个节点复制
    value = srcptr->link->data;
    desptr->link = new LinkNode<T>(value);
    desptr = desptr->link;
    srcptr = srcptr->link;
  }
  desptr->link = NULL;
};

template <class T>
void List<T>::makeEmpty() {
  //将链表置为空表
  LinkNode<T> *q;
  while(first->link != NULL) {   //当链不空时，删去链中所有节点
    q = first->link;
    first->link = q->link;     //保存被删除节点，从链上摘下该节点
    delete q;
  }
};

template <class T>
int List<T>::Length()const {
  //计算带头结点的单链表的长度
  LinkNode<T> *p = first->link;
  int count = 0;
  while(p != NULL) {      //循环扫描，寻找链表
    p = p->link;
    count++;
  }
  return count;
};

template <class T>
LinkNode<T> *List<T>::Search(T x) {
  //在链表中搜索含数据x的节点，搜索成功时函数返回该节点地址; 否则返回NULL
  LinkNode<T> *current = first->link;
  while(current != NULL) {
    if(current->data == x)
      break;      //循链找含x节点
    else 
      current = current->link;
    return current;
  }
};

template <class T>
LinkNode<T> *List<T>::Locate(int i) {
  //定位函数。返回表中第i个元素的地址。若i<0或i超出表中节点个数，则返回NULL
  if(i < 0)
    return NULL;
  LinkNode<T> *current = first;
  int k = 0;
  while(current != NULL && k < i) {    //循链找第i个节点
    current = current->link;
    k++;
  }
  return current;    //返回第i个节点地址，若返回NULL，表示i值太大
};

template <class T>
bool List<T>::GetData(int i, T& x) {
  //取出链表中第i个元素的值
  if(i <= 0) 
    return false;
  LinkNode<T> *current = Locate(i);
  if(current == NULL)
    return false;
  else {
    x = current->data;
    return true;
  }
};

template <class T>
void List<T>::SetData(int i, T& x) {
//给链表中第i个元素赋值x
  if(i <= 0)
    return;
  LinkNode<T> *current = Locate(i);
  if(current == NULL)
    return;
  else 
    return current->data = x;
};

template <class T>
bool List<T>::Insert(int i, T& x) {
//将新元素x插入在链表中第i个节点之后
  LinkNode<T> *current = Locate(i);
  if(current == NULL)
    return false;
  LinkNode<T> *newNode = new LinkNode<T>(x);
  if(newNode == NULL) {
    std::cerr << "存储分配错误!" << std::endl;
    exit(1);
  }
  newNode->link = current->link;    //连接在current之后
  current->link = newNode;
  return true;
};

#if 0
template <class T>
void List<T>::inputFront(T endTag) {    //前插
//endTag是约定的输入序列结束的标志。如果输入序列是正整数，endTag可以是0或负数; 如果输入序列是字符，endTag可以是字符集中不会出现的字符，如"\0"
  LinkNode<T> *newNode;
  T val;
  makeEmpty();
  std::cin >> val;
  while(val != endTag) {
    newNode = new LinkNode<T>(val);   //创建新节点
    if(newNode == NULL) {
      std::cerr << "存储分配错误!" << std::endl;
      exit(1);
    }
    newNode->link = first->link;
    first->link = newNode;     //插入到表前端
    std::cin >> val;
  }
};

template <class T>
void List<T>::inputRear(T endTag) {
//endTag是约定的输入序列结束标志
  LinkNode<T> *newNode, *last;
  T val;
  makeEmpty();
  std::cin >> val;
  last = first;
  while(val != endTag) {        //last指向表尾
    newNode = new LinkNode<T>(val);
    if(newNode == NULL) {
      std::cerr << "存储分配错误!" << std::endl;
      exit(1);
    }
    last->link = newNode;
    last = newNode;
    std::cin >> val;     //插入到表末端
  }
  last->link = NULL;    //表收尾，可以省略
};
#endif 



template <class T>
bool List<T>::Remove(int i, T& x) {
//将链表中的第i个元素删去，通过引用型参数x返回该元素的值
  LinkNode<T> *current = Locate(i - 1);
  if(current == NULL || current->link == NULL)
    return false;
  LinkNode<T> *del = current->link;    //重新拉链，将被删除节点从链中摘下
  current->link = del->link;
  x = del->data;
  delete del;    //取出被删除节点中的数据值
  return true;
};

template <class T>
void List<T>::output() {
//单链表的输出函数：将单链表中所有数据按逻辑顺序输出到屏幕上
  LinkNode<T> *current = first->link;
  while(current != NULL) {
    std::cout << current->data << std::endl;
    current = current->link;
  }
};

template <class T>
List<T>& List<T>::operator=(List<T>& L) {
//重载函数：赋值操作，形如A=B，其中A是调用此操作的List对象，B是参数表中的引用型参数L结合的实参
  T value;
  LinkNode<T> *srcptr = L.getHead();     //被复制表的头结点地址
  LinkNode<T> *desptr = first = new LinkNode<T>;
  while(srcptr->link != NULL) {          //逐个节点复制
    value = srcptr->link->data;
    desptr->link = new LinkNode<T>(value);
    desptr = desptr->link;
    srcptr = srcptr->link;
  }
  desptr->link = NULL;
  return *this;           //返回操作对象地址
};



#if 0
bool List::Insert(int i, int& x) {
  //将新元素x插入到第i个节点之后，i从1开始，i = 0表示插入到第一个节点之前
  if(first ==NULL || i == 0) {
    LinkNode *newNode = new LinkNode(x);
    if(newNode == NULL) {
      std::cerr << "存储分配错误!\n";
      exit(1);
    }
    newNode->link = first;
    first = newNode;    //新节点成为第一个节点
  }

  else {
    LinkNode *current = first;
    for(int  k = 1; k < i; k++) {
      if(current == NULL)
        break;
      else 
        current = current->link;
    }
    if (current == NULL) {                      //非空表且链太短
      std::cerr << "无效的插入位置!\n";
      return false;
    }
    else {                                       //插入在链表的中间
      LinkNode *newNode = new LinkNode(x);
      if(newNode == NULL) {
        std::cerr << "存储分配错误!\n";
        exit(1);
      }
      newNode->link = current->link;
      current->link = newNode;
    }
  }
  return true;
};


bool List::Remove(int i, int& x) {
  //将链表中的第i个元素删去，i从1开始
  LinkNode *del, *current;
  if(i <= 1) {
    del = first;
    first = first->link;
  }
  else {                //删除第一个节点时重新拉链
    current =first;
    for(int k = 1; k < i - 1; k++) 
      if(current == NULL)
        break;
      else 
        current = current->link;
    if(current == NULL || current->link == NULL) {
      std::cerr << "无效的删除位置!\n";
      return false;
    }
    del = current->link;      //删除中间节点或尾节点时拉链
    current->link = del->link;
  }
  x = del->data;   //取出被删节点中的数据值
  delete del;    
  return true;
};
#endif
#endif
