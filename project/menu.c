#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include"menu.h"
#include"teacher.h"
#include"student.h"
#include"teacher_subject.h"
//主界面菜单

void print_menu()
{
	char ch='\0';
	while(1)
	{
		system("clear");
		printf("\t\t**********************\n");
		printf("\t\t*欢迎使用学生管理系统*\n");
		printf("\t\t*1.管理员登录        *\n");
		printf("\t\t*2.教师登录          *\n");
		printf("\t\t*3.学生登录          *\n");
		printf("\t\t*0.退出              *\n");
		printf("\t\t**********************\n");
		printf("请输入你的选择:\n");
		scanf("%c",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case MENU_CON:
				//管理员登录验证
				cizhi();
				controller_login_test();
				break;
			case MENU_TEACHER:
				//教师类别认证
				teacher_type();
				break;
			case MENU_STUDENT:
				//学生登录验证
				student_login_test();
				break;
			case MENU_EXIT:
				printf("谢谢使用，再见！\n");
				exit(0);
			default:
				printf("没有这个选项!\n");
		}
		printf("按回车继续\n");
		while(getchar()!='\n');
	}
}

//辞职处理
void cizhi()
{
	int b=0;
	teacher_link_t *head=readfile();
	teacher_link_t *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->next->data.flag!=0)
		{
			printf("工号为%d的教师辞职\n",temp->next->data.id);
			printf("同意/不同意(1/0)");
			scanf("%d",&b);
			while(getchar()!='\n');
			if(b==1)
			{
				delete_teacher_info();
				return;
			}else{
				temp->next->data.flag=0;
				writefile(head);
				return;
			}
		}
		temp=temp->next;
	}

}
//教师类别认证
void teacher_type()
{
	int num=0;
	int num1=0;
	printf("请输入你的id:");
	scanf("%d",&num);
	while(getchar()!='\n');
	num1=num;
	while(num>2)
	{
		num=num/10;
	}
	if(num==1)
	{
		teacher_login_test(num1);
		return;
	}else
	{
		teacher_subject_test(num1);
		return;
	}
}

//管理员登录验证
void controller_login_test()
{
	int i=0;
	char ch1[5]={'\0'};
	char ch2[5]={'\0'};
	char ch[5]={'1','2','3'};
	char name_ch[5]="root";
	char *p=ch2;
	char a[37]={"0123456789qwertyuioplkjhgfdsazxcvbnm"};
	char b[5]={'\0'};
	char c[5]={'\0'};
	srand((unsigned)time(NULL));
	for(i=0;i<4;i++)
	{
		int j=rand()%36;
		b[i]=a[j];
	}
	printf("验证码:%s\n",b);
	printf("请输入验证码:");
	scanf("%s",c);
	while(getchar()!='\n');
	if(strncmp(b,c,4)==0)
	{
		for(i=0;i<3;i++)
		{
			printf("你的帐号：");
			scanf("%s",ch1);
			while(getchar()!='\n');
			p=getpass("你的密码:");
			if(strncmp(ch,p,5)==0&&strncmp(name_ch,ch1,5)==0)
			{
				printf("欢迎使用!\n");
				//管理员菜单
				print_menu_controller();
				return ;
			}else
			{
				printf("登录失败!请重新登录\n");
			}
		}
	}else
	{
		printf("验证码错误\n");
	}
}

void print_menu_controller()
{
	int c=0;
	while(1)
	{
		system("clear");
		printf("\t\t******************\n");
		printf("\t\t*1.教师信息的录入*\n");
		printf("\t\t*2.修改教师信息  *\n");
		printf("\t\t*3.查看教师信息  *\n");
		printf("\t\t*4.删除教师信息  *\n");
		printf("\t\t*0.退出          *\n");
		printf("\t\t******************\n");
		printf("请输入你的选择：");
		scanf("%d",&c);
		while(getchar()!='\n');
		switch(c)
		{
			case 1:
				//录入教师信息
				annal_teacher_info();
				break;
			case 2:
				//修改教师信息
				change_teacher_info();
				break;
			case 3:
				//查看教师信息
				cat_teacher_info();
				break;
			case 4:
				//删除教师信息
				delete_teacher_info();
				break;
			case 0:
				//销毁链表
				destroy_link_list();
				print_menu();
				break;
			default:
				printf("输入错误!\n");
		}
		printf("按回车继续\n");
		while(getchar()!='\n');
	}
}


//销毁链表
void destroy_link_list()
{
	free(readfile());
	printf("已销毁！\n");
}

