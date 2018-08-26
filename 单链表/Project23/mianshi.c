#include"linklist.h"

typedef struct SListNode
{
	DataType _data;
	struct SListNode* _pNext; // ָ����һ������ָ�� 
}Node, *PNode;

void PrintListFromTail2Head(PNode pHead)//�Ӻ���ǰ��ӡ������
{
	if (pHead)
	{
		PrintListFromTail2Head(pHead->_pNext);//�õݹ飬Ҫ���ܹ����һ�����õĵط���ʼ��ӡ
		printf("%d ", pHead->_data);
	}
}
void InsertFront(PNode pos, DataType data)//��POSǰ����һ�����ݣ����ܱ���
{
	assert(pos);
	PNode newnode = (PNode*)malloc(sizeof(DataType));

	newnode->_pNext = pos->_pNext;
	pos->_pNext = newnode;
	
	newnode->_data = pos->_data;
	pos->_data = data;
}

void Delete(PNode pos)//ɾ������β���
{
	assert(pos);
	PNode pdel = NULL;

	//����POS��POSλ�õ���һ��������
	DataType temp= pos->_data;
	pos->_data = pos->_pNext->_data;
	pos->_pNext->_data = temp;

	//������������
	pdel = pos->_pNext;
	pos->_pNext = pos->_pNext->_pNext;

	//�ͷ�Ҫɾ���Ľ��Ŀռ�
	free(pdel);

}
void JosephCircle(PNode* pHead, size_t M)// 1 2 3 4 5 6 7��ÿ3��ɾ��һ�£���һ��ɾ������3,6
{
	assert(pHead);
	
	PNode pcur = *pHead;
	while (pcur->_pNext)
	{
		pcur = pcur->_pNext;
	}
	pcur->_pNext = *pHead;//��β��ͷ������һ��
	while (pcur!=pcur->_pNext)//�������ֻʣһ���ڵ㣬��ô������
	{
		size_t count = M;//ÿһ�ֿ�ʼM��ֵ�ָ�ԭ����
		PNode pdel = NULL;
		while (--count)
		{
			pdel = pcur;
			pcur = pcur->_pNext;
		}
		pdel->_pNext = pcur->_pNext;//2ָ��4
		pdel = pcur;//Ҫɾ���Ľ��Ų����3��λ��
		free(pdel);//�ͷ�3
		pcur = pcur->_pNext;//��ǰ���ָ��4
	}
	pcur = *pHead;
	printf("%d", pcur->_data);
}
void ReverseList(PNode* pHead)//��ת������
{
	if (pHead == NULL ||(*pHead)->_pNext == NULL)//û�н�㣬����ֻ��һ���ڵ㣬����Ҫ����
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
	*pHead = p1;//���շ��ص����µ�ͷ���
}


void BubbleSort(PNode pHead)//ð������3 5 2 7 1 0
{
	assert(pHead);
	PNode pcur = pHead;
	if (pHead == NULL || pHead->_pNext == NULL)//Ϊ�ջ���ֻ��һ���ڵ�
	{
		return;
	}
	while (pcur)//�������β��㴦
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
PNode FindMiddleNode(PNode pHead)//���м�Ľ��  1 2 3 4 5 ->NULL
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
		pslow = pslow->_pNext;//ָ��2
		pfast = pfast->_pNext->_pNext;//ָ��4
	}
	//��������󷵻ص���pslowָ���3
}
PNode FindLastKNode(PNode pHead, size_t K)//���ҵ�����k�����
{
	assert(pHead);
	if (pHead == NULL || pHead->_pNext == NULL)
	{
		return;
	}
	PNode pslow = pHead;
	PNode pfast = pHead;
	//��ָ�����ߵ�k-1��
	while (--K)
	{
		pfast = pfast->_pNext;
	}
	//����ָ�붼�ƶ�
	while (pfast->_pNext != NULL)
	{
		pslow = pslow->_pNext;
		pfast = pfast->_pNext;
	}
	//��󷵻���ָ��
	return pslow;
}
int DeleteLastKNode(PNode* ppHead, size_t K)//ɾ��������k�����
{
	assert(ppHead);
	PNode pos=FindLastKNode(ppHead, K);
	
	//�൱��ת������ɾ��POSλ�õĽ��
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
	free(pos->_pNext);
}
PNode MergeList(PNode pHead1, PNode pHead2)//���������������תΪһ���µ���������
{
	assert(pHead1);
	assert(pHead2);
	PNode newhead = NULL;//����һ��������
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	PNode pcur = newhead;
	if (pcur1->_data < pcur2->_data)//��ѡ���������ͷ���
	{
		newhead = pcur1;
		pcur1 = pcur1->_pNext;
	}
	else
	{
		newhead = pcur2;
		pcur2 = pcur2->_pNext;
	}
	while (pcur1&&pcur2)//������������Ϊ��ʱ
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

	
PNode HasCircle(PNode pHead)//�жϵ������Ƿ����
{
	assert(pHead);
	PNode pslow = pHead;//��ָ��
	PNode pfast = pHead->_pNext;//��ָ��
	while (pfast->_pNext != NULL)
	{
		pslow = pslow->_pNext;//һ����һ��
		pfast = pfast->_pNext->_pNext;//һ��������
		if (pslow == pfast)//�����ָ�����ָ�������ˣ�˵������
		{
			return pslow;//���������������ĵ�
		}
	}
	return;//˵����ָ�����ָ���յĵط�����ô�Ͳ����ڻ���

}
	
size_t GetCircleLen(PNode pHead)//���ĳ��ȣ���������������¼����
{
	assert(pHead);
	PNode pcur = HasCircle(pHead);//��ʼ��ʱ��ָ������ָ�������ĵ�
	if (pcur == NULL)//˵��û�л�
	{
		return;
	}
	int circlelen = 1;//����л���ô���ٳ���Ϊ1
	while (pcur->_pNext != pcur)
	{
		pcur = pcur->_pNext;
		circlelen++;
	}
	return circlelen;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)//������ڵ�
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

int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)//�����������Ƿ��ཻ
{
	assert(pHead1);
	assert(pHead2);
	
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)//Ϊ��
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

