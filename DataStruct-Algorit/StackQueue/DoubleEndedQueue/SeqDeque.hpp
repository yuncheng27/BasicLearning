#include "Deque.h"
#include "SeqQueue.h"

template <class T>
class SeqDeque:public SeqQueue<T>, public Deque<T>{
  public:
    SeqDeque(int sz):SeqQueue<T>::SeqQueue(sz) {}    //构造函数：调用了SeqQueue的构造函数
    ~SeqDeque(){
      delete []SeqQueue<T>::getElements();
    }
    bool getTail(int& x);    //新增队尾函数
    bool EnQueueHead(const int& x);   //新增从队头进队函数
    bool DeQueueTail(int& x);    //新增从队尾出队函数
    friend std::ostream& operator<<(std::ostream& ostr, SeqDeque& D);   //输出运算符重载
};


template <class T>
bool SeqDeque<T>::getTail(int& x) {
//SeqDeque继承了SeqQueue的私有数据成员，但没有访问权限，所以通过SeqQueue的公有函数来访问
  if(SeqQueue<T>::isEmpty())
    return false;
  else {
    x = SeqQueue<T>::getElements()[(SeqQueue<T>::getRear() - 1 + SeqQueue<T>::getMaxSize()) % SeqQueue<T>::getMaxSize()];
    return true;
  }
}


template <class T>
bool SeqDeque<T>::EnQueueHead(const int& x) {
    if(SeqQueue<T>::isFull())
      return false;
    else {
      SeqQueue<T>::getFront() = (SeqQueue<T>::getFront() - 1 + SeqQueue<T>::getMaxSize()) % SeqQueue<T>::getMaxSize();
      SeqQueue<T>::getElements()[SeqQueue<T>::getFront()] = x;
      return true;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, SeqDeque<T>& D) {
  ostr << "front=" << D.getFront() << " " << "rear=" << D.getRear() << std::endl;
  for(int i = D.getFront(); i != D.getRear(); i = (i + 1) % D.getMaxSize())
    ostr << i + 1 << ": " << D.getElements()[i] << std::endl;
  return ostr;
}
