#include<stdio.h>
int main()
{
	//判断字符串中的有效长度
	int count=0;
	int i=0;
	char name[20]={'\0'};
	printf("输入：");
	scanf("%s",name);
/*	for(i=0;i<20;i++)
	{
		if(name[i]=='\0')
		{
			printf("%d",i);
			break;
		}
	}*/
	//strlen(name) 4
//	sizeof(name) 20
	while(1)
	{
		if(name[count]!='\0')
		{
			count++;
		}else{
			break;
		}
	}
	printf("%d\n",count);
	return 0;
}
