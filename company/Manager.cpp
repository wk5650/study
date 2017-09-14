#include"Manager.h"
#include"DataSet.h"
Manager::Manager(string name,string level,int salary):Base(name,level),Tec(name,level)
{
	m_fSalary=salary;
}
Manager::~Manager(){}
void Manager::info()
{
	Base::info();
	cout << "薪水:" << m_fSalary << endl;
}
int Manager::getSalary()
{
	return m_fSalary;
}

void Manager::setSalary(int num)
{
	m_fSalary=num;
}

void Manager::addTec()
{
	string name;
	cout << "请输入要添加的技术员的姓名:\n";
	cin >> name;
	while(getchar()!='\n');
	Tec *tec=new Tec(name);
	tec->setLeader(getId());
	DataSet::getInstance().getTecMap().insert(PAIR_TEC(tec->getId(),tec));
	cout << "添加成功\n";
}
void Manager::deleteTec(int id)
{
	if(0==id)
	{
		cout << "请输入要删除的技术员的id:\n";
		cin >> id;
		while(getchar()!='\n');
	}
	MAP_TEC &refMap=DataSet::getInstance().getTecMap();
	MAP_TEC::iterator iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "成功删除编号为:" << id << "的技术人员" << endl;
	}
	else
	{
		cout << "没有编号为:" << id << "的技术人员" << endl;
	}
}
void Manager::updateTec(int id)
{
	if(0==id)
	{
		cout << "请输入要修改的技术员的编号:\n";
		cin >> id;
	}
	findTec(id)->info();
	while(1)
	{
		int time=0;
		int money=0;
		int uid=0;
		int num=-1;
		cout << "\t\t**********************\n";
		cout << "\t\t1.修改技术员工作时间  \n";
		cout << "\t\t2.修改技术员工作时薪  \n";
		cout << "\t\t3.修改技术员的上级    \n";
		cout << "\t\t4.修改技术员的备注    \n";
		cout << "\t\t0.退出                \n";
		cout << "\t\t**********************\n";
		cout << "请选择:\n";
		cin >> num;
		switch(num)
		{
			case 1:
			{
				cout << "输入技术员的工作时间:\n";
				cin >> time;
				findTec(id)->setTime(time);
				break;
			}
			case 2:
			{
				cout << "输入技术员的时薪:\n";
				cin >> money;
				findTec(id)->setMoney(money);
				break;
			}
			case 3:
			{
				cout << "输入技术员的上级编号:\n";
				cin >> uid;
				findTec(id)->setLeader(uid);
				break;
			}
			case 4:
			{
				string note;
				cout << "请输入该技术员的备注:\n";
				cin >> note;
				findTec(id)->setNote(note);
				cout << "备注修改成功\n";
				break;
			}
			case 0:
				return;
			default:
				cout << "输入错误\n";
		}
	}
	DataSet::getInstance().getTecMap().insert(PAIR_TEC(id,findTec(id)));
}
Tec* Manager::findTec(int id)
{
	if(0==id)
	{
		cout << "请输入要查找的技术员的id:\n";
		cin >> id;
	}
	while(getchar()!='\n');
	Tec *tec=NULL;
	MAP_TEC::iterator iter;
	MAP_TEC &refMap=DataSet::getInstance().getTecMap();
	iter=refMap.find(id);
	if(iter!=refMap.end())
	{
		tec=iter->second;
	}
	return tec;
}
//显示技术人员
void Manager::infoTec()
{
	MAP_TEC &refMap=DataSet::getInstance().getTecMap();
	MAP_TEC::iterator iter=refMap.begin();
	for(;iter!=refMap.end();iter++)
	{
		iter->second->info();
	}
}
void Manager::work()
{
	while(1)
	{
		system("clear");
		int ch;
		cout << "\t\t欢迎 " << getName() << " 进入!\n";
		cout << "\t\t**************\n";
		cout << "\t\t1.查看信息    \n";
		cout << "\t\t2.修改密码    \n";
		cout << "\t\t3.添加技术员  \n";
		cout << "\t\t4.删除技术员  \n";
		cout << "\t\t5.修改技术员  \n";
		cout << "\t\t6.查找技术员  \n";
		cout << "\t\t7.显示技术员  \n";
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
				addTec();
				break;
			case 4:
				deleteTec();
				break;
			case 5:
				updateTec();
				break;
			case 6:
			{
				if(NULL!=findTec())
				{
					findTec()->info();
				}
				break;
			}
			case 7:
				infoTec();
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
