#pragma once
#include <malloc.h>
#include <assert.h>
#include <stdio.h>


typedef int DataType;

typedef struct DCLNode
{
	struct DCLNode* _pNext;
	struct DCLNode* _pPre;
	DataType _data;
}Node, *PNode;

void DCLInit(PNode* ppHead);
void DCLPushBack(PNode pHead, DataType data);
void DCLPopBack(PNode pHead);
void DCLPushFront(PNode pHead, DataType data);
void DCLPopFront(PNode pHead);
void DCLInsert(PNode pos, DataType data);
void DCLErase(PNode pos);
void DCLDestroy(PNode* ppHead);
PNode DCLFind(PNode pHead, DataType data);

PNode DCLBuyNode(DataType data);
void DCLPrintList(PNode pHead);
