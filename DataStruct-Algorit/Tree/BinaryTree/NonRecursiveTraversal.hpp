#include "../../StackQueue/Stack/Stack.h"
#include "BinaryTree.hpp"
#include "../../StackQueue/Queue/Queue.h"


//用栈的前序遍历非递归算法
template <class T>
void BinaryTree<T>::preOrder(void (* visit)(BinTreeNode<T> *p)) {
  Stack<BinTreeNode<T> *> S;
  BinTreeNode<T> *p = root;    //初始化
  S.Push(NULL);
  while(p != NULL) {
    visit(p);     //访问节点
    if(p->rightChild != NULL)
      S.Push(p->rightChild);   //预留右子树指针在栈中
    if(p->leftChild != NULL)
      p = p->leftChild;   //进左子树
    else 
      S.Pop(p);    //左子树为空
  }
};

//另一种前序遍历的方法。为了保证先左子树后右子树的顺序，在进栈时先进有子节点地址，然后进左子节点地址，出栈时正好相反
template <class T>
void BinaryTree<T>::preOrder(void (* visit)(BinTreeNode<T> *p)) {
  Stack<BinTreeNode<T> *> S;
  BinTreeNode<T> *p;
  S.Push(root);
  while(! S.IsEmpty()) {
    S.Pop(p);
    visit(p);      //退栈，访问
    if(p->rightChild != NULL)
      S.Push(p->rightChild);
    if(p->leftChild != NULL)
      S.Push(p->leftChild);
  }
};


//用队列实现层次序遍历
template <class T>
void BinaryTree<T>::levelOrder(void (* visit)(BinTreeNode<T> *p)) {
  Queue<BinTreeNode<T> *> Q;
  BinTreeNode<T> *p = root;
  Q.EnQueue(p);
  while(! Q.IsEmpty()) {   //队列不空
    Q.DeQueue(p);
    visit(p);    //退出一个节点，访问
    if(p->leftChild != NULL)
      Q.EnQueue(p->leftChild);    //左子女进队
    if(p->rightChild != NULL)
      Q.EnQueue(p->rightChild);   //右子女进队
  }
}

//利用栈的中序遍历非递归算法
template <class T>
void BinaryTree<T>::inOrder(void (* visit)(BinTreeNode<T> *p)) {
  Stack<BinTreeNode<T> *> S;
  BinTreeNode<T> *p = root;    //p是遍历指针，从根节点开始
  do {
    while(p != NULL) {   //遍历指针未到最坐下的节点，不空
      S.Push(p);    //该子树沿途节点进栈
      p = p->leftChild;    //遍历指针进到左子节点
    }
    if(!S.IsEmpty()) {   //栈不空时退栈
      S.Pop(p);
      visit(p);    //退栈，访问根节点
      p = p->rightChild;    //遍历指针进到右子节点
    }
  } while (p != NULL || !S.IsEmpty());
};

//利用栈的后序遍历非递归算法
template <class T>
struct stkNode {    //在遍历时所用栈节点类定义
  BinTreeNode<T> *ptr;   //指向树节点的指针
  enum tag{L, R};    //该节点退栈标记
  stkNode(BinTreeNode<T> *N = NULL): ptr(N), tag(L) {}   //构造函数
};

template <class T>
void BinaryTree<T>::postOrder(void (* visit)(BinTreeNode<T> *p)) {
  Stack<stkNode<T>> S;
  stkNode<T> w;
  BinTreeNode<T> *p = root;    //p是遍历指针
  do {
    while(p != NULL) {   //左子树经过节点加L进栈
      w.ptr = p;
      w.tag = L;
      S.Push(w);
      p = p->leftChild;     //向最左下节点走下去
    }
    int continue1 = 1;     //继续循环标记，用于R
    while(continue1 && !S.IsEmpty()) {
      S.Pop(w);
      p = w.ptr;     //栈不空，退栈
      switch(w.tag) {    
        case L: 
          w.tag = R;   //判断栈顶的tag标记
          S.Push(w);   //从左子树退回，修改栈顶tag
          continue1 = 0;
          p = p->rightChild;    //向右子树遍历下去
          break;
        case R:
          visit(p);
          break;    //从右子树退回，访问根节点
      }
    }
  }while(!S.IsEmpty());    //还有节点未遍历，继续循环
  std::cout << std:: endl;
};
