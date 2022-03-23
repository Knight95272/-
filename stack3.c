#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int nValue;
	struct node * pNext;
}Data;

typedef struct stack
{
	int nCount;
	Data * pTop;
}Stack;

typedef struct queue
{
	Stack * pStack1;
	Stack * pStack2;
}Queue;

void q_init(Queue ** pQueue);
void q_push(Queue * pQueue,int nVal);
int q_pop(Queue * pQueue);

void init(Stack ** pStack);
void push(Stack * pStack,int nVal);
int pop(Stack * pStack);
void clear(Stack * pStack);
void destory(Stack ** pStack);
int GetTop(Stack * pStack);
int GetCount(Stack * pStack);
int IsEmpty(Stack * pStack);

void SqueueIn(Stack * pStack1,Stack *pStack2,int nVal);
int SqueueOut(Stack * pStack2);
int main(void)
{
	Queue * pQueue =NULL;
	Stack * pStack1 = NULL;
	Stack * pStack2 = NULL;
	init(&pStack1);
	init(&pStack2);
	SqueueIn(pStack1,pStack2,1);
	SqueueIn(pStack1,pStack2,2);
	SqueueIn(pStack1,pStack2,3);
	SqueueIn(pStack1,pStack2,4);
	SqueueIn(pStack1,pStack2,5);

	printf("%d\n",SqueueOut(pStack2));
	printf("%d\n",SqueueOut(pStack2));
	printf("%d\n",SqueueOut(pStack2));
	printf("%d\n",SqueueOut(pStack2));
	printf("%d\n",SqueueOut(pStack2));

	q_init(&pQueue);
	q_push(pQueue,1);
	q_push(pQueue,2);
	q_push(pQueue,3);
	q_push(pQueue,4);
	printf("q_push success\n");
	printf("%d\n",q_pop(pQueue));
	printf("%d\n",q_pop(pQueue));
	q_push(pQueue,5);
	q_push(pQueue,6);
	printf("%d\n",q_pop(pQueue));
	printf("%d\n",q_pop(pQueue));
	printf("%d\n",q_pop(pQueue));
	printf("%d\n",q_pop(pQueue));

	return 0;
}
void q_init(Queue ** pQueue)
{
	*pQueue =(Queue *)malloc(sizeof(Queue));
	init(&((*pQueue)->pStack1));
	init(&((*pQueue)->pStack2));
}
void q_push(Queue * pQueue,int nVal)
{
	if(IsEmpty(pQueue->pStack2))
	{
		push(pQueue->pStack1,nVal);
	}
	else
	{
		while(pQueue->pStack2->nCount)
		{
			push(pQueue->pStack1,pop(pQueue->pStack2));
		}
		push(pQueue->pStack1,nVal);
	}

}
int q_pop(Queue * pQueue)
{
	if(IsEmpty(pQueue->pStack1)!=1)
	{
		while(pQueue->pStack1->nCount)
		{
			push(pQueue->pStack2,pop(pQueue->pStack1));
		}
	}
	int num = pop(pQueue->pStack2);
	return num;

}
void SqueueIn(Stack * pStack1,Stack *pStack2,int nVal)
{
	int num =0;

	if(pStack2->nCount == 0)
	{
		push(pStack1,nVal);
	}
	else
	{
		while(pStack2->nCount != 0)
		{
			num = pop(pStack2);
			push(pStack1,num);
		}
		push(pStack1,nVal);
	}
	//未添加将stack1 的节点转到 stack2中
	while(pStack1->nCount!=0)
	{
		num = pop(pStack1);
		push(pStack2,num);
	}
}
int SqueueOut(Stack * pStack2)
{
	int num = 0;
	num = pop(pStack2);
	return num;
}
void init(Stack ** pStack)
{
	*pStack = (Stack *)malloc(sizeof(Stack));
	(*pStack)->nCount = 0;
	(*pStack)->pTop = NULL;
}
void push(Stack * pStack,int nVal)
{
	if(pStack == NULL)
	{
		printf("stack is empty\n");
		exit(-1);
	}

	Data * pTemp = (Data*)malloc(sizeof(Data));
	pTemp->nValue = nVal;

	pTemp->pNext = pStack->pTop;
	pStack->pTop = pTemp;
	pStack->nCount++;
}
int pop(Stack * pStack)
{
	if(pStack == NULL)
	{
		printf("stack is empty\n");
		exit(1);
	}
	if(pStack->pTop == NULL)
	{
		exit(1);
	}

	int num = pStack->pTop->nValue;
	Data * pDel = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext;
	free(pDel);
	pDel = NULL;
	pStack->nCount--;
	return num;
}
void clear(Stack * pStack)
{
	if( pStack==NULL || pStack->nCount==0) return;
	while(pStack->nCount != 0)
	{
		pop(pStack);
	}
}
void destory(Stack ** pStack)
{
	clear(*pStack);
	free(*pStack);
	*pStack = NULL;
}
int GetTop(Stack * pStack)
{
	if(pStack==NULL ||pStack->nCount == 0)
	{
		printf("stack is empty\n");
		exit(1);
	}
	return pStack->pTop->nValue;
}
int GetCount(Stack * pStack)
{
	if(pStack==NULL ||pStack->nCount == 0)
	{
		printf("stack is empty\n");
		exit(1);
	}
	return pStack->nCount;

}
int IsEmpty(Stack * pStack)
{
	
	if(pStack==NULL)
	{
		printf("stack is not exit\n");
		exit(1);
	}
	return pStack->nCount == 0 ? 1 : 0;
}
