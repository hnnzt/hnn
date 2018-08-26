#include"seqlist.h"



void InitSeqlist(pseqlist pseq)//��ʼ��
{
	assert(pseq);
	pseq->size = 0;
}
void PrintSeqlist(pseqlist pseq)//���
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		printf("%d ", pseq->arr[i]);
	}
}


int Find(pseqlist pseq, DataType data)//����
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] == data)
		{
			return i;//��������λ��
		}
	}
	return 0;
}
void PushBack(pseqlist pseq, DataType data)//β��
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("˳�������!\n");
	}
	pseq->arr[pseq->size] = data;
	pseq->size++;
	
}
void PopBack(pseqlist pseq)//βɾ
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("˳����ѿ�!\n");
	}
	pseq->size--;
}
void PushFront(pseqlist pseq, DataType data)//ͷ��
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("˳�������!\n");
	}
	for (int i = pseq->size - 1; i > 0; i--)//ͷ�������
	{
		pseq->arr[i+1] = pseq->arr[i];
	}
	pseq->arr[0] = data;
	pseq->size++;
	
}
void PopFront(pseqlist pseq)//ͷɾ
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("˳����ѿ�!\n");
	}
	for (int i = pseq->size - 1; i > 0; i--)
	{
		pseq->arr[i - 1] = pseq->arr[i];
	}
	pseq->size--;
}
void Insert(pseqlist pseq, int pos, DataType data)//����λ�ò���
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("˳�������!\n");
	}

	//���POS��λ��
	if (pos<0 || pos>max_size)
	{
		printf("λ�÷Ƿ�!\n");
		return;
	}
	for (int i = pseq->size - 1; i > pos; i--)//pos֮������ݵı仯
	{
		pseq->arr[i + 1] = pseq->arr[i];
	}
	pseq->arr[pos-1] = data;
	pseq->size++;
}
void Erase(pseqlist pseq, int pos)//����λ��ɾ��
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("˳����ѿ�\n");
		return;
	}
	if (pos<0 || pos>max_size)
	{
		printf("λ�÷Ƿ�");
		return;
	}
	for (int i = pseq->size - 1; i > pos; i--)
	{
		pseq->arr[i] = pseq->arr[i - 1];
	}
	pseq->size--;
}

void Remove(pseqlist pseq, DataType data)//ɾ����һ��Ϊdata������
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("˳����ѿ�\n");
		return;
	}
	int pos=Find(pseq, data);
	for (int i = pseq->size - 1; i > pos; i++)
	{
		pseq->arr[i - 1] = pseq->arr[i];
	}
	pseq->size--;
}
void RemoveAll(pseqlist pseq, DataType data)//ɾ������Ϊdata ������
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("˳����ѿ�\n");
		return;
	}
	int count = 0;
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] == data)//����ҵ���Ҫɾ�������ݣ����д���
		{
			count++;
			pseq->arr[i] = pseq->arr[i + 1];
		}
		//û�оͷ��ص�forѭ���������
	}
	pseq->size -= count;
}

int Empty(pseqlist pseq)//�п�
{
	assert(pseq);
	if (pseq->size == 0)
	{
		return 1;
	}
	return 0;
}
void Bubblesort(pseqlist pseq)//ð������
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < pseq->size; i++)
	{
		flag = 0;
		for (j = i + 1; j < pseq->size - i; j++)
		{
			if (pseq->arr[i] > pseq->arr[j])
			{
				int flag = 1;
				int temp = pseq->arr[i];
				pseq->arr[i] = pseq->arr[j];
				pseq->arr[j] = temp;
			}
			
		}
	}

}
void SelectSort(pseqlist pseq)//ѡ������
{
	assert(pseq);
	int min = 0;
	int max = pseq->size - 1;
	for (int i = 0; i < pseq->size; i++)
	{
		for (int j = i; j<pseq->size - i; j++)
		{
			if (min > pseq->arr[j])
			{
				min = j;

			}
			if (max < pseq->arr[j])
			{
				max = j;
			}
			if (min != 0)
			{
				int temp = pseq->arr[0];
				pseq->arr[0] = pseq->arr[min];
				pseq->arr[min] = temp;
			}
			if (max != pseq->size - 1)
			{

				int temp = pseq->arr[pseq->size-1];
				pseq->arr[pseq->size-1] = pseq->arr[max];
				pseq->arr[max] = temp;
			}
		}
}