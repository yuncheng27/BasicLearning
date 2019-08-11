#include <iostream>
#include <vector>
using namespace std;

//循环队列
class MyCircularQueue{
  private:
    vector<int> data;
    int head;
    int tail;
    int size;
  public:
    MyCircularQueue(int k){
      data.resize(k);
      head = -1;
      tail = -1;
      size = k;
    }

    bool enQueue(int value) {
      if(isFull())    //如果已经满了，则不能插入
        return false;
      if(isEmpty())
        head = 0;
      tail = (tail + 1) % size;
      data[tail] = value;
      return true;
    }

    bool deQueue() {
      if(isEmpty()) {
        return false;
      }
      if(head == tail) {
        head = -1;
        tail = -1;
        return true;
      }
      head = (head + 1) % size;
      return true;
    }

    int Front() {
      if(isEmpty()) {
        return -1;
      }
      return data[head];
    }

    int Rear() {
      if(isEmpty()) {
        return -1;
      }
      return data[tail];
    }

    bool isEmpty() {
      return head == -1;
    }

    bool isFull() {
      return (tail + 1) % size == head;
    }
};



#if 0
class Queue{
  private:
    vector<int> data;
    int pStart;

  public:
    //构造函数
    Queue(){
      pStart = 0;
    }
    bool enQueue(int x) {
      data.push_back(x);
      return true;
    }
    bool deQueue() {
      if(isEmpty()) {
        return false;
      }
      pStart++;
      return true;
    }
    int Front() {
      return data[pStart];
    }
    bool isEmpty() {
      if(data.size() == 0)
        return true;
      else 
        return false;
    }
};

#endif

int main() {
  MyCircularQueue q(100);
  q.enQueue(10);
  q.enQueue(100);
  if(!q.isEmpty()) {
    cout << q.Front() << endl;
  }
  q.deQueue();
  if(!q.isEmpty()) {
    cout << q.Front() << endl;
  }
  q.deQueue();
  if(!q.isEmpty()) {
    cout << q.Front() << endl;
  }
  return 0;
}

