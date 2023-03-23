#include "teacher.h"

Teacher::Teacher()
{

}
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "��ӭ��ʦ:" << this->m_name << "��¼! " << endl;
	cout << "1���鿴����ԤԼ" << endl;
	cout << "2�����ԤԼ" << endl;
	cout << "0��ע����¼" << endl;
	cout << "��ѡ������ѡ��:" ;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		// ��string ת��Ϊ int  string->C str->int
		cout << i + 1 << "��";
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ԤԼʱ�䣺��" << of.m_orderData[i]["data"];
		cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " �����ţ�" << of.m_orderData[i]["roomId"];
		string status = " ״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	return;
}

// ���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	int index = 0;
	cout << "��ǰ��Ҫ��˵���Ϣ��" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		// ��string ת��Ϊ int  string->C str->int
		string status = " ״̬��";
		status += "�����";
		
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << " ������" << of.m_orderData[i]["stuName"];
			cout << " ԤԼʱ�䣺��" << of.m_orderData[i]["data"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.m_orderData[i]["roomId"];
			cout << status << endl;
		}
	}
	cout << "��������Ҫͨ���ı��(��0�˳�)��";
	int select=0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				switch (ret)
				{
				case 1:
					of.m_orderData[v[select - 1]]["status"] = "2";
					break;
				case 2:
					of.m_orderData[v[select - 1]]["status"] = "-1";
					break;
				default:
					break;
				}
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		else
			cout << "������������������" << endl;
	}
	
	system("pause");
	system("cls");
	return;
}