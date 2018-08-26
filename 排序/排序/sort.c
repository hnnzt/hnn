
//////////////////////////插入排序/////////////////////////////////////////////
// 直接插入排序 ，时间复杂度为o(n^2),空间复杂度为o(1),稳定性较高，但是只适合接近有序，数据较少的情况
void InsertSort(int *array, int size)  //1,7,8,10,18, 3 ，9  
{
	for (int i = 1; i < size; i++)//直接从7开始算
	{
		//0~i-1已经排好序
		int end = i - 1;//排好序的最后一个，18
		int key = array[i];//要比较的那一个，3
		while (array[end] >key&&end>0)//18>3
		{
			array[end+1]=array[end];//需要后移，给3腾出可以和其他的比较的位置
			end--;//第一次完成之后，为1,7,8,10,3,18  还需要前移
	    }//第一轮比较的结果是  1 3  7  8  10  18  9
		array[end+1] = key;//end到了7之前,则需要+1，将3插入到7的前面
	}
	return array;
}

// 插入排序使用二分进行优化 
void InsertSort_OP(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int end = i - 1;
		int key = array[i];
		int left = 0;
		int right = end;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (key < array[mid])
			{
				right = mid + 1;
			}
			else
				left = mid + 1;

		}
		array[left] = key;

	}
}
// 希尔排序 

void ShellSort(int* array, int size)
{
	int gap=1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap)
	{
		for (int i = 0; i < size; i += gap)//首先是分组
		{
			int end = i - gap;
			int key = array[i];
			while (array[end] < array[i] && end >= 0)//也是进行比较，往前移动
			{
				array[end + gap] = array[end];
				end -= gap;//每次需要移的是gap的间隔
			}
			array[end + gap] = key;//将比较的数字插入进去

		}
		gap--;//缩小间隔
	}
	
}

//////////////////////////////////选择排序/////////////////////////////////////////////////////////////
//选择排序，原理为遍历整个序列，将每次遍历的结果与最大的比较，从而排好序
void SelectSort(int* array, int size)//例：5 4 9 3 6 8 7 1 0 2 ，按照从大到小的方式排列
{
	int maxpos = 0;
	for (int i = 0; i < size - 1; i++)//若有10个数，只需要比较9次即可
	{
		for (int j = i+1; j < size - i; j++)
		{
			if (array[j]>array[maxpos])
			{
				maxpos = j;
				
			}
		}
		Swap(&array[maxpos], &array[size - i]);//选出最大的之后，将它与size-i个互换
	}
}
void SelectSort(int* array, int size)//按照从小到大的方式排列,只需要将开始的索引定为min就行
{
	int minpos= 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size - i; j++)
		{
			if (array[j]>array[minpos])
			{
				minpos = j;

			}

		}
		Swap(&array[minpos], &array[i]);
	}
}


			
// 使用每次找最大最小元素对选择排序进行优化 ,时间复杂度会得到优化
void SelectSort_OP(int* array, int size)
{
	int maxpos = size-1;
	int minpos = 0;
	for (int i = 0; i < size - 1; i++)//若有10个数，只需要比较9次即可
	{
		for (int j = i+1; j < size - i; j++)
		{
			if (array[j]>array[maxpos])
			{
				maxpos = j;
            }
			if (array[j] < array[minpos])
			{
				minpos = j;
		    }
			if (minpos != 0)

				Swap(&array[minpos], &array[i]);//将第一个和最小的进行交换
			if (i = maxpos)
				maxpos = minpos;
			if (maxpos != size - 1)
				Swap(&array[maxpos], &array[size - 1]);//将最后1个与最大的进行交换
         }
	}

}

// 堆排序
void HeapSort(int* array, int size)
{
	int end = size - 1;
	int root = (end - 1) / 2;
	//创建一个最大堆，因为开始是杂乱的，是一个散的数组排列成的
	for (; root >= 0; root--)//找到最后一个结点的双亲结点，就可以进行向下调整
	{

		HeapAdjust(array, size, root);
	}
	//进行排序
	while (end > 1)//当删除到第一个的时候说明已经排好了
	{
		Swap(&array[0], &array[size - 1]);
		--end;//相当于删除了一个最大的，将最小的放在了上面
		HeapAdjust(array, end, 0);//根节点始终为根节点，只是数量在变化
	}
}



