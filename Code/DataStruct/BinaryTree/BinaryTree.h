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

// ����������(ͨ��ǰ�����������ABD##E#H##CF##G##��(A(B(D,E( ,H)),C(F,G)))�����Ķ�����)
BinTreeNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);
BinTreeNode* CopyBinTree(BinTreeNode* pRoot);
void DestroyBinTree(BinTreeNode** pRoot);
// ����������
void PreOrder(BinTreeNode* pRoot);//ǰ�����
void InOrder(BinTreeNode* pRoot);//�������
void PostOrder(BinTreeNode* pRoot);//�������

void PreOrderNor(BinTreeNode* pRoot);//ǰ��ǵݹ����
void InOrderNor(BinTreeNode* pRoot);//����ǵݹ����
void PostOrderNor(BinTreeNode* pRoot);//����ǵݹ����

void LevelOrder(BinTreeNode* pRoot);//�������
int BinaryTreeComplete(BTNode *pRoot); //�ж϶������Ƿ�Ϊ��ȫ������

int GetBinTreeSize(BinTreeNode* pRoot);
int GetLeafNodeCount(BinTreeNode* pRoot);
int GetKLevelNodeCount(BinTreeNode* pRoot, int K);
int Height(BinTreeNode* pRoot);

BinTreeNode* Find(BinTreeNode* pRoot, BTDataType data);

/////////////////////////////////////////
void TestBinTree();

#endif 
