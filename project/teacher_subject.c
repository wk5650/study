#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"student.h"
#include"teacher.h"
#include"menu.h"
#include"student.h"
#include"teacher_subject.h"

void teacher_subject_test(int id)
{
	char num1[10]={'\0'};
	char *p=num1;
	teacher_link_t *head=readfile();
	teacher_link_t *temp;
	p=getpass("请输入你的密码:");
	while(head->next!=NULL)
	{
		if(strncmp(head->next->data.passwd,p,strlen(p))==0&&(head->next->data.id==id))
		{
			//任课教师菜单
			temp=head->next;
			teacher_subject_menu(temp,id);
			return;
		}
		head=head->next;
	}
	printf("登录失败\n");
	return;
}

//任课教师菜单
void teacher_subject_menu(teacher_link_t *p,int id)
{

	int ch=0;
	while(1)
	{
		system("clear");
		printf("\t\t****************\n");
		printf("\t\t*1.查看学生信息*\n");
		printf("\t\t*2.修改学生信息*\n");
		printf("\t\t*3.查看排名    *\n");
		printf("\t\t*4.修改登录密码*\n");
		printf("\t\t*5.辞职        *\n");
		printf("\t\t*0.退出        *\n");
		printf("\t\t****************\n");
		printf("请输入你的选择:");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				//查看学生信息(自己所教的科目)
				cat_student_of_subject(id);
				break;
			case 2:
				//修改学生信息(自己所教的科目)
				change_student_of_subject(p,id);
				break;
			case 3:
				//查看排名(自己所教的科目)
				cat_student_ranking_subject(p,id);
				break;
			case 4:
				//修改登录密码
				change_passwd(id);
				break;
			case 5:
				//辞职
				bye(id);
				break;
			case 0:
				//退出
				destroy_teacher_list();
				printf("666\n");
				print_menu();
				break;
			default :
				printf("没有这个选项\n");
		}
		printf("按回车继续\n");
		while(getchar()!='\n');
	}
}

//查看学生信息(自己所教的科目)
void cat_student_of_subject(int id)
{
	char ch1[10]="math";
	char ch2[10]="chinese";
	teacher_link_t *head=readfile();
	student_link_t *shead=readfile1();
	while(head->next!=NULL)
	{
		if(id==head->next->data.id)
		{
			if(strncmp(head->next->data.subject,ch1,4)==0)
			{
				printf("id\t姓名\t年龄\t班级\t性别\t数学\n");
				while(shead->next!=NULL)
				{
					printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",shead->next->data.id,shead->next->data.name,shead->next->data.age,shead->next->data.cl,shead->next->data.gender,shead->next->data.math);
				shead=shead->next;
				}
				printf("\n");
				return;
			}else
			{
				printf("id\t姓名\t年龄\t班级\t性别\t语文\n");
				while(shead->next!=NULL)
				{
					printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",shead->next->data.id,shead->next->data.name,shead->next->data.age,shead->next->data.cl,shead->next->data.gender,shead->next->data.chinese);
					shead=shead->next;
				}
				printf("\n");
				return;
			}
		}
		head=head->next;
	}
}

//修改学生信息
void change_student_of_subject(teacher_link_t *p,int id)
{
	char ch1[5]="math";
	int num=0;
	student_link_t *head=readfile1();
	student_link_t *temp=head;
	printf("输入你想修改的学生id:");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id&&strncmp(p->data.subject,ch1,5)==0)
		{
			printf("原来信息为:\n");
			printf("id\t姓名\t年龄\t班级\t性别\t数学\n");
			printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",temp->next->data.id,temp->next->data.name,temp->next->data.age,temp->next->data.cl,temp->next->data.gender,temp->next->data.math);
			printf("新科目成绩:");
			scanf("%f",&temp->next->data.math);
			while(getchar()!='\n');
			writefile1(head);
			printf("修改后的学生信息为:\n");
			printf("id\t姓名\t年龄\t班级\t性别\t数学\n");
			printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",temp->next->data.id,temp->next->data.name,temp->next->data.age,temp->next->data.cl,temp->next->data.gender,temp->next->data.math);
			return;
		}
		else if(num==temp->next->data.id)
		{
			printf("原来信息为:\n");
			printf("id\t姓名\t年龄\t班级\t性别\t语文\n");
			printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",temp->next->data.id,temp->next->data.name,temp->next->data.age,temp->next->data.cl,temp->next->data.gender,temp->next->data.chinese);
			printf("新科目成绩:");
			scanf("%f",&temp->next->data.chinese);
			while(getchar()!='\n');
			writefile1(head);
			printf("修改后的学生信息为:\n");
			printf("id\t姓名\t年龄\t班级\t性别\t语文\n");
			printf("%d\t%s\t%d\t%d\t%s\t%.2f\n",temp->next->data.id,temp->next->data.name,temp->next->data.age,temp->next->data.cl,temp->next->data.gender,temp->next->data.chinese);
			return;

		}
		temp=temp->next;
	}
	printf("没有这个学生\n");
	return;
}


//查看排名
void cat_student_ranking_subject(teacher_link_t *p,int id)
{
	char ch[5]="math";
	student_link_t *head=readfile1();
	student_link_t *temp=(student_link_t *)malloc(sizeof(student_link_t));
	student_link_t *p1=head->next;
	student_link_t *p2;
	student_link_t *max;
	printf("学生排名为:\n");
	if(strncmp(p->data.subject,ch,5)==0)
	{
		while(p1!=NULL)
		{
			max=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(max->data.math<p2->data.math)
				{
					max=p2;
					p2=p2->next;
				}else
				{
					p2=p2->next;
				}
			}
			if(max!=p1)
			{
				temp->data=max->data;
				max->data=p1->data;
				p1->data=temp->data;
			}
			p1=p1->next;
		}
		printf("id\t姓名\t班级\t数学\n");
		while(head->next!=NULL)
		{
			printf("%d\t%s\t%d\t%.2f\n",head->next->data.id,head->next->data.name,head->next->data.cl,head->next->data.math);
			head=head->next;
		}
		free(temp);
		printf("*********************************************\n");
		return;
	}else
	{
		while(p1!=NULL)
		{
			max=p1;
			p2=p1->next;
			while(p2!=NULL)
			{
				if(max->data.chinese<p2->data.chinese)
				{
					max=p2;
					p2=p2->next;
				}else
				{
					p2=p2->next;
				}
			}
			if(max!=p1)
			{
				temp->data=max->data;
				max->data=p1->data;
				p1->data=temp->data;
			}
			p1=p1->next;
		}
		printf("id\t姓名\t班级\t语文\n");
		while(head->next!=NULL)
		{
			printf("%d\t%s\t%d\t%.2f\n",head->next->data.id,head->next->data.name,head->next->data.cl,head->next->data.chinese);
			head=head->next;
		}
		free(temp);
		printf("*********************************************\n");
		return;
	}

}
