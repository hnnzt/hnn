#include"queue.h"

//��ʽ����,ֻ����ͷɾβ��Ĳ���

void QueueInit(Queue* q)//��ʼ������
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
void QueuePush(Queue* q, DataType data)//�����,β��
{
	assert(q);
	PNode newnode = BuyNode(data);
	q->_pTail->_pNext = newnode;
	q->_pTail = newnode;

}
void QueuePop(Queue* q)//�����У�ͷɾ
{
	assert(q);
	if (q->_pHead == NULL || q->_pHead==q->_pTail)
	{
		return;

	}
	else
	{
		PNode pcur = q->_pHead;
		q->_pHead = pcur->_pNext;
		free(pcur);
	}
}
int QueueSize(Queue* q)//��ЧԪ�صĸ���
{
	assert(q);
	if (q == NULL)
	{
		return 0;
	}
	PNode pcur = q->_pHead;
	int size = 0;
	while (pcur)
	{
		pcur = pcur->_pNext;
		size++;
	}
	return size;
}

DataType QueueFront(Queue* q)//��ͷԪ��
{
	assert(q);
	if (q->_pHead == NULL)
	{
		return;
	}
	return q->_pHead->_data;
}
DataType QueueBack(Queue* q)//��βԪ��
{
	assert(q);
	if (q->_pHead)
	{
		return;
	}
	return q->_pTail->_data;
	
}
void QueueDestroy(Queue* q)//���ٶ���
{
	assert(q);
	PNode pcur = q->_pHead;
	while (pcur)//����ÿһ����㣬Ȼ���ͷţ�ָ��ָ���
	{
		q->_pHead = pcur->_pNext;
		free(pcur);
		pcur = q->_pHead;
	}
	q->_pTail = NULL;
}
PNode BuyNode(DataType data)//�����½ڵ�
{
	PNode newnode = (PNode*)malloc(sizeof(Node));
	newnode->_data = data;
	newnode->_pNext = NULL;
	return newnode;
}