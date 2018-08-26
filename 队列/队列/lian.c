#include"queue.h"

//链式队列,只进行头删尾插的操作

void QueueInit(Queue* q)//初始化队列
{
	assert(q);
	q->_pHead = NULL;
	q->_pTail = NULL;
}
void QueuePush(Queue* q, DataType data)//入队列,尾插
{
	assert(q);
	PNode newnode = BuyNode(data);
	q->_pTail->_pNext = newnode;
	q->_pTail = newnode;

}
void QueuePop(Queue* q)//出队列，头删
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
int QueueSize(Queue* q)//有效元素的个数
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

DataType QueueFront(Queue* q)//队头元素
{
	assert(q);
	if (q->_pHead == NULL)
	{
		return;
	}
	return q->_pHead->_data;
}
DataType QueueBack(Queue* q)//队尾元素
{
	assert(q);
	if (q->_pHead)
	{
		return;
	}
	return q->_pTail->_data;
	
}
void QueueDestroy(Queue* q)//销毁队列
{
	assert(q);
	PNode pcur = q->_pHead;
	while (pcur)//销毁每一个结点，然后释放，指针指向空
	{
		q->_pHead = pcur->_pNext;
		free(pcur);
		pcur = q->_pHead;
	}
	q->_pTail = NULL;
}
PNode BuyNode(DataType data)//创建新节点
{
	PNode newnode = (PNode*)malloc(sizeof(Node));
	newnode->_data = data;
	newnode->_pNext = NULL;
	return newnode;
}