#include"stdio.h"
#include"assert.h"
#include"malloc.h"



typedef char DataType;

typedef enum{ LINK, THREAD }PointFlag;

typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	struct BinTreeNode* _pParent;
	DataType _data;
	PointFlag _leftThread;//前驱
	PointFlag _rightThread;//后驱

}Node, *PNode;


void InitBinTree(PNode pRoot)
{
	pRoot = 0;
}

PNode BuyNode(DataType data);


void _CreateBinTree(PNode* pRoot, DataType array[], int size, int* index, DataType invalid);//创建二叉树

void CreateBinTree(PNode* pRoot, DataType array[], int size, DataType invalid);

void _PreOrderThd(PNode pRoot, PNode* prev);//非递归前序线索化
void PreOrderThd(PNode pRoot);//递归前序线索化


void _InOrderThd(PNode pRoot, PNode* prev);//非递归中序线索化
void InOrderThd(PNode pRoot);//递归中序线索化


void _PostOrderThd(PNode pRoot, PNode* prev);//非递归后序线索化
void PostOrderThd(PNode pRoot);//递归后续线索化


void PreOrderD(PNode pRoot);//前序


void InOrderD(PNode pRoot);//中序



