#include "../../StackQueue/PriorityQueue/PQueue.hpp"

#define DefaultSize 10

template <class E>
class MinHeap: public PQueue<E> {    //最小堆继承了(最小)优先级队列
  public:
    MinHeap(int sz = DefaultSize);   //构造函数：建立空堆
    MinHeap(E arr[], int n);    //构造函数：通过一个数组建堆
    ~MinHeap() {delete []heap;}   //析构函数
    bool Insert(const E& x);   //将x插入到最小堆中
    bool RemoveMin(E& x);    //删除堆顶上的最小元素
    bool IsEmpty()const {
      return (currentSize == 0) ? true : false;    //判断堆空否 空返回1，否则返回0 
    }
    bool IsFull()const {
      return (currentSize == 0) ? true : false;    //判堆满否 
    }
    void MakeEmpty() {currentSize = 0;}     //置空堆
  private:
    E *heap;   //存放最小堆中元素的数组
    int currentSize;    //最小堆中当前元素个数
    int maxHeapSize;    //最小堆最多允许元素个数
    void siftDown(int start, int m);    //从start到m下滑调整成最小堆
    void siftUp(int start);    //从start到0上滑调整成为最小堆
};


template <class E>
MinHeap<E>::MinHeap(int sz) {
  maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
  heap = new E[maxHeapSize];    //创建堆存储空间
  if(heap == NULL) {
    std::cerr << "堆存储分配失败!" << std::endl;
    exit(1);
  }
  currentSize = 0;    //建立当前大小
};

template <class E>
MinHeap<E>::MinHeap(E arr[], int n) {
  maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
  heap = new E[maxHeapSize];
  if(heap == NULL) {
    std::cerr << "堆存储分配失败!" << std::endl;
    exit(1);
  }
  for(int i = 0; i < n; i++)
    heap[i] = arr[i];
  currentSize = n;    //复制堆数组，建立当前大小
  int currentPos = (currentSize - 2)/2;    //找最初调整位置：最后分支节点
  while(currentPos >= 0) {
    siftDown(currentPos, currentSize - 1);   //局部自上向下下滑调整
    currentPos--;    //再向前换一个分支节点
  }
};


template <class E>
void MinHeap<E>::siftDown(int start, int m) {
//私有函数：从节点start开始到m为止，自上向下比较，如果节点的值小于父节点的值，则关键码小的上浮，继续向下层比较，这样将一个集合局部调整为最小堆
  int i = start, j = 2 * i + 1;   //j是i的左孩子位置
  E temp = heap[i];
  while(j <= m){   //检查是否到最后位置
    if(j < m && heap[j] > heap[j+1])
      j++;    //让j指向两孩子中的小者
    if(temp <= heap[j])
      break;     //小则不做调整
    else{
      heap[i] = heap[j];
      i = j;
      j = 2*j+1;     //否则小者上移，i,j下降
    }
  }
  heap[i] = temp;     //回放temp中暂存的元素
};


template <class E>
void MinHeap<E>::siftUp(int start) {
//私有函数：从节点start开始到节点0为止，自下向上比较，如果子女的值小于父节点的值，则相互交换，这样将集合重新调整为最小堆。关键码比较符"<="在E中定义
  int j = start, i =(j-1)/2;
  E temp = heap[j];
  while(j > 0){    //沿父节点路径向上直达根
    if(heap[i] <= temp) break;    //父节点小，不调整
    else  {
      heap[j] = heap[i];
      j = i;
      i = (i - 2)/2;
    }    //父节点值大，调整
  }
  heap[j] =temp;    //回送
};

template <class E>
bool MinHeap<E>::Insert(const E& x){
//公共函数：将x插入到最小堆中
  if(currentSize == maxHeapSize) {
    std::cerr << "Heap Full" << std::endl;
    return false;   //堆满
  }
  heap[currentSize] = x;    //插入
  siftUp(currentSize);     //向上调整
  currentSize++;    //堆计数加1
  return true;
};

//最小堆的删除算法
template <class E>
bool MinHeap<E>::RemoveMin(E& x) {
  if(!currentSize) {
    std::cout << "Heap empty" << std::endl;
    return false;     //堆空，返回false
  }
  x = heap[0];
  heap[0] = heap[currentSize - 1];    //最后元素填补到根节点
  currentSize--;
  siftDown(0, currentSize-1);   //自上向下调整为堆
  return true;    //返回最小元素
};
