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
	cout << "欢迎教师:" << this->m_name << "登录! " << endl;
	cout << "1、查看所有预约" << endl;
	cout << "2、审核预约" << endl;
	cout << "0、注销登录" << endl;
	cout << "请选择您的选择:" ;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		// 将string 转化为 int  string->C str->int
		cout << i + 1 << "、";
		cout << "学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 预约时间：周" << of.m_orderData[i]["data"];
		cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房号：" << of.m_orderData[i]["roomId"];
		string status = " 状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	return;
}

// 审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	int index = 0;
	cout << "当前需要审核的信息：" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		// 将string 转化为 int  string->C str->int
		string status = " 状态：";
		status += "审核中";
		
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "学号：" << of.m_orderData[i]["stuId"];
			cout << " 姓名：" << of.m_orderData[i]["stuName"];
			cout << " 预约时间：周" << of.m_orderData[i]["data"];
			cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号：" << of.m_orderData[i]["roomId"];
			cout << status << endl;
		}
	}
	cout << "请输入您要通过的编号(按0退出)：";
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
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
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
				cout << "审核完毕" << endl;
				break;
			}
		}
		else
			cout << "输入有误请重新输入" << endl;
	}
	
	system("pause");
	system("cls");
	return;
}