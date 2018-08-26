#include"weitu.h"

void InitBitMap(BitMap* bmp, size_t size)//��ʼ��λͼ
{
	if (bmp == NULL)
	{
		return;
	}
	bmp->_capacity = (size >> 5) + 1;//�ܵı���λ����32��Ȼ��ó��Ŀռ���
	bmp->_bitMap = (size_t *)malloc(sizeof(size_t)*bmp->_capacity);
	assert(bmp->_bitMap);

	memset(bmp->_bitMap, 0, sizeof(size_t)*bmp->_capacity);
}


// ��Ϊ1
void Set(BitMap* bmp, size_t which)//��ָ����λ����Ϊ1������ѵ�33 λ��Ϊ1
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
	num = which >> 5;//�ж�Ӧ����λͼ�е��ĸ�����
	int pos = which % 32;//�ж�������ĵڼ�λ
	while (bmp->_bitMap[num])
	{
		bmp->_bitMap[num] |= 1 << (num);//��posΪ��Ϊ1
	}
	
}
// ��Ϊ0
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
	num = which >> 5;//�ж�Ӧ����λͼ�е��ĸ�����
	int pos = which % 32;//�ж�������ĵڼ�λ
	while (bmp->_bitMap[num])
	{
		bmp->_bitMap[num] &= ~1 << (num);//��posΪ��Ϊ0
	}


}

// ���ĳ������λ�Ƿ�Ϊ1
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

// λͼ��1�ĸ���
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
			count += bitCount[ch & 0x0F];//��4λ
			ch >>= 4;
			count += bitCount[ch & 0x0F];//��4λ
			pos>>= 8;
			j++;
		}
	}

	return count;

}

void DestroyBitMap(BitMap* bmp)//����λͼ
{
	assert(bmp);

	frre(bmp->_bitMap);
	bmp->_capacity = 0;
	bmp->_size = 0;

}