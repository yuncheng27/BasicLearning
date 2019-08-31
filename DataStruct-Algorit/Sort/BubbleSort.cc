//基本冒泡排序算法
typedef int T;     //定义数据类型T为int
void BubbleSort(T V[], int n) {
//对数组V中的n个元素进行冒泡排序，执行n-1趟，第i趟对V[n-1]~V[i]冒泡
  for(int i = 1; i < n; i++)    //从1到n-1，逐步缩小待排序列
    for(int j = n - 1; j >= i; j--)   //反向检测，检查是否逆序
      if(V[j - 1] > V[j]) {  //发生逆序，交换元素的值
        T temp = V[j - 1];
        V[j - 1] = V[j];
        V[j] = temp; 
      }     
};

//改进的冒泡排序算法
typedef int T;
void BubbleSort(T V[], int n) {
  bool exchange;    //exchange为是否发生交换标志
  int i, j;
  for(i = 1; i < n; i++) {
    exchange = false;     //检查前假设没有发生交换
    for(j = n - 1; j >= i; j--)    //从后向前检查是否发生逆序
      if(V[j - 1] > V[j]) {    //发生逆序，交换元素的值
        T temp = V[j - 1];
        V[j - 1] = V[j];
        V[j] = temp;
        exchange = true;    //置exchange为有交换状态
      }
    if(exchange == false)
      return;    //本趟无逆序，停止处理
  }
};
