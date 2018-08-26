#include"seqd.h"

void SeqListDInit(PSeqListD pSeq)//��ʼ��
{
	assert(pSeq);
	pSeq->_pData = (DataType*)malloc(sizeof(DataType)*(pSeq->_capacity));
	if (pSeq->_pData == NULL)
	{
		printf("���ٿռ�ʧ��");
		return;
	}
	pSeq->_size = 0;
	pSeq->_capacity = 0;
}
void SeqListDPushBack(PSeqListD pSeq, DataType  data)//β��
{
	assert(pSeq);
	if (CheckCapacity(pSeq))
	{
		pSeq->_pData[pSeq->_size] = data;
		pSeq->_size++;
	}
	return 0;
}
void SeqListDPopBack(PSeqListD pSeq)//βɾ
{
	aseert(pSeq);
	if (SeqListDEmpty(pSeq))
	{
		printf("˳����ѿ�\n");
		return;
	}
	pSeq->_size--;
}
int SeqListDEmpty(PSeqListD pSeq)//�п�
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		return 1;
	}
	return 0;
}
int SeqListDSize(PSeqListD pSeq)//��С
{
	assert(pSeq);
	return pSeq->_size;

}
int SeqListDCapacity(PSeqListD pSeq)//��ȡ����
{
	assert(pSeq);
	return pSeq->_capacity;

}
void SeqListDClear(PSeqListD pSeq)//���
{
	assert(pSeq);
	pSeq->_size = 0;
}
int CheckCapacity(PSeqListD pSeq)//����
{
	aseert(pSeq);
	if (pSeq->_size >= pSeq->_capacity)
	{
		int newcapacity = pSeq->_capacity * 2;
		DataType *ptemp= (DataType *)malloc(sizeof(DataType)*newcapacity);
		if (pSeq->_pData == NULL)
		{
			printf("����ʧ��\n");
			return 0;
		}
		memcpy(ptemp, pSeq->_pData, sizeof(DataType)*newcapacity);
		free(pSeq->_pData);
		pSeq->_capacity = newcapacity;
		pSeq->_pData = ptemp;
	}
	return 1;

}
void SeqListDDestroy(PSeqListD pSeq)//����
{
	assert(pSeq);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
	free(pSeq->_pData);
	return;
}
void Insert(PSeqListD pSeq, size_t pos, DataType data)//�������
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
