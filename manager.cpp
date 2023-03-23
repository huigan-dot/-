#include"manager.h"
#include "globalFile.h"
Manager::Manager()
{

}
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_Pwd = pwd;
	this->initVector();
	this->initComRoom();
}
void Manager::operMenu()
{
	cout << "欢迎来到管理员 " << this->m_name <<"子菜单" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "请输入您的选择：";
}

void Manager::addPerson()// 添加账号
{
	cout << "请输入添加的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	int selcet = 0;
	cin >> selcet;

	string filename;
	string tips;
	//string 
	if (selcet == 1)
	{
		filename = STUDENT_FILE;
		tips = "请输入学号：";

	}
	else if (selcet == 2)
	{
		filename = TEACHER_FILE;
		tips = "请输入职工编号：";
	}
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);// 采用追加的方式写文件
	int id;
	string name;
	string pwd;
	cout << tips;
	cin >> id;
	while (true)
	{
		if (checkRepeat(id, selcet))
		{
			if (selcet == 1)
			{
				cout << "当前输入学生学号重复,请重新输入:";
			}
			else
				cout << "当前输入老师编号重复,请重新输入:";
			cin >> id;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	if (selcet == 1)
	{
		Student s(id, name, pwd);
		this->vStu.push_back(s);
		//for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		//{
		//	cout << it->m_Id << " " << it->m_name << " " << it->m_Pwd << endl;
		//}
	}
	else
	{
		Teacher t(id, name, pwd);
		this->vTea.push_back(t);
	}
	system("pause");
	system("cls");
	ofs.close();

}

void MyprintStu(Student& s)
{
	cout << s.m_Id << " " << s.m_name << " " << s.m_Pwd << endl;
}

void MyprintTea(Teacher& s)
{
	cout << s.m_EmpId << " " << s.m_name << " " << s.m_Pwd << endl;
}

class MyprintTeaclass
{
public:
	void operator()(Teacher& s) const
	{
		cout << s.m_EmpId << " " << s.m_name << " " << s.m_Pwd << endl;
	}
};

void Manager::showPerson()// 查看账号
{
	cout << "请输入添加的类型" << endl;
	cout << "1.查看学生信息" << endl;
	cout << "2.查看老师信息" << endl;
	int selcet = 0;
	cin >> selcet;
	if (selcet == 1)
	{
		cout << "学生所有信息如下：" << endl;
		//for_each(this->vStu.begin(), this->vStu.end(), MyprintStu);// 函数指针
		for (auto n : this->vStu)
		{
			cout << n.m_Id << " " << n.m_name << " " << n.m_Pwd << endl;
		}
	}
	else
	{
		cout << "老师所有信息如下：" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), MyprintTeaclass()); // 普通函数或者仿函数
	}
	system("pause");
	system("cls");
}
void Manager::showComputer()
{
	cout << "机房信息如下:" << endl;
	for (auto c : this->vComRoom)
	{
		cout << "机房编号为：" << c.m_ComId << "机房容量为：" << c.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearnFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	this->vStu.clear();
	this->vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << STUDENT_FILE << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << TEACHER_FILE << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::initComRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << COMPUTER_FILE <<"文件打开失败" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vComRoom.push_back(c);
	}
	ifs.close();
	cout << "机房的数量为：" << this->vComRoom.size() << endl;
}