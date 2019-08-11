#include "../Queue/Queue.h"


template <class T>
class Deque: public Queue<T> {
  public:
    virtual bool getHead(T& x) const = 0;
    virtual bool getTail(T& x) const = 0;
    virtual bool EnQueue(const T& x) = 0;
    virtual bool EnQueueHead(const T& x) = 0;
    virtual bool EnQueueTail(const T& x) = 0;
    virtual bool DeQueue(T& x);
    virtual bool DeQueueHead(T& x) = 0;
    virtual bool DeQueueTail(T& x) = 0;
};
