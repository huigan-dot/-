#pragma once
#include<iostream>
using  namespace std;
// �����Խ��г���
class Identity
{
public:

	// �����˵������麯��
	virtual void operMenu() = 0;

	// �û���
	string m_name;
	// ����
	string m_Pwd;
};