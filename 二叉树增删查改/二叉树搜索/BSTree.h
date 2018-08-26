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



void InitBSTree(PNode* pRoot);//��ʼ��������
int InsertBST(PNode* pRoot, DataType data);//��������в�����
PNode FindBST(PNode pRoot, DataType data);//Ѱ��ĳһ�����
int DeleteBSTree(PNode* pRoot, int data);//ɾ��ĳһ�����
void InOrder(PNode pRoot);//�������
void DestroyBSTree(PNode* pRoot);//���ٶ�����
PNode BuyBSTreeNode(DataType data);//�������


#endif _BSTree_H__



