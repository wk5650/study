#include<stdio.h>
//自定义函数
void myprintf(int i,int j);
int main()
{
	int a=0,b=0;
	myprintf(a,b);
	return 0;
}
void myprintf(int i,int j)
{
	printf("请输入：");
	scanf("%d",&i);
	while(getchar()!='\n');
	scanf("%d",&j);
	while(getchar()!='\n');
	printf("%d\n",i+j);
}

