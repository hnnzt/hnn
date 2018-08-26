#include"stdio.h"
#include "assert.h"
#include "malloc.h"
#include"string.h"
#include "windows.h"

#ifndef _SEQLIST_H__
#define _SEQLIST_H__

#define max_size 10
typedef int DataType;//将int型重新定义一个类型
typedef struct seqlist
{
	DataType arr[max_size];//最大可容纳的元素个数
	int size;//有效元素个数
}seqlist, *pseqlist;//seqlist为新的类型，pseqlist为指向新类型的指针;

typedef enum status{ true, false }status;//定义一个枚举


void InitSeqlist(pseqlist pseq);//初始化
void PrintSeqlist(pseqlist pseq);//输出
int Find(pseqlist pseq, DataType data);//查找
void PushBack(pseqlist pseq, DataType data);//尾插
void PopBack(pseqlist pseq);//尾删
void PushFront(pseqlist pseq, DataType data);//头插
void PopFront(pseqlist pseq);//头删
void Insert(pseqlist pseq, int pos, DataType data);//任意位置插入
void Erase(pseqlist pseq, int pos);//任意位置删除
void Remove(pseqlist pseq, DataType data);//删除第一个为data的数据
//void RemoveAll(pseqlist pseq, DataType data);//删除所有为data 的数据
void RemoveAll1(pseqlist pseq, DataType data);//改进之后
void RemoveAll2(pseqlist pseq, DataType data);
int Empty(pseqlist pseq);//判空
void Bubblesort(pseqlist pseq);//冒泡排序
void SelectSort(pseqlist pseq);//选择排序

#endif _SEQLIST_H__
