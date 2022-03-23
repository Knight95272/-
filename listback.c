#include<stdio.h>
#include<stdlib.h>


typedef struct Mylist
{
	int id;
	struct Mylist * pNext;
}list_t;


void back(list_t **phead)
{
	//添加异常直接退出
	if((*phead)->pNext==NULL || *phead == NULL) exit(-1);
	list_t *p_0;
	list_t *p_1;
	list_t *p_2;

	p_0= NULL;
	p_1= *phead;
	p_2= (*phead)->pNext;


	while(p_2!=NULL)
	{
		p_1->pNext = p_0;
		p_0 = p_1;
		p_1 = p_2;
		p_2 = p_2->pNext;
	}
	p_1->pNext = p_0;
	//注意此时*phead 里面的元素为1,是最后一个节点，需要重新赋值
	*phead = p_1;
}
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
int main(void)
{
	list_t * phead=NULL; //注意不赋值为空，为野指针，会出现段错误
	Createlist(&phead);
	myprint(phead);
	//倒置输出只输出一个节点的原因  phead没有重新赋值，倒置之后指向的为最后一个元素的地址
	back(&phead);
	myprint(phead);
	return 0;

}