// 堆调整，向下调整，最大堆的调整
void HeapAdjust(int* array,int size,int parent)
{
	
	int child = 2 * parent + 1;
	while (child<size)
	{

		if (array[child]<array[child + 1] && child<size)//在两个孩子结点中找出大的那一个
		{
			child = child + 1;
		}
		if (array[child] >array[parent])
		{
			Swap(&array[parent], &array[child]);//交换位置
			parent = child;//更新双亲结点和孩子结点
			child = parent * 2 + 1;
		}
	}
}



// 交换排序 
// 冒泡排序 
void BubbleSort(int* array, int size)//例： 2 5 7 8 4 5 3 1
{
	for (int i = 0; i < size - 1; i++)//遍历比较
	{
		for (int j = 0;j< size - 1 - i; j++)
		{
			if (array[j-1] >array[j ])//若前一个比后一个大，3比1大
			{
				Swap(&array[j], &array[j +1]);//交换3和1
			}
		}//一轮过后将最小的1 放到了最前面
     }// 第二轮则要排序的为第二个数字2 开始的以后的部分
}


void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
// 快速排序 
int Quicksort(int *array, int left, int right)
{
	int div;
	int key;
	if (left < right)
	{
		div = partion(left, right, array,key);//第一次返回了5
	}
	
	
	Quicksort(array, left, div);//则第二轮开始的是 2   4  1  3 0 5
	Quicksort(array, div, right);//5 7 6 9 8
}

int partion(int left, int right, int *array)// 2 4 9 3 6 8 7  0 1  5
{                                           // b                  end
	int key = array[right-1];//为5
	int begin = left;//2
	int end = right - 1;//为5
	while (begin < end)
	{
		while (array[begin] <= key)//小的放在左边
		{
			begin++;//向后移
		}
		while (array[end] >= key)//大的放右边
		{
			end--;//向前移
		}
		Swap(&array[begin], &array[end]);//第一次交换是9 和1
		
	}//第一次排序出来是 2  4  1 3 0  8 7 6 9  5
				//                   b end    key

	Swap(&array[begin], &array[right - 1]);//交换8和5
	return begin;//返回5
	// 2   4  1  3 0 5 7 6 9 8


}
// 挖坑法 
int partion2(int* array, int left, int right) // 2  4  1  8  3  7  5
{                                        
	int begin = left;
	int end = right;
	int key = 5;//基准数为5
	
	while (begin < end)
	{//将最后一个先当作坑
		while (array[begin] < key)
		{
			begin++;
		}
		array[end] = array[begin];//将最后的坑先填住，空出一个新的坑,将8放到最后一个坑的位置
		while (array[end] >= key)
		{
			end--;
		}
		array[begin] = array[end];//后面出现比基准数小的，就用它填刚刚空出的坑，把3放到刚刚begin空出的坑里
	}
	array[begin] = key;//最后用基准数填刚刚的那个坑
	return begin;
}


// 前后指针 
int partion3(int* array, int left, int right) //2 4  1  8  3  7  5
{
	int pcur = left;//开始的时候指向2，指向大的
	int prev = left - 1;//开始的时候指向-1的位置，指向小的
	int key = 5;
	while (pcur > prev)
	{
		while (array[pcur] < key)//如果比key小，需要prev指向
		{
			Swap(&array[pcur], &array[prev]);//将2 放到-1 的位置上
		}
		pcur++;//如果比key大，则不做处理，则向后移

	}
	return prev;//最后返回的是prev的位置，把整个排序分成了两个部分，进行递归排序
}




//归并排序 
// 二路并归，将两组有序的数组合并成一组有序数组 
void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = 0;
	while (begin1 < end1&&begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
		{
			temp[index++] = array[begin1++];//第一个数组的指针后移
		
		}
		else
		{
			temp[index++] = array[begin2++];//第二个数组的指针后移
			
		}
	}
	while (begin1 < end1)//第一个数组有剩余，剩下的都移到temp中
	{
		temp[index++] = array[begin1];
	}
	while (begin2 < end2)//第二组有剩余
	{
		temp[index++] = array[begin2];
	}
}


