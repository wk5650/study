#ifndef COMPANY_H
#define COMPANY_H

#include<stdlib.h>
#include<stdio.h>

#include"Base.h"
#include"Tec.h"
#include"Manager.h"
#include"Sale.h"
#include"SaleManager.h"
#include"Boss.h"
#include"DataSet.h"

class Company
{
	public:
		Company();
		virtual ~Company();
		
		void setId();

		//增加老板
		void init();

		char menu();
		void work();
		template<typename T>
		T loginCompare(int id,string &strPwd,map<int,T>& container);
};
template<typename T>
T Company::loginCompare(int id,string &strPwd,map<int,T>& container)
{
	T reval=NULL;
	typename map<int,T>::iterator iter=container.find(id);
	if(iter!=container.end())
	{
		if(iter->second->getPwd()==strPwd)
		{
			reval=iter->second;
		}
	}
	return reval;
}

#endif
