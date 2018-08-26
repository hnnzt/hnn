
//////////////////////////��������/////////////////////////////////////////////
// ֱ�Ӳ������� ��ʱ�临�Ӷ�Ϊo(n^2),�ռ临�Ӷ�Ϊo(1),�ȶ��Խϸߣ�����ֻ�ʺϽӽ��������ݽ��ٵ����
void InsertSort(int *array, int size)  //1,7,8,10,18, 3 ��9  
{
	for (int i = 1; i < size; i++)//ֱ�Ӵ�7��ʼ��
	{
		//0~i-1�Ѿ��ź���
		int end = i - 1;//�ź�������һ����18
		int key = array[i];//Ҫ�Ƚϵ���һ����3
		while (array[end] >key&&end>0)//18>3
		{
			array[end+1]=array[end];//��Ҫ���ƣ���3�ڳ����Ժ������ıȽϵ�λ��
			end--;//��һ�����֮��Ϊ1,7,8,10,3,18  ����Ҫǰ��
	    }//��һ�ֱȽϵĽ����  1 3  7  8  10  18  9
		array[end+1] = key;//end����7֮ǰ,����Ҫ+1����3���뵽7��ǰ��
	}
	return array;
}

// ��������ʹ�ö��ֽ����Ż� 
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
// ϣ������ 

void ShellSort(int* array, int size)
{
	int gap=1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap)
	{
		for (int i = 0; i < size; i += gap)//�����Ƿ���
		{
			int end = i - gap;
			int key = array[i];
			while (array[end] < array[i] && end >= 0)//Ҳ�ǽ��бȽϣ���ǰ�ƶ�
			{
				array[end + gap] = array[end];
				end -= gap;//ÿ����Ҫ�Ƶ���gap�ļ��
			}
			array[end + gap] = key;//���Ƚϵ����ֲ����ȥ

		}
		gap--;//��С���
	}
	
}

//////////////////////////////////ѡ������/////////////////////////////////////////////////////////////
//ѡ������ԭ��Ϊ�����������У���ÿ�α����Ľ�������ıȽϣ��Ӷ��ź���
void SelectSort(int* array, int size)//����5 4 9 3 6 8 7 1 0 2 �����մӴ�С�ķ�ʽ����
{
	int maxpos = 0;
	for (int i = 0; i < size - 1; i++)//����10������ֻ��Ҫ�Ƚ�9�μ���
	{
		for (int j = i+1; j < size - i; j++)
		{
			if (array[j]>array[maxpos])
			{
				maxpos = j;
				
			}
		}
		Swap(&array[maxpos], &array[size - i]);//ѡ������֮�󣬽�����size-i������
	}
}
void SelectSort(int* array, int size)//���մ�С����ķ�ʽ����,ֻ��Ҫ����ʼ��������Ϊmin����
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


			
// ʹ��ÿ���������СԪ�ض�ѡ����������Ż� ,ʱ�临�ӶȻ�õ��Ż�
void SelectSort_OP(int* array, int size)
{
	int maxpos = size-1;
	int minpos = 0;
	for (int i = 0; i < size - 1; i++)//����10������ֻ��Ҫ�Ƚ�9�μ���
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

				Swap(&array[minpos], &array[i]);//����һ������С�Ľ��н���
			if (i = maxpos)
				maxpos = minpos;
			if (maxpos != size - 1)
				Swap(&array[maxpos], &array[size - 1]);//�����1�������Ľ��н���
         }
	}

}

// ������
void HeapSort(int* array, int size)
{
	int end = size - 1;
	int root = (end - 1) / 2;
	//����һ�����ѣ���Ϊ��ʼ�����ҵģ���һ��ɢ���������гɵ�
	for (; root >= 0; root--)//�ҵ����һ������˫�׽�㣬�Ϳ��Խ������µ���
	{

		HeapAdjust(array, size, root);
	}
	//��������
	while (end > 1)//��ɾ������һ����ʱ��˵���Ѿ��ź���
	{
		Swap(&array[0], &array[size - 1]);
		--end;//�൱��ɾ����һ�����ģ�����С�ķ���������
		HeapAdjust(array, end, 0);//���ڵ�ʼ��Ϊ���ڵ㣬ֻ�������ڱ仯
	}
}



