#include <iostream>
#include <stdlib.h>

template <class E, class K>
struct BSTNode {
  E data;    //二叉树节点类
  BSTNode<E, K> *left, *right;    //数据域
  BSTNode() : left(NULL), right(NULL) {}   //左子女和右子女
  BSTNode(const E d, BSTNode<E, K> *L = NULL, BSTNode<E, K> *R = NULL) : data(d), left(L), right(R) {}  //构造函数
  ~BSTNode(){}    //析构函数
  void setData(E d) {data = d;}   //修改
  E getData(){return data;}   //提取
  //在定义E的数据类型时需定义元素间判小于(<)，判大于(>)，判相等(=),  以及元素与关键码间判小于(<)，判大于(>)，判相等(==)的重载函数
};

template <class E, class K>
class BST {    //二叉搜索树类定义
  public:
    BST() : root(NULL) {}    //构造函数
    BST(K value);    //构造函数
    ~BST(){};     //析构函数
    bool Search(const K x)const {
      return (Search(x, root) != NULL) ? true : false;   //搜索 
    }
    BST<E, K>& operator=(const BST<E, K>& R);    //赋值
    void makeEmpty() {
      makeEmpty(root);
      root = NULL;    //置空
    }
    void PrintTree()const {PrintTree(root);}   //输出
    E Min() {return Min(root)->data;}   //求最小
    E Max() {return Max(root)->data;}   //求最大
    bool Insert(const E& el) {return Insert(el, root);}   //插入新元素
    bool Remove(const K x) {return Remove(x, root);}   //删除含x的节点

  private:
    BSTNode<E, K> *root;    //二叉搜索树的根指针
    K RefValue;    //输入停止标志，用于输入
    BSTNode<E, K> *Search(const K x, BSTNode<E, K> *ptr);    //递归：搜索
    void makeEmpty(BSTNode<E, K> *& ptr);     //递归：置空
    void PrintTree(BSTNode<E, K> *ptr)const;    //递归：打印
    BSTNode<E, K> *Copy(const BSTNode<E, K> *ptr);   //递归：复制
    BSTNode<E, K> *Min(BSTNode<E, K> *ptr)const;    //递归：求最小
    BSTNode<E, K> *Max(BSTNode<E, K> *ptr)const;    //递归，求最大
    bool Insert(const E& el, BSTNode<E, K> *&ptr);   //递归：插入
    bool Remove(const K x, BSTNode<E, K> *&ptr);     //递归：删除
};


template <class E, class K>
BSTNode<E, K> *BST<E, K>::Search(const K x, BSTNode<E, K> *ptr) {
//私有递归函数：在以ptr为根的二叉搜索树中搜索含x的节点。若找到，则函数返回该节点的地址，否则返回NULL
  if(ptr == NULL)
    return NULL;
  else if(x < ptr->data)
    return Search(x, ptr->left);     //到左子树中继续搜索
  else if(x > ptr->data)
    return Search(x, ptr->right);   //到右子树中继续搜索
  else 
    return ptr;     //搜索成功
};


//二叉搜索树的插入算法
template <class E, class K>
bool BST<E, K>::Insert(const E& el, BSTNode<E, K> *& ptr) {
//私有函数：在以ptr为根的二叉搜索树中插入所含值为el的节点。若树中已存在，则不插入
  if(ptr == NULL) {    //新节点作为叶结点插入
    ptr = new BSTNode<E, K>(el);   //创建新节点
    if(ptr == NULL) {
      std::cerr << "Out of space" << std::endl;
      exit(1);
    }
    return true;
  }
  else if(el < ptr->data)
    Insert(el, ptr->left);    //左子树插入
  else if(el > ptr->data)
    Insert(el, ptr->right);   //右子树插入
  else 
    return false;   //x已在树中，不再插入
};


//建立二叉搜索树的算法
template <class E, class K>
BST<E, K>::BST(K value) {
//输入一个元素序列，建立一棵二叉搜索树
  E x;
  root = NULL; 
  RefValue = value;   //置空树
  std::cin >> x;    //输入数据
  while(x.key != RefValue) {    //RefValue是一个输入结束标志
    Insert(x, root);
    std::cin >> x;   //插入，再输入数据
  }
};


//二叉搜索树上的删除算法
template <class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K> *& ptr) {
//私有函数：在以ptr为根的二叉搜索树中删除含x的节点，若删除成功则新根通过ptr返回
  BSTNode<E, K> *temp;
  if(ptr != NULL) {
    if(x < ptr->data)
      Remove(x, ptr->left);   //在左子树中执行删除
    else if(x > ptr->data)
      Remove(x, ptr->right);    //在右子树中执行删除
    else if(ptr->left != NULL && ptr->right != NULL) { //ptr指示关键码为x的节点，它有两个子女
      temp = ptr->right;    //到右子树搜寻中序下第一个节点
      while(temp->left != NULL)
        temp = temp->left;
      ptr->data = temp->data;    //用该节点数据代替根节点数据
      Remove(ptr->data, ptr->right);
    }
    else {    //ptr指示关键码为x的节点，它只有一个或零个子女
      temp = ptr;
      if(ptr->left == NULL)
        ptr = ptr->right;
      else 
        ptr = ptr->left;
      delete temp;
      return true;
    }
  }
  return false;
};
