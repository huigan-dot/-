#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"
class Manager :public Identity
{
public:

	Manager();
	Manager(string name, string pwd);
	virtual void operMenu();

	void addPerson();// ÃÌº”’À∫≈

	void showPerson();// ≤Èø¥’À∫≈

	void showComputer();

	void clearnFile();
	
	void initVector();

	vector<Student> vStu;
	vector<Teacher> vTea;

	bool checkRepeat(int id, int type);

	vector<ComputerRoom> vComRoom;
	void initComRoom();
};