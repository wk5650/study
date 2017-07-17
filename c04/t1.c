#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	//将时间设置为随机数种子
	//整个程序中只要有一次就好
	srand((unsigned)time(NULL));
	int index=0;
	printf("1.黄山\n");
	printf("2.沙县\n");
	printf("3.盖浇饭\n");
	printf("4.东北面\n");
	printf("5.不吃\n");
	index=rand()%5+1;//0--4
	switch(index){
		case 1:
			printf("1.黄山\n");
			break;
		case 2:
			printf("2.沙县\n");
			break;
		case 3:
			printf("3.盖浇饭\n");
			break;
		case 4:
			printf("4.东北面\n");
			break;
		case 5:
			printf("5.不吃\n");
			break;
	}
	return 0;
}
