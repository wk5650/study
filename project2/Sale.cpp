#include"Sale.h"
Sale::Sale(string name,string level,int sale):Base(name,level)
{
	m_fSaleMoney=sale;
	m_iLeader=0;
}
Sale::~Sale(){}
void Sale::info()
{
	Base::info();
	cout << "薪水:" << m_fSaleMoney*0.1 << "上级:" << m_iLeader << endl;
}
int Sale::getSaleMoney()
{
	return m_fSaleMoney*0.1;
}
int Sale::getLeader()
{
	return m_iLeader;
}

//设置销售员的月销售额
void Sale::setSaleMoney(int money)
{
	m_fSaleMoney=money;
}
void Sale::setLeader(int id)
{
	m_iLeader=id;
}
void Sale::work()
{
	while(1)
	{
		int ch;
		cout << "\t\t***************\n";
		cout << "\t\t*1.查看信息   *\n";
		cout << "\t\t*2.修改密码   *\n";
		cout << "\t\t*0.退出       *\n";
		cout << "\t\t***************\n";
		cout << "请输入你的选择:\n";
		cin >> ch;
		switch(ch)
		{
			case 1:
				info();
				break;
			case 2:
				setPwd();
				break;
			case 0:
				return;
			default:
				cout << "输入错误!\n";
		}
	}
}
