#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>


#define MAX_SIZE 8
typedef int DataType;

typedef struct Queue//ѭ������
{
	DataType _array[MAX_SIZE];//Ԫ�ص�����
	int _front;//ָ����ǰ��Ԫ��
	int _back;//ָ�����һ����ЧԪ�ص���һ��Ԫ��
	int _count;//������Ԫ�ظ���
}Queue;


void QueueInit(Queue* q);

void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
int QueueEmpty(Queue* q);
int QueueSize(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int Queuelen(Queue *q);


///////////��ʽ�Ӷ���////////////

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

typedef struct Queue
{
	PNode _pHead;//ͷ���
	PNode _pTail;//β���
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
void QueueDestroy(Queue* q);
PNode BuyNode(DataType data);



