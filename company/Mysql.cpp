#include"Mysql.h"

int Mysql::saveTecMapToMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);//初始化句柄
	if(NULL==conn)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="delete from Tec";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024]={'\0'};
	char buf[100]="insert into Tec values(";
	MAP_TEC &refMap=DataSet::getInstance().getTecMap();
	MAP_TEC::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s','%s',%d,%d,%d,%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPwd().data(),
				iter->second->getLevel().data(),
				iter->second->getTime(),
				iter->second->getMoney(),
				iter->second->getSalary(),
				iter->second->getLeader(),
				iter->second->getNote().data());
		mysql_query(conn,buff);
	}
	mysql_close(conn);
}

int Mysql::saveManagerMapToMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);//初始化句柄
	if(NULL==conn)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="delete from Manager";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024]={'\0'};
	char buf[100]="insert into Manager values(";
	MAP_MANAGER &refMap=DataSet::getInstance().getManagerMap();
	MAP_MANAGER::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s','%s',%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPwd().data(),
				iter->second->getLevel().data(),
				iter->second->getSalary(),
				iter->second->getNote().data());
		mysql_query(conn,buff);
	}
	mysql_close(conn);
}
int Mysql::saveSaleMapToMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);//初始化句柄
	if(NULL==conn)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="delete from Sale";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024]={'\0'};
	char buf[100]="insert into Sale values(";
	MAP_SALE &refMap=DataSet::getInstance().getSaleMap();
	MAP_SALE::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s','%s',%d,%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPwd().data(),
				iter->second->getLevel().data(),
				iter->second->getSaleSalary(),
				iter->second->getLeader(),
				iter->second->getNote().data());
		mysql_query(conn,buff);
	}
	mysql_close(conn);
}
int Mysql::saveSaleManagerMapToMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);//初始化句柄
	if(NULL==conn)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="delete from SaleManager";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024]={'\0'};
	char buf[100]="insert into SaleManager values(";
	MAP_SALEMANAGER &refMap=DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMANAGER::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s','%s',%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPwd().data(),
				iter->second->getLevel().data(),
				iter->second->getSalary(),
				iter->second->getNote().data());
		mysql_query(conn,buff);
	}
	mysql_close(conn);
}
int Mysql::saveBossMapToMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);//初始化句柄
	if(NULL==conn)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="delete from Boss";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024]={'\0'};
	char buf[100]="insert into Boss values(";
	MAP_BOSS &refMap=DataSet::getInstance().getBossMap();
	MAP_BOSS::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s','%s',%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPwd().data(),
				iter->second->getLevel().data(),
				iter->second->getBossSalary(),
				iter->second->getNote().data());
		mysql_query(conn,buff);
	}
	mysql_close(conn);
}

//从数据库获得技术员的数据
int Mysql::getTecMapFromMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);
	if(conn==NULL)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="select * from Tec";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(NULL==res)
	{
		cout << "mysql_use_result error!\n";
		return -1;
	}
	while(NULL!=(row=mysql_fetch_row(res)))
	{
		Tec *t=new Tec(row[1]);
		t->getId()=atoi(row[0]);
		t->getPwd()=row[2];
		t->getLevel()=row[3];
		t->getTime()=atoi(row[4]);
		t->getMoney()=atoi(row[5]);
		t->setSalary(atoi(row[6]));
		t->getLeader()=atoi(row[7]);
		t->getNote()=row[8];
		DataSet::getInstance().getTecMap().insert(PAIR_TEC(atoi(row[0]),t));
	}
	mysql_free_result(res);
	mysql_close(conn);
}


//从数据库获得销售员的数据
int Mysql::getSaleMapFromMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);
	if(conn==NULL)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="select * from Sale";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(NULL==res)
	{
		cout << "mysql_use_result error!\n";
		return -1;
	}
	while(NULL!=(row=mysql_fetch_row(res)))
	{
		Sale *t=new Sale(row[1]);
		t->getId()=atoi(row[0]);
		t->getPwd()=row[2];
		t->getLevel()=row[3];
		t->setSaleSalary(atoi(row[4]));
		t->setLeader(atoi(row[5]));
		t->getNote()=row[6];
		DataSet::getInstance().getSaleMap().insert(PAIR_SALE(atoi(row[0]),t));
	}
	mysql_free_result(res);
	mysql_close(conn);
}

//从数据库获得技术经理的数据
int Mysql::getManagerMapFromMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);
	if(conn==NULL)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="select * from Manager";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(NULL==res)
	{
		cout << "mysql_use_result error!\n";
		return -1;
	}
	while(NULL!=(row=mysql_fetch_row(res)))
	{
		Manager *t=new Manager(row[1]);
		t->getId()=atoi(row[0]);
		t->getPwd()=row[2];
		t->getLevel()=row[3];
		t->setSalary(atoi(row[4]));
		t->getNote()=row[5];
		DataSet::getInstance().getManagerMap().insert(PAIR_MANAGER(atoi(row[0]),t));
	}
	mysql_free_result(res);
	mysql_close(conn);
}

//从数据库获得销售经理的数据
int Mysql::getSaleManagerMapFromMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);
	if(conn==NULL)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="select * from SaleManager";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(NULL==res)
	{
		cout << "mysql_use_result error!\n";
		return -1;
	}
	while(NULL!=(row=mysql_fetch_row(res)))
	{
		SaleManager *t=new SaleManager(row[1]);
		t->getId()=atoi(row[0]);
		t->getPwd()=row[2];
		t->getLevel()=row[3];
		t->setsalary(atoi(row[4]));
		t->getNote()=row[5];
		DataSet::getInstance().getSaleManagerMap().insert(PAIR_SALEMANAGER(atoi(row[0]),t));
	}
	mysql_free_result(res);
	mysql_close(conn);
}

//从数据库获得老板的数据
int Mysql::getBossMapFromMysql()
{
	MYSQL *conn=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn=mysql_init(NULL);
	if(conn==NULL)
	{
		cout << "连接失败\n";
		return -1;
	}
	const char *host="localhost";
	const char *user="root";
	const char *pwd="123";
	const char *db="company";
	conn=mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL==conn)
	{
		cout << mysql_error(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q="use company";
	mysql_real_query(conn,q,strlen(q));
	q="select * from Boss";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(NULL==res)
	{
		cout << "mysql_use_result error!\n";
		return -1;
	}
	while(NULL!=(row=mysql_fetch_row(res)))
	{
		Boss *t=new Boss(row[1]);
		t->getId()=atoi(row[0]);
		t->getPwd()=row[2];
		t->getLevel()=row[3];
		t->setBossSalary(atoi(row[4]));
		t->getNote()=row[5];
		DataSet::getInstance().getBossMap().insert(PAIR_BOSS(atoi(row[0]),t));
	}
	mysql_free_result(res);
	mysql_close(conn);
}
