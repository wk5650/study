#include<stdio.h>
int main()
{
	int i=0,j=0,n=0;
//	printf("请输入循环次数：");
//	scanf("%d",&n);
	for(n=1;n<5;n++){
	for(i=0;i<n;i++)
	{
		printf("%c",65+i);
	}
	for(j=n;j>0;j--)
	{
		printf("%d",j);
	}
	printf("\n");
	}
	return 0;
}
