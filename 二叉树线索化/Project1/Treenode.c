#include"Treenode.h"

void CreateBinTree(PNode* pRoot, DataType* array, int size, DataType invalid)
{
	int index = 0;
	_CreateBinTree(&pRoot,  array, size, &index, '#');//#������Чֵ��Ϊ��
}
void _CreateBinTree(PNode* pRoot, DataType* array, int size, int* index, DataType invalid)
{
	if (invalid != array[*index])//�������ָ�������Чֵ����
	{
		//�������ڵ�
		PNode pRoot = BuyNode(array[*index]);
		//����������
        _CreateBinTree(&(pRoot->_pLeft), array, size, ++(*index), '#');
		//����������
		_CreateBinTree(&pRoot->_pRight, array, size, ++(*index), '#');
	}
}
PNode BuyNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	assert(pNewNode);
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	pNewNode->_pParent = NULL;
	pNewNode->_data = data;
	pNewNode->_leftThread = LINK;
	pNewNode->_rightThread = LINK;

	return pNewNode;
}

void _PreOrderThd(PNode pRoot)//�ǵݹ�ǰ��������
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pcur)
	{
		if (pcur->_pLeft==NULL )//3��ǰ��ָ��2
		{
			pcur->_pLeft = prev;
			pcur->_leftThread = THREAD;
		}

		if (prev&&prev->_pRight == NULL)
		{
			prev->_pRight=pcur;//3ָ��4
			prev->_rightThread = THREAD;
		}
		prev = pcur;//4�ǵ�ǰ���
		if (pcur->_leftThread == LINK)
		{
			_PreOrderThd(pcur->_pLeft);//4��������������
		}
		if (pcur->_rightThread == LINK)
		{
			_PreOrderThd(pcur->_pRight);//4��������������
		}
	}

}
	
void PreOrderThd(PNode pRoot)//�ݹ�ǰ��������
{
	PNode *prev = NULL;
	_PreOrderThd(pRoot);
}



void _InOrderThd(PNode pRoot) // �ǵݹ�����������
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pRoot)
	{
		_InOrderThd(pRoot->_pLeft);//��������������
		if (pcur->_pLeft == NULL)
		{
			pcur->_pLeft = prev;
			pcur->_leftThread = THREAD;
		}
		if (prev&&prev->_pRight == NULL)//��ǰ���Ϊ2��prevΪ3
		{
			prev->_pRight = pcur;//3�ĺ��ָ��2
			prev->_rightThread = THREAD;
		}
		prev = pcur;//2Ϊ��ǰ���
		_InOrderThd(pcur->_pRight);//������2��������
	}
}


void InOrderThd(PNode pRoot)//�ݹ�����������
{
	PNode prev = NULL;
	_InOrderThd(pRoot, &prev);
}



void _PostOrderThd(PNode pRoot)//�ǵݹ����������
{
	PNode prev = NULL;
	PNode pcur = pRoot;
	if (pcur)
	{
		_PostOrderThd(pcur->_pLeft);
		_PostOrderThd(pcur->_pRight);

		if (pcur->_pLeft == NULL)
		{
			pcur->_leftThread = THREAD;
			pcur->_pLeft = prev;//3��ǰ��ָ���
		}
		if (prev&&prev->_pRight == NULL)//��ǰ���Ϊ4
		{
			prev->_pRight = pcur;//3�ĺ��ָ��4
			prev->_rightThread = THREAD;
		}
		prev = pcur;
	}
}


void PostOrderThd(PNode pRoot)//�ݹ����������
{
	PNode prev = NULL;
	_PostOrderThd(pRoot, &prev);
}





void PreOrderD(PNode pRoot)//ǰ��ݹ�
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrderD(pRoot->_pLeft);
		PreOrderD(pRoot->_pRight);
	}
}

void PreOrder(PNode pRoot)//�ǵݹ�ǰ��һ�ֹ����Ŀ���Ǵ�ӡ3�Լ�3�����
{
	PNode pcur = pRoot;
	while (pcur)
	{
		while (pcur->_leftThread == LINK)//��������
		{
			printf("%d ", pcur->_data);//��ӡ1,2
			pcur = pcur->_pLeft;
		}
		printf("%d", pcur->_data);//��ӡ3

		while(pcur->_rightThread == THREAD)//������Ҫ��ӡ4��Ѱ��3�ĺ�̽��
		{
			pcur = pcur->_pRight;
			printf("%d ", pcur->_data);
		}

		if(pcur->_leftThread==LINK)//�ж�4�����滹��û��
		{
			pcur = pcur->_pLeft;
		}
		else
		{
			pcur = pcur->_pRight;

		}

	}

}

void InOrderD(PNode pRoot)//�ǵݹ�����һ�ֹ���Ķ�Ŀ���Ǵ�ӡ3��3�����2
{
	PNode pCur = pRoot;

	while (pCur)
	{
		// ������ߵĽ��
		while (LINK == pCur->_leftThread)//���ҵ�3
		{
			pCur = pCur->_pLeft;
		}
		printf("%c ", pCur->_data);//��ӡ3

		// ������Ҫ��ӡ2
		while (THREAD == pCur->_rightThread)
		{
			pCur = pCur->_pRight;
			printf("%c ", pCur->_data);//��ӡ2
		}
		
		pCur = pCur->_pRight;//ָ��4
	}
}




		














