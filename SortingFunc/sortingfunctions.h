 ///
 /// @file    sortingfunctions.h
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-20 11:19:05
 ///

#ifndef SORTINGFUNCTIONS_H
#define SORTINGFUNCTIONS_H

#include <iostream>
#include <ctime>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

class SortingFunctions
{
public:
	SortingFunctions(){};
	~SortingFunctions(){};
	void bubble(int [], int);
	void selectionSort(int [], int);
	void insertSort(int [], int);
	void shellSort(int [], int);
	void mergeSort(int [], int [], int, int);
	void quickSort(int [], int, int);
	void maxHeapSort(int [], int);
private:
	int partition(int array[], int left, int right);
	void merge(int [], int [], int, int);
	void maxHeapFix(int [],  int, int);
	void maxHeap(int [], int);
};

#endif
