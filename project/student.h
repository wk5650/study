#ifndef __STUDENT_H__
#define __STUDENT_H__

#define STUDENT_ITEM 10

//结构体
typedef struct student
{
	int id;
	char name[STUDENT_ITEM];
	int passwd;
	int age;
	int cl;
	char gender[STUDENT_ITEM];
	float math;
	float chinese;
	char e[STUDENT_ITEM];

}student_t;

//链表
typedef struct student_link
{
	student_t data;
	struct student_link *next;
}student_link_t;

//将结构体链表写进文件
void writefile1(student_link_t *head);

//从文件将信息读到内存，即链表
student_link_t *readfile1();

//学生登录界面
void student_login_test();

//学生菜单
void student_menu(int id);
//查看自己的总分排名
void cat_score();

//修改自己的登录密码
void change_student_passwd(int id);

//给老师留言
void e_to_teacher();

//注销(返回登录界面)
void logout();

#endif
