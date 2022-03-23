#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int nValue;
	struct node * pNext;
}Stack;
typedef struct node1
{
 	int count;
	Stack * pTop;
}Ptop;

void init(Ptop ** p_top)
{
	Ptop * ptemp =(Ptop *)malloc(sizeof(Ptop));
	ptemp->pTop=NULL;
	ptemp->count =0;
}
void push(Ptop ** p,int nValue)
{
	Stack * ptemp = (Stack *)malloc(sizeof(Stack));
	ptemp->nValue = nValue;
	ptemp->pNext = NULL;

	(*p)->pTop = ptemp;
}
Stack * pop(Ptop ** p)
{
	Stack * pMark = NULL;
	if((*p)->pTop == NULL)
	{
		printf("stack is empty\n");
		exit(1);
	}
	pMark = (*p)->pTop;
	(*p)->pTop = (*p)->pTop->pNext;
	return pMark;
}
void clear(Ptop ** p)
{
	
}
void destroy(Ptop ** p_top)
{
	
}

void print(Ptop * p)
{
	while(p->pTop!=NULL)
	{
		printf("%d\n",(p->pTop)->nValue);
		p->pTop = (p->pTop)->pNext;
	}
}
int main(void)
{
	Ptop * p =NULL;
	init(&p);
	push(&p,1);
	printf("增加成功\n");
	push(&p,2);
	push(&p,3);
	push(&p,4);
	print(p);


	return 0;
}



