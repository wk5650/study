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

#if 0
void Base::setId()
{
	MAP_TEC &refMap1=DataSet::getInstance().getTecMap();
	MAP_TEC::iterator iter1=refMap1.begin();
	for(;iter1!=refMap1.end();iter1++)
	{
		if(iter1->first>=m_iBase)
		{
			m_iBase=iter1->first;
		}
	}

	MAP_SALE &refMap2=DataSet::getInstance().getSaleMap();
	MAP_SALE::iterator iter2=refMap.begin();
	for(;iter2!=refMap2.end();iter2++)
	{
		if(iter2->first>=m_iBase)
		{
			m_iBase=iter2->first;
		}
	}
	MAP_MANAGER &refMap3=DataSet::getInstance().getManagerMap();
	MAP_MANAGER::iterator iter3=refMap3.begin();
	for(;iter3!=refMap3.end();iter3++)
	{
		if(iter3->first>=m_iBase)
		{
			m_iBase=iter3->first;
		}
	}
	MAP_SALEMANAGER &refMap4=DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMANAGER::iterator iter4=refMap4.begin();
	for(;iter4!=refMap4.end();iter4++)
	{
		if(iter4->first>=m_iBase)
		{
			m_iBase=iter4->first;
		}
	}
	MAP_BOSS &refMap5=DataSet::getInstance().getBossMap();
	MAP_BOSS::iterator iter5=refMap5.begin();
	for(;iter5!=refMap5.end();iter5++)
	{
		if(iter5->first>=m_iBase)
		{
			m_iBase=iter5->first;
		}
	}
	m_iBase++;
}
#endif

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
void setNote()
{
}
