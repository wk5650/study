#include"Base.h"
#include"Tec.h"
#include"Manager.h"
#include"Sale.h"
#include"SaleManager.h"
#include"Company.h"
#include"Mysql.h"

int main(void)
{
	Mysql t;
	t.getTecMapFromMysql();
	t.getManagerMapFromMysql();
	t.getSaleMapFromMysql();
	t.getSaleManagerMapFromMysql();
	t.getBossMapFromMysql();
	Company c;
	c.work();

	t.saveTecMapToMysql();
	t.saveManagerMapToMysql();
	t.saveSaleMapToMysql();
	t.saveSaleManagerMapToMysql();
	t.saveBossMapToMysql();

	return 0;
}
