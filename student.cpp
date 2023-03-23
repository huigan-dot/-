#include "student.h"


// Ĭ�Ϲ���
Student::Student()
{

}
// �вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_Pwd = pwd;
	// ��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	ifs.close();
}
// �˵�ҳ��
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "����������ѡ��";
 }

// ����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int week = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> week;
		if (week >= 1 && week <= 5)
		{
			break;
		}
		cout << "������������������:";
	}
	cout << "������ʱ�Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������:";
	}
	cout << "�����������" << endl;
	cout << "1.�������:" << this->vCom[0].m_ComId << ",��������:" << this->vCom[0].m_MaxNum << endl;
	cout << "2.�������:" << this->vCom[1].m_ComId << ",��������:" << this->vCom[1].m_MaxNum << endl;
	cout << "3.�������:" << this->vCom[2].m_ComId << ",��������:" << this->vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������:";
	}
	cout << "ԤԼ�ɹ�����ˣ�" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << week << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
	
}

// �鿴����ԤԼ
void Student::showMyOrder()
{
	//cout << "�鿴�ҵ�ԤԼ" << endl;
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
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "ԤԼʱ�䣺��" << of.m_orderData[i]["data"];
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
	}
	system("pause");
	system("cls");
	return;

}

// �鿴����
void Student::showAllOrder()
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


// ȡ��ԤԼ
void Student::cancelOreder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1;
	vector<int> vIndex;
	for (int i = 0; i < of.m_Size; i++)
	{
		// ���ж�����ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			// ��ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				vIndex.push_back(i);
				cout << index++ << "��";
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
		}


	}
	cout << "������ȡ����¼��0������:";
	int select = 0;
	
	while (true)
	{
		cin >> select;
		if (select > vIndex.size() || select < 0)
		{
			cout << "��ǰ���볬����Χ�����������룺";
		}
		else
			break;
	}
	if (select != 0)
	{
		int index = vIndex[select - 1];
		of.m_orderData[index]["status"] = "0";
		of.updateOrder();
		cout << "��ȡ��ԤԼ" << endl;
	}
	system("pause");
	system("cls");
}