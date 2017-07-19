#include<stdio.h>

void ex(int *a,int *b);
int main()
{
	int i=0,j=0;
	int re=0;
	printf("输入：");
	scanf("%d",&i);
	while(getchar()!='\n');
	scanf("%d",&j);
	ex(i,j);
	printf("%d\t%d\n",i,j);
	return 0;
}
void ex(int *a,int *b)
{
	int t=0;
	t=*a;
	*a=*b;
	*b=*t;
}
