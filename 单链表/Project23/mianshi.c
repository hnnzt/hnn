#include"linklist.h"

typedef struct SListNode
{
	DataType _data;
	struct SListNode* _pNext; // 指向下一个结点的指针 
}Node, *PNode;

void PrintListFromTail2Head(PNode pHead)//从后往前打印单链表
{
	if (pHead)
	{
		PrintListFromTail2Head(pHead->_pNext);//用递归，要才能够最后一个调用的地方开始打印
		printf("%d ", pHead->_data);
	}
}
void InsertFront(PNode pos, DataType data)//在POS前插入一个数据，不能遍历
{
	assert(pos);
	PNode newnode = (PNode*)malloc(sizeof(DataType));

	newnode->_pNext = pos->_pNext;
	pos->_pNext = newnode;
	
	newnode->_data = pos->_data;
	pos->_data = data;
}

void Delete(PNode pos)//删除不是尾结点
{
	assert(pos);
	PNode pdel = NULL;

	//交换POS和POS位置的下一个的数据
	DataType temp= pos->_data;
	pos->_data = pos->_pNext->_data;
	pos->_pNext->_data = temp;

	//重新连接链表
	pdel = pos->_pNext;
	pos->_pNext = pos->_pNext->_pNext;

	//释放要删除的结点的空间
	free(pdel);

}
void JosephCircle(PNode* pHead, size_t M)// 1 2 3 4 5 6 7，每3个删除一下，第一轮删除的是3,6
{
	assert(pHead);
	
	PNode pcur = *pHead;
	while (pcur->_pNext)
	{
		pcur = pcur->_pNext;
	}
	pcur->_pNext = *pHead;//将尾和头连接在一起
	while (pcur!=pcur->_pNext)//如果不是只剩一个节点，那么向后遍历
	{
		size_t count = M;//每一轮开始M的值恢复原来的
		PNode pdel = NULL;
		while (--count)
		{
			pdel = pcur;
			pcur = pcur->_pNext;
		}
		pdel->_pNext = pcur->_pNext;//2指向4
		pdel = pcur;//要删除的结点挪到了3的位置
		free(pdel);//释放3
		pcur = pcur->_pNext;//当前结点指向4
	}
	pcur = *pHead;
	printf("%d", pcur->_data);
}
void ReverseList(PNode* pHead)//反转单链表
{
	if (pHead == NULL ||(*pHead)->_pNext == NULL)//没有结点，或者只有一个节点，不需要逆置
	{
		return;
	}
	PNode p1 = *pHead;

	PNode p2 = p1->_pNext;

	while (p2)
	{
		PNode p3 = p2->_pNext;
		p3 = p1;
		p1 = p2;
		p2 = p3;
	}
	*pHead = p1;//最终返回的是新的头结点
}


