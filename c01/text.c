#include<stdio.h>
int main()
{
	/*定义变量*/
	int price1,price2;
	float price3;
	double sum;
	/*给出变量的值*/
	price1=5;
	price2=100;
	price3=5.2;
	/*计算商品价格之和*/
	sum=price1+price2+price3;
	/*输出计算结果*/
	printf("三种商品的总价是%.2f\n",sum);
	return 0;

}
