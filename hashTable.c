#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct list
{
	int nValue;
	struct list * pNext;
}List;

List ** hashTable(int src[],int nlen)  //根据传递的数组创建哈希表
{
	if(src == NULL || nlen <=0 ) return 0; //数组为空，或者没有传数组元素个数直接返回
	//因为所传递的为指针而非数组，一定要传数组元素个数

	//表头
	List ** pHash = NULL;
	pHash = (List **)malloc(sizeof(List*)*nlen);
	memset(pHash,0,sizeof(List*)*nlen);

	//元素入表
	int nIndex; //下标
	List * pTemp = NULL; //添加的节点
	int i;
	
	for(i = 0;i<nlen;i++) //循环将数组的所有元素入表
	{
		nIndex = src[i]%nlen; //散列函数计算，得到下标位置

		pTemp = (List *)malloc(sizeof(List));  //添加的节点初始化
		pTemp->nValue = src[i];
		pTemp->pNext = pHash[nIndex];  //头添加,实现更快
		pHash[nIndex] = pTemp;
	}
	return pHash;
	
}
void HashSearch(List ** pHash,int nlen,int nNum)//哈希表的查找
{
	if(pHash == NULL) return; //哈希表为空直接返回
	
	int nIndex = nNum%nlen; //直接获得哈希表对应的下标

	List * pTemp = pHash[nIndex];
	while(pTemp)  //遍历对应下标所存的指针 所指向的内容是否与所要查询的值一致
	{
		if(pTemp->nValue == nNum)
		{
			printf("success %d\n",pTemp->nValue);
			return;
		}
		pTemp = pTemp->pNext;
	}
	printf("fail\n");
}
int main(void)
{
	int src[]={45,5,55,989,456,65,75,57,69,123,458,64};
	List ** pHash = NULL;
	pHash = hashTable(src,12);
	HashSearch(pHash,12,25);
	return 0;
}
