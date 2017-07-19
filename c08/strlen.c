#include<stdio.h>
int str(char * ch);
int main()
{
	int len=0;
	char ch[20]={'\0'};
	printf("输入字符串：");
	scanf("%s",ch);
	while(getchar()!='\n');
	len=str(ch);
	printf("%d\n",len);
	return 0;
}
int str(char * ch)
{
	int i=0;
	while(ch[i]!='\0')
	{
		i++;
	}
	return i;
}
