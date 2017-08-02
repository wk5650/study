#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"student.h"
#include"teacher.h"
#include"menu.h"


//教师登录界面
void teacher_login_test(int teacher_id)
{
	teacher_link_t *head=readfile();
	char num2[10]={'\0'};
	char *p=num2;
	p=getpass("你的密码:");
	while(head->next!=NULL)
	{
		if(strncmp(head->next->data.passwd,p,strlen(p))==0&&(teacher_id==head->next->data.id))
		{	
			//教师菜单
			teacher_menu(teacher_id);
			return;
		}
		head=head->next;
	}
	printf("登录失败！\n");
	return;
}

//教师菜单
void teacher_menu(int id)
{
	int ch=0;
	//教师菜单
	while(1)
	{
		system("clear");
		printf("\t\t************************\n");
		printf("\t\t*1.查看学生信息        *\n");
		printf("\t\t*2.录入学生信息        *\n");
		printf("\t\t*3.修改学生信息        *\n");
		printf("\t\t*4.删除学生信息        *\n");
		printf("\t\t*5.查看排名            *\n");
		printf("\t\t*6.修改登录密码        *\n");
		printf("\t\t*7.提交辞职            *\n");
		printf("\t\t*8.查看学生留言        * \n");
		printf("\t\t*9.根据姓名查看学生信息*\n");
		printf("\t\t*0.注销退出            *\n");
		printf("\t\t************************\n");
		printf("请输入你的选择：");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				//查看学生信息
				cat_student_info();
				break;
			case 2:
				//录入学生信息
				annal_student_info();
				break;
			case 3:
				//修改学生信息
				change_student_info();
				break;
			case 4:
				//删除学生信息
				delete_student_info();
				break;
			case 5:
				//查看学生排名
				cat_student_ranking();
				break;
			case 6:
				//修改登录密码
				change_passwd(id);
				break;
			case 7:
				//申请辞职
				bye(id);
				break;
			case 8:
				//查看学生留言
				cat_e();
				break;
			case 9:
				//根据姓名查看学生的信息
				cat_student_info_from_name();
				break;
			case 0:
				//摧毁链表(退出)
				destroy_teacher_list();
				print_menu();
				break;
			default:
				printf("没有这种操作！\n");
		}
		printf("按回车继续！\n");
		while(getchar()!='\n');
	}
}
//查看学生留言
void cat_e()
{
	int num=0;
	student_link_t *head=readfile1();
	printf("输入你想查看的学生id：");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(head->next!=NULL)
	{
		if(head->next->data.id==num)
		{
			if(strlen(head->next->data.e)==0)
			{
				printf("这名学生暂时没有留言\n");
				return;
			}else
			{
				printf("该学生的留言：\n");
				printf("%s\n",head->next->data.e);
				return;
			}
		}
		head=head->next;
	}
	printf("此id不存在\n");
	return;
}
//修改学生信息
void change_student_info()
{
	int num=0;
	int c=0;
	student_link_t *head=readfile1();
	student_link_t *temp=head;
	printf("输入想修改的学生的id：");
	scanf("%d",&num);
	while(getchar()!='\n');
	printf("\t\t********\n");
	printf("\t\t*1.id  *\n");
	printf("\t\t*2.姓名*\n");
	printf("\t\t*3.年龄*\n");
	printf("\t\t*4.性别*\n");
	printf("\t\t*5.班级*\n");
	printf("\t\t*6.数学*\n");
	printf("\t\t*7.语文*\n");
	printf("\t\t*0.退出*\n");
	printf("\t\t********\n");
	printf("输入你想修改的学生信息:");
	scanf("%d",&c);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id)
		{
			printf("原来的信息：\n");
			cat_student_info();
			switch(c)
			{
				case 1:
					printf("id:");
					scanf("%d",&temp->next->data.id);
					while(getchar()!='\n');
					break;
				case 2:
					printf("名字:");
					scanf("%s",temp->next->data.name);
					while(getchar()!='\n');
					break;
				case 3:
					printf("年龄:");
					scanf("%d",&temp->next->data.age);
					while(getchar()!='\n');
					break;
				case 4:
					printf("性别:");
					scanf("%s",temp->next->data.gender);
					while(getchar()!='\n');
					break;
				case 5:
					printf("班级:");
					scanf("%d",&temp->next->data.cl);
					while(getchar()!='\n');
					break;
				case 6:
					printf("数学:");
					scanf("%f",&temp->next->data.math);
					while(getchar()!='\n');
					break;
				case 7:
					printf("语文:");
					scanf("%f",&temp->next->data.chinese);
					while(getchar()!='\n');
					break;
				case 0:
					printf("未作变动\n");
					return;
				default :
					printf("没有这种操作\n");
					break;
			}
			writefile1(head);
			printf("修改后的学生信息：\n");
			printf("id\t姓名\t性别\t年龄\t班级\t密码\t数学\t语文\t留言\n");
			printf("%d\t%s\t%s\t%d\t%d\t%d\t%.2f\t%.2f\t%s\n",temp->next->data.id,temp->next->data.name,temp->next->data.gender,temp->next->data.age,temp->next->data.cl,temp->next->data.passwd,temp->next->data.math,temp->next->data.chinese,temp->next->data.e);
			return;
		}
		temp=temp->next;
	}
	printf("没有这个学生！\n");
	return;
}

