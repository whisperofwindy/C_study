 ///
 /// @file    LinkStack.c
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-19 19:29:11
 ///

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define dim(x) sizeof(x) / sizeof(x[0])

typedef struct LSNODE
{
	int iData;
	struct LSNODE *pNext;
}Lsnode, *pLsnode;

Lsnode * Push(Lsnode *pTop, int x)
{
	Lsnode *pNew = (Lsnode*)malloc(sizeof(Lsnode));
	pNew->iData = x;

	if(pTop == NULL)
	{
		pTop = pNew;
		pTop->pNext = NULL;
	}
	else
	{
		pNew->pNext = pTop;
		pTop = pNew;
	}
	return pTop;
}

int Pop(Lsnode **pTop)
{
	if(*pTop == NULL)
		return -1;
	else
	{
		int iTemp = (*pTop)->iData;
		Lsnode *pTemp = (*pTop)->pNext;
		free(*pTop);
		*pTop = pTemp;
		return iTemp;
	}
}

void print(Lsnode *pTop)
{
	Lsnode *pCurr = pTop;
	while(pCurr != NULL)
	{
		printf("%d ", pCurr->iData);
		pCurr = pCurr->pNext;
	}
	printf("\r\n");
}

int main()
{
	Lsnode *pTop = NULL;
	int i;
	for(i = 1; i < 7; i++)
	{
		pTop = Push(pTop, i);
	}
	print(pTop);
	for(i = 1; i < 4; i++)
	{
		Pop(&pTop);
	}
	print(pTop);
	return 0;
}



