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
	PointFlag _leftThread;//ǰ��
	PointFlag _rightThread;//����

}Node, *PNode;


void InitBinTree(PNode pRoot)
{
	pRoot = 0;
}

PNode BuyNode(DataType data);


void _CreateBinTree(PNode* pRoot, DataType array[], int size, int* index, DataType invalid);//����������

void CreateBinTree(PNode* pRoot, DataType array[], int size, DataType invalid);

void _PreOrderThd(PNode pRoot, PNode* prev);//�ǵݹ�ǰ��������
void PreOrderThd(PNode pRoot);//�ݹ�ǰ��������


void _InOrderThd(PNode pRoot, PNode* prev);//�ǵݹ�����������
void InOrderThd(PNode pRoot);//�ݹ�����������


void _PostOrderThd(PNode pRoot, PNode* prev);//�ǵݹ����������
void PostOrderThd(PNode pRoot);//�ݹ����������


void PreOrderD(PNode pRoot);//ǰ��


void InOrderD(PNode pRoot);//����



