#include<stdio.h>
int main()
{
	int i=1,sum=0,n=0;
	printf("请输入你想计算的数字：");
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("1--%d的值为：%d\n",n,sum);
	return 0;
}
