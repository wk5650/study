#include"SaleManager.h"
#include"DataSet.h"
SaleManager::SaleManager(string name,string level,int salary):Base(name,level),Sale(name,level)
{
	m_fSalary=salary;
}
SaleManager::~SaleManager(){}
void SaleManager::info()
{
	Base::info();
	cout << "薪水:" << m_fSalary << endl;
}
int SaleManager::getSalary()
{
	return m_fSalary;
}
//设置销售经理薪水
void SaleManager::setsalary(int money)
{
	m_fSalary=money;
}
void SaleManager::work()
{
	while(1)
	{
		system("clear");
		int ch=-1;
		cout << "\t\t欢迎 " << getName() << " 进入!\n";
		cout << "\t\t**************\n";
		cout << "\t\t1.查看信息    \n";
		cout << "\t\t2.修改密码    \n";
		cout << "\t\t3.添加销售员  \n";
		cout << "\t\t4.删除销售员  \n";
		cout << "\t\t5.修改销售员  \n";
		cout << "\t\t6.查找销售员  \n";
		cout << "\t\t7.显示销售员  \n";
		cout << "\t\t0.退出        \n";
		cout << "\t\t**************\n";
		cout << "请输入你的选择:\n";
		cin >> ch;
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				info();
				break;
			case 2:
				setPwd();
				break;
			case 3:
				addSale();
				break;
			case 4:
				deleteSale();
				break;
			case 5:
				updateSale();
				break;
			case 6:
			{
				//findSale函数运行两次，第二次函数越界
				if(NULL!=findSale())
				{
					findSale()->info();
				}
				break;
			}
			case 7:
				infoSale();
				break;
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
		cout << "按回车继续\n";
		while(getchar()!='\n');
	}
}
void SaleManager::addSale()
{
	string name;
	cout << "请输入要添加的销售员的姓名:\n";
	cin >> name;
	while(getchar()!='\n');
	Sale *sale=new Sale(name);
	sale->setLeader(getId());
	DataSet::getInstance().getSaleMap().insert(PAIR_SALE(sale->getId(),sale));
	cout << "添加成功\n";
}
void SaleManager::deleteSale(int id)
{
	if(0==id)
	{
		cout << "输入要删除的销售员的编号:\n";
		cin >> id;
		while(getchar()!='\n');
	}
	MAP_SALE &refMap=DataSet::getInstance().getSaleMap();
	MAP_SALE::iterator iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "成功删除编号为:" << id << "的销售员" << endl;
	}
	else
	{
		cout << "没有编号为:" << id << "的销售员" << endl;
	}
}
void SaleManager::updateSale(int id)
{
	if(0==id)
	{
		cout << "输入你想修改的销售员的编号:";
		cin >> id;
	}
	findSale(id)->info();
	while(1)
	{
		int num=-1;
		int money=0.0f;
		int uid=0;
		cout << "\t\t*************************\n";
		cout << "\t\t1.修改该销售员的月销售额:\n";
		cout << "\t\t2.修改该销售员的上级     \n";
		cout << "\t\t3.修改该销售员的备注     \n";
		cout << "\t\t0.退出                   \n";
		cout << "\t\t*************************\n";
		cout << "\t\t请选择:\n";
		cin >> num;
		switch(num)
		{
			case 1:
			{
				cout << "请输入该销售员的月销售额:\n";
				cin >> money;
				findSale(id)->setSaleMoney(money);
				cout << "修改成功\n";
				break;
			}
			case 2:
			{
				cout << "请输入该销售员的上级编号:\n";
				cin >> uid;
				findSale(id)->setLeader(uid);
				cout << "修改成功\n";
				break;
			}
			case 3:
			{
				string note;
				cout << "请输入该销售员的备注:\n";
				cin >> note;
				findSale(id)->setNote(note);
				cout << "修改备注成功\n";
				break;
			}
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
	DataSet::getInstance().getSaleMap().insert(PAIR_SALE(id,findSale(id)));
}
Sale* SaleManager::findSale(int id)
{
	if(0==id)
	{
		cout << "输入你要查找的销售员的编号:";
		cin >> id;
	}
	while(getchar()!='\n');
	Sale *sale=NULL;
	MAP_SALE::iterator iter;
	MAP_SALE &refMap=DataSet::getInstance().getSaleMap();
	iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		sale=iter->second;
		return sale;
	}
	else
	{
		cout << "没有这个销售员\n";
		return sale=NULL;
	}
}
//显示销售员
void SaleManager::infoSale()
{
	MAP_SALE &refMap=DataSet::getInstance().getSaleMap();
	MAP_SALE::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		iter->second->info();
	}
}
