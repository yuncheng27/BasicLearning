#include <iostream>
#include <stdlib.h>


template <class T>
struct BinTreeNode {     //二叉树节点类定义
  T data;     //数据域
  BinTreeNode<T> *leftChild, *rightChild;     //左子女域，右子女链域
  BinTreeNode(): leftChild(NULL), rightChild(NULL) {}
  BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) : data(x), leftChild(l), rightChild(r) {}
};

template <class T>
class BinaryTree {    //二叉树类定义
  public:
    BinaryTree(): root(NULL){}   //构造函数
    BinaryTree(T value): RefValue(value), root(NULL) {}  //构造函数
    BinaryTree(BinaryTree<T>& s);   //复制构造函数
    ~BinaryTree(){ destroy(root);}   //析构函数
    bool IsEmpty() {return (root == NULL) ? true : false;}   //判断二叉树空否
    BinTreeNode<T> *Parent(BinTreeNode<T> *current) {
      return (root == NULL || root == current) ? NULL : Parent(root, current);       //返回父节点
    }
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *current) {
      return (current != NULL) ? current->leftChild : NULL;     //返回左孩子
    }
    BinTreeNode<T> *RightChild(BinTreeNode<T> *current) {
      return (current != NULL) ? current->rightChild : NULL;    //返回右孩子
    }
    int Height() {return Height(root);}     //返回树高度
    int Size() {return Size(root);}     //返回节点数
    BinTreeNode<T> *getRoot() const {return root;}   //取根
    void preOrder(void (* visit)(BinTreeNode<T> *p)) {
      preOrder(root, visit);        //前序遍历
    }
    void inOrder(void (* visit)(BinTreeNode<T> *p)) {
      inOrder(root, visit);        //中序遍历
    }
    void postOrder(void (* visit)(BinTreeNode<T> *p)) {
      postOrder(root, visit);        //后序遍历
    }
    void levelOrder(void (* visit)(BinTreeNode<T> *p));     //层次序遍历
    int Insert(const T& item);     //插入新元素
    BinTreeNode<T> *Find(T& item)const;    //搜索
    void PrintBTree(BinTreeNode<T> *BT);   //以广义表形式输出二叉树


  protected:
    BinTreeNode<T> *root;      //二叉树的根指针
    T RefValue;             //数据输入停止标志
    void CreateBinTree(std::istream& in, BinTreeNode<T> *& subTree);    //从文件输入停止标志
    bool Insert(BinTreeNode<T> *& subTree, const T& x);    //插入
    bool destroy(BinTreeNode<T> *& subTree);      //删除
    bool Find(BinTreeNode<T> *subTree, const T& x)const;     //查找
    BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);    //复制
    int Height(BinTreeNode<T> *subTree);   //返回树高度
    int Size(BinTreeNode<T> *subTree);    //返回节点数
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);     //返回父节点
    //BinTreeNode<T> *Find(BinTreeNode<T> *subTree, const T& x)const;     //搜寻x
    void Traverse(BinTreeNode<T> *subTree, std::ostream& out);    //前序遍历输出
    void preOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T> *p));     //前序遍历
    void inOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T> *p));    //中序遍历
    void postOrder(BinTreeNode<T>& Tree, void (* visit)(BinTreeNode<T> *p));     //后序遍历
    friend std::istream& operator>>(std::istream& in, BinaryTree<T>& Tree);    //输入重载
    friend std::ostream& operator<<(std::istream& out, BinaryTree<T>& Tree);   //输出重载
};



template <class T>
bool BinaryTree<T>::destroy(BinTreeNode<T> *& subTree) {
//私有函数：若指针subTree不为空，则删除根为subTree的子树
  if(subTree != NULL) {
    destroy(subTree->leftChild);     //递归删除subTree的左子树
    destroy(subTree->rightChild);     //递归删除subTree的右子树
    delete subTree;      //递归subTree
  }
};


template <class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) {
//私有函数：从节点subTree开始，搜索节点current的父节点。若找到节点current的父节点，则函数返回父节点地址，否则返回NULL
  if(subTree == NULL) 
    return NULL;
  if(subTree->leftChild == current || subTree->rightChild == current)
    return subTree;      //找到，返回父节点subTree
  BinTreeNode<T> *p;
  if((p = Parent(subTree->leftChild, current)) != NULL) 
    return p;     //递归在左子树中搜索
  else
    return Parent(subTree->rightChild, current);    //递归在左子树中搜索
};

template <class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, std::ostream& out) {
//私有函数：搜索并输出根为subTree的二叉树
  if(subTree != NULL) {     //subTree为空则返回
    std::cout << subTree->data << ' ';    //输出subTree的数据
    Traverse(subTree->leftChild, out);     //递归搜索并输出subTree的左子树
    Traverse(subTree->rightChild, out);    //递归搜索并输出subTree的右子树
  }
};


template <class T>
std::istream& operator>>(std::istream& in, BinaryTree<T>& Tree) {
//重载操作：输入并建立一棵二叉树Tree，in是输入流对象  
  CreateBinTree(in, Tree.root);    //建立二叉树
  return in;
};

