#ifndef TEC_H
#define TEC_H

#include"Base.h"

using namespace std;

class Tec:virtual public Base
{
	public:
		Tec(string name="技术员",string level="ENUM_BASE_LEVEL_TEC",int money=90);
//		Tec(int id=0,string name="技术员",string pwd="123",string level="level",int time=0,int money=90,int salary=0,int leader=0,string note="good");
		virtual ~Tec();
		int getTime() const;
		int &getTime();
		int getMoney() const;
		int &getMoney();
		int getLeader() const;
		int &getLeader();
		int getSalary();
		void setSalary(int salary);
		void setTime(int time);
		void setMoney(int Money);
		//设置技术员的上级
		void setLeader(int id);
		void info();
		void work();
	private:
		int m_iTime;
		int m_iMoney;
		int m_fSalary;
		int m_iLeader;
};




#endif
