#include<stdio.h>
int main()
{
/*	int num=0;
	printf("请输入一个五位数：");
	scanf("%d",&num);
	getchar();
	for(int i=0;i<5;i++)
	{
		printf("%d",num%10);
		num=num/10;

	}
	*/

	int num=0;
	printf("请输入一个数：");
	scanf("%d",&num);
	getchar();
	while(num!=0){
		printf("%d",num%10);
		num=num/10;
	}
/*	for(int i=0;i<n;i++)
		{
			printf("%d",num%10);
			num=num/10;
		}
		*/
		return 0;
}