//添加教师信息
void annal_teacher_info()
{
	teacher_link_t *head=readfile();
	teacher_link_t *p=head;
	teacher_link_t *temp=(teacher_link_t *)malloc(sizeof(teacher_link_t));
	if(temp==NULL)
	{
		printf("fail\n");
		return;
	}
	temp->next=NULL;
	printf("请输入教师的id:");
	scanf("%d",&temp->data.id);
	while(getchar()!='\n');
	while(p->next!=NULL)
	{
		if(temp->data.id==p->next->data.id)
		{
			printf("此id已存在\n");
			return;
		}
		p=p->next;
	}
	printf("请输入教师的姓名:");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("请输入教师的密码:");
	scanf("%s",temp->data.passwd);
	while(getchar()!='\n');
	printf("请输入教师的职位:");
	scanf("%s",temp->data.place);
	while(getchar()!='\n');
	printf("请输入教师的科目:");
	scanf("%s",temp->data.subject);
	while(getchar()!='\n');
	printf("请输入教师的标志:");
	scanf("%d",&temp->data.flag);
	while(getchar()!='\n');
	if(head->next!=NULL)
	{
		temp->next=head->next;
		head->next=temp;
	}
	else{
		head->next=temp;
	}
	writefile(head);
	printf("教师的信息为：\n");
	printf("工号\t姓名\t密码\t职位\t科目\t标志\n");
	printf("%d\t%s\t%s\t%s\t%s\t%d\n",head->next->data.id,head->next->data.name,head->next->data.passwd,head->next->data.place,head->next->data.subject,head->next->data.flag);
	free(temp);
	return;
}

//修改教师信息
void change_teacher_info()
{
	int num=0;
	teacher_link_t *head=readfile();
	teacher_link_t *temp=head;
	printf("请输入你想修改的教师的id：");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id)
		{
			printf("原来的数据为：\n");
			cat_teacher_info();
			printf("请输入新id：");
			scanf("%d",&temp->next->data.id);
			while(getchar()!='\n');
			printf("请输入新姓名：");
			scanf("%s",temp->next->data.name);
			while(getchar()!='\n');
			printf("请输入新密码：");
			scanf("%s",temp->next->data.passwd);
			while(getchar()!='\n');
			printf("请输入新职位:");
			scanf("%s",temp->next->data.place);
			while(getchar()!='\n');
			printf("请输入新科目:");
			scanf("%s",temp->next->data.subject);
			while(getchar()!='\n');
			writefile(head);
			printf("修改后的数据为：\n");
			cat_teacher_info();
			return;
		}
		temp=temp->next;
	}
	printf("此id不存在！\n");
	return;
}

//查看教师信息
void cat_teacher_info()
{
	teacher_link_t *head=readfile();
	if(head->next==NULL)
	{
		printf("没有信息\n");
		return;
	}
	printf("id\t姓名\t密码\t职位\t科目\t标志\n");
	while(head->next!=NULL)
	{
		printf("%d\t%s\t%s\t%s\t%s\t%d\n",head->next->data.id,head->next->data.name,head->next->data.passwd,head->next->data.place,head->next->data.subject,head->next->data.flag);
		head=head->next;
	}
	printf("\n");
	return;
}

//删除教师信息
void delete_teacher_info()
{
	int num=0;
	teacher_link_t *head=readfile();
	teacher_link_t *temp=head;
	printf("请输入你想删除的教师的id：");
	scanf("%d",&num);
	while(getchar()!='\n');
	while(temp->next!=NULL)
	{
		if(num==temp->next->data.id)
		{
			temp->next=temp->next->next;
			writefile(head);
			printf("删除成功!\n");
			free(temp);
			return;
		}
		temp=temp->next;
	}
	printf("删除失败！\n");
	return;
}


//将结构体链表写入文件
void writefile(teacher_link_t *head)
{
	if(NULL==head)
	{
		printf("信息存储失败！\n");
		return;
	}
	FILE *fp;
	fp=fopen("teacher.txt","w");
	while(head->next!=NULL)
	{
		fwrite(head->next,sizeof(teacher_link_t),1,fp);
		head=head->next;
	}
	fclose(fp);
	return;
}


//从文件中将信息读到内存，即链表
teacher_link_t *readfile()
{
	FILE *fp=fopen("teacher.txt","r");
	teacher_link_t *temp=(teacher_link_t *)malloc(sizeof(teacher_link_t));
	teacher_link_t *head=(teacher_link_t *)malloc(sizeof(teacher_link_t));
	head->next=NULL;
	while(fread(temp,sizeof(teacher_link_t),1,fp)>0)
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(teacher_link_t *)malloc(sizeof(teacher_link_t));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;
}

