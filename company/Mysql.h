#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>
#include<map>
#include"Tec.h"
#include"Manager.h"
#include"Sale.h"
#include"SaleManager.h"
#include"Boss.h"
#include"DataSet.h"
using namespace std;

class Mysql
{
	public:
		int saveTecMapToMysql();
		int saveManagerMapToMysql();
		int saveSaleMapToMysql();
		int saveSaleManagerMapToMysql();
		int saveBossMapToMysql();

		int getTecMapFromMysql();
		int getManagerMapFromMysql();
		int getSaleMapFromMysql();
		int getSaleManagerMapFromMysql();
		int getBossMapFromMysql();
};
