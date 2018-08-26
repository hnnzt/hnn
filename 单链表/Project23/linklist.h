#include"stdio.h"
#include"assert.h"
#include"windows.h"

#ifndef _LINKLIST_H__
#define _LINKLIST_H__

//链表类型在头文件中的定义
typedef int DataType;



typedef struct SListNode
{
	DataType _data;
	struct SListNode* _pNext; // 指向下一个结点的指针 
}Node, *PNode;


// 创建结点,并初始化
PNode BuySListNode(DataType data);

// 尾插 
void SListPushBack(PNode*ppHead, DataType data);

// 尾删 
void SListPopBack(PNode* ppHead);

// 头插 
void SListPushFront(PNode*ppHead, DataType data);

// 头删 
void SListPopFront(PNode* ppHead);

// 在链表中查找元素data，返回该结点在链表中的位置 
PNode Find(PNode pHead, DataType data);
// data插入在pos之前 
void SListInsert(PNode* ppHead, PNode pos, DataType data);

// 删除链表中pos位置的结点 
void SListErase(PNode* ppHead, PNode pos);

// 获取链表中结点的个数 
size_t Size(PNode pHead);

// 判断链表是否为空，若为空，返回true，否则返回false 
size_t Empty(PNode pHead);

// 销毁单链表 
void SListDestroy(PNode* ppHead);



// 打印单链表 
void SListPrint(PNode pHead);

////////////////////////////////////////////面试///////////////////////////////////////

void PrintListFromTail2Head(PNode pHead);
void Delete(PNode pos);
void InsertFront(PNode pos, DataType data);
void JosephCircle(PNode* pHead, size_t M);
void ReverseList(PNode* pHead);
PNode ReverseList_P(PNode pHead);
void BubbleSort(PNode pHead);
PNode FindMiddleNode(PNode pHead);
PNode FindLastKNode(PNode pHead, size_t K);
int DeleteLastKNode(PNode* ppHead, size_t K);
PNode MergeList(PNode pHead1, PNode pHead2);
PNode HasCircle(PNode pHead);
size_t GetCircleLen(PNode pHead);
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);
PNode GetCorssNode(PNode pHead1, PNode pHead2);
PNode GetEnterNode(PNode pHead, PNode pMeetNode);
int IsCrossWithCircle(PNode pHead1, PNode pHead2);


void Findequaldata(PNode pHead1, PNode pHead2);




#endif  _LINKLIST_H__