void BubbleSort(PNode pHead)//冒泡排序，3 5 2 7 1 0
{
	assert(pHead);
	PNode pcur = pHead;
	if (pHead == NULL || pHead->_pNext == NULL)//为空或者只有一个节点
	{
		return;
	}
	while (pcur)//如果不到尾结点处
	{
		int flag = 0;
		if (pcur->_data > pcur->_pNext->_data)
		{
			flag = 1;
			int temp = pcur->_data;
			pcur->_data = pcur->_pNext->_pNext;
			pcur->_pNext->_data = temp;
		}
		else
		{
			pcur = pcur->_pNext;
		}
		if (flag == 0)
		{
			break;
		}
	}
}
PNode FindMiddleNode(PNode pHead)//找中间的结点  1 2 3 4 5 ->NULL
{
	assert(pHead);
	if (pHead == NULL || pHead->_pNext == NULL)
	{
		return;
	}
	PNode pslow = pHead;
	PNode pfast = pHead->_pNext;
	while (pfast->_pNext)
	{
		pslow = pslow->_pNext;//指向2
		pfast = pfast->_pNext->_pNext;//指向4
	}
	//本例子最后返回的是pslow指向的3
}
PNode FindLastKNode(PNode pHead, size_t K)//查找倒数第k个结点
{
	assert(pHead);
	if (pHead == NULL || pHead->_pNext == NULL)
	{
		return;
	}
	PNode pslow = pHead;
	PNode pfast = pHead;
	//快指针先走到k-1步
	while (--K)
	{
		pfast = pfast->_pNext;
	}
	//快慢指针都移动
	while (pfast->_pNext != NULL)
	{
		pslow = pslow->_pNext;
		pfast = pfast->_pNext;
	}
	//最后返回慢指针
	return pslow;
}
int DeleteLastKNode(PNode* ppHead, size_t K)//删除倒数第k个结点
{
	assert(ppHead);
	PNode pos=FindLastKNode(ppHead, K);
	
	//相当于转化成了删除POS位置的结点
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
	free(pos->_pNext);
}
PNode MergeList(PNode pHead1, PNode pHead2)//将两个有序的链表转为一个新的有序单链表
{
	assert(pHead1);
	assert(pHead2);
	PNode newhead = NULL;//创建一个新链表
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	PNode pcur = newhead;
	if (pcur1->_data < pcur2->_data)//先选出新链表的头结点
	{
		newhead = pcur1;
		pcur1 = pcur1->_pNext;
	}
	else
	{
		newhead = pcur2;
		pcur2 = pcur2->_pNext;
	}
	while (pcur1&&pcur2)//当两个链表都不为空时
	{
		if (pcur1->_data < pcur2->_data)
		{
			pcur->_pNext = pcur1;
			pcur1 = pcur1->_pNext;
		}
		else
		{
			pcur->_pNext = pcur2;
			pcur2 = pcur2->_pNext;
		}

	}
	if (pcur1)
	{
		pcur->_pNext = pcur1;
	}
	else
	{
		pcur->_pNext = pcur2;
	}
	return pcur;
}

	
PNode HasCircle(PNode pHead)//判断单链表是否带环
{
	assert(pHead);
	PNode pslow = pHead;//慢指针
	PNode pfast = pHead->_pNext;//快指针
	while (pfast->_pNext != NULL)
	{
		pslow = pslow->_pNext;//一次走一步
		pfast = pfast->_pNext->_pNext;//一次走两步
		if (pslow == pfast)//如果快指针和慢指针相遇了，说明带环
		{
			return pslow;//给函数返回相遇的点
		}
	}
	return;//说明快指针可以指到空的地方，那么就不存在环了

}
	
size_t GetCircleLen(PNode pHead)//环的长度，遍历整个环，记录长度
{
	assert(pHead);
	PNode pcur = HasCircle(pHead);//开始的时候指向两个指针相遇的点
	if (pcur == NULL)//说明没有环
	{
		return;
	}
	int circlelen = 1;//如果有环那么至少长度为1
	while (pcur->_pNext != pcur)
	{
		pcur = pcur->_pNext;
		circlelen++;
	}
	return circlelen;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)//环的入口点
{
	assert(pHead);
	PNode enternode = pHead;
	while (enternode != pMeetNode)
	{
		enternode = enternode->_pNext;
		pMeetNode = pMeetNode->_pNext;

	}
	return enternode;
}

int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)//链表不带环，是否相交
{
	assert(pHead1);
	assert(pHead2);
	
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)//为空
	{
		return;
	}
	while (pcur1->_pNext&&pcur2->_pNext)
	{
		if (pcur1 == pcur2)
		{
			return 1;
		}
		else
		{
			pcur1 = pcur1->_pNext;
			pcur2 = pcur2->_pNext;
		}
	}
	return 0;
}

PNode GetCorssNode(PNode pHead1, PNode pHead2)//不带环的相交，返回相交的点
{
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	PNode pfast = NULL;
	PNode pslow = NULL;
	if (pcur1 == NULL&&pcur2 == NULL)
	{
		return;
	}
	if (!IsCrossWithoutCircle(pHead1,pHead2))//没有交点
	{
		return 0;
	}
	int len1 = 0;
	int len2 = 0;
	int k = 0;
	while (pcur1)
	{
		len1++;
		pcur1 = pcur1->_pNext;
	}
	while (pcur2)
	{
		len1++;
		pcur2 = pcur2->_pNext;
	}
	if (len1 > len2)//如果1长，那就要遍历1
	{
		k = len1 - len2;
		pfast = pHead1;
		pslow = pHead2;
	}
	else
	{
		k = len2 - len1;
		pfast = pHead2;
		pslow = pHead1;
	}
	
	//开始遍历，先走k步，保证了两个同时遍历的时候长度是一样的
	while (--k)
	{
		pfast = pfast->_pNext;
	}
	while (pfast->_pNext&&pslow->_pNext)//两个指针同时开始遍历
	{
		if (pfast == pslow)
		{
			return pslow;
		}
		else
		{
			pfast = pfast->_pNext;
			pslow = pslow->_pNext;
		}
	}
	return 0;
}


