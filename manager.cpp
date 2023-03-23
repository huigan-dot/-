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
	cout << "��ӭ��������Ա " << this->m_name <<"�Ӳ˵�" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "����������ѡ��";
}

void Manager::addPerson()// ����˺�
{
	cout << "��������ӵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	int selcet = 0;
	cin >> selcet;

	string filename;
	string tips;
	//string 
	if (selcet == 1)
	{
		filename = STUDENT_FILE;
		tips = "������ѧ�ţ�";

	}
	else if (selcet == 2)
	{
		filename = TEACHER_FILE;
		tips = "������ְ����ţ�";
	}
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);// ����׷�ӵķ�ʽд�ļ�
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
				cout << "��ǰ����ѧ��ѧ���ظ�,����������:";
			}
			else
				cout << "��ǰ������ʦ����ظ�,����������:";
			cin >> id;
		}
		else
		{
			break;
		}
	}
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
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

void Manager::showPerson()// �鿴�˺�
{
	cout << "��������ӵ�����" << endl;
	cout << "1.�鿴ѧ����Ϣ" << endl;
	cout << "2.�鿴��ʦ��Ϣ" << endl;
	int selcet = 0;
	cin >> selcet;
	if (selcet == 1)
	{
		cout << "ѧ��������Ϣ���£�" << endl;
		//for_each(this->vStu.begin(), this->vStu.end(), MyprintStu);// ����ָ��
		for (auto n : this->vStu)
		{
			cout << n.m_Id << " " << n.m_name << " " << n.m_Pwd << endl;
		}
	}
	else
	{
		cout << "��ʦ������Ϣ���£�" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), MyprintTeaclass()); // ��ͨ�������߷º���
	}
	system("pause");
	system("cls");
}
void Manager::showComputer()
{
	cout << "������Ϣ����:" << endl;
	for (auto c : this->vComRoom)
	{
		cout << "�������Ϊ��" << c.m_ComId << "��������Ϊ��" << c.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearnFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
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
		cout << "�ļ���ʧ��" << STUDENT_FILE << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << TEACHER_FILE << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
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
		cout << COMPUTER_FILE <<"�ļ���ʧ��" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vComRoom.push_back(c);
	}
	ifs.close();
	cout << "����������Ϊ��" << this->vComRoom.size() << endl;
}