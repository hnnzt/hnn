#include"stdio.h"
#include"assert.h"
#include"malloc.h"

#ifndef  _BSTree_H__
#define _BSTree_H__

typedef char DataType;

typedef struct BSTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	DataType _data;
}node, *PNode;



void InitBSTree(PNode* pRoot);//初始化二叉树
int InsertBST(PNode* pRoot, DataType data);//向二叉树中插入结点
PNode FindBST(PNode pRoot, DataType data);//寻找某一个结点
int DeleteBSTree(PNode* pRoot, int data);//删除某一个结点
void InOrder(PNode pRoot);//中序遍历
void DestroyBSTree(PNode* pRoot);//销毁二叉树
PNode BuyBSTreeNode(DataType data);//创建结点


#endif _BSTree_H__



