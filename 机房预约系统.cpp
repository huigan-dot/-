#include <iostream>
#include "Identity.h"
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "teacher.h"
#include "manager.h"
#include "student.h"

void mangerMenu(Identity*& manager)// *&��ʾָ�������
{
	while (true)
	{
		manager->operMenu();// ��̬
		Manager* man = (Manager*)manager;// ������ָ��ת��Ϊ����ָ��
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// ����˺�
			man->addPerson();
			break;
		case 2:
			// �鿴�˺�
			man->showPerson();
			break;
		case 3:
			// �鿴����
			man->showComputer();
			break;
		case 4:
			// ��ռ�¼
			man->clearnFile();
			break;
		default:
			delete manager;
			cout << "ע���ɹ�������" << endl;
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
		student->operMenu();// ��̬
		Student* man = (Student*)student;// ������ָ��ת��Ϊ����ָ��
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// ����˺�
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
			cout << "ע���ɹ�������" << endl;
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
		teacher->operMenu();// ��̬
		Teacher* man = (Teacher*)teacher;// ������ָ��ת��Ϊ����ָ��
		int select = 0;

		cin >> select;
		switch (select)
		{
		case 1:
			// �鿴����ԤԼ
			man->showAllOrder();
			break;
		case 2:
			// ���ԤԼ
			man->validOrder();
			break;
		default:
			delete teacher;
			cout << "ע���ɹ�������" << endl;
			//break;
			system("pause");
			system("cls");
			return;
		}
	}
}

// ��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;// ����ָ��ָ���������

	// ���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	// ׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	cout << "�������û���:";
	cin >> name;
	cout << "����������:" ;
	cin >> pwd;
	if (type == 1)
	{
		// ѧ�������֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) // ͬʱ��ȡһ����Ϣ �����ո�����
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
				// ����ѧ���Ӳ˵�
			}
		}

	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) // ͬʱ��ȡһ����Ϣ �����ո�����
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
				// ����ѧ���Ӳ˵�
			}
		}
	}
	else if (type == 3)
	{
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) // ͬʱ��ȡһ����Ϣ �����ո�����
		{
			//cout << fid << " " << fname << " " << fpwd << endl;
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				mangerMenu(person);
				return;
				// ����ѧ���Ӳ˵�
			}
		}
	}
	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << "�������������" << endl;
		cout << "1.ѧ������" << endl;
		cout << "2.��    ʦ" << endl;
		cout << "3.�� �� Ա" << endl;
		cout << "0.��    ��" << endl;
		cout << "����������ѡ��" ;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}
