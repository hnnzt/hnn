#include "linklist.h"

int main()
{
	Node* L=NULL;//LΪָ�������ָ��
	Node *pos = L;//posΪ����ָ��
	pos = pos->_pNext;
	BuySListNode(0);
	

	SListPushBack(&L, 1);//��Ҫ��ָ��ĵ�ַ����Ϊ��Ҫ������������ݵĸı�
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

	// �������в���Ԫ��data�����ظý���������е�λ�� 
	Find(&L, 3);
	
	// data������pos֮ǰ 
	SListInsert(&L, pos, 8);
	SListPrint(&L);

	SListErase(&L, pos);
	SListPrint(L);

	// ��ȡ�����н��ĸ��� 
	Size(L);

	// �ж������Ƿ�Ϊ�գ���Ϊ�գ�����true�����򷵻�false 
	Empty(L);

	// ���ٵ����� 
	SListDestroy(&L);

	system("pause");
	return 0;
}