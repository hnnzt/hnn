#include"Treenode.h"

void CreateBinTree(PNode* pRoot, DataType* array, int size, DataType invalid)
{
	int index = 0;
	_CreateBinTree(&pRoot,  array, size, &index, '#');//#代表无效值，为空
}
void _CreateBinTree(PNode* pRoot, DataType* array, int size, int* index, DataType invalid)
{
	if (invalid != array[*index])//如果索引指向的是有效值，则
	{
		//创建根节点
		PNode pRoot = BuyNode(array[*index]);
		//创建左子树
        _CreateBinTree(&(pRoot->_pLeft), array, size, ++(*index), '#');
		//创建右子树
		_CreateBinTree(&pRoot->_pRight, array, size, ++(*index), '#');
	}
}
PNode BuyNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	assert(pNewNode);
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	pNewNode->_pParent = NULL;
	pNewNode->_data = data;
	pNewNode->_leftThread = LINK;
	pNewNode->_rightThread = LINK;

	return pNewNode;
}

void _PreOrderThd(PNode pRoot)//非递归前序线索化
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pcur)
	{
		if (pcur->_pLeft==NULL )//3的前继指向2
		{
			pcur->_pLeft = prev;
			pcur->_leftThread = THREAD;
		}

		if (prev&&prev->_pRight == NULL)
		{
			prev->_pRight=pcur;//3指向4
			prev->_rightThread = THREAD;
		}
		prev = pcur;//4是当前结点
		if (pcur->_leftThread == LINK)
		{
			_PreOrderThd(pcur->_pLeft);//4的左子树线索化
		}
		if (pcur->_rightThread == LINK)
		{
			_PreOrderThd(pcur->_pRight);//4的右子树线索化
		}
	}

}
	
void PreOrderThd(PNode pRoot)//递归前序线索化
{
	PNode *prev = NULL;
	_PreOrderThd(pRoot);
}



void _InOrderThd(PNode pRoot) // 非递归中序线索化
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pRoot)
	{
		_InOrderThd(pRoot->_pLeft);//先线索化左子树
		if (pcur->_pLeft == NULL)
		{
			pcur->_pLeft = prev;
			pcur->_leftThread = THREAD;
		}
		if (prev&&prev->_pRight == NULL)//当前结点为2，prev为3
		{
			prev->_pRight = pcur;//3的后继指向2
			prev->_rightThread = THREAD;
		}
		prev = pcur;//2为当前结点
		_InOrderThd(pcur->_pRight);//线索化2的右子树
	}
}


void InOrderThd(PNode pRoot)//递归中序线索化
{
	PNode prev = NULL;
	_InOrderThd(pRoot, &prev);
}



void _PostOrderThd(PNode pRoot)//非递归后序线索化
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pcur)
	{
		_PostOrderThd(pcur->_pLeft);
		_PostOrderThd(pcur->_pRight);

		if (pcur->_pLeft == NULL)
		{
			pcur->_leftThread = THREAD;
			pcur->_pLeft = prev;//3的前继指向空
		}
		if (prev&&prev->_pRight == NULL)//当前结点为4
		{
			prev->_pRight = pcur;//3的后继指向4
			prev->_rightThread = THREAD;
		}
		prev = pcur;
	}
}


void PostOrderThd(PNode pRoot)//递归后序线索化
{
	PNode prev = NULL;
	_PostOrderThd(pRoot, &prev);
}





void PreOrderD(PNode pRoot)//前序递归
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrderD(pRoot->_pLeft);
		PreOrderD(pRoot->_pRight);
	}
}

void PreOrder(PNode pRoot)//非递归前序，一轮过后的目的是打印3以及3后面的
{
	PNode pcur = pRoot;
	while (pcur)
	{
		while (pcur->_leftThread == LINK)//有左子树
		{
			printf("%d ", pcur->_data);//打印1,2
			pcur = pcur->_pLeft;
		}
		printf("%d", pcur->_data);//打印3

		while(pcur->_rightThread == THREAD)//接下来要打印4，寻找3的后继结点
		{
			pcur = pcur->_pRight;
			printf("%d ", pcur->_data);
		}

		if(pcur->_leftThread==LINK)//判断4的下面还有没有
		{
			pcur = pcur->_pLeft;
		}
		else
		{
			pcur = pcur->_pRight;

		}

	}

}

void InOrderD(PNode pRoot)//非递归中序，一轮过后的而目的是打印3和3后面的2
{
	PNode pCur = pRoot;

	while (pCur)
	{
		// 找最左边的结点
		while (LINK == pCur->_leftThread)//先找到3
		{
			pCur = pCur->_pLeft;
		}
		printf("%c ", pCur->_data);//打印3

		// 接下来要打印2
		while (THREAD == pCur->_rightThread)
		{
			pCur = pCur->_pRight;
			printf("%c ", pCur->_data);//打印2
		}
		
		pCur = pCur->_pRight;//指向4
	}
}




		














