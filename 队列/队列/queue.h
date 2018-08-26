#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>


#define MAX_SIZE 8
typedef int DataType;

typedef struct Queue//循环队列
{
	DataType _array[MAX_SIZE];//元素的数据
	int _front;//指向最前的元素
	int _back;//指向最后一个有效元素的下一个元素
	int _count;//队列中元素个数
}Queue;


void QueueInit(Queue* q);

void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
int QueueEmpty(Queue* q);
int QueueSize(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int Queuelen(Queue *q);


///////////链式队队列////////////

typedef int DataType;

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

typedef struct Queue
{
	PNode _pHead;//头结点
	PNode _pTail;//尾结点
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
void QueueDestroy(Queue* q);
PNode BuyNode(DataType data);



