 ///
 /// @file    sortingfunction.cc
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-20 11:25:48
 ///
 
#include "sortingfunctions.h"

using namespace std;

void SortingFunctions::bubble(int array[], int n)
{
	int i;
	int j;
	int temp;
	for(i = 0; i < n -1; ++i)
	{
		for(j = n - 1; j > 1; j--)
		{
			if(array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

// 选择排序
// 最坏时间代价：n2
// 最小时间代价：n2
// 平均时间代价：n2

void SortingFunctions::selectionSort(int array[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min = i;
		int j;
		for(j= i + 1; j < n; j++)
		{
			if(array[j] < array[min])
				min = j;
		}
		int temp;
		temp = array[j];
		array[j] = array[min];
		array[min] = temp;
	}
}

// 插入排序
// 最大时间代价：n2
// 最小时间代价：n
// 平均时间代价；n2

void SortingFunctions::insertSort(int array[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int j;
		for(j = i; j > 0; j--)
		{
			if(array[j] < array[j - 1])
			{
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
			else
				break;
		}
	}
}

//希尔排序
//平均时间代价：n1.5 增量每次除以2的情况下

void SortingFunctions::shellSort(int array[], int n)
{
	int i, j, k, l;
	for(i = n / 2; i > 0; i /= 2)
	{
		for(j = 0; j < i; j++)
		{
			for(k = j + i; k < n; k += i)
			{
				for(l = k; l > i; )
				{
					if(array[l] < array[l - i])
					{
						int temp = array[l];
						array[l] = array[l - i];
						array[l - i] = temp;
						l -= i;
					}
					else
					{
						l-=i;
						break;
					}
				}
			}
		}
	}
}
/*
int SortingFunctions::partition(int array[], int left, int right)
{
	int pivot = (left + right) / 2;
	int tmp = array[pivot];
	
}
*/

void SortingFunctions::quickSort(int array[], int left, int right)
{
	if(right <= left)
		return ;
	int pivot = SortingFunctions::partition(array, left, right);
	quickSort(array, left, pivot - 1);
	quickSort(array, pivot + 1, right);
}

// 归并排序(merge sorting)
// 最大时间代价： nlogn
// 最小时间代价： nlogn
// 平均时间代价： nlogn
//

void SortingFunctions::mergeSort(int array[], int temp[], int left, int right)
{
	int middle = (left + right) / 2;
	if(left >= right)
		return;
	mergeSort(array, temp, left, middle);
	mergeSort(array, temp, middle + 1, right);
	for(int i = left; i < right; i++)
		temp[i] = array[i];

	int j = left;
	int k = middle + 1;
	for(int curr = left; curr <= right; curr++)
	{
		if(j == middle + 1)
			array[curr] = temp[k++];
		else if(k > right)
			array[curr] = temp[j++];
		else if(temp[j] < temp[k])
			array[curr] = temp[j++];
		else
		{
			array[curr] = temp[k++];
		}
	}
}

// 最大堆调整函数
// 用于插入或删除堆中的数值时重组堆的操作

void SortingFunctions::maxHeapFix(int a[], int n, int i)
{
	int j, temp;
	temp = a[i];
	j = i * 2 + 1;
	while(j < n)
	{
		if(j + 1 < n && a[j] < a[j + 1])
			j++;
		if(a[j] <= temp)
			break;
		a[i] = a[j];
		i = j;
		j = i * 2 + 1;
	}
	a[i] = temp;
}


void SortingFunctions::maxHeap(int a[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		maxHeapFix(a, n, i);
}

void SortingFunctions::maxHeapSort(int a[], int n)
{
	maxHeap(a, n);
	for(int i = n -1; i >= 1; i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		maxHeapFix(a, i, 0);
	}
}
