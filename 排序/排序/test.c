#include"sort.h"
int main()
{
	int array[] = { 1, 7, 9, 2, 5, 8, 3, 6, 4, 0};
	int size = sizeof(array) / sizeof(array[0]);
	InsertSort(array, size);
	Printsort(array, size);

	InsertSort(array, size);
	Printsort(array, size);





}