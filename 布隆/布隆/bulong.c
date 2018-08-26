#pragma once
#include"weitu.h"
#include"common.h"



typedef char* DataType;
typedef size_t(*PHF)(DataType);
#define FUNCNUM 5

typedef struct BloomFilter
{
	BitMap _bmp;//位图
	PHF _HashFunc[FUNCNUM];//哈希算法
	size_t _size;//有效的比特位
}BF;

void InitBloomFilter(BF* bf, PHF hashFunc[FUNCNUM], size_t size)//初始化
{
	int i = 0;
	if (NULL == bf)
		return;

	InitBitMap(&bf->_bmp, size);//初始化位图

	for (; i < FUNCNUM; ++i)//五种常见的哈希算法给布隆器
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
	//通过哈希算法算出下标,对应的比特位下标,有五种算法，就有五种，可能也有相等的
	for (int i = 0; i < FUNCNUM; i++)
	{
		bit[i] = bf->_HashFunc[i](key) % bf->_size;
	}
	//然后按照位图的插入，将其插入位图中
	for (int i = 0; i < FUNCNUM; i++)
	{
		Set(&bf->_bmp, bit[i]);
	}
	bf->_size++;
	return 1;
}

int IsInBloomFilter(BF* bf, DataType key)//一个字符串是否存在
{
	if (bf == NULL)
	{
		return;
	}
	size_t bit[FUNCNUM];//计算在哪个比特位
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
void DestroyBloomFilter(BF* bf)//销毁过滤器
{
	if (bf == NULL)
	{
		return;
	}
	DestroyBitMap(&bf->_bmp);

}
