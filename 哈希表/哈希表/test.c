#include"HT.h"

int main()
{
	HT ht;
	int capacity = 0;
	InitHashBucket(&ht,capacity);
	InsertHashBucketUnique(&ht, 11,1);
	InsertHashBucketUnique(&ht, 12,2);
	InsertHashBucketUnique(&ht, 22, 2);
	InsertHashBucketUnique(&ht, 67, 7);


	PrintHashBucket(&ht);
	DeleteHashBucketUnique(&ht,22);
    FindHashBucket(& ht, 67);
	FindHashBucket(&ht, 78);

}






