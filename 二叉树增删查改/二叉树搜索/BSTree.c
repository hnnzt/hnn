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
	if (*pRoot == NULL)//二叉树为空
		pRoot = BuyBSTreeNode(data);
	PNode pcur = *pRoot;
	PNode parent = *pRoot;
	while (pcur)//找待插入的结点
	{
		if (pcur->_data == data)
		{
			return;//如果是，就返回
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
	pcur = BuyBSTreeNode(data);//插入结点
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
	if (NULL == pRoot)//为空
	{
		return;
	}
	PNode pcur = *pRoot;
	PNode parent = *pRoot;
	while (pcur)//找待删结点
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
	if (NULL == pcur->_pRight)//只有左子树或者是叶子结点
	{
		if (pcur == *pRoot)//要删除的是根节点
		{
			pdel = *pRoot;
			*pRoot = (*pRoot)->_pLeft;
		}
		else if (pcur == parent->_pLeft)//只有左子树的结点
		{
			parent->_pLeft = pcur->_pLeft;
		}
		else // 叶子结点
			parent->_pRight = pcur->_pRight;//即指向空
	}
	if (NULL == pcur->_pRight)//只有右子树或者是叶子结点
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
	else//左右子树都存在

	{
		parent = pcur;
		pdel = pcur->_pRight;//在右子树中找到所要替代的删除点
		while (pdel->_pLeft)
		{
			parent = pdel;
			pdel = pdel->_pLeft;
		}
		pcur->_data = pdel->_data;

		if (pdel == parent->_pLeft)
			parent->_pLeft = pdel->_pRight;
		else//例如删除7
			parent->_pRight = pdel->_pRight;
	}
    free(pdel);
	
}
void InOrderD(PNode pRoot)//中序

{  
	if (pRoot)

	{

		InOrderD(pRoot->_pLeft);

		printf("%c ", pRoot->_data);

		InOrderD(pRoot->_pRight);
	}
}




void DestroyBSTree(PNode* pRoot)//销毁
{
	assert(pRoot);
	if (*pRoot)//按照后序的方法销毁
	{
		DestroyBSTree((*pRoot)->_pLeft);
		DestroyBSTree((*pRoot)->_pRight);
		free(pRoot);
		*pRoot = NULL;//指向空，不然会成为野指针
	}
		
}
PNode BuyBSTreeNode(DataType data)
{
	PNode pnewnode = (PNode) malloc(sizeof(node));
	pnewnode->_pLeft = NULL;
	pnewnode->_pRight = NULL;
	pnewnode->_data = data;

}


