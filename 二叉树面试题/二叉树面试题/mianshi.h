#pragma once


typedef char BTDataType;

typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BTNode, *PBTNode;


/////////////////////////////////////////////////////
void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid);
void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid);//����������
PBTNode CopyBinTree(PBTNode pRoot);//����������

void PreOrder(PBTNode pRoot);//ǰ�����
void PreOrderNor(PBTNode pRoot);
void InOrder(PBTNode pRoot);//�������
void InOrderNor(PBTNode pRoot);
void PostOrder(PBTNode pRoot);//�������
void PostOrder(PBTNode pRoot);

int Size(PBTNode pRoot);//�������Ĵ�С
int GetLeafCount(PBTNode pRoot);//Ҷ�ӽ��ĸ���
int GetKLevel(PBTNode pRoot, int K);//��k��Ľ��ĸ���

int Height(PBTNode pRoot);//�������ĸ߶�
int MAXLEN(PBTNode pRoot);//��Զ���������ľ���

void LevelOrder(PBTNode pRoot);//�������������

void Mirror(PBTNode pRoot);//�������ľ���
void Mirror_Nor(PBTNode pRoot);

int IsCompleteBinTree(PBTNode pRoot);//�ж��Ƿ�����ȫ���������õ��˲������
int IsBlanceBinTree(PBTNode pRoot);//�ж��Ƿ���ƽ�������

PBTNode Find(PBTNode pRoot, BTDataType data);//��һ����

int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);//�ж�һ�����Ƿ��ڶ�������
PBTNode getcommon(PBTNode pRoot, PBTNode X1, PBTNode X2);//�������������������
PBTNode Treetolist(PBTNode pRoot, PBTNode prev);//ת��Ϊ˫������


PBTNode LeftChild(PBTNode pNode);
PBTNode RightChild(PBTNode pNode);
void DestroyBinTree(PBTNode* pRoot);//���ٶ�����
PBTNode BuyBinTreeNode(BTDataType data);





//////////////////////////////////////////////////
//
void TestBinTree();