// �ѵ��������µ��������ѵĵ���
void HeapAdjust(int* array,int size,int parent)
{
	
	int child = 2 * parent + 1;
	while (child<size)
	{

		if (array[child]<array[child + 1] && child<size)//���������ӽ�����ҳ������һ��
		{
			child = child + 1;
		}
		if (array[child] >array[parent])
		{
			Swap(&array[parent], &array[child]);//����λ��
			parent = child;//����˫�׽��ͺ��ӽ��
			child = parent * 2 + 1;
		}
	}
}



// �������� 
// ð������ 
void BubbleSort(int* array, int size)//���� 2 5 7 8 4 5 3 1
{
	for (int i = 0; i < size - 1; i++)//�����Ƚ�
	{
		for (int j = 0;j< size - 1 - i; j++)
		{
			if (array[j-1] >array[j ])//��ǰһ���Ⱥ�һ����3��1��
			{
				Swap(&array[j], &array[j +1]);//����3��1
			}
		}//һ�ֹ�����С��1 �ŵ�����ǰ��
     }// �ڶ�����Ҫ�����Ϊ�ڶ�������2 ��ʼ���Ժ�Ĳ���
}


void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
// �������� 
int Quicksort(int *array, int left, int right)
{
	int div;
	int key;
	if (left < right)
	{
		div = partion(left, right, array,key);//��һ�η�����5
	}
	
	
	Quicksort(array, left, div);//��ڶ��ֿ�ʼ���� 2   4  1  3 0 5
	Quicksort(array, div, right);//5 7 6 9 8
}

int partion(int left, int right, int *array)// 2 4 9 3 6 8 7  0 1  5
{                                           // b                  end
	int key = array[right-1];//Ϊ5
	int begin = left;//2
	int end = right - 1;//Ϊ5
	while (begin < end)
	{
		while (array[begin] <= key)//С�ķ������
		{
			begin++;//�����
		}
		while (array[end] >= key)//��ķ��ұ�
		{
			end--;//��ǰ��
		}
		Swap(&array[begin], &array[end]);//��һ�ν�����9 ��1
		
	}//��һ����������� 2  4  1 3 0  8 7 6 9  5
				//                   b end    key

	Swap(&array[begin], &array[right - 1]);//����8��5
	return begin;//����5
	// 2   4  1  3 0 5 7 6 9 8


}
// �ڿӷ� 
int partion2(int* array, int left, int right) // 2  4  1  8  3  7  5
{                                        
	int begin = left;
	int end = right;
	int key = 5;//��׼��Ϊ5
	
	while (begin < end)
	{//�����һ���ȵ�����
		while (array[begin] < key)
		{
			begin++;
		}
		array[end] = array[begin];//�����Ŀ�����ס���ճ�һ���µĿ�,��8�ŵ����һ���ӵ�λ��
		while (array[end] >= key)
		{
			end--;
		}
		array[begin] = array[end];//������ֱȻ�׼��С�ģ���������ոտճ��Ŀӣ���3�ŵ��ո�begin�ճ��Ŀ���
	}
	array[begin] = key;//����û�׼����ոյ��Ǹ���
	return begin;
}


// ǰ��ָ�� 
int partion3(int* array, int left, int right) //2 4  1  8  3  7  5
{
	int pcur = left;//��ʼ��ʱ��ָ��2��ָ����
	int prev = left - 1;//��ʼ��ʱ��ָ��-1��λ�ã�ָ��С��
	int key = 5;
	while (pcur > prev)
	{
		while (array[pcur] < key)//�����keyС����Ҫprevָ��
		{
			Swap(&array[pcur], &array[prev]);//��2 �ŵ�-1 ��λ����
		}
		pcur++;//�����key�����������������

	}
	return prev;//��󷵻ص���prev��λ�ã�����������ֳ����������֣����еݹ�����
}




//�鲢���� 
// ��·���飬���������������ϲ���һ���������� 
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
			temp[index++] = array[begin1++];//��һ�������ָ�����
		
		}
		else
		{
			temp[index++] = array[begin2++];//�ڶ��������ָ�����
			
		}
	}
	while (begin1 < end1)//��һ��������ʣ�࣬ʣ�µĶ��Ƶ�temp��
	{
		temp[index++] = array[begin1];
	}
	while (begin2 < end2)//�ڶ�����ʣ��
	{
		temp[index++] = array[begin2];
	}
}


