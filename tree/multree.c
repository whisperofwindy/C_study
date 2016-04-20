 ///
 /// @file    multree.c
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-19 20:02:02
 ///

#include <stdio.h>

#define dim(x) sizeof(x)/sizeof(x[0])

typedef struct NODE
{
	char iData;
	struct NODE *pChild[5];
}Node, *pNode;

void preOrder(Node *node)
{
	if(node == NULL)
		return ;
	printf("%c", node->iData);

	int i;
	for(i = 0; i < 5; i++)
	{
		preOrder(node->pChild[i]);
	}

	void inOrder(Node *node)
	{
	}
}
