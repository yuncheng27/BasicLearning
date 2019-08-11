#include "SeqList.hpp"

void Merge(SeqList<int>& LA, SeqList<int>& LB) {
//合并顺序表LA和LB，结果存于LA中，重复元素只留一个
  int n = LA.Length(), m = LB.Length(), i, k, x;
  for(i = 1; i <= m; i++) {
    LB.getData(i, x);
    k = LA.Search(x);
    if(k == 0){
      LA.Insert(n, x);
      n++;
    }
  }
}

void Intersection(SeqList<int>& LA, SeqList<int>& LB) {
//求顺序表LA与LB中的共有元素，结果存于LA
  int n = LA.Length(), m = LB.Length(), i = 1, k, x;
  while(i <= n) {
    LA.getData(i, x);
    k = LB.Search(x);
    if(k == 0) {
      LA.Remove(i, x);
      n--;
    }
    else 
      i++;
  }
}

int main()
{
  return 0;
}