template <class T>
std::ostream& operator<<(std::ostream& out, BinaryTree<T>& Tree) {
//重载操作：输出一棵二叉树Tree，out是输出流对象
  out << "二叉树的前序遍历\n";     //搜索二叉树
  Tree.Traverse(Tree.root, out);    //从根开始输出
  out << std::endl;
  return out;
};


template <class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T> *p)) {
//递归函数：中序遍历以subTree为根的子树
  if(subTree != NULL) {     //=NULL是递归终止条件
    inOrder(subTree->leftChild, visit);     //中序遍历根的左子树
    visit(subTree);      //访问根节点
    inOrder(subTree->rightChild, visit);     //中序遍历根的右子树
  }
};

template <class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T> *p)) {
  if(subTree != NULL) {    //递归结束条件
    visit(subTree);      //访问根节点
    preOrder(subTree->leftChild, visit);     //前序遍历访问左子树
    preOrder(subTree->rightChild, visit);     //前序遍历根的右子树
  }
};

template <class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T> *p)) {
  if(subTree != NULL) {
    postOrder(subTree->leftChild, visit);
    postOrder(subTree->rightChild, visit);
    visit(subTree);
  }
};

template <class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree) {
//私有函数：计算以*subTree为根的二叉树的节点个数
  if(subTree == NULL)
    return 0;      //递归结束：空树节点个数为0
  else 
    return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
};

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree) {
//私有函数：计算以*subTree为根的二叉树的高度或深度
  if(subTree == NULL)
    return 0;     //递归结束：空树高度为0
  else {
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return (i < j) ? j + 1 : i + 1;
  }
};


template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& s) {
//公共函数：复制构造函数
  root = Copy(s.root);
};


template <class T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T> *orignode) {
//私有函数：这个函数返回一个指针，它给出一个以orignode为根的二叉树的副本
  if(orignode == NULL)
    return NULL;       //根为空。返回空指针
  BinTreeNode<T> *temp = new BinTreeNode<T>;     //创建根节点
  temp->data = orignode->data;     //传送数据
  temp->leftChild = Copy(orignode->leftChild);    //复制左子树
  temp->rightChild = Copy(orignode->rightChild);    //复制右子树
  return temp;     //返回根指针
};

template <class T>
int operator==(const BinaryTree<T>& s, const BinaryTree<T>& t) {
//判断两棵树的等价性，假定它是BinaryTree类的友元函数
  return (equal(s.root, t.root)) ? true : false;
};

template <class T>
bool equal(BinTreeNode<T> *a, BinTreeNode<T> *b) {
//如果a和b的子树不等同，则函数返回false，头则返回true. 假定它是BinTreeNode类的友元函数
  if(a == NULL && b == NULL)
    return true;    //两者都是NULL
  if(a != NULL && b != NULL && a->data == b->data     //两者根节点数据相等
      && equal(a->leftChild, b->leftChild)     //且左子树相同
      && equal(a->rightChild, b->rightChild))    //且右子树相同
    return true;
  else 
    return false;
};


template <class T>
void BinaryTree<T>::CreateBinTree(std::istream& in, BinTreeNode<T> *& subTree) {
//私有函数：以递归方式建立二叉树
  T item;
  if(!in.eof()) {    //未读完，读入并建树
    in >> item;      //读入根节点的值
    if(item != RefValue) {
      subTree = new BinTreeNode<T>(item);     //建立根节点
      if(subTree == NULL) {
        std::cerr << "存储分配错!" << std::endl;
        exit(1);
      }
      CreateBinTree(in, subTree->leftChild);    //递归建立左子树
      CreateBinTree(in, subTree->rightChild);    //递归建立右子树
    }
    else 
      subTree = NULL;    //封闭指向空子树的指针
  }
};


template <class T>
void PrintBTree(BinTreeNode<T> *BT) {
//以广义表形式输出二叉树
  if(BT != NULL) {    //树为空时结束递归
    std::cout << BT->data;     //输出根节点的值
    if(BT->leftChild != NULL || BT->rightChild != NULL) {
      std::cout << '(';    //输出左括号
      PrintBTree(BT->leftChild);    //输出左子树
      std::cout << ',';    //输出逗号分隔符
      if(BT->rightChild != NULL)    //若右子树不为空
        PrintBTree(BT->rightChild);   //输出右子树
      std::cout << ')';    //输出右括号
    }
  } 
};


//利用前序序列和中序序列构造二叉树
template <class T>
BinTreeNode<T> *createBinaryTree(T *VLR, T *LVR, int n) {
//VLR是二叉树的前序序列，LVR是二叉树的中序序列.构造出的二叉树根指针由函数返回
  if(n == 0)
    return NULL;
  int k = 0;     
  while(VLR[0] != LVR[k])  //在中序序列中寻找根
    k++;
  BinTreeNode<T> *t = new BinTreeNode<T>(VLR[0]);   //创建根节点
  t->leftChild = createBinaryTree(VLR + 1, LVR, k);   //从前序VLR + 1开始对中序的0~k-1左子序列的k个元素递归建立左子树
  t->rightChild = createBinaryTree(VLR + k + 1, LVR + k + 1, n-k-1);  //从前序VLR+k+1开始对中序的k+1~n-1右子序列的n-k-1个元素建立右子树
  return t;
};
