#include<stdio.h>
int main()
{
	int sum=0;
	int a[5]={0};
	int * p=&a[0];
	printf("输入5个数：");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&p[i]);
		while(getchar()!='\n');
	}
	for(int i=0;i<5;i++)
	{
		sum+=*(p+i);
	}
	printf("平均数：%d\n",sum/5);
	return 0; 
}
