#include<stdio.h>
int main()
{
	int a1[5]={1,2,3,4,5};
	int a2[5]={6,7,8,9,10};
	int a3[5]={11,12,13,14,15};
	int * arr[3]={a1,a2,a3};
	//二维数组的原理
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
