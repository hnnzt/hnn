#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "mianshi.h"
#include "Queue.h"
#include "Stack.h"


PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode pNewNode = (PBTNode)malloc(sizeof(BTNode));
	assert(pNewNode);
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}



void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid)//创建二叉树

{
	assert(index);//添加一个索引，方便遍历
	if (*index < size&&invalid != array[*index])
	{
		//先创建根节点
		*pRoot = BuyBinTreeNode(array[*index]);
		//创建左子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);
		//创建右子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}




void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

PBTNode CopyBinTree(PBTNode pRoot)//拷贝二叉树
{
	PBTNode pNewRoot = NULL;
	if (pRoot)
	{
		// 拷贝当前树的根节点
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		// 拷贝当前树的左子树
		if (pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		// 拷贝当前树的右子树
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}


// 根节点--->左子树--->右子树
void PreOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		printf("%c  ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 中序：左子树--->根节点--->右子树
void InOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c  ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// 左子树--->右子树--->根节点
void PostOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c  ", pRoot->_data);
	}
}

void DestroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

int Size(PBTNode pRoot)//二叉树的大小
{
	int leftSize = 0;
	int rightSize = 0;

	if (NULL == pRoot)//
		return 0;

	leftSize = Size(pRoot->_pLeft);
	rightSize = Size(pRoot->_pRight);

	return leftSize + rightSize + 1;

}

int GetLeafCount(PBTNode pRoot)//叶子结点的个数，左子树的叶子结点加上右子树的叶子结点
{
	if (NULL == pRoot)//为空
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)//当左右都为空的时候，说明是叶子结点
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

int Height(PBTNode pRoot)//高度，计算出左右高度，选一个大的
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (NULL == pRoot)
		return 0;

	leftHeight = Height(pRoot->_pLeft);
	rightHeight = Height(pRoot->_pRight);

	return leftHeight>rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int MAXLEN(PBTNode pRoot, int *maxlen)//最远的两个结点的距离
{
	//先判断是否为空树
	if (pRoot == NULL)
	{
		return;
	}
	//获得左右子树的高度
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);

	//两树等高
	if (maxlen < left + right)
		maxlen = left + right;

	//两树不等高，要在同一侧的树上找最远距离,利用递归
	MAXLEN(pRoot->_pLeft, maxlen);
	MAXLEN(pRoot->_pRight, maxlen);
	return maxlen;
}



int GetKLevel(PBTNode pRoot, int K)//第k层的结点个数，
{
	if (NULL == pRoot || K <= 0)
		return 0;

	if (1 == K)//第一层只有根节点
		return 1;

	return GetKLevel(pRoot->_pLeft, K - 1) + GetKLevel(pRoot->_pRight, K - 1);
}

void LevelOrder(PBTNode pRoot)//层序遍历二叉树
{
	Queue q;
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);//先将根结点放入队列中，

	while (!QueueEmpty(&q))
	{
		pCur = QueueFront(&q);//取队头

		printf("%c ", pCur->_data);//先是a，然后是b,然后是c

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);//b也放入到队列中

		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);//c也放入到队列中

		QueuePop(&q);//出队列，先进先出
	}

	printf("\n");
	QueueDestroy(&q);
}

