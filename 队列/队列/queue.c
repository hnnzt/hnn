#include"queue.h"


typedef struct Queue
{
	DataType _array[MAX_SIZE];//Ԫ�ص�����
	int _front;//��һ��Ԫ��
	int _back;//���һ��Ԫ�ص���һ��
	int _count;//�����е���ЧԪ�صĸ���
}Queue;

void QueueInit(Queue* q)//���еĳ�ʼ��
{
	assert(q);
	q->_front = 0;
	q->_back = 0;
	q->_count = 0;
}
void QueuePush(Queue* q, DataType data)//�����
{
	assert(q);
	if (q->_front == q->_back)
	{
		printf("��������\n");
		return;
	}
	q->_array[q->_back] = data;//����backָ���λ��
	q->_back = (q->_back + 1) % MAX_SIZE;//Ȼ�����back����һ��λ��
	q->_count++;

}


void QueuePop(Queue* q)//������
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("�����ѿ�\n");
		return;
	}
	q->_front = (q->_front + 1) % MAX_SIZE;//front����һ��λ��
	q->_count--;
}

int QueueEmpty(Queue* q)//�п�
{
	assert(q);
	if (q->_front == q->_back)
	{
		return 1;
	}

}
int QueueSize(Queue* q)//�����е�Ԫ�ظ���
{
	assert(q);
	return q->_count;

}
DataType QueueFront(Queue* q)//��ͷԪ��
{
	assert(q);
	return q->_front;
	
}
DataType QueueBack(Queue* q)//��βԪ��
{
	assert(q);
	if (q->_back != 0)//˵����һ����0,�����������
	{
		return q->_array[q->_back - 1];
	}
	else//��һ����0��˵����������
	{
		return q->_array[MAX_SIZE-1];

	}
}

int Queuelen(Queue *q)//���еĳ���
{
	assert(q);
	return (q->_back - q->_front + MAX_SIZE) % MAX_SIZE;
}
