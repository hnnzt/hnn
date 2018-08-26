#include "linklist.h"

int main()
{
	Node* L=NULL;//L为指向链表的指针
	Node *pos = L;//pos为二级指针
	pos = pos->_pNext;
	BuySListNode(0);
	

	SListPushBack(&L, 1);//需要传指针的地址，因为需要对链表会有内容的改变
	SListPushBack(&L, 2);
	SListPushBack(&L, 3);
	SListPushBack(&L, 4);
	SListPushBack(&L, 5);
	SListPrint(&L);

	SListPopBack(&L);
	SListPrint(&L);

	SListPushFront(&L, 0);
	SListPrint(&L);

	SListPopFront(&L);

	// 在链表中查找元素data，返回该结点在链表中的位置 
	Find(&L, 3);
	
	// data插入在pos之前 
	SListInsert(&L, pos, 8);
	SListPrint(&L);

	SListErase(&L, pos);
	SListPrint(L);

	// 获取链表中结点的个数 
	Size(L);

	// 判断链表是否为空，若为空，返回true，否则返回false 
	Empty(L);

	// 销毁单链表 
	SListDestroy(&L);

	system("pause");
	return 0;
}