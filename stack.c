#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int id;
	struct node * pNext;
}Stack;
typedef struct node2
{
	int count;
	Stack * ptop; 
}pTop;


void push(Stack ** pPtop,int id)
{
	Stack * ptemp = (Stack * )malloc(sizeof(Stack));
	ptemp->id = id;
	ptemp->pNext = NULL;

	ptemp->pNext = *pPtop;
	*pPtop=ptemp;
}
Stack * pop(Stack ** pPtop)
{
	if(*pPtop == NULL)
	{
		printf("stack is empty\n");
		exit(-1);
	}
	Stack * pMark = NULL;
	
	if(*pPtop != NULL)
	{
		pMark = *pPtop;
		*pPtop = (*pPtop)->pNext;
	}
	return pMark;
}
void print(Stack *ptop)
{
	while(ptop!=NULL)
	{
		printf("%d\n",ptop->id);
		ptop = ptop->pNext;
	}
}
int main(void)
{
	Stack * ptop=NULL;
	push(&ptop,1);
	push(&ptop,2);
	print(ptop);
	printf("\n");
	push(&ptop,3);
	push(&ptop,4);
	print(ptop);
	printf("\n");

	pop(&ptop);
	pop(&ptop);
	print(ptop);
	printf("\n");
	pop(&ptop);
	pop(&ptop);
	print(ptop);
	printf("\n");

	return 0;
}