PNode GetCorssNode(PNode pHead1, PNode pHead2)//���������ཻ�������ཻ�ĵ�
{
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;
	PNode pfast = NULL;
	PNode pslow = NULL;
	if (pcur1 == NULL&&pcur2 == NULL)
	{
		return;
	}
	if (!IsCrossWithoutCircle(pHead1,pHead2))//û�н���
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
	if (len1 > len2)//���1�����Ǿ�Ҫ����1
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
	
	//��ʼ����������k������֤������ͬʱ������ʱ�򳤶���һ����
	while (--k)
	{
		pfast = pfast->_pNext;
	}
	while (pfast->_pNext&&pslow->_pNext)//����ָ��ͬʱ��ʼ����
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


int IsCrossWithCircle(PNode pHead1, PNode pHead2)//��������������Ƿ��ཻ
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return;
	}
	//���ж����������Ƿ����
	PNode meet1 = HasCircle(pHead1);
	PNode meet2 = HasCircle(pHead2);

	if (meet1&&meet2)//��������ͬʱ������ֻ��һ�������ǲ����Եģ���Ϊ�޷��ཻ
	{
		PNode pcur = meet1->_pNext;
		if (pcur != meet1)
		{
			if (pcur == meet2)//��ͬһ����
			{
				PNode pcur1 = GetEnterNode(pHead1, meet1);//��������������
				PNode pcur2 = GetEnterNode(pHead2, meet2);

				//�����ཻ
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
					if (p1 == p2)//����������Ĳ����ཻ��
					{
						return GetCorssNode(pHead1, pHead2);
					}

					//�����ཻ
					if (pcur1 == pcur2)//���������غϣ���㷵��һ����
					{
						return pcur1;
					}

				}
			}
		}
	}




	else if (meet1==NULL&&meet2==NULL)//��������������
	{
		return CorssNode(pHead1, pHead2);
	}
}

void Findequaldata(PNode pHead1, PNode pHead2)//�����ź���������е���ͬ������
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return;
	}
	PNode pcur1 = pHead1;
	PNode pcur2 = pHead2;

	while (pcur1&&pcur2)
	{
		if (pcur1->_data > pcur2->_data)//˭ָ���С,˭�����
		{
			pcur2 = pcur2->_pNext;
		}
		else
		{
			pcur1 = pcur1->_pNext;
		}
		if (pcur1->_data == pcur2->_data)//�����ȣ�ͬʱ�����
		{
			printf("%d ", pcur1->_data);
			pcur1 = pcur1->_pNext;
			pcur2 = pcur2->_pNext;
		}
	}

}
//��������ĸ���
typedef struct SCListNode
{
	struct SCListNode* _pNext;
	struct SCListNode* _random;//���ָ����
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
	//���Ƚ���ǰ��ÿһ�����ֱ�������Ӧ�Ľ�����
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
	//�������ָ����
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

	//����ԭ����͸��ƺ������
	pcur = pHead;

	while (pcur)
	{
		newhead = pcur->_pNext;
		pcur->_pNext = newnode->_pNext;//��һ������һ��ָ��ԭ���ĵڶ���
		newnode->_pNext = pcur->_pNext->_pNext;//���������һ��ָ���ƺ�ĵڶ���
	}
	return newhead;
}

