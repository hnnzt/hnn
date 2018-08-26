#include"stdio.h"
#include"malloc.h"
#include "assert.h"

typedef int DataType;

typedef struct Heap
{
	DataType* _hp;
	int _capacity; // 空间的大小 
	int _size; // 堆中有效元素的个数 
	
}Heap;

void CreateHeap(Heap* pHp, DataType array[], int size);//创建堆
void InitHeap(Heap* pHp);//初始化堆
void Insert(Heap* pHp, DataType data);//任意插入数据
void Remove(Heap* pHp);//删除
int EmptyHeap(Heap* pHp);//判空
int SizeHeap(Heap* pHp);//大小
void AdjustDown(Heap* pHp, int Root);//向下调整
void AdjustUp(Heap* pHp, int child);//向上调整
DataType Top(Heap* pHp);//找出堆顶元素
void CheckCapacity(Heap* pHp);//扩容
void HeapSort(Heap* pHp,int size);//堆排序
void Swap(int left, int right);

