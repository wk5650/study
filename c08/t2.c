#include<stdio.h>
#include<stdlib.h>
void printfarray(int * arr,int size);
int check(int *arr,int size);
int main()
{
	int a[5]={0};
//	printf("请输入：");
//	scanf("%d",a);
//	while(getchar()!='\n');
	int re=check(a,5);
	if(re==0)
	{
		printf("不是\n");
	}else{
		printf("是\n");
	}
	printfarray(a,sizeof(a));
	return 0;
}
int check(int * arr,int size)
{
	int i=0;
	for(i=0;i<size/2;i++)
	{
		if(arr[i]!=arr[size-i-1])
		{
			return 0;
		}
		else{
			return 1;
		}
	}
}
/*void printfarray(int *arr,int size)
{

	int i=0;
	int flag=0;
	for(i=0;i<size/2;i++)
	{
		if(arr[i]==arr[size-1-i])
		{
			flag=1;
		}else{
			printf("不是\n");
			break;
		}
	}
	if(flag==1)
		printf("是回文数\n");
}*/
