#include"weitu.h"

void InitBitMap(BitMap* bmp, size_t size)//初始化位图
{
	if (bmp == NULL)
	{
		return;
	}
	bmp->_capacity = (size >> 5) + 1;//总的比特位除以32，然后得出的空间数
	bmp->_bitMap = (size_t *)malloc(sizeof(size_t)*bmp->_capacity);
	assert(bmp->_bitMap);

	memset(bmp->_bitMap, 0, sizeof(size_t)*bmp->_capacity);
}


// 置为1
void Set(BitMap* bmp, size_t which)//把指定的位置置为1，例如把第33 位置为1
{
	if (bmp == NULL)
	{
		return;
	}
	int num= 0;
	if (which > bmp->_size)
	{
		return;
	}
	num = which >> 5;//判断应该在位图中的哪个组里
	int pos = which % 32;//判断在组里的第几位
	while (bmp->_bitMap[num])
	{
		bmp->_bitMap[num] |= 1 << (num);//将pos为置为1
	}
	
}
// 置为0
void ReSet(BitMap* bmp, size_t which)
{
	if (bmp == NULL)
	{
		return;
	}
	int num = 0;
	if (which > bmp->_size)
	{
		return;
	}
	num = which >> 5;//判断应该在位图中的哪个组里
	int pos = which % 32;//判断在组里的第几位
	while (bmp->_bitMap[num])
	{
		bmp->_bitMap[num] &= ~1 << (num);//将pos为置为0
	}


}

// 检测某个比特位是否为1
int Test(BitMap* bmp, size_t which)
{
	if (bmp == NULL)
	{
		return;
	}
	int num = which >> 5;
	int pos = which % 32;

	bmp->_bitMap[num] & (1 << pos);
}

size_t SizeBitMap(BitMap* bmp)
{
	if (bmp == NULL)
	{
		return;
	}
	return bmp->_size;
}

// 位图中1的个数
size_t CountBitMap(BitMap* bmp)
{
	if (bmp == NULL)
	{
		return 0;
	}
	size_t i = 0;
	size_t j = 0;
	size_t count = 0;
	size_t pos;
	char* bitCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";


	for (; i < bmp->_capacity; ++i)
	{
		j = 0;
		pos = bmp->_bitMap[i];
		while (j < 4)
		{
			char ch = pos;
			count += bitCount[ch & 0x0F];//低4位
			ch >>= 4;
			count += bitCount[ch & 0x0F];//高4位
			pos>>= 8;
			j++;
		}
	}

	return count;

}

void DestroyBitMap(BitMap* bmp)//销毁位图
{
	assert(bmp);

	frre(bmp->_bitMap);
	bmp->_capacity = 0;
	bmp->_size = 0;

}