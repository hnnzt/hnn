#include"stdio.h"
#include"assert.h"
#include"malloc.h"

typedef char* K;
typedef char* V;

typedef struct Pair
{
	K _key;
	V _value;
}Pair;


typedef (*phf)(int);
typedef struct Node
{
	struct Node* _pNext;
	Pair _data;
}Node, *PNode;


typedef struct HashTable
{
	PNode* table;//指向表的结点的指针
	unsigned long capacity;//容量
	unsigned long size;//大小
	
}HT;


#define _PrimeSize  28      

static const unsigned long _PrimeList[_PrimeSize] =

{

	53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul, 6151ul, 12289ul,

	24593ul, 49157ul, 98317ul, 196613ul, 393241ul, 786433ul, 1572869ul,

	3145739ul, 6291469ul, 12582917ul, 25165843ul, 50331653ul, 100663319ul,

	201326611ul, 402653189ul, 805306457ul, 1610612741ul, 3221225473ul, 4294967291ul

};




////////////////////////////////////////////////////////// 
// .h 
void InitHashBucket(HT* ht, int capacity);
int InsertHashBucketUnique(HT* ht, K key, V v);//插入不同的数据
int DeleteHashBucketUnique(HT* ht, K key);

void InsertHashBucketEqual(HT* ht, K key, V v);//插入相同的数据
int DeleteHashBucketEqual(HT* ht, K key);
PNode FindHashBucket(HT* ht, K key);
int ChechCapacity(HT* ht);
void DestroyHashBucket(HT* ht);

int HashFunc(HT* ht, K key);
PNode BuyNode(K key, V value);
void PrintHashBucket(HT* ht);
unsigned long GetPrime(int data);





