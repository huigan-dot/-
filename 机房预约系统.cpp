#include <iostream>
#include "Identity.h"
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "teacher.h"
#include "manager.h"
#include "student.h"

void mangerMenu(Identity*& manager)// *&表示指针的引用
{
	while (true)
	{
		manager->operMenu();// 多态
		Manager* man = (Manager*)manager;// 将父类指针转化为子类指纹
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// 添加账号
			man->addPerson();
			break;
		case 2:
			// 查看账号
			man->showPerson();
			break;
		case 3:
			// 查看机房
			man->showComputer();
			break;
		case 4:
			// 清空记录
			man->clearnFile();
			break;
		default:
			delete manager;
			cout << "注销成功！！！" << endl;
			//break;
			system("pause");
			system("cls");
			return;
		}
		


	}
}

void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();// 多态
		Student* man = (Student*)student;// 将父类指针转化为子类指纹
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// 添加账号
			man->applyOrder();
			break;
		case 2:
			man->showMyOrder();
			break;
		case 3:
			man->showAllOrder();
			break;
		case 4:
			man->cancelOreder();
			break;
		default:
			delete student;
			cout << "注销成功！！！" << endl;
			//break;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();// 多态
		Teacher* man = (Teacher*)teacher;// 将父类指针转化为子类指纹
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// 查看所有预约
			man->showAllOrder();
			break;
		case 2:
			// 审核预约
			man->validOrder();
			break;
		default:
			delete teacher;
			cout << "注销成功！！！" << endl;
			//break;
			system("pause");
			system("cls");
			return;
		}
	}
}

// 登录功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;// 父类指针指向子类对象

	// 读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	// 准备接收用户的信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：";
		cin >> id;
	}
	cout << "请输入用户名:";
	cin >> name;
	cout << "请输入密码:" ;
	cin >> pwd;
	if (type == 1)
	{
		// 学生身份验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) // 同时读取一行信息 遇到空格会结束
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
				// 进入学生子菜单
			}
		}

	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) // 同时读取一行信息 遇到空格会结束
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
				// 进入学生子菜单
			}
		}
	}
	else if (type == 3)
	{
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) // 同时读取一行信息 遇到空格会结束
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				mangerMenu(person);
				return;
				// 进入学生子菜单
			}
		}
	}
	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << "请输入您的身份" << endl;
		cout << "1.学生代表" << endl;
		cout << "2.老    师" << endl;
		cout << "3.管 理 员" << endl;
		cout << "0.退    出" << endl;
		cout << "请输入您的选择：" ;
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}
