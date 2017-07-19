#include<stdio.h>
int main()
{
	int i=0;
	char name[20]={'\0'};
	printf("请输入：");
	for(i=0;i<19;i++)
	{
		name[i]=getchar();
		if(name[i]=='\n'){
			break;
		}
	}
	name[i]='\0';
	if(i==19){
		while(getchar()!='\n');
	}
	printf("%s",name);
	return 0;
}
