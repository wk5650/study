#include<stdio.h>
#include<stdlib.h>
int main()
{
	float s1=0,s2=0;
	char ch='\0';
	printf("请输入:");
	scanf("%f%c%f",&s1,&ch,&s2);
	getchar();
	switch(ch){
		case('+'):
			printf("%f+%f=%f\n",s1,s2,s1+s2);
			break;
		case('-'):
			printf("%f-%f=%f\n",s1,s2,s1-s2);
			break;
		case('*'):
			printf("%f*%f=%f\n",s1,s2,s1*s2);
			break;
		case('/'):{
					  if(s2==0){
						  printf("除数不能为0\n");
						  exit(-1);
					  }else{
						  printf("%f/%f=%f\n",s1,s2,s1/s2);
					  }
					  break;
				  }
		default:
			printf("输入有误！\n");
	}
	return 0;
}
