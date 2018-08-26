#include"Heap.h"

void CreateHeap(Heap* pHp, DataType arr[], int size)//创建堆
{
	pHp->_hp = (DataType*)malloc(sizeof(DataType)*(size + 3));//开辟空间
	if (NULL == pHp->_hp)
	{
		return;
	}
	pHp->_capacity = size + 3;//堆的容量
	pHp->_size = size;//堆的大小

	for (int i = 0; i < size; i++)
	{
		pHp->_hp[i] = arr[i];//把数组中元素放到堆上
	}
	
	//对堆进行调整
	int root = (size - 2) / 2;//找到倒数第一个叶子结点的根结点
	for (; root >= 0; root--)
	{
		AdjustDown(pHp, root);
	}
}

void InitHeap(Heap* pHp)//初始化堆
{
	assert(pHp);
	pHp->_hp = NULL;
	pHp->_capacity = 0;
	pHp->_size = 0;
}
void Insert(Heap* pHp, DataType data)//任意插入数据
{
	assert(pHp);
	pHp->_hp[pHp->_size++] = data;//在数组的最后一位插入元素
	if (pHp->_size>1)//如果个数为1 的话不需要调整
	AdjustUp(pHp, pHp->_size - 1);//因为插入到了最后，所以用向上调整较为方便

}

void Remove(Heap* pHp)//删除
{
	assert(pHp);
	if (EmptyHeap(pHp))
	{
		return;
	}
	Swap(pHp->_hp[0], pHp->_hp[pHp->_size - 1]);//相当于删除了最后一个结点，不影响堆的结构

	pHp->_size--;
	AdjustDown(pHp, pHp->_hp[0]);//因为是整体都要调整，所以用向下调整比较方便
}


int EmptyHeap(Heap* pHp)//判空
{
	assert(pHp);
	if (NULL == pHp->_hp)
	{
		return 1;
	}
	return 0;
}
int SizeHeap(Heap* pHp)//大小
{
	return pHp->_size;
}


void AdjustDown(Heap* pHp, int Root)//向下调整最小堆，上面小，下面大
{
	int parent = 0;
	int child = 2 * parent + 1;
	while (child < pHp->_size)
	{
		if (pHp->_hp[child] >pHp->_hp[child + 1])//选出一个更小的
		{
			child = child + 1;//右结点更小
		}
		if (pHp->_hp[parent] > pHp->_hp[child])//如果双亲结点更大，则换掉
		{
			Swap(pHp->_hp[parent], pHp->_hp[child]);
			parent = child;//parent需要向下移动位置
			child = parent * 2 + 1;//child也需要向下移动位置
		}
	}
}

void AdjustUp(Heap* pHp, int child)//向上调整，最大堆
{
	int parent = (child - 1) / 2;//先找到双亲结点
	while (parent > 0)
	{
		if (pHp->_hp[parent] < pHp->_hp[child])//如果双亲结点小于孩子结点，向下放
		{
			Swap(pHp->_hp[parent], pHp->_hp[child]);
			child = parent;//向上调整需要的是child,所以要更新child
			parent = (child - 1) / 2;//顺便算出双亲结点
		}
	}
}
DataType Top(Heap* pHp)//找出堆顶元素
{
	return pHp->_hp[0];
}
void CheckCapacity(Heap* pHp)//扩容，改变容量，开辟新的空间
{
	assert(pHp);
	int newcap = pHp->_capacity * 2;//扩容
	if (pHp->_size > pHp->_capacity)
	{
		DataType *pnewcap = (DataType*)malloc(sizeof(pHp->_capacity) * 2);
		assert(pnewcap);
		memcpy(pnewcap, pHp->_hp, pHp->_size*sizeof(DataType));//把原来的堆拷贝到新的空间里
		free(pHp->_hp);//释放掉旧的空间
    }
	pHp->_capacity = newcap;
	
}
void Swap(int left, int right)
{
	int t = left;
	left = right;
	right = t;
}

void HeapSort(Heap* pHp, int size)//堆排序
{
	int end = size - 1;
	int root = (end-1) / 2;
	for (; root >= 0; root--)//只需要双亲结点，就可以进行向下调整
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


