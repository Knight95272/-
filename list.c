#include<stdio.h>
#include<stdlib.h>



typedef struct Mylist
{
	int id;
	struct Mylist * pNext;
}list_t;

void Createlist(list_t ** phead)
{
	list_t * pTemp=NULL;
	list_t * pTail=NULL;

	int nlen;
	int nNum;
	printf("请输入初始列表的长度\n");
	scanf("%d",&nlen);


	while(nlen)
	{
		printf("请输入值\n");
		scanf("%d",&nNum);
		pTemp = (list_t *)malloc(sizeof(list_t));
		pTemp->id = nNum;
		pTemp->pNext = NULL;

		if(*phead == NULL)
		{
			*phead = pTemp;
		}
		else
		{
			pTail->pNext = pTemp;
		}
		pTail = pTemp;
		nlen--;
	}
}
void myprint(list_t * phead)
{
	while(phead)
	{
		printf("%d",phead->id);
		phead = phead->pNext;
	}
	printf("\n");
}
void rePrint(list_t * phead)
{
	if(phead == NULL) return;

	rePrint(phead->pNext);
	printf("%d\n",phead->id);
}
int main(void)
{
	list_t * phead=NULL; //注意不赋值为空，为野指针，会出现段错误
	Createlist(&phead);
	myprint(phead);
	rePrint(phead);
	return 0;

}
