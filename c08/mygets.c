#include<stdio.h>
void mgets(char * ch,int size);
int main()
{
	char ch[20]={'\0'};
	printf("输入：");
	mgets(ch,20);
	printf("%s\n",ch);
	return 0;
}
void mgets(char * ch,int size)
{
	int i=0;
	for(i=0;i<size-1;i++)
	{
		ch[i]=getchar();
		if(ch[i]=='\n')
		{
			break;
		}
	}
	ch[i]='\0';
	if(i==size-1)
	{
		while(getchar()!='\n');
	}
}
