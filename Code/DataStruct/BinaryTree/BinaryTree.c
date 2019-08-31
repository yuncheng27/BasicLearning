#include"BinaryTree.h"
#if 0
typedef char BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BinTreeNode;
#endif

BinTreeNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
    
}

BinTreeNode* CopyBinTree(BinTreeNode *pRoot);

void DestroyBinTree(BinTreeNode** pRoot);//后序遍历

void PreOrder(BinTreeNode* pRoot);//前序遍历

void InOrder(BinTreeNode* pRoot);//中序遍历

void PostOrder(BinTreeNode* pRoot);//后序遍历

void PreOrderNor(BinTreeNode* pRoot);//前序非递归遍历

void InOrderNor(BinTreeNode* pRoot);//中序非递归遍历

void PostOrderNor(BinTreeNode* pRoot);//后序非递归遍历

void LevelOrder(BinTreeNode* pRoot);//层序遍历(使用队列,或者使用数组把每一层元素的孩子节点保存起来)

int BinaryTreeComplete(BTNode *pRoot); //判断二叉树是否为完全二叉树,按照层序遍历的方式来找临界点，使用队列

int GetBinTreeSize(BinTreeNode* pRoot);

int GetLeafNodeCount(BinTreeNode* pRoot);

int GetKLevelNodeCount(BinTreeNode* pRoot, int K);

int Height(BinTreeNode* pRoot);

BinTreeNode* Find(BinTreeNode* pRoot, BTDataType data);

int main()
{
    BinTreeNode p;
    p = (BinTreeNode)malloc(sizeof(BTDataType));
    // printf("please enter the node as PreOrder(# represent blank node)："); 
    CreateBinTree(&p);
    //递归遍历的结果
    PreOrder(&p);
    InOrder(&p);
    PostOrder(&p);
    //非递归遍历的结果
    PreOrderNor(&p);
    InOrderNor(&p);
    PostOrderNor(&p);
    return 0;
}
