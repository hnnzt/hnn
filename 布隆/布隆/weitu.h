#pragma once
#include <malloc.h>
#include <string.h>
#include <stddef.h>


typedef unsigned long size_t;

typedef struct BitMap
{
	size_t* _bitMap;
	size_t _capacity;  // 空间的个数
	size_t _size;  // 有效比特位的个数
}BitMap;
void InitBitMap(BitMap* bmp, size_t size);
void Set(BitMap* bmp, size_t which);
int Test(BitMap* bmp, size_t which);//检验是否存在
void DestroyBitMap(BitMap* bmp);//销毁位图
