#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int *GetNext(const char * pMatch)
{
	int i;
	int j;
	int * pNext = (int *)malloc(sizeof(int)*strlen(pMatch));

	pNext[0] = 0;
	i = 1;
	j = i - 1;

	while(i < strlen(pMatch)) //< 如果为<=则会报错
	{
		if(pMatch[i] == pMatch[pNext[j]])
		{
			pNext[i] = pNext[j] + 1;
			i++;
			j=i-1;
		}
		else
		{
			if(pNext[j] == 0)
			{
				pNext[i] = 0;
				i++;
				j=i-1;
			}
			else
			{
				j = pNext[j]-1;
			}
		}
	}
	return pNext;
}
int KMP(const char * src,const char * match)
{
	if(src == NULL || match == NULL ) return -1;

	int * pNext = NULL;
	pNext = GetNext(match);

	int i = 0;
	int j = 0;

	while(i<strlen(src) && j<strlen(match))
	{
		if(src[i] == match[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = pNext[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j == strlen(match))
	{
		printf("success.\n");
		return i-j;
	}
	else
	{
		printf("fail\n");
		return -1;
	}
}

int main(void)
{
	char * src = "asgasdasdhjkasdhs";
	char * match = "asd";

	printf("%d\n",KMP(src,match));
	return 0;
}
