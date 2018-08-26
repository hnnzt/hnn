#include"HT.h"

void InitHashBucket(HT* ht, int capacity)//��ʼ����ϣ��
{
	if (ht == NULL)
	{
		return;
	}
	//��ȡ����
	capacity = GetPrime(capacity);
	//��ȡ�ռ�
	ht->table = (PNode*)malloc(sizeof(Node)*capacity);

	//��ʼ����ϣ������
	for (int i = 0; i < ht->capacity; i++)
	{
		ht->table[i] = NULL;
	}

	ht->capacity = capacity;
	ht->size = 0;
}

int InsertHashBucketUnique(HT* ht, K key, V v)//���벻ͬ������
{
	if (ht == NULL)
	{
		return;
	}
	//����ǰ�ȼ���Ƿ���Ҫ����
	ChechCapacity(&ht);
	
	//��Ҫ�����λ��
	int pos = HashFunc(ht,key );
	PNode pcur = ht->table[pos];
	while (pcur)
	{
		if (pcur->_data._key == key)//�Ѿ����ڣ�����Ҫ����
		{
			return;
		}
		else
		{
			pcur = pcur->_pNext;//�������ȵĻ������ڵ�һ�����ֺ���
		}
	}
	//�����ϣ���ǿյ�,����һ���µĵ�
	PNode newnode = BuyNode(key, v);
	newnode->_pNext = ht->table[pos];
	ht->size++;
}

int DeleteHashBucketUnique(HT* ht, K key)//ɾ����ͬ������û���ظ���
{
	if (ht == NULL)
	{
		printf("��ϣ���ѿ�\n");
		return;
	}
	//���ҵ�Ҫɾ���Ľ���λ��
	int pos = HashFunc(&ht, key);
	PNode pcur = ht->table[pos];
	PNode prev = NULL;
	while (pcur)
	{
		if (pcur->_data._key == key)
		{
			prev->_pNext = pcur->_pNext;//��ôǰһ�����ĺ�̾�ָ��ǰ�ĺ���ҵ��Ǹ�Ԫ��
			free(pcur);
			ht->size--;
			return 1;//˵��֪����Ҫɾ����
			break;//����ҵ��˾��˳�����Ϊ���ǲ�ͬ����
		}
		//������ǵ�ǰ���ĵ�һ������������
		prev = pcur;
		pcur = pcur->_pNext;
	}
	return 0;


}

int DeleteHashBucketEqual(HT* ht, K key)//ɾ����ͬ������2,22,2,2,32,4
{
	if (ht == NULL)
	{
		return;
	}
	int pos = HashFunc(&ht, key);
	PNode pcur = ht->table[pos];
	PNode prev = NULL;
	//˵��һ�����������
	while (pcur)
	{
		if (pcur->_data._key == key)//pcur->data.key����źܶ������
		{
			if (pcur == ht->table[pos])//�ڵ�һ����λ��
			{
				ht->table[pos] = pcur->_pNext;//��22���ڵ�һ��λ����
				free(pcur);
				pcur = ht->table[pos];
				return 1;
				ht->size--;
			}
			else
			{
				//�����ǰ���ĵ�һ���������
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

PNode FindHashBucket(HT* ht, K key)//����
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



int ChechCapacity(HT* ht)//����
{
	if (ht == NULL)
	{
		return;
	}
	//�����µĿռ�
	if (ht->size == ht->capacity)
	{
		int newcapacity = GetPrime(ht->capacity);
		PNode *newtable = (PNode*)malloc(sizeof(PNode)*newcapacity);
		if (newtable == NULL)//û������ɹ���ֱ�ӷ���0
		{
			return 0;
		}
		//����ǰ��Ԫ�ذ��Ƶ����µĿռ���
		for (int i = 0; i < ht->capacity; i++)
		{
			while (ht->table[i]){//�Ȱ�ÿ��Ͱ���Ԫ��ȡ��������11ȡ����
				PNode pcur = ht->table[i];
				while (pcur)//�ŵ��¿ռ��Ͱ��
				{
					int pos = ��int��(pcur->_data._key) % newcapacity;//����ŵ��¿ռ����Ͱ��
					ht->table[i] = pcur->_pNext;

					//����
					pcur->_pNext = newtable[pos];
					newtable[pos] = pcur;

					//�ɱ��е�ָ��Ҫ�Ƶ���һ��
					pcur = ht->table[i];
				}
			}
		}

		//�ͷžɵĿռ�
		ht->table = newtable;
		ht->capacity = newcapacity;
		free(ht->table);
		return 1;
	}
	return 0;
}


void DestroyHashBucket(HT* ht)//���ٹ�ϣ��
{
	if (ht == NULL)
	{
		return;
	}
	for (int i = 0; i < ht->capacity; i++)
	{
		PNode pcur = ht->table[i];//ָ��ÿ��Ͱ����ʼλ��
		while (pcur)//Ȼ��ɾ��Ͱ��ߵ�ÿ��Ԫ��
		{
			ht->table[i] = pcur->_pNext;
			free(pcur);
			pcur = pcur->_pNext;
		}
	}
}


int HashFunc(HT* ht, K key)//��ϣ����
{
	PNode pcur = ht->table;
	
	return (int)(pcur->_data._key) % (ht->capacity);
}
PNode BuyNode(K key, V value)//�����½ڵ�
{
	PNode pnewnode = (PNode*)malloc(sizeof(Node));//���ٿռ�
	return pnewnode;
}
void PrintHashBucket(HT* ht)//��ӡ��ϣ��
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
unsigned long GetPrime( int data)//��ȡ����
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




