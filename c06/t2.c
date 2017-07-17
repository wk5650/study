#include<stdio.h>
int main()
{
	int i=0,j=0,max=0,n=0,tmp=0;
	int a[5]={0};
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		while(getchar()!='\n');
	}
	max=a[0];
	for(i=0;i<5;i++)
	{
	/*	max=0;
		n=0;*/
		for(j=i;j<5;j++)
		{
			if(max<a[j])
			{
				max=a[j];
				n=j;
			}
		}
		//k=i;
		//for(j=i;j<5;j++){
		//if(a[k]<a[j]){
		//k=j;
		//}
		//if(k!=i){
		//int t=a[k];
		//a[k]=a[i];
		//a[i]=t;

	/*	tmp=a[n];
		a[n]=a[i];
		a[i]=tmp;*/
		a[j]=a[i];
		a[i]=max;
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
