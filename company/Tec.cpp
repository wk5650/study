#include"Tec.h"
Tec::Tec(string name,string level,int money):Base(name,level)
{
	m_iMoney=money;
	m_iTime=0;
	m_iLeader=0;
}
#if 0
Tec::Tec(int id,string name,string pwd,string level,int time,int timeMoney,int salary,int leader,string note):Base(name)
{
}
#endif
Tec::~Tec(){}
void Tec::info()
{
	Base::info();
	cout << "工资:" << m_iTime*m_iMoney << "上级:" << m_iLeader << endl;
}
int Tec::getTime() const
{
	return m_iTime;
}
int &Tec::getTime()
{
	return m_iTime;
}
int Tec::getMoney() const
{
	return m_iMoney;
}
int &Tec::getMoney()
{
	return m_iMoney;
}
int Tec::getLeader() const
{
	return m_iLeader;
}
int &Tec::getLeader()
{
	return m_iLeader;
}
int Tec::getSalary()
{
	return m_iTime*m_iMoney;
}
void Tec::setSalary(int salary)
{
	m_fSalary=salary;
}

void Tec::setTime(int time)
{
	m_iTime=time;
}
void Tec::setMoney(int money)
{
	m_iMoney=money;
}
void Tec::setLeader(int id)
{
	m_iLeader=id;
}
void Tec::work()
{
	while(1)
	{
		system("clear");
		int ch;
		cout << "\t\t***************\n";
		cout << "\t\t*1.查看信息   *\n";
		cout << "\t\t*2.修改密码   *\n";
		cout << "\t\t*0.退出       *\n";
		cout << "\t\t***************\n";
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
			case 0:
				return;
			default:
				cout << "输入错误!\n";
		}
		cout << "按回车继续\n";
		while(getchar()!='\n');
	}
}
