#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){


	srand((unsigned)time(NULL));
	int index=0,u=0;
	printf("1.剪刀\n");
	printf("2.石头\n");
	printf("3.布\n");
	printf("请选择你的选项:");
	scanf("%d",&u);
	getchar();
	index=rand()%2+1;
	if(u==1){
		if(index==1){
			printf("我出剪刀，打平了\n");\
		}else if(index==2){
			printf("我出石头，我赢了\n");
		}else{
			printf("我出布，你赢了\n");
		}
	}
	else if(u==2){
		if(index==1){
			printf("我出剪刀，你赢了\n");\
		}else if(index==2){
			printf("我出石头，打平\n");
		}else{
			printf("我出布，我赢了\n");
		}
	}
	else if(u==3){
		if(index==1){
			printf("我出剪刀，我赢了\n");\
		}else if(index==2){
			printf("我出石头，你赢了\n");
		}else{
			printf("我出布，打平\n");
		}
	}
	else{
		printf("出错啦！\n");
	}
	return 0;
}
