#include"Heap.h"

int main()
{
	Heap hp;
	int arr[] = { 53, 17, 78, 9, 4, 5, 65, 87 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InitHeap(&hp);
	CreateHeap(&hp, arr, size);
	Insert(&hp,8);//²åÈëÊı¾İ
	Remove(&hp);//É¾³ı
}