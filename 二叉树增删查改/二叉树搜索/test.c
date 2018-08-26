#include"BSTree.h"

int main()
{
	PNode pRoot = NULL;
	InitBSTree(& pRoot);
	int arr[] = {5,6,7,8,9,0,1,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		InsertBST(& pRoot, arr[i]);
	}
	InOrder(&pRoot);

	FindBST(& pRoot, 6);


	DeleteBSTree(& pRoot, 7);
	InOrder(pRoot);
	
	DeleteBSTree(&pRoot, 9);
	InOrder(pRoot);


}