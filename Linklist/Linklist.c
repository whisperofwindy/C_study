 ///
 /// @file    Linklist.c
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-18 11:55:16
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define dim(x) sizeof(x) / sizeof(x[0])

struct tagStack
{
	int iData;
	struct tagStack *pPrev;
};

struct tagNode
{
	int iData;
	struct tagNode *pPrev;
	struct tagNode *pNext;
};

int main()
{
	struct tagStack AA = {11, NULL};
	struct tagStack BB = {22, &AA};
	struct tagStack CC = {33, &BB};
	struct tagStack DD = {44, &CC};
	struct tagStack EE = {55, &DD};

	struct tagStack *pTop = &EE;
	
	struct tagNode A = {11};
	struct tagNode B = {22};
	struct tagNode C = {33};
	struct tagNode D = {44};
	struct tagNode E = {55};

	A.pPrev = NULL;
	A.pNext = &B;

	B.pPrev = &A;
	B.pNext = &C;

	C.pPrev = &B;
	C.pNext = &D;

	D.pPrev = &C;
	D.pPrev = &E;

	E.pPrev = &D;
	E.pNext = NULL;

	struct tagNode *pHead = &A;
	struct tagNode *pCurr = pHead;
	struct tagNode *pLast = NULL;

	while(pCurr != NULL)
	{
		pLast = pCurr;

		struct tagNode * pTemp = pCurr->pNext;
		pCurr->pNext = pCurr->pPrev;
        pCurr->pPrev = pTemp;

		pCurr = pLast->pPrev;
	}

	pHead = pLast;

	pCurr = pHead;
	while(pCurr != NULL)
	{
		printf("%d", pCurr->iData);
		pCurr = pCurr->pNext;
	}
	return 0;
}
