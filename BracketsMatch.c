#include<stdio.h>
#include<string.h>

int BracketsMatch(const char * str)
{
	if(str == NULL) return 0;

	int i=0;
	int nCount=0;

	while(i<strlen(str))
	{
		if(str[i]=='(')
		{
			nCount++;
		}
		else
		{
			if(nCount < 0)
			{
				return 0;
			}
			nCount--;
		}
		i++;
	}
	return nCount>0 ? 0 :1;
}

int main(void)
{
	int num=BracketsMatch("()()()((())))");
	printf("%d\n",num);
	return 0;
}
