#ifndef SALEMANAGER_H
#define SALEMANAGER_H

#include"Sale.h"

using namespace std;

class SaleManager:public Sale
{
	public:
		SaleManager(string name="销售经理",string level="ENUM_BASE_LEVEL_SALEMANAGER",int salary=6000);
		virtual ~SaleManager();
		void info();
		void work();
		int getSalary();
		//设置销售经理薪水
		void setsalary(int money);

		//对销售员的增删改查
		void addSale();
		void deleteSale(int id=0);
		void updateSale(int id=0);
		Sale* findSale(int id=0);
		//显示销售员
		void infoSale();
	private:
		int m_fSalary;
};


#endif
