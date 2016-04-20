 ///
 /// @file    btree.c
 /// @author  whisper(1546466593@qq.com)
 /// @date    2016-04-20 09:44:16
 ///

#include <stdio.h>
#include <malloc.h>
#define dim(x) sizeof(x) / sizeof(x[0])

typedef struct NODE
{
	char iData;
	struct NODE *pLChild;
	struct NODE *pRChild;
}Node, *pNode;

void PreOrder(Node *node)
{
	if(node == NULL)
		return;
	printf("%c ", node->iData);
	PreOrder(node->pLChild);
	PreOrder(node->pRChild);
}

void InOrder(Node *node)
{
	if(node == NULL)
		return;
	InOrder(node->pLChild);
	printf("%c ", node->iData);
	InOrder(node->pRChild);
}

void LastOrder(Node *node)
{
	if(node == NULL)
		return;
	LastOrder(node->pLChild);
	LastOrder(node->pRChild);
	printf("%c ", node->iData);
}

int GetNodeNum(Node *node)
{
	int nCount = 0;
	if(node != NULL)
	{
		++nCount;
		nCount += GetNodeNum(node->pLChild);
		nCount += GetNodeNum(node->pRChild);
	}
	return nCount;
}

int GetNodeDepth(Node *node)
{
	if(node == NULL)
		return 0;
	int iLDepth = GetNodeDepth(node->pLChild);
	int iRDepth = GetNodeDepth(node->pRChild);

	int iDepth = iLDepth > iRDepth ? iLDepth : iRDepth;
	return (iDepth + 1);
}

int main()
{
	char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char pid[] = {'\0', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E'};
	Node *root = NULL;
	Node *tree[10];

	int i, j;
	for(i = 0; i < dim(data); i++)
	{
		tree[i] = (Node*)malloc(sizeof(Node));
		tree[i]->iData = data[i];
		tree[i]->pLChild = NULL;
		tree[i]->pRChild = NULL;
	}
	
	for(i = 0; i < dim(data); i++)
	{
		if(pid[i] == '\0')
		{
			root = tree[i];
			continue;
		}

		for(j = 0; j < dim(data); j++)
		{
			if(pid[i] == tree[j]->iData)
			{
				if(tree[j]->pLChild == NULL)
				{
					tree[j]->pLChild = tree[i];
					break;
				}
				else if(tree[j]->pRChild == NULL)
				{
					tree[j]->pRChild = tree[i];
					break;
				}
			}
		}
	}
	printf("PreOrder:\n");
	PreOrder(root);
	printf("\n\n");
	
	printf("InOrder:\n");
	InOrder(root);
	printf("\n\n");

	printf("LastOrder:\n");
	LastOrder(root);
	printf("\n\n");

	printf("the node count :%d\n", GetNodeNum(root));
	printf("\n\n");
	
	printf("the depth is %d", GetNodeDepth(root));
	printf("\n\n");
	return 0;
}

