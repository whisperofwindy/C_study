 ///
 /// @file    test.cc
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-20 11:29:44
 ///
 
#include "sortingfunctions.h"

using namespace std;

int main()
{
	SortingFunctions sort;
	srand(time(NULL));
	int num = 50000;
	int a[50000];
	int b[50000];
	
	int i;
	for(int i = 0; i < num; ++i)
	{
		a[i] = rand() % 100000;
		b[i] = 0;
	}

	long start = clock();
	//sort.bubble(a, num);
	//sort.selectionSort(a, num);
	//sort.insertSort(a, num);
	//sort.shellSort(a, num);
	//sort.mergeSort(a, b, 0, num - 1);
	//sort.quickSort(a, 0, num - 1);
	//sort.maxHeapSort(a, num);
	
	long finish = clock();
	double totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	for (i = 0; i < num ; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << "耗时：" << totaltime << 's';
	cout << endl;
	
	return 0;
}
