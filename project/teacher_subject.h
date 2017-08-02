#ifndef __TEACHER_SUBJECT_H__
#define __TEACHER_SUBJECT_H__

void teacher_subject_test(int id);

//任课教师菜单
void teacher_subject_menu(teacher_link_t *p,int id);

//查看学生信息(自己所教的科目)
void cat_student_of_subject(int id);

//修改学生信息
void change_student_of_subject(teacher_link_t *p,int id);

//查看排名
void cat_student_ranking_subject(teacher_link_t *p,int id);


#endif
