#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#include"teacher.h"
#include"menu.h"


//学生登录界面
void student_login_test()
{
	student_link_t *head=readfile1();
	int s_id=0;
	int num=0;
	printf("请输入你的id：");
	scanf("%d",&s_id);
	while(getchar()!='\n');
	printf("请输入你的密码：");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(head->next!=NULL)
	{
		if(num==head->next->data.passwd&&s_id==head->next->data.id)
		{
			student_menu(s_id);
			return;
		}
		head=head->next;
	}
	printf("登录失败\n");
	return;
}

//学生菜单
void student_menu(int id)
{
	int ch=0;
	while(1)
	{
		system("clear");
		printf("\t\t****************\n");
		printf("\t\t*1.查看总分排名*\n");
		printf("\t\t*2.修改登录密码*\n");
		printf("\t\t*3.给老师留言  *\n");
		printf("\t\t*0.退出        *\n");
		printf("\t\t****************\n");
		printf("请输入你的选择：\n");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				//查看自己的总分排名
				cat_score();
				break;
			case 2:
				//修改自己的登录密码
				change_student_passwd(id);
				break;
			case 3:
				//给老师留言
				e_to_teacher();
				break;
			case 0:
				//退出
				logout();
				print_menu();
				break;
			default :
				printf("没有这个操作！\n");
		}
		printf("按回车继续\n");
		while(getchar()!='\n');
	}
}


//查看自己的总分排名
void cat_score()
{
	int num=0;
	cat_student_score_ranking();
}

//修改自己的登录密码
void change_student_passwd(int id)
{
	int num2=0;
	int num3=0;
	char ch='\0';
	student_link_t *head=readfile1();
	student_link_t *temp=head;
	printf("请输入原密码：");
	while(getchar()!='\n');
	printf("输入新密码:");
	scanf("%d",&num2);
	while(getchar()!='\n');
	printf("请确认密码：");
	scanf("%d",&num3);
	while(getchar()!='\n');
	if(num2!=num3)
	{
		printf("密码错误！\n");
		return;
	}
	printf("确定修改(y/n)");
	scanf("%c",&ch);
	while(getchar()!='\n');
	switch(ch)
	{
		case 'y':
			while(temp->next!=NULL)
			{
				if(id==temp->next->data.id)
				{
					temp->next->data.passwd=num3;
					writefile1(head);
					printf("修改成功\n");
					free(head);
					return;
				}
				temp=temp->next;
			}
			printf("修改失败\n");
			break;
		case 'n':
			printf("已放弃修改\n");
			return;
		default :
			printf("输入错误\n");
			break;
	}
	return;
}

//给老师留言
void e_to_teacher()
{
	int num=0;
	student_link_t *head=readfile1();
	student_link_t *temp=head;
	printf("输入你的id:");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id)
		{
			printf("你想说的话:\n");
			scanf("%s",temp->next->data.e);
			while(getchar()!='\n');
			writefile1(head);
			printf("留言成功\n");
			return;
		}
		temp=temp->next;
	}
	printf("留言失败\n");
	return;
}

//注销(返回登录界面)
void logout()
{
	free(readfile1());
}
		
