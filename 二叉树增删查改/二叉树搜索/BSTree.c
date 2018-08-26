#include"BSTree.h"



void InitBSTree(PNode* pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
	
}
int InsertBST(PNode* pRoot, DataType data)
{
	PNode pcur = *pRoot;
	assert(pRoot);
	if (*pRoot == NULL)//������Ϊ��
		pRoot = BuyBSTreeNode(data);
	PNode pcur = *pRoot;
	PNode parent = *pRoot;
	while (pcur)//�Ҵ�����Ľ��
	{
		if (pcur->_data == data)
		{
			return;//����ǣ��ͷ���
		}
		else if (pcur->_data > data)
		{
			parent = pcur;
			pcur = pcur->_pLeft;
		}
		else
		{
			parent = pcur;
			pcur = pcur->_pRight;
		}
	}
	pcur = BuyBSTreeNode(data);//������
	if (data < parent->_data)
	{
		parent->_pLeft = pcur;
	}
	else if (data>parent->_data)
	{
		parent->_pRight = pcur;
	}
}
		



    

PNode FindBST(PNode pRoot, DataType data)
{
	assert(pRoot);
	PNode pcur = pRoot;
	while (pcur)
	{
		if (pcur->_data == data)
		{
			return pcur;
		}
		else if(pcur->_data > data)
		{
			pcur = pcur->_pLeft;
        }
		else 
		
		   pcur = pcur->_pRight;
	}
}


int DeleteBSTree(PNode* pRoot, int data)
{
	assert(pRoot);
	if (NULL == pRoot)//Ϊ��
	{
		return;
	}
	PNode pcur = *pRoot;
	PNode parent = *pRoot;
	while (pcur)//�Ҵ�ɾ���
	{
		if (pcur->_data == data)
		{
			break;
		}
		else if (pcur->_data > data)
		{
			parent = pcur;
			pcur = pcur->_pLeft;
		}
		else
		{
			parent = pcur;
			pcur = pcur->_pRight;
		}
	}
	if (NULL == pcur)
	{
		return 0;
	}
	PNode pdel = *pRoot;
	if (NULL == pcur->_pRight)//ֻ��������������Ҷ�ӽ��
	{
		if (pcur == *pRoot)//Ҫɾ�����Ǹ��ڵ�
		{
			pdel = *pRoot;
			*pRoot = (*pRoot)->_pLeft;
		}
		else if (pcur == parent->_pLeft)//ֻ���������Ľ��
		{
			parent->_pLeft = pcur->_pLeft;
		}
		else // Ҷ�ӽ��
			parent->_pRight = pcur->_pRight;//��ָ���
	}
	if (NULL == pcur->_pRight)//ֻ��������������Ҷ�ӽ��
	{
		if (pcur == *pRoot)
		{
			pdel = *pRoot;
			*pRoot = (*pRoot)->_pRight;
		}
		else if (pcur == parent->_pRight)
		{
			parent->_pRight = pcur->_pRight;
		}
		else

			parent->_pLeft = pcur->_pLeft;
	}
	else//��������������

	{
		parent = pcur;
		pdel = pcur->_pRight;//�����������ҵ���Ҫ�����ɾ����
		while (pdel->_pLeft)
		{
			parent = pdel;
			pdel = pdel->_pLeft;
		}
		pcur->_data = pdel->_data;

		if (pdel == parent->_pLeft)
			parent->_pLeft = pdel->_pRight;
		else//����ɾ��7
			parent->_pRight = pdel->_pRight;
	}
    free(pdel);
	
}
void InOrderD(PNode pRoot)//����

{  
	if (pRoot)

	{

		InOrderD(pRoot->_pLeft);

		printf("%c ", pRoot->_data);

		InOrderD(pRoot->_pRight);
	}
}




void DestroyBSTree(PNode* pRoot)//����
{
	assert(pRoot);
	if (*pRoot)//���պ���ķ�������
	{
		DestroyBSTree((*pRoot)->_pLeft);
		DestroyBSTree((*pRoot)->_pRight);
		free(pRoot);
		*pRoot = NULL;//ָ��գ���Ȼ���ΪҰָ��
	}
		
}
PNode BuyBSTreeNode(DataType data)
{
	PNode pnewnode = (PNode) malloc(sizeof(node));
	pnewnode->_pLeft = NULL;
	pnewnode->_pRight = NULL;
	pnewnode->_data = data;

}


