#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int user[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int com[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	srand((unsigned)time(NULL));
	while(1){
		int index=0;
		system("clear");//运行可在终端上运行的命令
		printf("1-->进攻\n2-->撤退\n输入你的选择：");
		char choose;
		int i=0;
		int life=0;
		scanf("%c",&choose);
		while(getchar()!='\n');
		switch(choose)
		{
			case '1':
//用户进攻
				for(i=0;i<3;i++)
				   {
				   index=rand()%15;
				   com[index]=0;
				   }
//	判断电脑	
				life=0;	
				for(i=0;i<15;i++)
				{
					life+=com[i];
				}
				printf("电脑：%d\n",life);
				if(life==0)
				{
					printf("玩家获胜");
					exit(1);
				}
//电脑反击
				for(i=0;i<3;i++)
				{
					index=rand()%15;
					user[index]=0;
				}
//判断用户
				life=0;
				for(i=0;i<15;i++)
				{
					life+=user[i];
				}
				printf("玩家：%d\n",life);
				if(life==0)
				{
					printf("电脑胜利");
					exit(1);
				}
				break;
			case '2':
				if(rand()%4==0)
				{
					printf("撤退成功");
					exit(1);
				}else{
					for(i=0;i<3;i++)
					{
						index=rand()%15;
						user[index]=0;
					}
//判断用户
					life=0;
					for(i=0;i<15;i++)
					{
						life+=user[i];
					}
					printf("玩家：%d\n",life);
					if(life==0)
					{
						printf("电脑胜利");
						exit(1);
					}

					}
				break;
			default:
				printf("输入错误\n");
		}
		printf("按回车继续\n");
		while(getchar()!='\n');
	}
	return 0;
}
