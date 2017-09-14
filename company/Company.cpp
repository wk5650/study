#include"Company.h"

Company::Company()
{
	init();
	setId();
}
Company::~Company(){}

void Company::setId()
{
	MAP_TEC &refMap1=DataSet::getInstance().getTecMap();
	MAP_TEC::iterator iter1=refMap1.begin();
	for(;iter1!=refMap1.end();iter1++)
	{
		if(iter1->first>=Base::m_iBase)
		{
			Base::m_iBase=iter1->first;
		}
	}

	MAP_SALE &refMap2=DataSet::getInstance().getSaleMap();
	MAP_SALE::iterator iter2=refMap2.begin();
	for(;iter2!=refMap2.end();iter2++)
	{
		if(iter2->first>=Base::m_iBase)
		{
			Base::m_iBase=iter2->first;
		}
	}
	MAP_MANAGER &refMap3=DataSet::getInstance().getManagerMap();
	MAP_MANAGER::iterator iter3=refMap3.begin();
	for(;iter3!=refMap3.end();iter3++)
	{
		if(iter3->first>=Base::m_iBase)
		{
			Base::m_iBase=iter3->first;
		}
	}
	MAP_SALEMANAGER &refMap4=DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMANAGER::iterator iter4=refMap4.begin();
	for(;iter4!=refMap4.end();iter4++)
	{
		if(iter4->first>=Base::m_iBase)
		{
			Base::m_iBase=iter4->first;
		}
	}
	MAP_BOSS &refMap5=DataSet::getInstance().getBossMap();
	MAP_BOSS::iterator iter5=refMap5.begin();
	for(;iter5!=refMap5.end();iter5++)
	{
		if(iter5->first>=Base::m_iBase)
		{
			Base::m_iBase=iter5->first;
		}
	}
//	Base::m_iBase++;
}



//增加老板
void Company::init()
{
	if(DataSet::getInstance().getBossMap().empty())
	{
		Boss *pboss=new Boss;
		DataSet::getInstance().getBossMap().insert(PAIR_BOSS(pboss->getId(),pboss));
		cout << pboss->getId() << ' ' << pboss->getPwd() << endl;
	}
}
char Company::menu()
{
	char ch='\0';
	cout << "\t\t欢迎使用公司管理系统\n";
	cout << "\t\t********************\n";
	cout << "\t\t*1.技术员登录      *\n";
	cout << "\t\t*2.技术经理登录    *\n";
	cout << "\t\t*3.销售员登录      *\n";
	cout << "\t\t*4.销售经理登录    *\n";
	cout << "\t\t*5.老板登录        *\n";
	cout << "\t\t*0.退出            *\n";
	cout << "\t\t********************\n";
	cout << "请输入你的选择:\n";
	cin >> ch;
	while(getchar()!='\n');
	return ch;
}
void Company::work()
{
	int flag=0;
	int id=0;
	char num=-1;
	string strPwd="";
	while(1)
	{
		num=menu();
		if('0'==num)
		{
			cout << "欢迎使用，再见!\n";
			return;
		}
		cout << "请输入员工编号:\n";
		cin >> id;
		getchar();
		cout << "请输入密码:\n";
		cout << "\033[8m";
		cin >> strPwd;
		cout << "\033[0m";
		switch(num)
		{
			case '1':
			{
				Tec *tec=loginCompare<Tec *>(id,strPwd,DataSet::getInstance().getTecMap());
				if(NULL!=tec)
				{
					tec->work();
				}
				else
				{
					cout << "登入失败\n";
					flag++;
					int num=3-flag;
					cout << "你还有" << num << "次机会\n";
				}
				if(flag==3)
				{
					cout << "机会已用完\n";
					exit(1);
				}
				break;
			}
			case '2':
			{
				Manager *manager=loginCompare<Manager *>(id,strPwd,DataSet::getInstance().getManagerMap());
				if(NULL!=manager)
				{
					manager->work();
				}
				else
				{
					cout << "登入失败\n";
					flag++;
					int num=3-flag;
					cout << "你还有" << num << "次机会\n";
				}
				if(flag==3)
				{
					cout << "机会已用完\n";
					exit(1);
				}
				break;
			}
			case '3':
			{
				Sale *sale=loginCompare<Sale *>(id,strPwd,DataSet::getInstance().getSaleMap());
				if(NULL!=sale)
				{
					sale->work();
				}
				else
				{
					cout << "登入失败\n";
					flag++;
					int num=3-flag;
					cout << "你还有" << num << "次机会\n";
				}
				if(flag==3)
				{
					cout << "机会已用完\n";
					exit(1);
				}
				break;
			}
			case '4':
			{
				SaleManager *saleManager=loginCompare<SaleManager *>(id,strPwd,DataSet::getInstance().getSaleManagerMap());
				if(NULL!=saleManager)
				{
					saleManager->work();
				}
				else
				{
					cout << "登入失败\n";
					flag++;
					int num=3-flag;
					cout << "你还有" << num << "次机会\n";
				}
				if(flag==3)
				{
					cout << "机会已用完\n";
					exit(1);
				}
				break;
			}
			case '5':
			{
				Boss *boss=loginCompare<Boss *>(id,strPwd,DataSet::getInstance().getBossMap());
				if(NULL!=boss)
				{
					boss->work();
				}
				else
				{
					cout << "登入失败\n";
					flag++;
					int num=3-flag;
					cout << "还有" << num << "次机会\n";
				}
				if(flag==3)
				{
					cout << "机会已用完\n";
					exit(1);
				}
				break;
			}
			default :
				cout << "输入错误!\n";
				break;
		}
	}
}
