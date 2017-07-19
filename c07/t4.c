#include<stdio.h>
#include<string.h>
int main()
{
	//gets(name) 没有边界检查 容易越界
	//scanf("%s",name) 残留回车，字符串不能有空格，没有边界检查
	int flag=0;
	char passwd1[20]={'\0'};
	char passwd2[20]={'\0'};
	printf("输入密码1：");
	scanf("%s",passwd1);
	while(getchar()!='\n');
	printf("输入密码2：");
	scanf("%s",passwd2);
	if(strlen(passwd1)==strlen(passwd2))
	{
		for(int i=0;i<20;i++)
	//for(int i=0;i<strlen(passwd1);i++)
		{
			if(passwd1[i]==passwd2[i])
			{
				flag=1;
			}else{
				printf("两者不一样\n");
				break;
			}
		}
		if(flag==1)
			printf("两者相同\n");
	}else{
		printf("两者不一样\n");
	}
	return 0;
}
