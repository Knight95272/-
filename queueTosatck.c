#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int nValue;
	struct node * pNext;
}Data;
typedef struct queue
{
	int nCount;
	Data * pTail;
	Data * pHead;
}Queue;

void init(Queue ** pQueue);
void push(Queue * pQueue,int nVal);
int pop(Queue * pQueue);
int IsEmpty(Queue * pQueue);
int FindLast(int n,int k);

int main(void)
{
	int num = FindLast(10,3);
	printf("%d\n",num);
	return 0;
}
int FindLast(int n,int k)
{
	Queue * pQueue =NULL;
	init(&pQueue);

	int nCount = 0;	
	int i = 1;
	int num = 0;
	while(i<=n)
	{
		push(pQueue,i);
		i++;
	}

	while(nCount < k)
	{
		nCount++;
		num = pop(pQueue);
		if(nCount == k)
		{
			nCount = 0;
			continue;
		}
		else
		{
			push(pQueue,num);
		}
		if(pQueue->nCount == 1) break;
	}

	return num;
}
void init(Queue ** pQueue)
{
	*pQueue = (Queue *)malloc(sizeof(Queue));
	(*pQueue)->pHead = NULL;
	(*pQueue)->pTail = NULL;
	(*pQueue)->nCount = 0;
}
void push(Queue * pQueue,int nVal)
{
	if(pQueue == NULL)
	{
		printf("queue is not exit\n");
		exit(1);
	}
	Data * pTemp = (Data *)malloc(sizeof(Data));
	pTemp->nValue = nVal;
	pTemp->pNext = NULL;

	if( pQueue-> pHead == NULL)
	{
		pQueue->pHead = pTemp;
	}
	else
	{
		pQueue->pTail->pNext = pTemp;
	}
	pQueue->pTail = pTemp;
	pQueue->nCount++;

}
int pop(Queue * pQueue)
{
	if(pQueue == NULL || pQueue->nCount == 0) return -1;
	Data * pDel = NULL;
	pDel = pQueue->pHead;
	int num = pQueue->pHead->nValue;
	pQueue->pHead = pQueue->pHead->pNext;
	free(pDel);
	pDel = NULL;
	pQueue->nCount--;

	if(pQueue->nCount == 0)
	{
		pQueue->pTail=NULL;
	}
	return num;
}
int IsEmpty(Queue * pQueue)
{
	if(pQueue==NULL)
	{
		printf("queue is not exit\n");
		exit(1);
	}
	return pQueue->nCount == 0?1:0;
}
