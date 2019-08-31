#pragma once
#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include<stdio.h>


typedef char BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BinTreeNode;

// 二叉树创建(通过前序遍历的数组ABD##E#H##CF##G##即(A(B(D,E( ,H)),C(F,G)))创建的二叉树)
BinTreeNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);
BinTreeNode* CopyBinTree(BinTreeNode* pRoot);
void DestroyBinTree(BinTreeNode** pRoot);
// 二叉树遍历
void PreOrder(BinTreeNode* pRoot);//前序遍历
void InOrder(BinTreeNode* pRoot);//中序遍历
void PostOrder(BinTreeNode* pRoot);//后序遍历

void PreOrderNor(BinTreeNode* pRoot);//前序非递归遍历
void InOrderNor(BinTreeNode* pRoot);//中序非递归遍历
void PostOrderNor(BinTreeNode* pRoot);//后序非递归遍历

void LevelOrder(BinTreeNode* pRoot);//层序遍历
int BinaryTreeComplete(BTNode *pRoot); //判断二叉树是否为完全二叉树

int GetBinTreeSize(BinTreeNode* pRoot);
int GetLeafNodeCount(BinTreeNode* pRoot);
int GetKLevelNodeCount(BinTreeNode* pRoot, int K);
int Height(BinTreeNode* pRoot);

BinTreeNode* Find(BinTreeNode* pRoot, BTDataType data);

/////////////////////////////////////////
void TestBinTree();

#endif 
