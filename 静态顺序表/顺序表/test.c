#include"seqlist.h"
int main()
{
	seqlist s;
    PushBack(&s, 1);//尾插
	PushBack(&s, 2);
	PushBack(&s, 3);
	PushBack(&s, 4);
	PushBack(&s, 5);
	PrintSeqlist(&s);
    PopBack(&s);//尾删
	PrintSeqlist(&s);
	PushFront(&s, 0);//头插
	PrintSeqlist(&s);
	PopFront(&s);//头删
	PrintSeqlist(&s);
	//Find(&s, 3);//查找
	Insert(&s, 3, 5);//任意位置插入
	PrintSeqlist(&s);
    Erase(&s,2);//任意位置删除
	PrintSeqlist(&s);
    Remove(&s, 5);//删除第一个为data的数据
	PrintSeqlist(&s);
    RemoveAll2(&s, 5);//删除所有为data的数据
	PrintSeqlist(&s);
	Empty(&s);//判空
    Bubblesort(&s);//冒泡排序
	PrintSeqlist(&s);
	SelectSort(&s);//选择排序
	PrintSeqlist(&s);
	system("pause");
	return 0;
}