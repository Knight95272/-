#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * GetNext(const char * match);
int sunday(const char * src , const char * match);

int main()
{
	char * src = "asdjhasjhdjashd";
	char * match = "jha";
	printf("%d\n",sunday(src,match));

	return 0;
}
int * GetNext(const char * match)
{
	int pNext[256];

	int i;
	for(i=0;i<256;i++)
	{
		pNext[i] = -1;
	}

	int n = strlen(match)-1;
	
	while(n>=0)
	{
		if(pNext[match[n]]==-1)
		{
			pNext[match[n]] = n;
		}
		n--;
	}
	printf("GetNext success\n");
	int * p = pNext;  //数组名表示为首元素的首地址，用指针转换则改为整个数组的首地址
	return p;
}
int sunday(const char * src , const char * match)
{
	if(src == NULL || match == NULL) return -1;

	int * pNext = NULL;
	pNext = GetNext(match); 

	printf("[1]\n");
	int i = 0;
	int j = 0;
	int mark = 0;
	int n = strlen(match);

 	//printf("%d\n",pNext[0]); //测试 不能成功
	
	while(i<strlen(src) && j<strlen(match))
	{
		if(src[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			i = mark + n;
			j = 0;

			printf("[2]\n");
			if(pNext[src[i]] == -1)
			{
				i++;
			}
			else
			{
				i = i - pNext[src[i]];
			}
			mark = i;
		}
	}
	if(j == strlen(match))
	{
		printf("success.\n");
		return i-j;
	}
	else
	{
		printf("fail.\n");
		return -1;
	}
}
