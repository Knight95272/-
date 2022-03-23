#include<stdio.h>
#include<stdlib.h>




int main(void)
{
	char * str ="hahaha";
	char str1[] = "hahaha";
	char str2[] ={'a','b'};
	printf("%d\n",sizeof(str));  // 4
	printf("%d\n",sizeof(str1));  // 7
	printf("%d\n",sizeof(str2)); // 2
	printf("%d\n",sizeof(*str)); //1
	printf("%d\n",sizeof(*str1)); //1
	printf("%d\n",sizeof(*str2)); //1
	printf("%c\n",*(str++)); //h
	printf("%c\n",*(++str)); //h
	//printf("%c\n",*(str1++)); //不能++ 


	return 0;
}
