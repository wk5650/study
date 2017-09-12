#include"Boss.h"
#include"DataSet.h"

Boss::Boss(string name,string level,int salary):Base(name,level),Manager(name),SaleManager(name)
{
	m_iSalary=salary;
}
Boss::~Boss(){}
int Boss::getBossSalary()
{
	return m_iSalary;
}
void Boss::setBossSalary(int salary)
{
	m_iSalary=salary;
}
//对技术员设置
void Boss::setTec()
{
	while(1)
	{
		int num=-1;
		cout << "\t\t*************\n";
		cout << "\t\t1.增加技术员 \n";
		cout << "\t\t2.删除技术员 \n";
		cout << "\t\t3.修改技术员 \n";
		cout << "\t\t4.查找技术员 \n";
		cout << "\t\t5.显示技术员 \n";
		cout << "\t\t0.退出       \n";
		cout << "\t\t*************\n";
		cout << "请输入你的选择:";
		cin >> num;
		switch(num)
		{
			case 1:
				Manager::addTec();
				break;
			case 2:
				Manager::deleteTec();
				break;
			case 3:
				Manager::updateTec();
				break;
			case 4:
				Manager::findTec();
				break;
			case 5:
				Manager::infoTec();
				break;
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
}
//对销售员设置
void Boss::setSale()
{
	while(1)
	{
		int num=-1;
		cout << "\t\t*************\n";
		cout << "\t\t1.增加销售员 \n";
		cout << "\t\t2.删除销售员 \n";
		cout << "\t\t3.修改销售员 \n";
		cout << "\t\t4.查找销售员 \n";
		cout << "\t\t5.显示销售员 \n";
		cout << "\t\t0.退出       \n";
		cout << "\t\t*************\n";
		cout << "请输入你的选择:";
		cin >> num;
		switch(num)
		{
			case 1:
				SaleManager::addSale();
				break;
			case 2:
				SaleManager::deleteSale();
				break;
			case 3:
				SaleManager::updateSale();
				break;
			case 4:
				SaleManager::findSale();
				break;
			case 5:
				SaleManager::infoSale();
				break;
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
}
//对技术经理设置
void Boss::setManager()
{
	while(1)
	{
		int num=-1;
		cout << "\t\t*****************\n";
		cout << "\t\t1.增加技术经理   \n";
		cout << "\t\t2.删除技术经理   \n";
		cout << "\t\t3.修改技术经理   \n";
		cout << "\t\t4.查找技术经理   \n";
		cout << "\t\t5.显示技术经理   \n";
		cout << "\t\t0.退出           \n";
		cout << "\t\t*****************\n";
		cout << "输入你的选择:\n";
		cin >> num;
		switch(num)
		{
			case 1:
				addManager();
				break;
			case 2:
				delManager();
				break;
			case 3:
				updataManager();
				break;
			case 4:
				findManager()->info();
				break;
			case 5:
				infoManager();
				break;
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
}
//对销售经理设置
void Boss::setSaleManager()
{
	while(1)
	{
		int num=-1;
		cout << "\t\t*****************\n";
		cout << "\t\t1.增加销售经理   \n";
		cout << "\t\t2.删除销售经理   \n";
		cout << "\t\t3.修改销售经理   \n";
		cout << "\t\t4.查找销售经理   \n";
		cout << "\t\t5.显示销售经理   \n";
		cout << "\t\t0.退出           \n";
		cout << "\t\t*****************\n";
		cout << "输入你的选择:\n";
		cin >> num;
		switch(num)
		{
			case 1:
				addSaleManager();
				break;
			case 2:
				delSaleManager();
				break;
			case 3:
				updateSaleManager();
				break;
			case 4:
				findSaleManager();
				break;
			case 5:
				infoSaleManager();
				break;
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
}
//对技术经理的增删改查
void Boss::addManager()
{
	string name;
	cout << "请输入要添加的技术经理的名字:\n";
	cin >> name;
	Manager *manager=new Manager(name);
	DataSet::getInstance().getManagerMap().insert(PAIR_MANAGER(manager->getId(),manager));
	cout << "添加成功\n";
}
void Boss::delManager(int id)
{
	if(0==id)
	{
		cout << "请输入你要删除的技术经理的编号:\n";
		cin >> id;
	}
	MAP_MANAGER &refMap=DataSet::getInstance().getManagerMap();
	MAP_MANAGER::iterator iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "删除编号为:" << id << "的技术经理成功" << endl;
	}
	else
	{
		cout << "没有编号为:" << id << "的技术经理" << endl;
	}
}
void Boss::updataManager(int id)
{
	int num=0;
	if(0==id)
	{
		cout << "请输入你要修改的技术经理的编号:\n";
		cin >> id;
	}
	findManager(id)->info();
	cout << "请输入技术经理的工资:";
	cin >> num;
	findManager(id)->setSalary(num);
	DataSet::getInstance().getManagerMap().insert(PAIR_MANAGER(id,findManager(id)));
	findManager(id)->info();
	cout << "修改成功" << endl;
}
Manager* Boss::findManager(int id)
{
	if(0==id)
	{
		cout << "请输入你要查找的技术经理的编号:\n";
		cin >> id;
	}
	Manager *manager=NULL;
	MAP_MANAGER::iterator iter;
	MAP_MANAGER &refMap=DataSet::getInstance().getManagerMap();
	iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		manager=iter->second;
	}
	return manager;
}
//显示技术经理
void Boss::infoManager()
{
	MAP_MANAGER &refMap=DataSet::getInstance().getManagerMap();
	MAP_MANAGER::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		iter->second->info();
	}
}
//对销售经理的增删改查
void Boss::addSaleManager()
{
	string name;
	cout << "请输入要添加的销售经理的名字:\n";
	cin >> name;
	SaleManager *sManager=new SaleManager(name);
	DataSet::getInstance().getSaleManagerMap().insert(PAIR_SALEMANAGER(sManager->getId(),sManager));
	cout << "添加成功\n";
}
void Boss::delSaleManager(int id)
{
	if(0==id)
	{
		cout << "请输入你要删除的销售经理的编号:\n";
		cin >> id;
	}
	MAP_SALEMANAGER &refMap=DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMANAGER::iterator iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "成功删除编号为:" << id << "的销售经理" << endl;
	}
	else
	{
		cout << "没有编号为:" << id << "的销售经理" << endl;
	}
}
void Boss::updateSaleManager(int id)
{
	if(0==id)
	{
		cout << "请输入要修改的销售经理的编号:\n";
		cin >> id;
	}
	findSaleManager(id)->info();
	float money;
	cout << "请输入该销售经理的工资:\n";
	cin >> money;
	findSaleManager(id)->setsalary(money);
	DataSet::getInstance().getSaleManagerMap().insert(PAIR_SALEMANAGER(id,findSaleManager(id)));
	findSaleManager(id)->info();
	cout << "修改成功" << endl;
}
SaleManager* Boss::findSaleManager(int id)
{
	if(0==id)
	{
		cout << "请输入要查找的销售经理的编号:\n";
		cin >> id;
	}
	SaleManager *sManager=NULL;
	MAP_SALEMANAGER::iterator iter;
	MAP_SALEMANAGER &refMap=DataSet::getInstance().getSaleManagerMap();
	iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		sManager=iter->second;
	}
	return sManager;
}
//显示销售经理
void Boss::infoSaleManager()
{
	MAP_SALEMANAGER &refMap=DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMANAGER::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		iter->second->info();
	}
}
//查看信息
void Boss::info()
{
	Base::info();
	cout << endl;
}
void Boss::work()
{
	while(1)
	{
		int ch=-1;
		cout << "\t\t欢迎你，老板!\n";
		cout << "\t\t*********************\n";
		cout << "\t\t1.查看信息           \n";
		cout << "\t\t2.对技术员进行操作   \n";
		cout << "\t\t3.对销售员进行操作   \n";
		cout << "\t\t4.对技术经理进行操作 \n";
		cout << "\t\t5.对销售经理进行操作 \n";
		cout << "\t\t6.显示技术经理       \n";
		cout << "\t\t7.显示销售经理       \n";
		cout << "\t\t0.退出               \n";
		cout << "\t\t*********************\n";
		cout << "\t\t请输入选择:\n";
		cin >> ch;
		switch(ch)
		{
			case 1:
				info();
				break;
			case 2:
				setTec();
				break;
			case 3:
				setSale();
				break;
			case 4:
				setManager();
				break;
			case 5:
				setSaleManager();
				break;
			case 6:
				infoManager();
				break;
			case 7:
				infoSaleManager();
				break;
			case 0:
				cout << "再见，老板\n";
				return;
			default:
				cout << "输入错误\n";
		}
	}
}
