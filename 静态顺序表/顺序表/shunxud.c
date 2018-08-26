#include"seqd.h"

void SeqListDInit(PSeqListD pSeq)//初始化
{
	assert(pSeq);
	pSeq->_pData = (DataType*)malloc(sizeof(DataType)*(pSeq->_capacity));
	if (pSeq->_pData == NULL)
	{
		printf("开辟空间失败");
		return;
	}
	pSeq->_size = 0;
	pSeq->_capacity = 0;
}
void SeqListDPushBack(PSeqListD pSeq, DataType  data)//尾插
{
	assert(pSeq);
	if (CheckCapacity(pSeq))
	{
		pSeq->_pData[pSeq->_size] = data;
		pSeq->_size++;
	}
	return 0;
}
void SeqListDPopBack(PSeqListD pSeq)//尾删
{
	aseert(pSeq);
	if (SeqListDEmpty(pSeq))
	{
		printf("顺序表已空\n");
		return;
	}
	pSeq->_size--;
}
int SeqListDEmpty(PSeqListD pSeq)//判空
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		return 1;
	}
	return 0;
}
int SeqListDSize(PSeqListD pSeq)//大小
{
	assert(pSeq);
	return pSeq->_size;

}
int SeqListDCapacity(PSeqListD pSeq)//获取容量
{
	assert(pSeq);
	return pSeq->_capacity;

}
void SeqListDClear(PSeqListD pSeq)//清空
{
	assert(pSeq);
	pSeq->_size = 0;
}
int CheckCapacity(PSeqListD pSeq)//扩容
{
	aseert(pSeq);
	if (pSeq->_size >= pSeq->_capacity)
	{
		int newcapacity = pSeq->_capacity * 2;
		DataType *ptemp= (DataType *)malloc(sizeof(DataType)*newcapacity);
		if (pSeq->_pData == NULL)
		{
			printf("扩容失败\n");
			return 0;
		}
		memcpy(ptemp, pSeq->_pData, sizeof(DataType)*newcapacity);
		free(pSeq->_pData);
		pSeq->_capacity = newcapacity;
		pSeq->_pData = ptemp;
	}
	return 1;

}
void SeqListDDestroy(PSeqListD pSeq)//销毁
{
	assert(pSeq);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
	free(pSeq->_pData);
	return;
}
void Insert(PSeqListD pSeq, size_t pos, DataType data)//任意插入
{
	aseert(pSeq);
	if (CheckCapacity(pSeq))
	{
		for (int i = pSeq->_size - 1; i > pos; i++)
		{
			pSeq->_pData[i + 1] = pSeq->_pData[i];
			pSeq->_size++;
		}
	}
	return 0;
}
