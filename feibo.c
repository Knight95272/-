#include<stdio.h>

int feiBo(int n)
{
	if(n < 0) return -1;
	if(n == 1 || n== 2)
	{
		return 1;
	}
	else
	{
		return feiBo(n-1) + feiBo(n-2);
	}

}

int main(void)
{
	printf("%d\n",feiBo(1));
	printf("%d\n",feiBo(2));
	printf("%d\n",feiBo(3));
	printf("%d\n",feiBo(4));
	printf("%d\n",feiBo(5));
	printf("%d\n",feiBo(6));

	return 0;
}
