#include<stdio.h>
int main()
{
	int year=0;
	printf("请输入一个年份：");
	scanf("%d",&year);
	getchar();
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		printf("这是闰年\n");
	}else{
		printf("这是平年\n");
	}
	return 0;
}