//删除学生信息
void delete_student_info()
{
	int num=0;
	student_link_t *head=readfile1();
	student_link_t *temp=head;
	printf("请输入你想删除的学生的id:");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id)
		{
			temp->next=temp->next->next;
			writefile1(head);
			printf("删除成功\n");
			free(temp);
			return;
		}
		temp=temp->next;
	}
	printf("删除失败\n");
	return;
}

//学生排名
void cat_student_ranking()
{
	int r=0;
	printf("1.总分排名\n");
	printf("2.学号排名\n");
	printf("请选择：");
	scanf("%d",&r);
	while(getchar()!='\n');
	switch(r)
	{
		case 1:
			cat_student_score_ranking();
			break;
		case 2:
			cat_student_hao();
			break;
		case 3:
			printf("bye\n");
			break;
		default :
			printf("没有这个选项\n");
			break;
	}
	return;
}

//查看学号排名
void cat_student_hao()
{
	student_link_t *head=readfile1();
	student_link_t *p1=head->next;
	student_link_t *p2=NULL;
	student_link_t *max=NULL;
	student_link_t *temp=(student_link_t *)malloc(sizeof(student_link_t));
	while(p1->next!=NULL)
	{
		max=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->data.id<p2->data.id)
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
	printf("id\t名字\t性别\t年龄\t班级\t数学\t语文\n");
	while(head->next!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%d\t%.2f\t%.2f\n",head->next->data.id,head->next->data.name,head->next->data.gender,head->next->data.age,head->next->data.cl,head->next->data.math,head->next->data.chinese);
		head=head->next;
	}
	free(temp);
	printf("*********************************\n");
	return;
}

