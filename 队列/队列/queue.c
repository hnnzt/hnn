#include"queue.h"


typedef struct Queue
{
	DataType _array[MAX_SIZE];//元素的数据
	int _front;//第一个元素
	int _back;//最后一个元素的下一个
	int _count;//队列中的有效元素的个数
}Queue;

void QueueInit(Queue* q)//队列的初始化
{
	assert(q);
	q->_front = 0;
	q->_back = 0;
	q->_count = 0;
}
void QueuePush(Queue* q, DataType data)//入队列
{
	assert(q);
	if (q->_front == q->_back)
	{
		printf("队列已满\n");
		return;
	}
	q->_array[q->_back] = data;//插入back指向的位置
	q->_back = (q->_back + 1) % MAX_SIZE;//然后计算back的下一个位置
	q->_count++;

}


void QueuePop(Queue* q)//出队列
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("队列已空\n");
		return;
	}
	q->_front = (q->_front + 1) % MAX_SIZE;//front的下一个位置
	q->_count--;
}

int QueueEmpty(Queue* q)//判空
{
	assert(q);
	if (q->_front == q->_back)
	{
		return 1;
	}

}
int QueueSize(Queue* q)//队列中的元素个数
{
	assert(q);
	return q->_count;

}
DataType QueueFront(Queue* q)//队头元素
{
	assert(q);
	return q->_front;
	
}
DataType QueueBack(Queue* q)//队尾元素
{
	assert(q);
	if (q->_back != 0)//说明下一个是0,不可再入队了
	{
		return q->_array[q->_back - 1];
	}
	else//下一个是0，说明被填满了
	{
		return q->_array[MAX_SIZE-1];

	}
}

int Queuelen(Queue *q)//队列的长度
{
	assert(q);
	return (q->_back - q->_front + MAX_SIZE) % MAX_SIZE;
}
