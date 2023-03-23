#pragma once
#include<iostream>
using  namespace std;
#include"Identity.h"
#include<string>
#include<vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "OrderFile.h"
class Student : public Identity
{
public:
	// Ĭ�Ϲ���
	Student();
	// �вι���
	Student(int id,string name,string pwd);
	// �˵�ҳ��
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴����ԤԼ
	void showMyOrder();

	// �鿴����
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOreder();
	// ѧ��ѧ��
	int m_Id;

	// ��������
	vector<ComputerRoom> vCom;
};