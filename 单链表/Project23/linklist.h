#include"stdio.h"
#include"assert.h"
#include"windows.h"

#ifndef _LINKLIST_H__
#define _LINKLIST_H__

//����������ͷ�ļ��еĶ���
typedef int DataType;



typedef struct SListNode
{
	DataType _data;
	struct SListNode* _pNext; // ָ����һ������ָ�� 
}Node, *PNode;


// �������,����ʼ��
PNode BuySListNode(DataType data);

// β�� 
void SListPushBack(PNode*ppHead, DataType data);

// βɾ 
void SListPopBack(PNode* ppHead);

// ͷ�� 
void SListPushFront(PNode*ppHead, DataType data);

// ͷɾ 
void SListPopFront(PNode* ppHead);

// �������в���Ԫ��data�����ظý���������е�λ�� 
PNode Find(PNode pHead, DataType data);
// data������pos֮ǰ 
void SListInsert(PNode* ppHead, PNode pos, DataType data);

// ɾ��������posλ�õĽ�� 
void SListErase(PNode* ppHead, PNode pos);

// ��ȡ�����н��ĸ��� 
size_t Size(PNode pHead);

// �ж������Ƿ�Ϊ�գ���Ϊ�գ�����true�����򷵻�false 
size_t Empty(PNode pHead);

// ���ٵ����� 
void SListDestroy(PNode* ppHead);



// ��ӡ������ 
void SListPrint(PNode pHead);

////////////////////////////////////////////����///////////////////////////////////////

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


