#include"stdio.h"
#include"malloc.h"
#include "assert.h"

typedef int DataType;

typedef struct Heap
{
	DataType* _hp;
	int _capacity; // �ռ�Ĵ�С 
	int _size; // ������ЧԪ�صĸ��� 
	
}Heap;

void CreateHeap(Heap* pHp, DataType array[], int size);//������
void InitHeap(Heap* pHp);//��ʼ����
void Insert(Heap* pHp, DataType data);//�����������
void Remove(Heap* pHp);//ɾ��
int EmptyHeap(Heap* pHp);//�п�
int SizeHeap(Heap* pHp);//��С
void AdjustDown(Heap* pHp, int Root);//���µ���
void AdjustUp(Heap* pHp, int child);//���ϵ���
DataType Top(Heap* pHp);//�ҳ��Ѷ�Ԫ��
void CheckCapacity(Heap* pHp);//����
void HeapSort(Heap* pHp,int size);//������
void Swap(int left, int right);

