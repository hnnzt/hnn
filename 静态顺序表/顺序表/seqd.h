#pragma once
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
// typedef struct SeqListD
// {
// 	DataType* _pData;
// 	int _size;   // ˳�������ЧԪ�صĸ���
// 	int _capacity;  // ˳����п�����Ԫ�ص����ֵ
// }SeqListD, *PSeqListD;

struct SeqListD
{
	DataType* _pData;
	int _size;   // ˳�������ЧԪ�صĸ���
	int _capacity;  // ˳����п�����Ԫ�ص����ֵ
};

typedef struct SeqListD  SeqListD;
typedef struct SeqListD*  PSeqListD;

/////////////////////////////////////////////////////////
// SeqListD.h
void SeqListDInit(struct SeqListD* pSeq);
void SeqListDPushBack(PSeqListD pSeq, DataType  data);
void SeqListDPopBack(PSeqListD pSeq);
int SeqListDEmpty(PSeqListD pSeq);
int SeqListDSize(PSeqListD pSeq);
int SeqListDCapacity(PSeqListD pSeq);
void SeqListDClear(PSeqListD pSeq);
int CheckCapacity(PSeqListD pSeq);
void SeqListDDestroy(PSeqListD pSeq);
void Insert(PSeqListD pSeq, size_t pos, DataType data);