//查看总分排名
void cat_student_score_ranking()
{
	student_link_t *head=readfile1();
	student_link_t *temp=(student_link_t *)malloc(sizeof(student_link_t));
	student_link_t *max=NULL;
	student_link_t *p=head;
	student_link_t *p1=head->next;
	printf("总分排名为：\n");
	while(p1!=NULL)
	{
		max=p1;
		p=p1->next;
		while(p!=NULL)
		{
			if((max->data.math+max->data.chinese)<(p->data.math+p->data.chinese))
			{
				max=p;
				p=p->next;
			}else
			{
				p=p->next;
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
	printf("id\t姓名\t年龄\t性别\t班级\t总分\t数学\t语文\n");
	while(head->next!=NULL)
	{
		printf("%d\t%s\t%d\t%s\t%d\t%.2f\t%.2f\t%.2f\n",head->next->data.id,head->next->data.name,head->next->data.age,head->next->data.gender,head->next->data.cl,(head->next->data.math+head->next->data.chinese),head->next->data.math,head->next->data.chinese);
		head=head->next;
	}
	free(temp);
	printf("*********************************************************\n");
	return;
}

//修改自己的登录密码
void change_passwd(int id)
{
	int ch=0;
	char num1[10]={'\0'};
	char num[10]={'\0'};
	teacher_link_t *head=readfile();
	teacher_link_t *p=head;
	printf("请输入密码:");
	scanf("%s",num);
	while(getchar()!='\n');
	printf("请输入新密码：");
	scanf("%s",num1);
	while(getchar()!='\n');
	printf("确定修改(1/0)");
	scanf("%d",&ch);
	while(getchar()!='\n');
	if(ch==1)
	{
		while(p->next!=NULL)
		{
			if((id==p->next->data.id)&&strncmp(p->next->data.passwd,num,strlen(p->next->data.passwd))==0)
			{
				strncpy(p->next->data.passwd,num1,strlen(num1));
				writefile(head);
				printf("更改成功\n");
				return;
			}
			p=p->next;
		}
	}else
	{
		printf("放弃修改!\n");
		return;
	}
	

}

//提出辞职
void bye(int a)
{
	char ch='\0';
	char ch1='\0';
	teacher_link_t *head=readfile();
	printf("确定辞职？(y/n)");
	scanf("%c",&ch);
	while(getchar()!='\n');
	if(ch=='y')
	{
		while(head->next!=NULL)
		{
			if(a==head->next->data.id)
			{
				printf("真的确定？(y/n)");
				scanf("%c",&ch1);
				while(getchar()!='\n');
				if(ch=='y')
				{
					head->next->data.flag=1;
					writefile(head);
					printf("辞职申请成功\n");
					return;
				}
			}
			head=head->next;
		}
	}else
	{
		printf("此id不存在\n");
		return;
	}
}

//查看学生信息
void cat_student_info()
{
	student_link_t *head=readfile1();
	if(head->next==NULL)
	{
		printf("没有学生信息\n");
		return;
	}
	printf("id\t姓名\t性别\t年龄\t班级\t密码\t数学\t语文\t留言\n");
	while(head->next!=NULL)
	{
		printf("%d\t%s\t%s\t%d\t%d\t%d\t%.2f\t%.2f\t%s\n",head->next->data.id,head->next->data.name,head->next->data.gender,head->next->data.age,head->next->data.cl,head->next->data.passwd,head->next->data.math,head->next->data.chinese,head->next->data.e);
		head=head->next;
	}
	printf("\n");
	return;

}

//根据姓名查看学生的信息
void cat_student_info_from_name()
{
	char n1[10]={'\0'};
	student_link_t *head=readfile1();
	if(head->next==NULL)
	{
		printf("没有学生信息\n");
		return;
	}
	printf("请输入学生的姓名：");
	scanf("%s",n1);
	while(getchar()!='\n');
	while(head->next!=NULL)
	{
		if(strncmp(head->next->data.name,n1,strlen(n1))==0)
		{
			printf("id\t姓名\t密码\t年龄\t班级\t性别\t数学\t语文\n");
			printf("%d\t%s\t%d\t%d\t%d\t%s\t%.2f\t%.2f\n",head->next->data.id,head->next->data.name,head->next->data.passwd,head->next->data.age,head->next->data.cl,head->next->data.gender,head->next->data.math,head->next->data.chinese);
			return;
		}
		head=head->next;
	}
	printf("没有这名学生\n");
	return;

}

//录入学生信息
void annal_student_info()
{
	student_link_t *head=readfile1();
	student_link_t *p=head;
	student_link_t *temp=(student_link_t *)malloc(sizeof(student_link_t));
	if(temp==NULL)
	{
		printf("申请空间失败！\n");
		return;
	}
	temp->next=NULL;
	printf("请输入学生id：");
	scanf("%d",&temp->data.id);
	while(p->next!=NULL)
	{
		if(temp->data.id==p->next->data.id)
		{
			printf("此id已存在！");
			return;
		}
		p=p->next;
	}
	while(getchar()!='\n');
	printf("请输入学生姓名：");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("请输入学生密码：");
	scanf("%d",&temp->data.passwd);
	while(getchar()!='\n');
	printf("请输入学生性别：");
	scanf("%s",temp->data.gender);
	while(getchar()!='\n');
	printf("请输入学生年龄：");
	scanf("%d",&temp->data.age);
	while(getchar()!='\n');
	printf("请输入学生班级：");
	scanf("%d",&temp->data.cl);
	while(getchar()!='\n');
	printf("请输入学生数学成绩：");
	scanf("%f",&temp->data.math);
	while(getchar()!='\n');
	printf("请输入学生语文成绩：");
	scanf("%f",&temp->data.chinese);
	while(getchar()!='\n');
	if(head->next!=NULL)
	{
		temp->next=head->next;
		head->next=temp;
	}else{
		head->next=temp;
	}
	writefile1(head);
	printf("学生信息为：\n");
	cat_student_info();
	free(temp);
	return;

}


//摧毁链表
void destroy_teacher_list()
{
	free(readfile1());
	free(readfile());
	printf("已摧毁\n");
}

//将结构体链表写入文件
void writefile1(student_link_t *head)
{
	if(NULL==head)
	{
		printf("信息存储失败！\n");
		return;
	}
	FILE *fp;
	fp=fopen("student.txt","w");
	while(head->next!=NULL)
	{
		fwrite(head->next,sizeof(student_link_t),1,fp);
		head=head->next;
	}
	fclose(fp);
	return;
}


//从文件中将信息读到内存，即链表
student_link_t *readfile1()
{
	FILE *fp=fopen("student.txt","r");
	student_link_t *temp=(student_link_t *)malloc(sizeof(student_link_t));
	student_link_t *head=(student_link_t *)malloc(sizeof(student_link_t));
	head->next=NULL;
	while(fread(temp,sizeof(student_link_t),1,fp)>0)
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(student_link_t *)malloc(sizeof(student_link_t));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;
}
