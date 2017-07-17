#include<stdio.h>
int main(){
	float num=0.0,num1=0.0,num2=0.0;
	printf("请输入10个数字：");
	for(int i=0;i<10;i++){
		scanf("%f",&num);
		getchar();
		if(num>=0)
			num1=num+num1;
		else
			num2=num+num2;
	}
	printf("正数之和为：%.2f\n",num1);
	printf("负数之和为：%.2f\n",num2);
	}

