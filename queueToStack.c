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

typedef struct stack
{
	Queue * pQueue1;
	Queue * pQueue2;
}Stack;
void init(Queue ** pQueue);
void push(Queue * pQueue,int nVal);
int pop(Queue * pQueue);
int IsEmpty(Queue * pQueue);
int FindLast(int n,int k);

void s_init(Stack ** pStack);
void s_push(Stack * pStack,int nVal);
int s_pop(Stack * pStack);

int main(void)
{
	Stack * pStack = NULL; //注意赋值为空
	s_init(&pStack);
	s_push(pStack,1);
	s_push(pStack,2);
	s_push(pStack,3);
	s_push(pStack,4);
	s_push(pStack,5);
	printf("成功push\n");
	printf("%d\n",s_pop(pStack));
	printf("%d\n",s_pop(pStack));
	printf("%d\n",s_pop(pStack));
	printf("%d\n",s_pop(pStack));
	printf("%d\n",s_pop(pStack));
	return 0;
}
void s_init(Stack ** pStack)
{
	*pStack = (Stack *)malloc(sizeof(Stack));
	//(*pStack)->pQueue1 = NULL;
	//(*pStack)->pQueue2 = NULL; 是调用初始化，不是赋值为空，赋值为空并没有指向队列的指针
	init(&((*pStack)->pQueue1));
	init(&((*pStack)->pQueue2));
}
void s_push(Stack * pStack,int nVal)
{
	printf("1 已进入\n");
	if(pStack->pQueue1->nCount == 0)
	{
		printf("2\n");
		push(pStack->pQueue2,nVal);
	}
	else
	{
		printf("2\n");
		push(pStack->pQueue1,nVal);
	}
}
int s_pop(Stack * pStack)
{
	if(pStack->pQueue1->nCount == 0 && pStack->pQueue2->nCount == 0) return -1;

	int num = 0;
	if(pStack->pQueue1->nCount != 0 )
	{
		while(pStack->pQueue1->nCount > 1)
		{
			push(pStack->pQueue2,pop(pStack->pQueue1));
		}
		num = pop(pStack->pQueue1);
	}
	else
	{
		while(pStack->pQueue2->nCount > 1)
		{
			push(pStack->pQueue1,pop(pStack->pQueue2));
		}
		num = pop(pStack->pQueue2);
	}
	return num;
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
