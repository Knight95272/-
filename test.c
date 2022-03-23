#include<stdio.h>



int main(void)
{
	int a[5]={1,2,3,4,5};
	int *p1 = (int*)((int)&a+1);
	printf("%p\n",&a);
	printf("%p\n",p1);//输出对应地址

	printf("%d\n",*p1);
	printf("%d\n",*((int *)((int)&a +1)));
	return 0;
}
