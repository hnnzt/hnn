#include "seqlist.h"
void InitSeqlist(pseqlist pseq)//初始化顺序表
{
	assert(pseq);
	pseq->size = 0;

}

void PrintSeqlist(pseqlist pseq)//打印顺序表
{
	assert(pseq);
	size_t i = 0;
	if ((pseq->size) == 0)
	{
		printf("已经为空");
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

int Find(pseqlist pseq, DataType data)//查找元素
{
	assert(pseq);
	if ((pseq->size) == 0)
	{
		printf("已经为空");
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


void PushBack(pseqlist pseq, DataType data)//尾插
{
	assert(pseq);//判断指针是否为空
	if ((pseq->size) >= max_size)//
	{
		printf("已经存满");
		return;
	}
	else
	{
		pseq->arr[pseq->size] = data;//size的位置在顺序表有效元素的后面
	}
	pseq->size++;//更新size
}


void PopBack(pseqlist pseq)//尾删
{
	assert(pseq);
	if ((pseq->size) == 0)
	{
		printf("已空");
		return;
	}
	else
	{
		pseq->size--;
		printf("删除成功");
	}
}


void PushFront(pseqlist pseq, DataType data)//头插
{
	assert(pseq);
	if ((pseq->size) >= max_size)
	{
		printf("已经存满");
		return;
	}
	else
	{
		for (int i = pseq->size; i >= 0; i--)
		{
			pseq->arr[i] = pseq->arr[i - 1];//将元素整体后移，空出arr[0]的位置
			pseq->arr[0] = data;
		}
		pseq->size++;
	}
}


void PopFront(pseqlist pseq)//头删
{
	assert(pseq);
	if (pseq->size == 0)
	{
		printf("已空");
		return;
	}
	else
	{
		for (int i = pseq->size - 1; i >0; i--)
		{
			pseq->arr[i - 1] = pseq->arr[i];//将整体前移
		}
		pseq->size--;
		printf("删除成功");
	}
}


void Insert(pseqlist pseq, int pos, DataType data)//从任意位置插入
{
	assert(pseq);//1.判断指针是否为空
	if ((pseq->size) >= max_size)//2.判断是否为满
	{
		printf("已经存满");
		return;
	}
	if (pos < 0 || pseq->size < pos)//3.判断位置是否非法
	{
		printf("位置非法");
		return;
	}
	else
	{
		for (int i = pseq->size - 1; i >= pos; --i)
		{
			pseq->arr[i + 1] = pseq->arr[i];//将pos以及pos位置以后的后移
			pseq->arr[pos - 1] = data;//腾出的位置放要插入的数据
		}
		pseq->size++;
	}
}



void Erase(pseqlist pseq, int pos)//从任意位置的删除数据
{
	assert(pseq);//1.判断指针是否为空
	if ((pseq->size) == 0)//2.判断是否为空
	{
		printf("已空");
		return;
	}
	if (pos < 0 || pseq->size < pos)//3.判断位置是否非法
	{
		printf("位置非法");
		return;
	}
	else
	{
		for (int i = pos - 1; i<pseq->size - 1; i++)
		{
			pseq->arr[i] = pseq->arr[i + 1];//从最后一个元素开始到pos的位置进行前移
		}
		pseq->size--;
	}
}


void Remove(pseqlist pseq, DataType data)//删除第一个为data的元素
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
		printf("已删除\n");
		return;
	}
	else
	{
		printf("没有找到该元素");
		return;
	}
}



void RemoveAll(pseqlist pseq, DataType data)//删除所有位置的data
{
	assert(pseq);
	int pos = Find(pseq, data);
	while (-1 != pos)
	{
		Erase(pseq, pos);
		pos++;
	}
}//时间复杂度高

void RemoveAll1(pseqlist pseq, DataType data)
{
	assert(pseq);
	int count = 0;
	int i = 0;
	DataType *ptmp = (DataType *)malloc(sizeof(DataType)*(pseq->size));//开辟一段空间,ptmp指向这段空间

	for (i = 0; i < pseq->size; i++)
	{
		if (pseq->arr[i] != data)
		{
			ptmp[count++] = pseq->arr[i];//将不是data数据的放入已经开辟好的空间中
		}


	}//空间复杂度高
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
		}//记录删除data的个数
	}
	pseq->size -= count;
}

//时间复杂度O(n),空间复杂度O(1）
int Empty(pseqlist pseq)//判空
{
	assert(pseq);
	if (pseq->size == 0)
		return true;
	else
		return false;
}

void Bubblesort(pseqlist pseq)//冒泡排序
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
void SelectSort(pseqlist pseq)//选择排序
{
	assert(pseq);
	int i = 0;
	int j = 0;
	int max = 0;
	for (i = 0; i < pseq->size - 1; i++)//假如size为10，只用比较9趟，所以是0到8
	{
		max = 0;
		for (j = 1; j < pseq->size - i; j++)//当i为8时，内部只需要比较1次，
		{
			if (pseq->arr[j]>pseq->arr[max])
				max = j;
		}
	}
	//更新max,假设序列为0 9 1 2 3 4 5 6 7 8
	DataType tmp = pseq->arr[max];//
	pseq->arr[max] = pseq->arr[pseq->size - i - 1];//第一趟结束，将倒数第一个数赋值给max
	pseq->arr[pseq->size - i - 1] = tmp;//将9放到最后



}










