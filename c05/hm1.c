#include<stdio.h>
int main()
{
	int i=0,num=0,j=0;
	printf("请输入数字：");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
			for(int n=1;n<=num-i;n++){
				printf(" ");
			}
			for(j=0;j<(2*i-1);j++){
				printf("*");
			}
			printf("\n");
	}
	for(i=num-1;i>0;i--)
	{
		for(int n=num-i;n>=1;n--)
			printf(" ");
		for(j=2*i-1;j>0;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
