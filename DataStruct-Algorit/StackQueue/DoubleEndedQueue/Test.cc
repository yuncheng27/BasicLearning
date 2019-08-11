#include "SeqDeque.hpp"

int main (){
  int a, n=5, value;
  SeqDeque<int> D(10);
  std::cout<<"please enter the date into Queue"<<std::endl;
  while(n--){
    std::cin>>a;
    D.EnQueue(a);

  }
  std::cout<<D<<std::endl;
  D.DeQueueTail(value);
  D.EnQueueHead(value);
  std::cout<<D<<std::endl;
  std::cout<<"队头元素："<<D.getElements()[D.getFront()]<<std::endl;
  D.getTail(value);
  std::cout<<"队尾元素："<<value<<std::endl;
  return 0;
}
