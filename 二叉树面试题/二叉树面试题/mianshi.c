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



void _CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, int* index, BTDataType invalid)//����������

{
	assert(index);//���һ���������������
	if (*index < size&&invalid != array[*index])
	{
		//�ȴ������ڵ�
		*pRoot = BuyBinTreeNode(array[*index]);
		//����������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);
		//����������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}




void CreateBinTree(PBTNode* pRoot, BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

PBTNode CopyBinTree(PBTNode pRoot)//����������
{
	PBTNode pNewRoot = NULL;
	if (pRoot)
	{
		// ������ǰ���ĸ��ڵ�
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		// ������ǰ����������
		if (pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		// ������ǰ����������
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}


// ���ڵ�--->������--->������
void PreOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		printf("%c  ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// ����������--->���ڵ�--->������
void InOrder(PBTNode pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c  ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// ������--->������--->���ڵ�
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

int Size(PBTNode pRoot)//�������Ĵ�С
{
	int leftSize = 0;
	int rightSize = 0;

	if (NULL == pRoot)//
		return 0;

	leftSize = Size(pRoot->_pLeft);
	rightSize = Size(pRoot->_pRight);

	return leftSize + rightSize + 1;

}

int GetLeafCount(PBTNode pRoot)//Ҷ�ӽ��ĸ�������������Ҷ�ӽ�������������Ҷ�ӽ��
{
	if (NULL == pRoot)//Ϊ��
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)//�����Ҷ�Ϊ�յ�ʱ��˵����Ҷ�ӽ��
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

int Height(PBTNode pRoot)//�߶ȣ���������Ҹ߶ȣ�ѡһ�����
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (NULL == pRoot)
		return 0;

	leftHeight = Height(pRoot->_pLeft);
	rightHeight = Height(pRoot->_pRight);

	return leftHeight>rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int MAXLEN(PBTNode pRoot, int *maxlen)//��Զ���������ľ���
{
	//���ж��Ƿ�Ϊ����
	if (pRoot == NULL)
	{
		return;
	}
	//������������ĸ߶�
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);

	//�����ȸ�
	if (maxlen < left + right)
		maxlen = left + right;

	//�������ȸߣ�Ҫ��ͬһ�����������Զ����,���õݹ�
	MAXLEN(pRoot->_pLeft, maxlen);
	MAXLEN(pRoot->_pRight, maxlen);
	return maxlen;
}



int GetKLevel(PBTNode pRoot, int K)//��k��Ľ�������
{
	if (NULL == pRoot || K <= 0)
		return 0;

	if (1 == K)//��һ��ֻ�и��ڵ�
		return 1;

	return GetKLevel(pRoot->_pLeft, K - 1) + GetKLevel(pRoot->_pRight, K - 1);
}

void LevelOrder(PBTNode pRoot)//�������������
{
	Queue q;
	PBTNode pCur = NULL;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);//�Ƚ�������������У�

	while (!QueueEmpty(&q))
	{
		pCur = QueueFront(&q);//ȡ��ͷ

		printf("%c ", pCur->_data);//����a��Ȼ����b,Ȼ����c

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);//bҲ���뵽������

		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);//cҲ���뵽������

		QueuePop(&q);//�����У��Ƚ��ȳ�
	}

	printf("\n");
	QueueDestroy(&q);
}

void Mirror(PBTNode pRoot)//�������ľ���ݹ�
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

void Mirror(PBTNode pRoot)//�������ľ���ݹ�
{
	PBTNode pcur = pRoot;
	if (pcur == NULL || (pcur->_pLeft == NULL&&pcur->_pRight == NULL))//���ֻ�и��ڵ㣬�������ǿյ�
	{
		return;
	}
	
	//������������
	PBTNode temp = pcur->_pLeft;
	pcur->_pLeft = pcur->_pRight;
	pcur->_pRight = temp;

	Mirror(pcur->_pLeft);
	Mirror(pcur->_pRight);
	
}






void Mirror_Nor(PBTNode pRoot)//�������ľ���ǵݹ�,����
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




int IsCompleteBinTree(PBTNode pRoot)//�Ƿ�Ϊ��ȫ������
{
	Queue q;
	QueueInit(&q);
	PBTNode pcur = pRoot;
	QueuePush(&q, pcur);
	while (!QueueEmpty(&q))
	{
		pcur=QueueFront(&q);//��ȡ��ͷΪ��ǰ���
		if (pcur->_pLeft&&pcur->_pRight)//����������������ȷŵ�������
		{
			QueuePush(&q,pcur->_pLeft);
			QueuePush(&q, pcur->_pRight);
		}
		if (pcur->_pLeft == NULL&&pcur->_pRight != NULL)//��ǰ���ֻ��������û�����������򷵻�0
		{
			return 0;
		}
		if (pcur->_pLeft != NULL&&pcur->_pRight == NULL)
		{
			if (pcur->_pLeft->_pLeft != NULL || pcur->_pLeft->_pRight != NULL)//˵�������ڶ��㲻�����򷵻�0
			{
				return 0;
			}
		}
		QueuePop(&q);
		
	}
	return 1;

}
int IsBlanceBinTree(PBTNode pRoot)//�ж��Ƿ���ƽ�������
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

int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode)//���Ƿ��ڶ�������
{
	int flag = 0;
	if (NULL == pRoot || NULL == pNode)//�޽��
		return 0;

	if (pRoot == pNode)//���Ϊ���ڵ�
		return 1;

	if (flag = IsNodeInBinTree(pRoot->_pLeft, pNode))
		return flag;

	return IsNodeInBinTree(pRoot->_pRight, pNode);
}

PBTNode getcommon(PBTNode pRoot, PBTNode X1, PBTNode X2)//�������������������
{
	//���ж����е�һ������Ƿ�Ϊ���ڵ�
	if ((IsNodeInBinTree(pRoot, X1) && (pRoot == X2)) || ((IsNodeInBinTree(pRoot, X2)) && (pRoot == X1)))
	{
		return pRoot;
	}
	//������ֱ�����������
	if ((IsNodeInBinTree(pRoot->_pLeft, X1)) && (IsNodeInBinTree(pRoot->_pRight, X2)) || (IsNodeInBinTree(pRoot->_pLeft, X2)) && (IsNodeInBinTree(pRoot->_pRight, X1)))
	{
		return pRoot;
	}
	
	//������ֱ���һ������,�������ڵ����Ͻ��еݹ�
	if ((IsNodeInBinTree(pRoot->_pLeft, X1)) && (IsNodeInBinTree(pRoot->_pLeft, X2)))
	{
		return getcommon(pRoot->_pLeft,X1,X2);
	}
	if ((IsNodeInBinTree(pRoot->_pRight, X1)) && (IsNodeInBinTree(pRoot->_pRight, X2)))
	{
		return getcommon(pRoot->_pRight, X1, X2);
	}
}

PBTNode Treetolist(PBTNode pRoot, PBTNode prev)//ת��Ϊ˫������0 1 2 3 4 5 6 7 8 9 //5�Ǹ��ڵ㣬ptail��βָ��
{
	//�п�
	if (pRoot == NULL)
	{
		return;
	}
	//�������ͷ���������������ߵĽ��
	PBTNode pHead = pRoot;
	while (pHead)
	{
		pHead = pHead->_pLeft;

	}

	//��������
	//�ȶ���ߵĽ���˫�����������
	Treetolist(pRoot->_pLeft, &prev);//���������Ѿ�������˫�������������
	if (prev)
	{
		prev->_pRight = pRoot;
		pRoot->_pLeft = prev;
		prev = pRoot;
	}

	//���ұߵĽ���˫�����������
	Treetolist(pRoot->_pRight, &prev);//���������Ѿ�����˫���������,��ʱ��prev��proot


}




PBTNode Find(PBTNode pRoot, BTDataType data)
{
	PBTNode pNode = NULL;
	if (NULL == pRoot)
		return NULL;

	if (pRoot->_data == data)//����Ǹ��ڵ㣬�򷵻ظ�
		return pRoot;

	if (pNode = Find(pRoot->_pLeft, data)) 
		return pNode;

	return Find(pRoot->_pRight, data);
}

void PreOrderNor(PBTNode pRoot)//��������
{
#if 0
	Stack s;
	if (NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);//�����ڵ�ѹ��ջ��

	while (!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);//ȡջ��Ԫ��
		printf("%c ", pCur->_data);//��ӡ
		StackPop(&s);//��ջ��Ԫ�س�ջ

		if (pCur->_pRight)//��ѹ���ҽ��
			StackPush(&s, pCur->_pRight);

		if (pCur->_pLeft)//��ѹ������
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

void InOrderNor(PBTNode pRoot)//�����������ջ,������
{
	Stack s;
	PBTNode pCur = pRoot;
	if (NULL == pRoot)
		return;

	StackInit(&s);

	while (pCur || !StackEmpty(&s))
	{
		// 1. �ҵ�ǰ���������Ľ�㲢��������·���е����нڵ�
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


void PostOrderNor(PBTNode pRoot)//������
{
	Stack s;
	PBTNode pCur = pRoot;
	PBTNode pTop = NULL;

	// ��¼������ʹ��Ľ��
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
		if (NULL == pTop->_pRight || pTop->_pRight == pPrev)//�˴�������жϣ����ظ�������ҽ��λ��
			//�ڴ˴���Ϊa ���ұ߲�Ϊ�գ������Ȳ���ӡa
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
		printf("����ȫ������!\n");
	else
		printf("������ȫ������!\n");

	Mirror(pRoot);
	Mirror_Nor(pRoot);
	LevelOrder(pRoot);

	printf("�������н��ĸ�����%d\n", Size(pRoot));
	printf("��������Ҷ�ӽ��ĸ�����%d\n", GetLeafCount(pRoot));
	printf("�������ĸ߶ȣ�%d\n", Height(pRoot));
	printf("��������%d��������%d\n", 3, GetKLevel(pRoot, 3));

	pNewRoot = CopyBinTree(pRoot);

	DestroyBinTree(&pRoot);
	DestroyBinTree(&pNewRoot);
}
