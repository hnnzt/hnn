#include"Treenode.h"

int main()
{
	PNode pRoot = NULL;
	DataType array[] = { 'A', 'B', 'D', '#', '#', 'C', 'E', 'F' };
	int size = sizeof(array) / sizeof(array[0]);
	CreateBinTree(&pRoot, array, size, '#');
}

	