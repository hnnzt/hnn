#pragma once
#include"weitu.h"
#include"common.h"



typedef char* DataType;
typedef size_t(*PHF)(DataType);
#define FUNCNUM 5

typedef struct BloomFilter
{
	BitMap _bmp;//λͼ
	PHF _HashFunc[FUNCNUM];//��ϣ�㷨
	size_t _size;//��Ч�ı���λ
}BF;

void InitBloomFilter(BF* bf, PHF hashFunc[FUNCNUM], size_t size)//��ʼ��
{
	int i = 0;
	if (NULL == bf)
		return;

	InitBitMap(&bf->_bmp, size);//��ʼ��λͼ

	for (; i < FUNCNUM; ++i)//���ֳ����Ĺ�ϣ�㷨����¡��
		bf->_HashFunc[i] = hashFunc[i];

	bf->_size = 0;
}

int InsertBF(BF* bf, DataType key)
{
	if (bf==NULL)
	{
		return;
	}
	size_t bit[FUNCNUM];
	//ͨ����ϣ�㷨����±�,��Ӧ�ı���λ�±�,�������㷨���������֣�����Ҳ����ȵ�
	for (int i = 0; i < FUNCNUM; i++)
	{
		bit[i] = bf->_HashFunc[i](key) % bf->_size;
	}
	//Ȼ����λͼ�Ĳ��룬�������λͼ��
	for (int i = 0; i < FUNCNUM; i++)
	{
		Set(&bf->_bmp, bit[i]);
	}
	bf->_size++;
	return 1;
}

int IsInBloomFilter(BF* bf, DataType key)//һ���ַ����Ƿ����
{
	if (bf == NULL)
	{
		return;
	}
	size_t bit[FUNCNUM];//�������ĸ�����λ
	for (int i = 0; i < FUNCNUM; i++)
	{
		bit[i] = bf->_HashFunc[i](key) % bf->_size;
	}
	for (int i = 0; i < FUNCNUM; i++)
	{
		if (Test(&bf->_bmp, bit[i]))
		{
			return 1;
		}
	}

}
void DestroyBloomFilter(BF* bf)//���ٹ�����
{
	if (bf == NULL)
	{
		return;
	}
	DestroyBitMap(&bf->_bmp);

}
