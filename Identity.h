#pragma once
#include<iostream>
using  namespace std;
// 将共性进行抽象
class Identity
{
public:

	// 操作菜单，纯虚函数
	virtual void operMenu() = 0;

	// 用户名
	string m_name;
	// 密码
	string m_Pwd;
};