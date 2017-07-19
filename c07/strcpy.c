#include<stdio.h>
#include<string.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	char ch1[20]={'\0'};
	char ch2[20]={'\0'};
	printf("请输入数组1：");
	scanf("%s",ch1);
	while(getchar()!='\n');
	printf("请输入数组2：");
	scanf("%s",ch2);
	while(getchar()!='\n');
	printf("输入复制个数：");
	scanf("%d",&d);
	a=strlen(ch1);
	b=strlen(ch2);
	c=a+b;
	int i=0;
	if(sizeof(ch1)>b+1)
	{
		for(i=0;i<d&&ch2[i]!='\0';i++)
		{
			ch1[i]=ch2[i];
		}
		ch1[i]='\0';
	}
	printf("%s\n",ch1);
	return 0;
}
