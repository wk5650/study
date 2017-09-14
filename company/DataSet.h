#ifndef DATASET_H
#define DATASET_H

#include<iostream>
#include<map>
#include"Tec.h"
#include"Manager.h"
#include"Sale.h"
#include"SaleManager.h"
#include"Boss.h"

using namespace std;

typedef map<int,Tec *> MAP_TEC;
typedef pair<int,Tec *> PAIR_TEC;

typedef map<int,Manager *> MAP_MANAGER;
typedef pair<int,Manager *> PAIR_MANAGER;

typedef map<int,Sale *> MAP_SALE;
typedef pair<int,Sale *> PAIR_SALE;

typedef map<int,SaleManager *> MAP_SALEMANAGER;
typedef pair<int,SaleManager *> PAIR_SALEMANAGER;

typedef map<int,Boss *> MAP_BOSS;
typedef pair<int,Boss *> PAIR_BOSS;

class DataSet
{
	public:
		DataSet();
		static DataSet &getInstance();
		MAP_TEC &getTecMap();
		MAP_MANAGER &getManagerMap();
		MAP_SALE &getSaleMap();
		MAP_SALEMANAGER &getSaleManagerMap();
		MAP_BOSS &getBossMap();
	private:
		MAP_TEC m_TecMap;
		MAP_MANAGER m_ManagerMap;
		MAP_SALE m_SaleMap;
		MAP_SALEMANAGER m_SaleManagerMap;
		MAP_BOSS m_BossMap;
};

#endif
