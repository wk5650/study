#ifndef SALE_H
#define SALE_H

#include"Base.h"

using namespace std;

class Sale:virtual public Base
{
	public:
		Sale(string name="销售员",string level="ENUM_BASE_LEVEL_SALE",int sale=10000);
		virtual ~Sale();
		void info();
		int getSaleMoney();
		int getSaleSalary();
		int getLeader();
		//设置销售员的月销售额
		void setSaleMoney(int money);

		void setSaleSalary(int money);
		void setLeader(int id);
		void work();
	private:
		//月销售额
		int m_fSaleMoney;
		//月薪
		int m_iSaleSalary;
		int m_iLeader;
};


#endif