int IsCrossWithCircle(PNode pHead1, PNode pHead2)//两个链表带环，是否相交
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return;
	}
	//先判断两个链表是否带环
	PNode meet1 = HasCircle(pHead1);
	PNode meet2 = HasCircle(pHead2);

	if (meet1&&meet2)//两个链表同时带环，只有一个带环是不可以的，因为无法相交
	{
		PNode pcur = meet1->_pNext;
		if (pcur != meet1)
		{
			if (pcur == meet2)//带同一个环
			{
				PNode pcur1 = GetEnterNode(pHead1, meet1);//获的两个环的入口
				PNode pcur2 = GetEnterNode(pHead2, meet2);

				//环外相交
				if (pcur1 != pcur2)
				{
					PNode p1 = pHead1;
					PNode p2 = pHead2;
					while (p1 != pcur1)
					{
						p1 = p1->_pNext;
					}
					while (p1 != pcur2)
					{
						p2 = p2->_pNext;
					}
					if (p1 == p2)//两个链表环外的部分相交了
					{
						return GetCorssNode(pHead1, pHead2);
					}

					//环内相交
					if (pcur1 == pcur2)//整个环都重合，随便返回一个点
					{
						return pcur1;
					}

				}
			}
		}
	}




	else if (meet1==NULL&&meet2==NULL)//两个链表都不带环
	{
		return CorssNode(pHead1, pHead2);
	}
}

void Findequaldata(PNode pHead1, PNode pHead2)//两个排好序的链表中的相同的数据
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return;
	}
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;

	while (pcur1&&pcur2)
	{
		if (pcur1->_data > pcur2->_data)//谁指向的小,谁向后移
		{
			pcur2 = pcur2->_pNext;
		}
		else
		{
			pcur1 = pcur1->_pNext;
		}
		if (pcur1->_data == pcur2->_data)//如果相等，同时向后移
		{
			printf("%d ", pcur1->_data);
			pcur1 = pcur1->_pNext;
			pcur2 = pcur2->_pNext;
		}
	}

}
//复杂链表的复制
typedef struct SCListNode
{
	struct SCListNode* _pNext;
	struct SCListNode* _random;//随机指针域
	int _data;
}SCLNode;

SCLNode* BuySCLNode(int data)
{
	SCLNode* pNewNode = (SCLNode*)malloc(sizeof(SCLNode));
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_random = NULL;

	return pNewNode;
}

SCLNode* CopyComplexList(SCLNode* pHead)
{
	//首先将当前的每一个结点分别复制在相应的结点后面
	SCLNode *pcur = pHead;
	SCLNode *newnode = NULL;
	SCLNode *newhead = NULL;

	while (pcur)
	{
		newnode = BuySCLNode(pcur->_data);
		pcur->_pNext = newnode;
		newnode->_pNext = pcur->_pNext;
		pcur = newnode->_pNext;
	}
	//复制随机指针域
	pcur = pHead;
	while (pcur)
	{
		if (pcur->_random == NULL)
		{
			newnode->_random = NULL;
		}
		else
		{
			newnode->_random = pcur->_random->_pNext;
		}
		pcur = newnode->_pNext;
	}

	//分离原链表和复制后的链表
	pcur = pHead;

	while (pcur)
	{
		newhead = pcur->_pNext;
		pcur->_pNext = newnode->_pNext;//第一个的下一个指向原来的第二个
		newnode->_pNext = pcur->_pNext->_pNext;//新链表的下一个指向复制后的第二个
	}
	return newhead;
}

