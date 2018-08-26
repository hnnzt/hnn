#include"linklist.h"


typedef struct SListNode
{
	DataType _data;//结点的数据
	struct SListNode* _pNext; // 指向下一个结点的指针 
}Node, *PNode;


// 创建结点,并初始化
PNode BuySListNode(DataType data)
{
	PNode node = (PNode*)malloc(sizeof(node));//创建一个新的结点
	node->_data = data;
	node->_pNext = NULL;
	return node;
}

// 尾插 
void SListPushBack(PNode*ppHead, DataType data)//1->2->3->4->NULL
{
	assert(ppHead);
	if (*ppHead==NULL)
	{
		BuySListNode(data);
	}
	else
	{
		PNode pcur = *ppHead;//标记要插入的指针
		while (pcur->_pNext)
		{
			pcur = pcur->_pNext;
		}//当前指向的结点的为4
		pcur->_pNext = BuySListNode(data);
	}
}

// 尾删 
void SListPopBack(PNode* ppHead)
{
	assert(ppHead);
	PNode prev = NULL;
	PNode pcur = *ppHead;
	if (ppHead == NULL)
	{
		printf("单链表已空\n");
		return;
	}
	else if (pcur->_pNext == NULL)//只有头结点
	{
		free(pcur);
		pcur = NULL;
	}
	else
	{
		while (pcur->_pNext)//比如当前的结点为3，下一个是4
		{
			prev = pcur;//prev指向3
			pcur = pcur->_pNext;//当前结点为4
		}
		prev->_pNext = NULL;//3指向空
		free(pcur);//释放4的空间
		pcur = NULL;
	}

}

// 头插 
void SListPushFront(PNode*ppHead, DataType data)
{
	assert(ppHead);
	PNode newnode=BuySListNode(data);
	newnode->_pNext = *ppHead;
}

// 头删 
void SListPopFront(PNode* ppHead)
{
	assert(ppHead);
	while (ppHead == NULL)
	{
		printf("单链表已空\n");
		return;
	}
	PNode pdel = *ppHead;
	*ppHead = (*ppHead)->_pNext;
	free(pdel);
}

// 在链表中查找元素data，返回该结点在链表中的位置 
PNode Find(PNode pHead, DataType data)
{
	assert(pHead);
	PNode pcur = pHead;
	while (pcur)//
	{
		if (pcur->_data == data)
		{
			return pcur;
		}
		pcur = pcur->_pNext;
	}
	return 0;
}
// data插入在pos之前 
void SListInsert(PNode* ppHead, PNode pos, DataType data)//1->2->3->4->5->NULL,在4之前插入0
{
	assert(ppHead);
	PNode pcur = *ppHead;
	PNode newnode = (DataType*)malloc(sizeof(DataType));
	if (pos == pcur)//在头部
	{
		SListPushFront(ppHead, data);
	}
	else if (pcur->_pNext!=pos)//不是的话，后移
	{
		pcur = pcur->_pNext;
	}
	else
	{
		pcur->_pNext = newnode;//3指向新节点0
		newnode->_pNext = pos;//0指向4
	}
}


// 删除链表中pos位置的结点 
void SListErase(PNode* ppHead, PNode pos)
{
	assert(ppHead);
	PNode pdel = *ppHead;
	PNode prev = NULL;
	if (Empty(ppHead))
	{
		printf("已为空");
		return;
	}
	if (pos==ppHead)//要删除的是头结点
	{
		SListPopFront(ppHead);
	}
	else//要删除的不是头结点
	{
		while (pdel)
		{
			if (pdel->_pNext == pos)//如果当前结点的下一个是要删除的
			{
				prev = pdel;
		        prev->_pNext = pos->_pNext;
				free(pos);
			}
			else
			{
				pdel = pdel->_pNext;
			}
		}
	}
}

// 获取链表中结点的个数 
size_t Size(PNode pHead)
{
	assert(pHead);
	int size = 0;
	PNode pcur = pHead;
	while (pcur)
	{
		pcur = pcur->_pNext;
		size++;
	}
	return 0;
}

// 判断链表是否为空，若为空，返回true，否则返回false 
size_t Empty(PNode pHead)
{
	assert(pHead);
	if (pHead == NULL)
	{
		return 1;
	}
	else
		return 0;
}

// 销毁单链表 
void SListDestroy(PNode* ppHead)
{
	assert(ppHead);
	PNode prev = NULL;
	PNode pcur = *ppHead;
	while (pcur)
	{
		prev = pcur;
		pcur = pcur->_pNext;
		free(prev);
	}
	*ppHead = NULL;
	
}
void SListDestroy2(PNode* ppHead)//逆向销毁
{
	assert(ppHead);
	if (*ppHead)
	{
		SListDestroy2((*ppHead)->_pNext);
		free(ppHead);
	}
	*ppHead = NULL;
}



// 打印单链表 
void SListPrint(PNode pHead)
{
	assert(pHead);
	PNode pcur = pHead;
	while (pcur)
	{
		printf("%d  ", pcur->_data);
		pcur = pcur->_pNext;
	}
	return 0;
}






