#include"linklist.h"


typedef struct SListNode
{
	DataType _data;//��������
	struct SListNode* _pNext; // ָ����һ������ָ�� 
}Node, *PNode;


// �������,����ʼ��
PNode BuySListNode(DataType data)
{
	PNode node = (PNode*)malloc(sizeof(node));//����һ���µĽ��
	node->_data = data;
	node->_pNext = NULL;
	return node;
}

// β�� 
void SListPushBack(PNode*ppHead, DataType data)//1->2->3->4->NULL
{
	assert(ppHead);
	if (*ppHead==NULL)
	{
		BuySListNode(data);
	}
	else
	{
		PNode pcur = *ppHead;//���Ҫ�����ָ��
		while (pcur->_pNext)
		{
			pcur = pcur->_pNext;
		}//��ǰָ��Ľ���Ϊ4
		pcur->_pNext = BuySListNode(data);
	}
}

// βɾ 
void SListPopBack(PNode* ppHead)
{
	assert(ppHead);
	PNode prev = NULL;
	PNode pcur = *ppHead;
	if (ppHead == NULL)
	{
		printf("�������ѿ�\n");
		return;
	}
	else if (pcur->_pNext == NULL)//ֻ��ͷ���
	{
		free(pcur);
		pcur = NULL;
	}
	else
	{
		while (pcur->_pNext)//���統ǰ�Ľ��Ϊ3����һ����4
		{
			prev = pcur;//prevָ��3
			pcur = pcur->_pNext;//��ǰ���Ϊ4
		}
		prev->_pNext = NULL;//3ָ���
		free(pcur);//�ͷ�4�Ŀռ�
		pcur = NULL;
	}

}

// ͷ�� 
void SListPushFront(PNode*ppHead, DataType data)
{
	assert(ppHead);
	PNode newnode=BuySListNode(data);
	newnode->_pNext = *ppHead;
}

// ͷɾ 
void SListPopFront(PNode* ppHead)
{
	assert(ppHead);
	while (ppHead == NULL)
	{
		printf("�������ѿ�\n");
		return;
	}
	PNode pdel = *ppHead;
	*ppHead = (*ppHead)->_pNext;
	free(pdel);
}

// �������в���Ԫ��data�����ظý���������е�λ�� 
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
// data������pos֮ǰ 
void SListInsert(PNode* ppHead, PNode pos, DataType data)//1->2->3->4->5->NULL,��4֮ǰ����0
{
	assert(ppHead);
	PNode pcur = *ppHead;
	PNode newnode = (DataType*)malloc(sizeof(DataType));
	if (pos == pcur)//��ͷ��
	{
		SListPushFront(ppHead, data);
	}
	else if (pcur->_pNext!=pos)//���ǵĻ�������
	{
		pcur = pcur->_pNext;
	}
	else
	{
		pcur->_pNext = newnode;//3ָ���½ڵ�0
		newnode->_pNext = pos;//0ָ��4
	}
}


// ɾ��������posλ�õĽ�� 
void SListErase(PNode* ppHead, PNode pos)
{
	assert(ppHead);
	PNode pdel = *ppHead;
	PNode prev = NULL;
	if (Empty(ppHead))
	{
		printf("��Ϊ��");
		return;
	}
	if (pos==ppHead)//Ҫɾ������ͷ���
	{
		SListPopFront(ppHead);
	}
	else//Ҫɾ���Ĳ���ͷ���
	{
		while (pdel)
		{
			if (pdel->_pNext == pos)//�����ǰ������һ����Ҫɾ����
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

// ��ȡ�����н��ĸ��� 
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

// �ж������Ƿ�Ϊ�գ���Ϊ�գ�����true�����򷵻�false 
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

// ���ٵ����� 
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
void SListDestroy2(PNode* ppHead)//��������
{
	assert(ppHead);
	if (*ppHead)
	{
		SListDestroy2((*ppHead)->_pNext);
		free(ppHead);
	}
	*ppHead = NULL;
}



// ��ӡ������ 
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






