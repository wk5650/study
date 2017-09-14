#ifndef MANAGER_H
#define MANAGER_H

#include"Tec.h"

using namespace std;

class Manager:public Tec
{
	public:
		Manager(string name="技术经理",string level="ENUM_BASE_LEVEL_MANAGER",int salary=10000);
		virtual ~Manager();
		void info();
		int getSalary();
		//设置工资
		void setSalary(int num);
		
		//对技术员的增删改查
		void addTec();
		void deleteTec(int id=0);
		void updateTec(int id=0);
		Tec* findTec(int id=0);
		//显示技术人员
		void infoTec();

		void work();
	private:
		int m_fSalary;
};


#endif
