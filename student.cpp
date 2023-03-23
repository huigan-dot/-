#include "student.h"


// 默认构造
Student::Student()
{

}
// 有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_Pwd = pwd;
	// 读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		this->vCom.push_back(c);
	}
	ifs.close();
}
// 菜单页面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "请输入您的选择：";
 }

// 申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一和周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
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
		cout << "输入有误，请重新输入:";
	}
	cout << "请输入时段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入:";
	}
	cout << "请输入机房：" << endl;
	cout << "1.机房编号:" << this->vCom[0].m_ComId << ",机房容量:" << this->vCom[0].m_MaxNum << endl;
	cout << "2.机房编号:" << this->vCom[1].m_ComId << ",机房容量:" << this->vCom[1].m_MaxNum << endl;
	cout << "3.机房编号:" << this->vCom[2].m_ComId << ",机房容量:" << this->vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入:";
	}
	cout << "预约成功，审核！" << endl;
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

// 查看自身预约
void Student::showMyOrder()
{
	//cout << "查看我的预约" << endl;
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
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "预约时间：周" << of.m_orderData[i]["data"];
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
	}
	system("pause");
	system("cls");
	return;

}

// 查看所有
void Student::showAllOrder()
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


// 取消预约
void Student::cancelOreder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1;
	vector<int> vIndex;
	for (int i = 0; i < of.m_Size; i++)
	{
		// 先判断自身学号
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			// 在筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				vIndex.push_back(i);
				cout << index++ << "、";
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
		}


	}
	cout << "请输入取消记录，0代表返回:";
	int select = 0;
	
	while (true)
	{
		cin >> select;
		if (select > vIndex.size() || select < 0)
		{
			cout << "当前输入超出范围，请重新输入：";
		}
		else
			break;
	}
	if (select != 0)
	{
		int index = vIndex[select - 1];
		of.m_orderData[index]["status"] = "0";
		of.updateOrder();
		cout << "已取消预约" << endl;
	}
	system("pause");
	system("cls");
}