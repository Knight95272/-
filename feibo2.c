#include<stdio.h>



unsigned int feibo(unsigned int num)
{
	if(num == 1||num == 2) return 1;
	if(num == 0) return -1;
	unsigned int fn;
	unsigned int fn_1 = 1;
	unsigned int fn_2 = 1;
	int i;
	for(i=3;i<=num;i++)
	{
		fn = fn_1 + fn_2;

		fn_2 = fn_1;
		fn_1 = fn;
	}

	return fn;
}

int main(void)
{
	printf("%d\n",feibo(8));
	return 0;
}
