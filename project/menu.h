#ifndef __MENU_H__
#define __MENU_H__

#define MENU_CON '1'
#define MENU_TEACHER '2'
#define MENU_STUDENT '3'
#define MENU_EXIT '0'
typedef struct link_node
{
	int data;
	struct link_node *next;
}link_node_t,*link_list_t;

//主界面菜单
void print_menu();

//辞职处理
void cizhi();

//管理员登录验证
void controller_login_test();


//教师类别认证
void teacher_type();

//管理员菜单
void print_menu_controller();

//录入教师信息
void annal_teacher_info();

//修改教师信息
void change_teacher_info();

//查看教师信息
void cat_teacher_info();

//删除教师信息
void delete_teacher_info();
#if 0
//清空链表
teacher_link_t * clear_link_list();
#endif
//销毁链表
void destroy_link_list();
#endif
