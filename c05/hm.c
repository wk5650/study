#include<stdio.h>
int main()
{
	int i=0,num=0;
	printf("请输入数字：");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
			for(int n=0;n<=num-i;n++){
				printf(" ");
			}
			for(j=0;j<(2*i-1);j++){
				printf("*");
			}
			printf("\n");
	}
	return 0;
}
