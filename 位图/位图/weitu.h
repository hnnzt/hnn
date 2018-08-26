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

void InitBitMap(BitMap* bmp, size_t capacity);
// 置为1
void Set(BitMap* bmp, size_t which);
// 置为0
void ReSet(BitMap* bmp, size_t which);

// 检测某个比特位是否为1
int Test(BitMap* bmp, size_t which);

size_t SizeBitMap(BitMap* bmp);

// 位图中1的个数
size_t CountBitMap(BitMap* bmp);

void DestroyBitMap(BitMap* bmp);


///////////////////////////////////////////////
void TestBitMap();