#include<stdio.h>
int main()
{
	int t=0,i=0,min=0,max=0;
	int n=0,m=0;
	int a[5];
	printf("输入5个数：\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		while(getchar()!='\n');
	}
	min=a[0];
	for(i=0;i<5;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			n=i;
		}
	}
	max=a[0];
	for(i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			m=i;
		}
	}
	t=a[n];
	a[n]=a[m];
	a[m]=t;
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
/*	t=min;
	min=max;
	max=t;
	h=n;
	n=m;
	m=h;
	printf("最大值为：%d\n最小值为：%d\n",max,min);
	printf("%d%d\n",n,m);*/
	return 0;
}
