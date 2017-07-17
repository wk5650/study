#include<stdio.h>
int main(){
	char ch='\0';
	printf("输入一个字母:");
	scanf("%c",&ch);
	getchar();
	//应写成ch>96 否则限制太死，造成闭区间 float型
	if(ch>=97&&ch<=122){
		printf("%c\n",ch-32);
	}else if(ch>=65&&ch<=90){
		printf("%c\n",ch+32);
	}
	else{
		printf("输入错误！");
	}
	return 0;
}
