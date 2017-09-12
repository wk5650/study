#include"Company.h"

Company::Company()
{
	init();
}
Company::~Company(){}
//增加老板
void Company::init()
{
//	cout << DataSet::getInstance().getBossMap().size() << endl;
	if(DataSet::getInstance().getBossMap().empty())
	{
		Boss *pboss=new Boss;
		DataSet::getInstance().getBossMap().insert(PAIR_BOSS(pboss->getId(),pboss));
		cout << pboss->getId() << ' ' << pboss->getPwd() << endl;
	}
}
int Company::menu()
{
	int ch;
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
	return ch;
}
void Company::work()
{
	int num=-1;
	int id=0;
	string strPwd="";
	while(1)
	{
		num=menu();
		if(0==num)
		{
			cout << "欢迎使用，再见!\n";
			return;
		}
		cout << "请输入员工编号:\n";
		cin >> id;
		getchar();
		cout << "请输入密码:\n";
		cin >> strPwd;
		getchar();
		switch(num)
		{
			case 1:
			{
				Tec *tec=loginCompare<Tec *>(id,strPwd,DataSet::getInstance().getTecMap());
				if(NULL!=tec)
				{
					tec->work();
				}
				else
				{
					cout << "登入失败\n";
				}
				break;
			}
			case 2:
			{
				Manager *manager=loginCompare<Manager *>(id,strPwd,DataSet::getInstance().getManagerMap());
				if(NULL!=manager)
				{
					manager->work();
				}
				else
				{
					cout << "登入失败\n";
				}
				break;
			}
			case 3:
			{
				Sale *sale=loginCompare<Sale *>(id,strPwd,DataSet::getInstance().getSaleMap());
				if(NULL!=sale)
				{
					sale->work();
				}
				else
				{
					cout << "登入失败\n";
				}
				break;
			}
			case 4:
			{
				SaleManager *saleManager=loginCompare<SaleManager *>(id,strPwd,DataSet::getInstance().getSaleManagerMap());
				if(NULL!=saleManager)
				{
					saleManager->work();
				}
				else
				{
					cout << "登入失败\n";
				}
				break;
			}
			case 5:
			{
				Boss *boss=loginCompare<Boss *>(id,strPwd,DataSet::getInstance().getBossMap());
				if(NULL!=boss)
				{
					boss->work();
				}
				else
				{
					cout << "登入失败\n";
				}
				break;
			}
			default :
				cout << "输入错误!\n";
		}
	}
}