void Mirror(PBTNode pRoot)//二叉树的镜像递归
{
	if (pRoot)
	{
		PBTNode p = pRoot->_pLeft;
		pRoot->_pLeft = pRoot->_pRight;
		pRoot->_pRight = p;

		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}

void Mirror(PBTNode pRoot)//二叉树的镜像递归
{
	PBTNode pcur = pRoot;
	if (pcur == NULL || (pcur->_pLeft == NULL&&pcur->_pRight == NULL))//如果只有根节点，或者树是空的
	{
		return;
	}
	
	//交换左右子树
	PBTNode temp = pcur->_pLeft;
	pcur->_pLeft = pcur->_pRight;
	pcur->_pRight = temp;

	Mirror(pcur->_pLeft);
	Mirror(pcur->_pRight);
	
}






void Mirror_Nor(PBTNode pRoot)//二叉树的镜像非递归,队列
{
	Queue q;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while (!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		PBTNode p = pCur->_pLeft;
		pCur->_pLeft = pCur->_pRight;
		pCur->_pRight = p;

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}

	QueueDestroy(&q);
}




int IsCompleteBinTree(PBTNode pRoot)//是否为完全二叉树
{
	Queue q;
	QueueInit(&q);
	PBTNode pcur = pRoot;
	QueuePush(&q, pcur);
	while (!QueueEmpty(&q))
	{
		pcur=QueueFront(&q);//先取队头为当前结点
		if (pcur->_pLeft&&pcur->_pRight)//如果有左右子树，先放到队列中
		{
			QueuePush(&q,pcur->_pLeft);
			QueuePush(&q, pcur->_pRight);
		}
		if (pcur->_pLeft == NULL&&pcur->_pRight != NULL)//当前结点只有右子树没有左子树，则返回0
		{
			return 0;
		}
		if (pcur->_pLeft != NULL&&pcur->_pRight == NULL)
		{
			if (pcur->_pLeft->_pLeft != NULL || pcur->_pLeft->_pRight != NULL)//说明倒数第二层不满，则返回0
			{
				return 0;
			}
		}
		QueuePop(&q);
		
	}
	return 1;

}
int IsBlanceBinTree(PBTNode pRoot)//判断是否是平衡二叉树
{
	if (pRoot == NULL)
	{
		return;
	}
	int height1 = Height(pRoot->_pLeft);
	int height2 = Height(pRoot->_pRight);
	
	if (height1 - height2 <-1 || height1 - height2 >1)
	{
		return 0;
	}
	return 0;
}

int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode)//点是否在二叉树上
{
	int flag = 0;
	if (NULL == pRoot || NULL == pNode)//无结点
		return 0;

	if (pRoot == pNode)//结点为根节点
		return 1;

	if (flag = IsNodeInBinTree(pRoot->_pLeft, pNode))
		return flag;

	return IsNodeInBinTree(pRoot->_pRight, pNode);
}

PBTNode getcommon(PBTNode pRoot, PBTNode X1, PBTNode X2)//两个结点的最近公共祖先
{
	//先判断其中的一个结点是否为根节点
	if ((IsNodeInBinTree(pRoot, X1) && (pRoot == X2)) || ((IsNodeInBinTree(pRoot, X2)) && (pRoot == X1)))
	{
		return pRoot;
	}
	//两个点分别在左右子树
	if ((IsNodeInBinTree(pRoot->_pLeft, X1)) && (IsNodeInBinTree(pRoot->_pRight, X2)) || (IsNodeInBinTree(pRoot->_pLeft, X2)) && (IsNodeInBinTree(pRoot->_pRight, X1)))
	{
		return pRoot;
	}
	
	//两个点分别在一个树上,则在所在的树上进行递归
	if ((IsNodeInBinTree(pRoot->_pLeft, X1)) && (IsNodeInBinTree(pRoot->_pLeft, X2)))
	{
		return getcommon(pRoot->_pLeft,X1,X2);
	}
	if ((IsNodeInBinTree(pRoot->_pRight, X1)) && (IsNodeInBinTree(pRoot->_pRight, X2)))
	{
		return getcommon(pRoot->_pRight, X1, X2);
	}
}

PBTNode Treetolist(PBTNode pRoot, PBTNode prev)//转化为双向链表，0 1 2 3 4 5 6 7 8 9 //5是根节点，ptail是尾指针
{
	//判空
	if (pRoot == NULL)
	{
		return;
	}
	//找链表的头，中序遍历的最左边的结点
	PBTNode pHead = pRoot;
	while (pHead)
	{
		pHead = pHead->_pLeft;

	}

	//进行连接
	//先对左边的进行双向链表的连接
	Treetolist(pRoot->_pLeft, &prev);//对左子树已经进行完双链表的连连接了
	if (prev)
	{
		prev->_pRight = pRoot;
		pRoot->_pLeft = prev;
		prev = pRoot;
	}

	//对右边的进行双向链表的连接
	Treetolist(pRoot->_pRight, &prev);//对右子树已经进行双链表的连接,此时的prev是proot


}




