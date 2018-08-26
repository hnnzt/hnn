#include"Heap.h"

void CreateHeap(Heap* pHp, DataType arr[], int size)//������
{
	pHp->_hp = (DataType*)malloc(sizeof(DataType)*(size + 3));//���ٿռ�
	if (NULL == pHp->_hp)
	{
		return;
	}
	pHp->_capacity = size + 3;//�ѵ�����
	pHp->_size = size;//�ѵĴ�С

	for (int i = 0; i < size; i++)
	{
		pHp->_hp[i] = arr[i];//��������Ԫ�طŵ�����
	}
	
	//�Զѽ��е���
	int root = (size - 2) / 2;//�ҵ�������һ��Ҷ�ӽ��ĸ����
	for (; root >= 0; root--)
	{
		AdjustDown(pHp, root);
	}
}

void InitHeap(Heap* pHp)//��ʼ����
{
	assert(pHp);
	pHp->_hp = NULL;
	pHp->_capacity = 0;
	pHp->_size = 0;
}
void Insert(Heap* pHp, DataType data)//�����������
{
	assert(pHp);
	pHp->_hp[pHp->_size++] = data;//����������һλ����Ԫ��
	if (pHp->_size>1)//�������Ϊ1 �Ļ�����Ҫ����
	AdjustUp(pHp, pHp->_size - 1);//��Ϊ���뵽��������������ϵ�����Ϊ����

}

void Remove(Heap* pHp)//ɾ��
{
	assert(pHp);
	if (EmptyHeap(pHp))
	{
		return;
	}
	Swap(pHp->_hp[0], pHp->_hp[pHp->_size - 1]);//�൱��ɾ�������һ����㣬��Ӱ��ѵĽṹ

	pHp->_size--;
	AdjustDown(pHp, pHp->_hp[0]);//��Ϊ�����嶼Ҫ���������������µ����ȽϷ���
}


int EmptyHeap(Heap* pHp)//�п�
{
	assert(pHp);
	if (NULL == pHp->_hp)
	{
		return 1;
	}
	return 0;
}
int SizeHeap(Heap* pHp)//��С
{
	return pHp->_size;
}


void AdjustDown(Heap* pHp, int Root)//���µ�����С�ѣ�����С�������
{
	int parent = 0;
	int child = 2 * parent + 1;
	while (child < pHp->_size)
	{
		if (pHp->_hp[child] >pHp->_hp[child + 1])//ѡ��һ����С��
		{
			child = child + 1;//�ҽ���С
		}
		if (pHp->_hp[parent] > pHp->_hp[child])//���˫�׽������򻻵�
		{
			Swap(pHp->_hp[parent], pHp->_hp[child]);
			parent = child;//parent��Ҫ�����ƶ�λ��
			child = parent * 2 + 1;//childҲ��Ҫ�����ƶ�λ��
		}
	}
}

void AdjustUp(Heap* pHp, int child)//���ϵ���������
{
	int parent = (child - 1) / 2;//���ҵ�˫�׽��
	while (parent > 0)
	{
		if (pHp->_hp[parent] < pHp->_hp[child])//���˫�׽��С�ں��ӽ�㣬���·�
		{
			Swap(pHp->_hp[parent], pHp->_hp[child]);
			child = parent;//���ϵ�����Ҫ����child,����Ҫ����child
			parent = (child - 1) / 2;//˳�����˫�׽��
		}
	}
}
DataType Top(Heap* pHp)//�ҳ��Ѷ�Ԫ��
{
	return pHp->_hp[0];
}
void CheckCapacity(Heap* pHp)//���ݣ��ı������������µĿռ�
{
	assert(pHp);
	int newcap = pHp->_capacity * 2;//����
	if (pHp->_size > pHp->_capacity)
	{
		DataType *pnewcap = (DataType*)malloc(sizeof(pHp->_capacity) * 2);
		assert(pnewcap);
		memcpy(pnewcap, pHp->_hp, pHp->_size*sizeof(DataType));//��ԭ���Ķѿ������µĿռ���
		free(pHp->_hp);//�ͷŵ��ɵĿռ�
    }
	pHp->_capacity = newcap;
	
}
void Swap(int left, int right)
{
	int t = left;
	left = right;
	right = t;
}

void HeapSort(Heap* pHp, int size)//������
{
	int end = size - 1;
	int root = (end-1) / 2;
	for (; root >= 0; root--)//ֻ��Ҫ˫�׽�㣬�Ϳ��Խ������µ���
	{
		AdjustDown(pHp, root);
	}

	while (end > 1)
	{
		Swap(pHp->_hp[0], pHp->_hp[end]);
		--end;
		AdjustDown(pHp, pHp->_hp[0]);
		
	}

}


