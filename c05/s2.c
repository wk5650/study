#include<stdio.h>
int main(){
	int i=0;
	int flag=0;
	for(i=1;i<101;i++)
	{
		flag=1;
		for(int j=2;j<i;j++){
			if(i%j==0)
				flag=0;
		}
		if(flag)
			printf("%d\n",i);
	}
	return 0;
}
