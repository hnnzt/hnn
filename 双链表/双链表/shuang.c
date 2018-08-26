#include"shuang.h"

typedef struct DCLNode
{
	struct DCLNode* _pNext;//��һ�����
	struct DCLNode* _pPre;//ǰһ�����
	DataType _data;//��ǰ��������
}Node, *PNode;

PNode DCLBuyNode(DataType data)//����һ���µĽ��
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



void DCLInit(PNode* ppHead)//˫����ĳ�ʼ��
{
	assert(ppHead);
	*ppHead = DCLBuyNode(0);
	(*ppHead)->_pPre == NULL;
	(*ppHead)->_pNext = NULL;
}
void DCLPushBack(PNode pHead, DataType data)//β��
{
	assert(pHead);
	PNode pcur = NULL;//���һ������pnext
	PNode newnode = DCLBuyNode(data);

	pcur = pHead->_pPre;
	pcur->_pNext = newnode->_pPre;
	newnode->_pPre = pcur;
	newnode->_pNext = pHead;
	pHead->_pPre = newnode;
}

void DCLPopBack(PNode pHead)//βɾ
{
	assert(pHead);
	if (pHead->_pNext == pHead)//ֻ��һ���ڵ�
	{
		return;
	}
	PNode pdel = pHead->_pPre->_pPre;//Ҫɾ���Ľ��
	free(pdel);//�ͷ���֮�����һ���ڵ����֮ǰ�ĵ����ڶ���
	pdel->_pNext = pHead;
	pHead->_pPre = pdel;
}

void DCLPushFront(PNode pHead, DataType data)//ͷ��
{
	assert(pHead);
	PNode newnode = DCLBuyNode(data);
	
	newnode->_pNext = pHead->_pPre;
	pHead->_pPre = newnode->_pNext;

	pHead->_pPre->_pNext = newnode;
	newnode->_pPre = pHead->_pPre;
}
void DCLPopFront(PNode pHead)//ͷɾ
{

	assert(pHead);
	if (pHead->_pNext == pHead)//Ϊ��
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
void DCLInsert(PNode pos, DataType data)//��posǰ����һ���ڵ�
{
	PNode newnode = DCLBuyNode(data);
	newnode->_pNext = pos;
	pos->_pPre->_pNext = newnode;
	pos->_pPre = newnode;
	newnode->_pPre = pos->_pPre;
}
void DCLErase(PNode pos)//POSλ�õ�ɾ��
{
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);


}
void DCLDestroy(PNode* ppHead)//����,Ҫ��һ��ָ�������pdel
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
PNode DCLFind(PNode pHead, DataType data)//�ж�һ���ڵ����ĸ�λ��
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




