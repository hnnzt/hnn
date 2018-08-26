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
void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid);//创建二叉树
PBTNode CopyBinTree(PBTNode pRoot);//拷贝二叉树

void PreOrder(PBTNode pRoot);//前序遍历
void PreOrderNor(PBTNode pRoot);
void InOrder(PBTNode pRoot);//中序遍历
void InOrderNor(PBTNode pRoot);
void PostOrder(PBTNode pRoot);//后序遍历
void PostOrder(PBTNode pRoot);

int Size(PBTNode pRoot);//二叉树的大小
int GetLeafCount(PBTNode pRoot);//叶子结点的个数
int GetKLevel(PBTNode pRoot, int K);//第k层的结点的个数

int Height(PBTNode pRoot);//二叉树的高度
int MAXLEN(PBTNode pRoot);//最远的两个结点的距离

void LevelOrder(PBTNode pRoot);//层序遍历二叉树

void Mirror(PBTNode pRoot);//二叉树的镜像
void Mirror_Nor(PBTNode pRoot);

int IsCompleteBinTree(PBTNode pRoot);//判断是否是完全二叉树，用到了层序遍历
int IsBlanceBinTree(PBTNode pRoot);//判断是否是平衡二叉树

PBTNode Find(PBTNode pRoot, BTDataType data);//找一个点

int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);//判断一个点是否在二叉树上
PBTNode getcommon(PBTNode pRoot, PBTNode X1, PBTNode X2);//两个结点的最近公共祖先
PBTNode Treetolist(PBTNode pRoot, PBTNode prev);//转化为双向链表


PBTNode LeftChild(PBTNode pNode);
PBTNode RightChild(PBTNode pNode);
void DestroyBinTree(PBTNode* pRoot);//销毁二叉树
PBTNode BuyBinTreeNode(BTDataType data);





//////////////////////////////////////////////////
//
void TestBinTree();