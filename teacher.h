#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include<vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "OrderFile.h"
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int empId,string name,string pwd);

	virtual void operMenu();

	void showAllOrder();

	// …Û∫À‘§‘º
	void validOrder();

	int m_EmpId;

};