// 归并排序 递归实现 
void MergeSrot(int* array,int left,int right)
{
	int *temp = (int*)malloc(sizeof(array[0])*(right - left));
	if (left < right)
	{

		int mid = left + (right - left) >> 1;//要分成两个数组进行排序
		MergeSrot(array, left, mid);
		MergeSrot(array, mid + 1, right);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(array[0])*(right - left));//将temp中的资源拷贝到原来的空间内
	}

}



// 非比较排序 
// 计数排序，仅适用于比10小的数字
void CountSort(int* array, int size, int *c, int *output, int k)//1 7  2 7 0 2 
{
	int i;
	int j;
	for (i = 0; i < size; i++)
	{
		c[array[i]]++;//计数，比如有两个2，那么c[2]=2;c[7]=2
	}
	for (i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i - 1];//比1小的有一个，为0，所以从c[1]=c[1]+c[0]=1+1=2;
	}


	//C[7]=6，output[6-1]=7;C[6]=6-1=5;//一共有6个数字,所以输出的数组下标是0-5,放到输出数组中之后，计数也要-1
	for (i = k; i >= 0; i--)
	{
		for (j =c[i]-c[i-1]; j > 0; j--)
		{
			output[c[i] - 1] = i;
			c[i] = c[i] - 1;//减少一个计数

		}
	}
	
	return 1;
}
	

// 基数排序--低关键码优先 
void RadixSortLSD(int* array, int size)//22 56 72 65 47 90 67
{
	//先找出最大的数
	int max = 0;
	int dig = 1;
	for (int i = 0; i < size; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}
	while (max > 10)//判断是几位数,比如22是两位数
	{
		dig++;
		max = max / 10;
	}


	//开辟一个临时数组temp，与数组的大小相同
	int *temp = (int*)malloc(sizeof(array[0])*size);


	int mod = 10;
	int count[] = { 0 };

	for (int i = 0; i < max; i++)
	{
		//用一个计数数组记录相同个位数的数据出现的次数
		for (int j = 0; j < size; j++)
		{
			int  k = (array[j] % mod) / dig;//先处理低位,22和72都是2为个位数的
			count[k]++;//那么count[2]会由原来的0变为2
		}
		//然后将每个桶里的数据按顺序收集起，放到另外一个数组里
		for (int j= 0; j < size; j+=count[)
		{
			temp[j] = array[j]
		}
	}
}


//桶排序
void bucketsort(int *array, int size)//22 53 72 63 47 90 63,因为开辟了一个计数数组，所以空间复杂度为O（n+k)
{
	//先找出最大的数
	int max = 0;
	int dig = 1;
	for (int i = 0; i < size; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}
	while (max > 10)//判断是几位数,比如22是两位数
	{
		dig++;
		max = max / 10;
	}
	while (dig)//个位计算完之后，还要计算十位和百位
	{

		int count[10] = { 0 };
		//计算每个桶中的元素的个数
		for (int i = 0; i < size; i++)
		{
			count[array[i] / dig % 10]++;
		}
		//计算每个桶的起始地址，只有10个桶 0-9
		int addr[10] = { 0 };
		for (int i = 0; i < 10; i++)
		{
			addr[i] = count[i - 1] + addr[i - 1];//前一个桶的地址加上前一个桶中的元素个数，
			//即addr[3]的地址就是前一个桶addr[2]的地址加上桶里的元素
		}

		//将桶里的数据收集起来
		int *bucket = (int*)malloc(sizeof(int)*size);

		for (int i = 0; i < size; i++)
		{
			bucket[addr[array[i] / dig % 10]++] = array[i];//将array中的元素按照前面的排序放到bucket中
			//比如要放array[2]=72,先计算出它应该在的起始地址，因为个位数是2，那么它的起始地址就是addr[1]起始地址加上1里面的元素个数
			//计算好之后，得出了72应该在的位置，放进去
		}
		dig--;
		//最后将bucket数组拷贝到原数组中，然后释放掉
		memcpy(array, bucket, sizeof(int)*size);
		free(bucket);
	}

}


