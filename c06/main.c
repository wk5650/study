#include<stdio.h>
int main()
{
	int i=0,max=0;
	int a[5];
	printf("请输入5个数：\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		while(getchar()!='\n');
	}
	max=a[0];
	for(i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	printf("最大数为：%d\n",max);
}
