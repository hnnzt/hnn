#include"stdio.h"
#include "assert.h"
#include "malloc.h"
#include"string.h"
#include "windows.h"

#ifndef _SEQLIST_H__
#define _SEQLIST_H__

#define max_size 10
typedef int DataType;//��int�����¶���һ������
typedef struct seqlist
{
	DataType arr[max_size];//�������ɵ�Ԫ�ظ���
	int size;//��ЧԪ�ظ���
}seqlist, *pseqlist;//seqlistΪ�µ����ͣ�pseqlistΪָ�������͵�ָ��;

typedef enum status{ true, false }status;//����һ��ö��


void InitSeqlist(pseqlist pseq);//��ʼ��
void PrintSeqlist(pseqlist pseq);//���
int Find(pseqlist pseq, DataType data);//����
void PushBack(pseqlist pseq, DataType data);//β��
void PopBack(pseqlist pseq);//βɾ
void PushFront(pseqlist pseq, DataType data);//ͷ��
void PopFront(pseqlist pseq);//ͷɾ
void Insert(pseqlist pseq, int pos, DataType data);//����λ�ò���
void Erase(pseqlist pseq, int pos);//����λ��ɾ��
void Remove(pseqlist pseq, DataType data);//ɾ����һ��Ϊdata������
//void RemoveAll(pseqlist pseq, DataType data);//ɾ������Ϊdata ������
void RemoveAll1(pseqlist pseq, DataType data);//�Ľ�֮��
void RemoveAll2(pseqlist pseq, DataType data);
int Empty(pseqlist pseq);//�п�
void Bubblesort(pseqlist pseq);//ð������
void SelectSort(pseqlist pseq);//ѡ������

#endif _SEQLIST_H__
