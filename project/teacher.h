#ifndef __TEACHER_H__
#define __TEACHER_H__

#define TEACHER_ITEM 10
typedef struct teacher
{
	int id;
	char name[TEACHER_ITEM];
	char passwd[TEACHER_ITEM];
	char place[TEACHER_ITEM];
	char subject[TEACHER_ITEM];
	int flag;
}teacher_t;

//链表
typedef struct link_teacher
{
	teacher_t data;
	struct link_teacher *next;
}teacher_link_t;

//将结构体链表写入文件
void writefile(teacher_link_t *head);

//从文件中将信息读到内存，即链表
teacher_link_t *readfile();

//教师菜单
void teacher_menu(int id);

//教师登录界面
void teacher_login_test(int teacher_id);

//录入学生信息
void annal_student_info();

//查看学生信息
void cat_student_info();

//修改学生信息
void change_student_info();

//删除学生信息
void delete_student_info();

//查看排名
void cat_student_ranking();

//查看总分排名
void cat_student_score_ranking();

//查看学号排名
void cat_student_hao();

//修改自己的登录密码
void change_passwd(int id);

//提出辞职
void bye(int a);

//查看学生留言
void cat_e();

//根据姓名查看学生的信息
void cat_student_info_from_name();

//摧毁链表
void destroy_teacher_list();

#endif
