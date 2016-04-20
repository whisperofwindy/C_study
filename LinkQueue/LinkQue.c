 ///
 /// @file    LinkQue.c
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-19 19:56:34
 ///

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define dim(x) sizeof(x) / sizeof(x[0])

typedef struct LQNODE
{
	int iData;
	struct LQNODE *pNext;
}Lqnode, *pLqnode;

void AddQ(Lqnode *pReal, int x)
{


}

int main()
{
	printf("LinkQueue is more valurable in C++ , by class\n");
	return 0;
}
