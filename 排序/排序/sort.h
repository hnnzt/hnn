#include"stdio.h"


//实现以下各种排序，并分析其时间、空间复杂度，稳定性和适用场景
// 插入排序 
// 直接插入排序 
void InsertSort(int* array, int size);
// 插入排序使用二分进行优化 
void InsertSort_OP(int* array, int size);
// 希尔排序 
void ShellSort(int* array, int size);
// 递归实现插入排序 
void QuickSort(int* array, int left, int right);
// 非递归实现插入排序 
void QuickSortNor(int* array, int size);





// 选择排序 
void SelectSort(int* array, int size);
// 使用每次找最大最小元素对选择排序进行优化 
void SelectSort_OP(int* array, int size);

// 堆调整 向下调整 
void HeapAdjust(int* array, int size, int parent);
// 堆排序 
void HeapSort(int* array, int size);





// 交换排序 
// 冒泡排序 
void BubbleSort(int* array, int size);



// 快速排序 
int Quicksort(int *array,int left,int right);
// 三数取中法 
int GetMidDataIndex(int* array, int left, int right);
// Horn版本分离数据 
int partion1(int* array, int left, int right);
// 挖坑法 
int partion2(int* array, int left, int right);
// 前后指针 
int partion3(int* array, int left, int right);






//归并排序 
// 二路并归，将两组有序的数组合并成一组有序数组 
void MergeData(int* array, int left, int mid, int right, int* temp);
// 归并排序 递归实现 
void MergeSrot(int* array, int size);
// 非递归归并排序
void MergeSortNor(int* array, int size);

// 非比较排序 
// 计数排序 
void CountSort(int* array, int size,int *c,int *output,int k);

// 基数排序--低关键码优先 
void RadixSortLSD(int* array, int size);
// 高关键码优先 
void RadixSortMSD(int* array, int size);
/ 桶排序
void bucketsort(int *array, int size);
此处的各种排序非常重要，面试中被写到或问到的概率非常高，好好去完成，最好写一篇博客总结下
