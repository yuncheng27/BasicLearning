#include "Deque.h"
#include "SeqQueue.h"
#include "../Queue/LinkedQueue.hpp"

template <class T>
class LinkedDeque: public Deque<T>, public LinkedQueue<T> {
  public:
    LinkedDeque();
    ~LinkedDeque();
    bool getHead(T& x)const;
    bool EnQueueTail(T& x);
    bool DeQueueHead(T& x);
    bool getTail(T& x)const;
    bool EnQueueHead(const T& x);
    bool DeQueueTail(T& x);
};

template <class T>
bool LinkedDeque<T>::getHead(T& x)const{
  T temp;
  bool tag = LinkedQueue<T>::getFront(temp);
  x = temp;
  return tag;
};

template <class T>
bool LinkedDeque<T>::EnQueueTail(T& x) {
  return LinkedQueue<T>::EnQueue(x);
};

template <class T>
bool LinkedDeque<T>::DeQueueHead(T& x) {
  T temp;
  bool tag = LinkedQueue<T>::DeQueue(temp);
  x = temp;
  return tag;
};

template <class T>
bool LinkedDeque<T>::getTail(T& x)const{
  if(SeqQueue<T>::front == NULL)
    return false;
  x = SeqQueue<T>::rear->data;
  return true;
};

template <class T>
bool LinkedDeque<T>::EnQueueHead(const T& x) {
  LinkNode<T> *p = new LinkNode<T>(x);
  if(p == NULL)
    return false;
  p->link = SeqQueue<T>::front;
  SeqQueue<T>::front = p;
  return true;
};

template <class T>
bool LinkedDeque<T>::DeQueueTail(T& x) {
  if(SeqQueue<T>::front == NULL)
    return false;
  LinkNode<T> *p =SeqQueue<T>::front;
  while(p->link !=SeqQueue<T>::rear)
    p = p->link;
  x = SeqQueue<T>::rear->data;
  delete SeqQueue<T>::rear;
  p->link = NULL;
  SeqQueue<T>::rear = p;
  return true;
};