PBTNode Find(PBTNode pRoot, BTDataType data)
{
	PBTNode pNode = NULL;
	if (NULL == pRoot)
		return NULL;

	if (pRoot->_data == data)//如果是根节点，则返回根
		return pRoot;

	if (pNode = Find(pRoot->_pLeft, data)) 
		return pNode;

	return Find(pRoot->_pRight, data);
}

void PreOrderNor(PBTNode pRoot)//根，左，右
{
#if 0
	Stack s;
	if (NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);//将根节点压入栈中

	while (!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);//取栈顶元素
		printf("%c ", pCur->_data);//打印
		StackPop(&s);//让栈顶元素出栈

		if (pCur->_pRight)//先压入右结点
			StackPush(&s, pCur->_pRight);

		if (pCur->_pLeft)//再压入左结点
			StackPush(&s, pCur->_pLeft);
	}

	printf("\n");
#endif

	Stack s;
	if (NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);

	while (!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);
		StackPop(&s);
		while (pCur)
		{
			printf("%c ", pCur->_data);
			if (pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			pCur = pCur->_pLeft;
		}
	}

	printf("\n");
}

void InOrderNor(PBTNode pRoot)//中序遍历，用栈,左中右
{
	Stack s;
	PBTNode pCur = pRoot;
	if (NULL == pRoot)
		return;

	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		// 1. 找当前树中最左侧的结点并保存所经路径中的所有节点
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);

		pCur = pCur->_pRight;
	}

	printf("\n");
}


void PostOrderNor(PBTNode pRoot)//左右中
{
	Stack s;
	PBTNode pCur = pRoot;
	PBTNode pTop = NULL;

	// 记录最近访问过的结点
	PBTNode pPrev = NULL;

	if (NULL == pRoot)
		return;

	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pTop = StackTop(&s);
		if (NULL == pTop->_pRight || pTop->_pRight == pPrev)//此处如果不判断，会重复遍根的右结点位置
			//在此处因为a 的右边不为空，所以先不打印a
		{
			printf("%c ", pTop->_data);
			pPrev = pTop;
			StackPop(&s);
		}
		else
			pCur = pTop->_pRight;
	}
}

PBTNode LeftChild(PBTNode pNode)
{
	return (NULL == pNode) ? NULL : pNode->_pLeft;
}

PBTNode RightChild(PBTNode pNode)
{
	return (NULL == pNode) ? NULL : pNode->_pRight;
}


//////////////////////////////////////////////////////////////////
//test.c
void TestBinTree()
{
	char* pStr = "ABD###CE##F";
	PBTNode pRoot = NULL;
	PBTNode pNewRoot = NULL;

	CreateBinTree(&pRoot, pStr, strlen(pStr), '#');
	PreOrder(pRoot);
	printf("\n");
	PreOrderNor(pRoot);

	InOrder(pRoot);
	InOrderNor(pRoot);
	printf("\n");

	PostOrder(pRoot);
	printf("\n");
	PostOrderNor(pRoot);

	LevelOrder(pRoot);

	if (IsCompleteBinTree(pRoot))
		printf("是完全二叉树!\n");
	else
		printf("不是完全二叉树!\n");

	Mirror(pRoot);
	Mirror_Nor(pRoot);
	LevelOrder(pRoot);

	printf("二叉树中结点的个数：%d\n", Size(pRoot));
	printf("二叉树中叶子结点的个数：%d\n", GetLeafCount(pRoot));
	printf("二叉树的高度：%d\n", Height(pRoot));
	printf("二叉树第%d层结点数：%d\n", 3, GetKLevel(pRoot, 3));

	pNewRoot = CopyBinTree(pRoot);

	DestroyBinTree(&pRoot);
	DestroyBinTree(&pNewRoot);
}
