#ifndef BOSS_H
#define BOSS_H

#include"Manager.h"
#include"SaleManager.h"

class Boss:public Manager,public SaleManager
{
	public:
		Boss(string name="Boss",string level="ENUM_BASE_LEVEL_BOSS",int salary=1000000);
		virtual ~Boss();
		int getBossSalary();
		void setBossSalary(int salary);
		//对技术员设置
		void setTec();
		//对销售员设置
		void setSale();
		//对技术经理设置
		void setManager();
		//对销售经理设置
		void setSaleManager();
		//查看信息
		void info();
		void work();
		//对技术经理的增删改查
		void addManager();
		void delManager(int id=0);
		void updataManager(int id=0);
		Manager* findManager(int id=0);
		//显示技术经理
		void infoManager();
		//对销售经理的增删改查
		void addSaleManager();
		void delSaleManager(int id=0);
		void updateSaleManager(int id=0);
		SaleManager* findSaleManager(int id=0);
		//显示销售经理
		void infoSaleManager();
	private:
		int m_iSalary;
};


#endif

