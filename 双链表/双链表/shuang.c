#include"shuang.h"

typedef struct DCLNode
{
	struct DCLNode* _pNext;//后一个结点
	struct DCLNode* _pPre;//前一个结点
	DataType _data;//当前结点的数据
}Node, *PNode;

PNode DCLBuyNode(DataType data)//创建一个新的结点
{
	PNode pnewnode = (DataType *)malloc(sizeof(DataType));
	if (pnewnode==NULL)
	{
		return;
	}
	pnewnode->_pNext = NULL;
	pnewnode->_pPre = NULL;
	pnewnode->_data = data;
}



void DCLInit(PNode* ppHead)//双链表的初始化
{
	assert(ppHead);
	*ppHead = DCLBuyNode(0);
	(*ppHead)->_pPre == NULL;
	(*ppHead)->_pNext = NULL;
}
void DCLPushBack(PNode pHead, DataType data)//尾插
{
	assert(pHead);
	PNode pcur = NULL;//最后一个结点的pnext
	PNode newnode = DCLBuyNode(data);

	pcur = pHead->_pPre;
	pcur->_pNext = newnode->_pPre;
	newnode->_pPre = pcur;
	newnode->_pNext = pHead;
	pHead->_pPre = newnode;
}

void DCLPopBack(PNode pHead)//尾删
{
	assert(pHead);
	if (pHead->_pNext == pHead)//只有一个节点
	{
		return;
	}
	PNode pdel = pHead->_pPre->_pPre;//要删除的结点
	free(pdel);//释放了之后最后一个节点就是之前的倒数第二个
	pdel->_pNext = pHead;
	pHead->_pPre = pdel;
}

void DCLPushFront(PNode pHead, DataType data)//头插
{
	assert(pHead);
	PNode newnode = DCLBuyNode(data);
	
	newnode->_pNext = pHead->_pPre;
	pHead->_pPre = newnode->_pNext;

	pHead->_pPre->_pNext = newnode;
	newnode->_pPre = pHead->_pPre;
}
void DCLPopFront(PNode pHead)//头删
{

	assert(pHead);
	if (pHead->_pNext == pHead)//为空
	{
		return;
	}
	else
	{
		PNode pDel = pHead->_pNext;
		pHead->_pNext = pDel->_pNext;
		pDel->_pNext->_pPre = pHead;
		free(pDel);

	}

}
void DCLInsert(PNode pos, DataType data)//在pos前插入一个节点
{
	PNode newnode = DCLBuyNode(data);
	newnode->_pNext = pos;
	pos->_pPre->_pNext = newnode;
	pos->_pPre = newnode;
	newnode->_pPre = pos->_pPre;
}
void DCLErase(PNode pos)//POS位置的删除
{
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);


}
void DCLDestroy(PNode* ppHead)//销毁,要有一个指针来标记pdel
{
	assert(ppHead);
	PNode pdel = NULL;
	PNode pcur = *ppHead;
	while (pcur)
	{
		pdel = pcur;
		pcur = pcur->_pNext;
		free(pdel);
	}
	free(pcur);
	*ppHead = NULL;
}
PNode DCLFind(PNode pHead, DataType data)//判断一个节点在哪个位置
{
	assert(pHead);
	PNode pcur = pHead;
	while (pcur)
	{
		if (pcur->_data == data)
		{
			return pcur;
		}
		pcur = pcur->_pNext;
	}
	return 0;

}


void DCLPrintList(PNode pHead)
{
	assert(pHead);
	PNode pcur = pHead;
	while (pcur)
	{
		printf("%d ", pcur->_data);
		pcur = pcur->_pNext;
	}
}




