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
void InitBitMap(BitMap* bmp, size_t size);
void Set(BitMap* bmp, size_t which);
int Test(BitMap* bmp, size_t which);//�����Ƿ����
void DestroyBitMap(BitMap* bmp);//����λͼ
