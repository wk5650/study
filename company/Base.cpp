#include"Base.h"

int Base::m_iBase=1000;
Base::Base(string name,string level)
{
	m_iId=m_iBase++;
	m_strName=name;
	m_strPwd="123";
	m_strLevel=level;
	m_strNote="表现良好";
}
Base::~Base()
{}

int Base::getId() const
{
	return m_iId;
}
int &Base::getId()
{
	return m_iId;
}
string Base::getPwd() const
{
	return m_strPwd;
}
string &Base::getPwd()
{
	return m_strPwd;
}
string Base::getName() const
{
	return m_strName;
}
string &Base::getName()
{
	return m_strName;
}
string Base::getLevel() const
{
	return m_strLevel;
}
string &Base::getLevel()
{
	return m_strLevel;
}
string Base::getNote() const
{
	return m_strNote;
}
string &Base::getNote()
{
	return m_strNote;
}
void Base::info()
{
	cout << "编号:" << m_iId << ' ' << "姓名:" << m_strName << ' ' << "密码:" << m_strPwd << ' ';
	if(m_strLevel=="ENUM_BASE_LEVEL_TEC")
	{
		cout << "级别:" << "技术员" << ' ';
	}
	else if(m_strLevel=="ENUM_BASE_LEVEL_MANAGER")
	{
		cout << "级别:" << "技术经理" << ' ';
	}
	else if(m_strLevel=="ENUM_BASE_LEVEL_SALE")
	{
		cout << "级别:" << "销售员" << ' ';
	}
	else if(m_strLevel=="ENUM_BASE_LEVEL_SALEMANAGER")
	{
		cout << "级别:" << "销售经理" << ' ';
	}
	else if(m_strLevel=="ENUM_BASE_LEVEL_BOSS")
	{
		cout << "级别:" << "老板" << ' ';
	}
	cout << "备注:" << m_strNote << ' ';
}
void Base::setPwd()
{
	string login;
	cout << "输入原密码:\n";
	cin >> login;
	if(login==m_strPwd)
	{
		cout << "请输入新密码:\n";
		cin >> m_strPwd;
		cout << "密码修改成功\n";
	}
	else
	{
		cout << "密码错误\n";
	}
}
void Base::setNote(string note)
{
	m_strNote=note;
}