// �鲢���� �ݹ�ʵ�� 
void MergeSrot(int* array,int left,int right)
{
	int *temp = (int*)malloc(sizeof(array[0])*(right - left));
	if (left < right)
	{

		int mid = left + (right - left) >> 1;//Ҫ�ֳ����������������
		MergeSrot(array, left, mid);
		MergeSrot(array, mid + 1, right);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(array[0])*(right - left));//��temp�е���Դ������ԭ���Ŀռ���
	}

}



// �ǱȽ����� 
// �������򣬽������ڱ�10С������
void CountSort(int* array, int size, int *c, int *output, int k)//1 7  2 7 0 2 
{
	int i;
	int j;
	for (i = 0; i < size; i++)
	{
		c[array[i]]++;//����������������2����ôc[2]=2;c[7]=2
	}
	for (i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i - 1];//��1С����һ����Ϊ0�����Դ�c[1]=c[1]+c[0]=1+1=2;
	}


	//C[7]=6��output[6-1]=7;C[6]=6-1=5;//һ����6������,��������������±���0-5,�ŵ����������֮�󣬼���ҲҪ-1
	for (i = k; i >= 0; i--)
	{
		for (j =c[i]-c[i-1]; j > 0; j--)
		{
			output[c[i] - 1] = i;
			c[i] = c[i] - 1;//����һ������

		}
	}
	
	return 1;
}
	

// ��������--�͹ؼ������� 
void RadixSortLSD(int* array, int size)//22 56 72 65 47 90 67
{
	//���ҳ�������
	int max = 0;
	int dig = 1;
	for (int i = 0; i < size; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}
	while (max > 10)//�ж��Ǽ�λ��,����22����λ��
	{
		dig++;
		max = max / 10;
	}


	//����һ����ʱ����temp��������Ĵ�С��ͬ
	int *temp = (int*)malloc(sizeof(array[0])*size);


	int mod = 10;
	int count[] = { 0 };

	for (int i = 0; i < max; i++)
	{
		//��һ�����������¼��ͬ��λ�������ݳ��ֵĴ���
		for (int j = 0; j < size; j++)
		{
			int  k = (array[j] % mod) / dig;//�ȴ����λ,22��72����2Ϊ��λ����
			count[k]++;//��ôcount[2]����ԭ����0��Ϊ2
		}
		//Ȼ��ÿ��Ͱ������ݰ�˳���ռ��𣬷ŵ�����һ��������
		for (int j= 0; j < size; j+=count[)
		{
			temp[j] = array[j]
		}
	}
}


//Ͱ����
void bucketsort(int *array, int size)//22 53 72 63 47 90 63,��Ϊ������һ���������飬���Կռ临�Ӷ�ΪO��n+k)
{
	//���ҳ�������
	int max = 0;
	int dig = 1;
	for (int i = 0; i < size; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}
	while (max > 10)//�ж��Ǽ�λ��,����22����λ��
	{
		dig++;
		max = max / 10;
	}
	while (dig)//��λ������֮�󣬻�Ҫ����ʮλ�Ͱ�λ
	{

		int count[10] = { 0 };
		//����ÿ��Ͱ�е�Ԫ�صĸ���
		for (int i = 0; i < size; i++)
		{
			count[array[i] / dig % 10]++;
		}
		//����ÿ��Ͱ����ʼ��ַ��ֻ��10��Ͱ 0-9
		int addr[10] = { 0 };
		for (int i = 0; i < 10; i++)
		{
			addr[i] = count[i - 1] + addr[i - 1];//ǰһ��Ͱ�ĵ�ַ����ǰһ��Ͱ�е�Ԫ�ظ�����
			//��addr[3]�ĵ�ַ����ǰһ��Ͱaddr[2]�ĵ�ַ����Ͱ���Ԫ��
		}

		//��Ͱ��������ռ�����
		int *bucket = (int*)malloc(sizeof(int)*size);

		for (int i = 0; i < size; i++)
		{
			bucket[addr[array[i] / dig % 10]++] = array[i];//��array�е�Ԫ�ذ���ǰ�������ŵ�bucket��
			//����Ҫ��array[2]=72,�ȼ������Ӧ���ڵ���ʼ��ַ����Ϊ��λ����2����ô������ʼ��ַ����addr[1]��ʼ��ַ����1�����Ԫ�ظ���
			//�����֮�󣬵ó���72Ӧ���ڵ�λ�ã��Ž�ȥ
		}
		dig--;
		//���bucket���鿽����ԭ�����У�Ȼ���ͷŵ�
		memcpy(array, bucket, sizeof(int)*size);
		free(bucket);
	}

}


