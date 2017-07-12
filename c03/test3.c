#include<stdio.h>
int main()
{
//定义成绩s1,s2.s3
	float s1,s2,s3;
//定义总分sum
	float sum;
//定义平均分avage
	double avg;
	printf("请输入成绩:");
//输入成绩
	scanf("%f%f%f",&s1,&s2,&s3);
//计算总分以及平均分
	sum=s1+s2+s3;
	avg=sum/3.0;
//输出结果
	printf("总分是:%.2f,平均分是:%.2lf\n",sum,avg);
	
//控制printf输出的宽度
	
	
	return 0;
}

