#include "seqlist.h"
void InitSeqlist(pseqlist pseq)//��ʼ��˳���
{
	assert(pseq);
	pseq->size = 0;

}

void PrintSeqlist(pseqlist pseq)//��ӡ˳���
{
	assert(pseq);
	size_t i = 0;
	if ((pseq->size) == 0)
	{
		printf("�Ѿ�Ϊ��");
		return;
	}
	else
	{
		for (i = 0; i < pseq->size; i++)
		{
			printf("%d->", pseq->arr[pseq->size]);

		}
		printf("\n");
	}
}

int Find(pseqlist pseq, DataType data)//����Ԫ��
{
	assert(pseq);
	if ((pseq->size) == 0)
	{
		printf("�Ѿ�Ϊ��");
		return 0;
	}
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[pseq->size] == data)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}


void PushBack(pseqlist pseq, DataType data)//β��
{
	assert(pseq);//�ж�ָ���Ƿ�Ϊ��
	if ((pseq->size) >= max_size)//
	{
		printf("�Ѿ�����");
		return;
	}
	else
	{
		pseq->arr[pseq->size] = data;//size��λ����˳�����ЧԪ�صĺ���
	}
	pseq->size++;//����size
}


void PopBack(pseqlist pseq)//βɾ
{
	assert(pseq);
	if ((pseq->size) == 0)
	{
		printf("�ѿ�");
		return;
	}
	else
	{
		pseq->size--;
		printf("ɾ���ɹ�");
	}
}


void PushFront(pseqlist pseq, DataType data)//ͷ��
{
	assert(pseq);
	if ((pseq->size) >= max_size)
	{
		printf("�Ѿ�����");
		return;
	}
	else
	{
		for (int i = pseq->size; i >= 0; i--)
		{
			pseq->arr[i] = pseq->arr[i - 1];//��Ԫ��������ƣ��ճ�arr[0]��λ��
			pseq->arr[0] = data;
		}
		pseq->size++;
	}
}


void PopFront(pseqlist pseq)//ͷɾ
{
	assert(pseq);
	if (pseq->size == 0)
	{
		printf("�ѿ�");
		return;
	}
	else
	{
		for (int i = pseq->size - 1; i >0; i--)
		{
			pseq->arr[i - 1] = pseq->arr[i];//������ǰ��
		}
		pseq->size--;
		printf("ɾ���ɹ�");
	}
}


void Insert(pseqlist pseq, int pos, DataType data)//������λ�ò���
{
	assert(pseq);//1.�ж�ָ���Ƿ�Ϊ��
	if ((pseq->size) >= max_size)//2.�ж��Ƿ�Ϊ��
	{
		printf("�Ѿ�����");
		return;
	}
	if (pos < 0 || pseq->size < pos)//3.�ж�λ���Ƿ�Ƿ�
	{
		printf("λ�÷Ƿ�");
		return;
	}
	else
	{
		for (int i = pseq->size - 1; i >= pos; --i)
		{
			pseq->arr[i + 1] = pseq->arr[i];//��pos�Լ�posλ���Ժ�ĺ���
			pseq->arr[pos - 1] = data;//�ڳ���λ�÷�Ҫ���������
		}
		pseq->size++;
	}
}



void Erase(pseqlist pseq, int pos)//������λ�õ�ɾ������
{
	assert(pseq);//1.�ж�ָ���Ƿ�Ϊ��
	if ((pseq->size) == 0)//2.�ж��Ƿ�Ϊ��
	{
		printf("�ѿ�");
		return;
	}
	if (pos < 0 || pseq->size < pos)//3.�ж�λ���Ƿ�Ƿ�
	{
		printf("λ�÷Ƿ�");
		return;
	}
	else
	{
		for (int i = pos - 1; i<pseq->size - 1; i++)
		{
			pseq->arr[i] = pseq->arr[i + 1];//�����һ��Ԫ�ؿ�ʼ��pos��λ�ý���ǰ��
		}
		pseq->size--;
	}
}


void Remove(pseqlist pseq, DataType data)//ɾ����һ��Ϊdata��Ԫ��
{
	assert(pseq);
	int i = Find(pseq, data);
	if (i >= 0)
	{
		while (i < (int)pseq->size)
		{
			pseq->arr[i - 1] = pseq->arr[i];
			i++;
		}
		pseq->size--;
		printf("��ɾ��\n");
		return;
	}
	else
	{
		printf("û���ҵ���Ԫ��");
		return;
	}
}



void RemoveAll(pseqlist pseq, DataType data)//ɾ������λ�õ�data
{
	assert(pseq);
	int pos = Find(pseq, data);
	while (-1 != pos)
	{
		Erase(pseq, pos);
		pos++;
	}
}//ʱ�临�Ӷȸ�

void RemoveAll1(pseqlist pseq, DataType data)
{
	assert(pseq);
	int count = 0;
	int i = 0;
	DataType *ptmp = (DataType *)malloc(sizeof(DataType)*(pseq->size));//����һ�οռ�,ptmpָ����οռ�

	for (i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] != data)
		{
			ptmp[count++] = pseq->arr[i];//������data���ݵķ����Ѿ����ٺõĿռ���
		}


	}//�ռ临�Ӷȸ�
}







void RemoveAll2(pseqlist pseq, DataType data)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] != data)
		{
			pseq->arr[i - count] = pseq->arr[i];
		}
		else
		{
			count++;
		}//��¼ɾ��data�ĸ���
	}
	pseq->size -= count;
}

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1��
int Empty(pseqlist pseq)//�п�
{
	assert(pseq);
	if (pseq->size == 0)
		return true;
	else
		return false;
}

void Bubblesort(pseqlist pseq)//ð������
{
	assert(pseq);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < pseq->size; i++)
	{
		int flag = 0;
		for (j = 0; j < pseq->size - i; i++)
		{
			if (pseq->arr[j]>pseq->arr[j + 1])
			{
				DataType tmp = pseq->arr[j];
				pseq->arr[j] = pseq->arr[j + 1];
				pseq->arr[j + 1] = tmp;
			}
			flag = 1;
		}
	}
}
void SelectSort(pseqlist pseq)//ѡ������
{
	assert(pseq);
	int i = 0;
	int j = 0;
	int max = 0;
	for (i = 0; i < pseq->size - 1; i++)//����sizeΪ10��ֻ�ñȽ�9�ˣ�������0��8
	{
		max = 0;
		for (j = 1; j < pseq->size - i; j++)//��iΪ8ʱ���ڲ�ֻ��Ҫ�Ƚ�1�Σ�
		{
			if (pseq->arr[j]>pseq->arr[max])
				max = j;
		}
	}
	//����max,��������Ϊ0 9 1 2 3 4 5 6 7 8
	DataType tmp = pseq->arr[max];//
	pseq->arr[max] = pseq->arr[pseq->size - i - 1];//��һ�˽�������������һ������ֵ��max
	pseq->arr[pseq->size - i - 1] = tmp;//��9�ŵ����



}










