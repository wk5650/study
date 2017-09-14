#ifndef BASE_H
#define BASE_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

//枚举法
enum ENUM_BASE_LEVEL 
{
	ENUM_BASE_LEVEL_MIN=0,
	ENUM_BASE_LEVEL_TEC,//技术员
	ENUM_BASE_LEVEL_MANAGER,//技术员经理
	ENUM_BASE_LEVEL_SALE,//销售员
	ENUM_BASE_LEVEL_SALEMANAGER,//销售员经理
	ENUM_BASE_LEVEL_BOSS,//老板
	ENUM_BASE_LEVEL_MAX=0x00ffffff
};

class Base
{
	public:
		Base(string name="NewStu",string level="ENUM_BASE_LEVEL_MIN");
		virtual ~Base();
		//获得Id
		int getId() const;
		int &getId();
		string getName() const;
		string &getName();
		string getLevel() const;
		string &getLevel();
		string getNote() const;
		string &getNote();
		//获得密码
		string getPwd() const;
		string &getPwd();
		//显示信息
		void info();

//		void setId();
		//修改密码
		void setPwd();
		//设置备注信息
		void setNote();
	public:
		static int m_iBase;
	private:
		int m_iId;
		string m_strName;
		string m_strPwd;
		string m_strLevel;
		string m_strNote;
};

#endif
