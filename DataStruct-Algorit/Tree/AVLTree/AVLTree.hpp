#include "../BinarySortTree/BST.hpp"

template <class E, class K>
struct AVLNode: public BSTNode<E, K> {  //AVL树节点的类定义
  int bf;
  AVLNode() : BSTNode<E, K>::left(NULL), BSTNode<E, K>::right(NULL), bf(0) {}
  AVLNode(E d, AVLNode<E, K> *l = NULL, AVLNode<E, K> *r = NULL) : BSTNode<E, K>::data(d), BSTNode<E, K>::left(l), BSTNode<E, K>::right(r), bf(0) {}
};

template <class E, class K>
class AVLTree : public BST<E, K> {    //平衡的二叉搜索树(AVL)类定义  
  public:
    AVLTree() : BST<E, K>::root(NULL) {}      //构造函数:构造非空AVL树
    AVLTree(K Ref) : BST<E, K>::RefValue(Ref), BST<E, K>::root(NULL) {}  //构造函数：构造非空AVL树
    bool Insert(E& el){return Insert(BST<E, K>::root, el);}
    bool Remove(K x, E& el) {return Remove(BST<E, K>::root, x, el);}
    friend std::istream& operator>>(std::istream& in, AVLTree<E, K>& Tree);
    friend std::ostream& operator<<(std::ostream& out, const AVLTree<E, K>& Tree);
    int Height()const;
  protected:
    AVLNode<E, K> *Search(K x, AVLNode<E, K> *& par)const;
    bool Insert(AVLNode<E, K> *& ptr, E& el);
    bool Remove(AVLNode<E, K> *& ptr, K x, E& el);
    void RotateL(AVLNode<E, K> *& ptr);     //左单旋
    void RotateR(AVLNode<E, K> *& ptr);     //右单旋
    void RotateLR(AVLNode<E, K> *& ptr);    //先左后右双旋
    void RotateRL(AVLNode<E, K> *& ptr);    //先右后左双旋
    int Height(AVLNode<E, K> *ptr)const;    //求高度
};

//左单旋算法
template <class E, class K>
void AVLTree<E, K>::RotateL(AVLNode<E, K> *& ptr) {
//右子树比左子树高：对以ptr为根的AVL树做左单旋，旋转后新根在ptr
  AVLNode<E, K> *subL = ptr;    //要左旋转的节点
  ptr = subL->right;      //原根的右子女
  subL->right = ptr->left;    //ptr成为新根前卸掉左边负载
  ptr->left = subL;    //左单旋，ptr为新根
  ptr->bf = subL->bf = 0;
};

//右单旋算法
template <class E, class K>
void AVLTree<E, K>::RotateR(AVLNode<E, K> *& ptr) {
//左子树比右子树高：对以ptr为根的AVL树做右单旋，旋转后新根在ptr
  AVLNode<E, K> *subR = ptr;    //要右旋转的节点
  ptr = subR->left;    //原根的左子女
  subR->left = ptr->right;   //ptr成为新根前卸掉右边负载
  ptr->right = subR;     //右单旋，ptr成为新根
  ptr->bf = subR->bf = 0;
};


//先左后右的双旋转算法
template <class E, class K>
void AVLTree<E, K>::RotateLR(AVLNode<E, K> *& ptr) {
  AVLNode<E, K> *subR = ptr, *subL = subR->left;
  ptr = subL->right;
  subL->right = ptr->left;    //ptr成为新根前甩掉它左边的负载
  ptr->left = subL;    //左单旋，ptr成为新根
  if(ptr->bf <= 0)
    subL->bf = 0;    //插入新节点后ptr左子树变高
  else 
    subL->bf = -1;
  subR->left = ptr->right;    //ptr成为新根前甩掉它右边的负载
  ptr->right = subR;     //右单旋，ptr成为新根
  if(ptr->bf == -1)
    subR->bf = 1;
  else 
    subR->bf = 0;
  ptr->bf = 0;
};

//P325
