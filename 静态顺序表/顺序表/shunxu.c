#include"seqlist.h"



void InitSeqlist(pseqlist pseq)//初始化
{
	assert(pseq);
	pseq->size = 0;
}
void PrintSeqlist(pseqlist pseq)//输出
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		printf("%d ", pseq->arr[i]);
	}
}


int Find(pseqlist pseq, DataType data)//查找
{
	assert(pseq);
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] == data)
		{
			return i;//返回它的位置
		}
	}
	return 0;
}
void PushBack(pseqlist pseq, DataType data)//尾插
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("顺序表已满!\n");
	}
	pseq->arr[pseq->size] = data;
	pseq->size++;
	
}
void PopBack(pseqlist pseq)//尾删
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("顺序表已空!\n");
	}
	pseq->size--;
}
void PushFront(pseqlist pseq, DataType data)//头插
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("顺序表已满!\n");
	}
	for (int i = pseq->size - 1; i > 0; i--)//头部后面的
	{
		pseq->arr[i+1] = pseq->arr[i];
	}
	pseq->arr[0] = data;
	pseq->size++;
	
}
void PopFront(pseqlist pseq)//头删
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("顺序表已空!\n");
	}
	for (int i = pseq->size - 1; i > 0; i--)
	{
		pseq->arr[i - 1] = pseq->arr[i];
	}
	pseq->size--;
}
void Insert(pseqlist pseq, int pos, DataType data)//任意位置插入
{
	assert(pseq);
	if (pseq->size >= max_size)
	{
		printf("顺序表已满!\n");
	}

	//检查POS的位置
	if (pos<0 || pos>max_size)
	{
		printf("位置非法!\n");
		return;
	}
	for (int i = pseq->size - 1; i > pos; i--)//pos之后的数据的变化
	{
		pseq->arr[i + 1] = pseq->arr[i];
	}
	pseq->arr[pos-1] = data;
	pseq->size++;
}
void Erase(pseqlist pseq, int pos)//任意位置删除
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("顺序表已空\n");
		return;
	}
	if (pos<0 || pos>max_size)
	{
		printf("位置非法");
		return;
	}
	for (int i = pseq->size - 1; i > pos; i--)
	{
		pseq->arr[i] = pseq->arr[i - 1];
	}
	pseq->size--;
}

void Remove(pseqlist pseq, DataType data)//删除第一个为data的数据
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("顺序表已空\n");
		return;
	}
	int pos=Find(pseq, data);
	for (int i = pseq->size - 1; i > pos; i++)
	{
		pseq->arr[i - 1] = pseq->arr[i];
	}
	pseq->size--;
}
void RemoveAll(pseqlist pseq, DataType data)//删除所有为data 的数据
{
	assert(pseq);
	if (Empty(pseq))
	{
		printf("顺序表已空\n");
		return;
	}
	int count = 0;
	for (int i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] == data)//如果找到了要删除的数据，进行处理
		{
			count++;
			pseq->arr[i] = pseq->arr[i + 1];
		}
		//没有就返回到for循环，向后移
	}
	pseq->size -= count;
}

int Empty(pseqlist pseq)//判空
{
	assert(pseq);
	if (pseq->size == 0)
	{
		return 1;
	}
	return 0;
}
void Bubblesort(pseqlist pseq)//冒泡排序
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
void SelectSort(pseqlist pseq)//选择排序
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