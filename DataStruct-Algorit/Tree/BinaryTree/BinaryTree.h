template <class T>
class BinaryTree {    //对象：节点的有限集合，二叉树是有序树
  public:
    BinaryTree();   //构造函数，构造一颗空的二叉树
    BinaryTree(BinTreeNode<T> *lch, BinTreeNode<T> *rch, T item);  //构造函数，以item为根，lch和rch为左，右子树构造一棵二叉树
    int Height();     //返回树的深度或高度
    int Size();     //返回树中节点个数
    bool IsEmpty();     //判二叉树空否
    BinTreeNode<T> *Parent(BinTreeNode<T> *current);
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *current);
    BinTreeNode<T> *RightChild(BinTreeNode<T> *current);
    bool Insert(T item);      //按指定规则在树中插入新元素item
    bool Remove(T item);     //在树中删除元素item
    bool Find(const T& item)const;    //判断item是否在树中
    bool getData(const T& item)const;    //取得节点数据，通过item返回
    BinTreeNode<T> *getRoot()const;      //取根
    void preOrder(void (* visit)(BinTreeNode<T> *p));     //前序遍历，visit是访问函数
    void inOrder(void (* visit)(BinTreeNode<T> *p));     //中序遍历，visit是访问函数
    void postOrder(void (* visit)(BinTreeNode<T> *p));    //后序遍历，visit是访问函数
    void levelOrder(void (* visit)(BinTreeNode<T> *p));   //层次序遍历，visit是访问函数
};
