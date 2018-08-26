#pragma once
#include <malloc.h>
#include <string.h>
#include <stddef.h>


typedef unsigned long size_t;

typedef struct BitMap
{
	size_t* _bitMap;
	size_t _capacity;  // �ռ�ĸ���
	size_t _size;  // ��Ч����λ�ĸ���
}BitMap;

void InitBitMap(BitMap* bmp, size_t capacity);
// ��Ϊ1
void Set(BitMap* bmp, size_t which);
// ��Ϊ0
void ReSet(BitMap* bmp, size_t which);

// ���ĳ������λ�Ƿ�Ϊ1
int Test(BitMap* bmp, size_t which);

size_t SizeBitMap(BitMap* bmp);

// λͼ��1�ĸ���
size_t CountBitMap(BitMap* bmp);

void DestroyBitMap(BitMap* bmp);


///////////////////////////////////////////////
void TestBitMap();