#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i=0,a=0,b=0,c=0,d=0,j=0;
	char ch1[20]={'\0'};
	char ch2[20]={'\0'};
	printf("输入字符串1：");
	scanf("%s",ch1);
	while(getchar()!='\n');
	printf("输入字符串2：");
	scanf("%s",ch2);
	while(getchar()!='\n');
	a=strlen(ch1)+strlen(ch2);
	b=strlen(ch1);
	c=strlen(ch2);
	d=sizeof(ch1);
	if(sizeof(ch1)>=a+1)
	{
		for(i=0;i<c;i++)
		{
			ch1[b+i]=ch2[i];
			}
		
	}else{
		for(j=0;j<d-1-b;j++)
		{
			ch1[b+j]=ch2[j];
			if(strlen(ch1)==d){
				getchar()==ch2[j];
			}
		}
	}
	printf("%s\n",ch1);
	return 0;
}
