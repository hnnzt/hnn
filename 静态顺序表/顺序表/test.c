#include"seqlist.h"
int main()
{
	seqlist s;
    PushBack(&s, 1);//β��
	PushBack(&s, 2);
	PushBack(&s, 3);
	PushBack(&s, 4);
	PushBack(&s, 5);
	PrintSeqlist(&s);
    PopBack(&s);//βɾ
	PrintSeqlist(&s);
	PushFront(&s, 0);//ͷ��
	PrintSeqlist(&s);
	PopFront(&s);//ͷɾ
	PrintSeqlist(&s);
	//Find(&s, 3);//����
	Insert(&s, 3, 5);//����λ�ò���
	PrintSeqlist(&s);
    Erase(&s,2);//����λ��ɾ��
	PrintSeqlist(&s);
    Remove(&s, 5);//ɾ����һ��Ϊdata������
	PrintSeqlist(&s);
    RemoveAll2(&s, 5);//ɾ������Ϊdata������
	PrintSeqlist(&s);
	Empty(&s);//�п�
    Bubblesort(&s);//ð������
	PrintSeqlist(&s);
	SelectSort(&s);//ѡ������
	PrintSeqlist(&s);
	system("pause");
	return 0;
}