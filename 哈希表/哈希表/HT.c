#include"HT.h"

void InitHashBucket(HT* ht, int capacity)//初始化哈希表
{
	if (ht == NULL)
	{
		return;
	}
	//获取容量
	capacity = GetPrime(capacity);
	//获取空间
	ht->table = (PNode*)malloc(sizeof(Node)*capacity);

	//初始化哈希表数组
	for (int i = 0; i < ht->capacity; i++)
	{
		ht->table[i] = NULL;
	}

	ht->capacity = capacity;
	ht->size = 0;
}

int InsertHashBucketUnique(HT* ht, K key, V v)//插入不同的数据
{
	if (ht == NULL)
	{
		return;
	}
	//插入前先检查是否需要扩容
	ChechCapacity(&ht);
	
	//找要插入的位置
	int pos = HashFunc(ht,key );
	PNode pcur = ht->table[pos];
	while (pcur)
	{
		if (pcur->_data._key == key)//已经存在，则不需要插入
		{
			return;
		}
		else
		{
			pcur = pcur->_pNext;//如果不相等的话，挂在第一个数字后面
		}
	}
	//如果哈希表是空的,创建一个新的点
	PNode newnode = BuyNode(key, v);
	newnode->_pNext = ht->table[pos];
	ht->size++;
}

int DeleteHashBucketUnique(HT* ht, K key)//删除不同的数，没有重复的
{
	if (ht == NULL)
	{
		printf("哈希表已空\n");
		return;
	}
	//先找到要删除的结点的位置
	int pos = HashFunc(&ht, key);
	PNode pcur = ht->table[pos];
	PNode prev = NULL;
	while (pcur)
	{
		if (pcur->_data._key == key)
		{
			prev->_pNext = pcur->_pNext;//那么前一个结点的后继就指向当前的后面挂的那个元素
			free(pcur);
			ht->size--;
			return 1;//说明知道了要删除的
			break;//如果找到了就退出，因为都是不同的数
		}
		//如果不是当前结点的第一个，再往后移
		prev = pcur;
		pcur = pcur->_pNext;
	}
	return 0;


}

int DeleteHashBucketEqual(HT* ht, K key)//删除相同的数，2,22,2,2,32,4
{
	if (ht == NULL)
	{
		return;
	}
	int pos = HashFunc(&ht, key);
	PNode pcur = ht->table[pos];
	PNode prev = NULL;
	//说明一定在这个表中
	while (pcur)
	{
		if (pcur->_data._key == key)//pcur->data.key里面放很多的数据
		{
			if (pcur == ht->table[pos])//在第一个的位置
			{
				ht->table[pos] = pcur->_pNext;//把22放在第一个位置上
				free(pcur);
				pcur = ht->table[pos];
				return 1;
				ht->size--;
			}
			else
			{
				//如果当前结点的第一个，向后移
				pcur = pcur->_pNext;
				prev->_pNext = pcur->_pNext;
			}
		}
		prev = pcur;
		pcur = pcur->_pNext;
		prev->_pNext = pcur->_pNext;
			
		
	}
	return 0;
}

PNode FindHashBucket(HT* ht, K key)//查找
{
	if (ht == NULL)
	{
		return;
	}
	int pos = HashFunc(&ht, key);
	PNode pcur = ht->table[pos];
	while (pcur)
	{
		if (pcur->_data._key == key)
		{
			return 1;
		}
		pcur = pcur->_pNext;
	}
	return 0;
}



int ChechCapacity(HT* ht)//扩容
{
	if (ht == NULL)
	{
		return;
	}
	//开辟新的空间
	if (ht->size == ht->capacity)
	{
		int newcapacity = GetPrime(ht->capacity);
		PNode *newtable = (PNode*)malloc(sizeof(PNode)*newcapacity);
		if (newtable == NULL)//没有申请成功，直接返回0
		{
			return 0;
		}
		//将以前的元素搬移到到新的空间里
		for (int i = 0; i < ht->capacity; i++)
		{
			while (ht->table[i]){//先把每个桶里的元素取出来，把11取出来
				PNode pcur = ht->table[i];
				while (pcur)//放到新空间的桶中
				{
					int pos = （int）(pcur->_data._key) % newcapacity;//计算放到新空间里的桶号
					ht->table[i] = pcur->_pNext;

					//连接
					pcur->_pNext = newtable[pos];
					newtable[pos] = pcur;

					//旧表中的指针要移到下一个
					pcur = ht->table[i];
				}
			}
		}

		//释放旧的空间
		ht->table = newtable;
		ht->capacity = newcapacity;
		free(ht->table);
		return 1;
	}
	return 0;
}


void DestroyHashBucket(HT* ht)//销毁哈希表
{
	if (ht == NULL)
	{
		return;
	}
	for (int i = 0; i < ht->capacity; i++)
	{
		PNode pcur = ht->table[i];//指向每个桶的起始位置
		while (pcur)//然后删除桶里边的每个元素
		{
			ht->table[i] = pcur->_pNext;
			free(pcur);
			pcur = pcur->_pNext;
		}
	}
}


int HashFunc(HT* ht, K key)//哈希函数
{
	PNode pcur = ht->table;
	
	return (int)(pcur->_data._key) % (ht->capacity);
}
PNode BuyNode(K key, V value)//创建新节点
{
	PNode pnewnode = (PNode*)malloc(sizeof(Node));//开辟空间
	return pnewnode;
}
void PrintHashBucket(HT* ht)//打印哈希表
{
	if (ht == NULL)
	{
		return;
	}
	for (int i = 0; i < ht->capacity; i++)
	{
		PNode pcur = ht->table[i];
		while (pcur)
		{
			printf("d%,d%->", pcur->_data._key, pcur->_data._key);

		}
		printf("NULL\n");
	}
}
unsigned long GetPrime( int data)//获取容量
{
	for (int i = 0; i<_PrimeSize;i++)

	{
		if (_PrimeList[i]>data)

		{

			data = _PrimeList[i];

		}

	}

	return data;

}




