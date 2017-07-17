#include<stdio.h>
int main()
{
	int i=0,j=0,k=0,num=0;
	printf("输入：");
	scanf("%d",&num);
	getchar();
	for(i=0;i<num;i++)
	{
		for(k=num-i;k>0;k--)
		{
			printf(" ");
		}
		for(j=0;j<i;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
