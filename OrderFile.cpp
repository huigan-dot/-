#include "OrderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;// 日期
	string interval; // 时间段
	string stuId; // 学生编号
	string stuName; // 学生姓名
	string roomId; // 机房编号
	string status; // 预约状态

	this->m_Size = 0; // 预约记录的条数
	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << data << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;

		//int pos = data.find(":");
		//if (pos != -1)
		//{
		//	key = data.substr(0, pos);
		//	value = data.substr(pos + 1);
		//	m.insert(make_pair(key, value));
		//}
		this->cutstring(data);
		this->cutstring(interval);
		this->cutstring(stuId);
		this->cutstring(stuName);
		this->cutstring(roomId);
		this->cutstring(status);

		//
		this->m_orderData.insert(make_pair(this->m_Size, this->m));
		this->m.clear();
		this->m_Size++;
	}
	ifs.close();

	//for (auto x : this->m_orderData)
	//{
	//	cout << x.first << endl;
	//	for (auto i : x.second)
	//	{
	//		cout << i.first << "\t" << i.second << "\t";
	//	}
	//	cout << endl;
	//}

}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE,ios::out|ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";
		ofs << endl;
	}
	ofs.close();
}

void OrderFile::cutstring(string str)
{
	string key;
	string value;
	
	int pos = str.find(":");
	if (pos != -1)
	{
		key = str.substr(0, pos);
		value = str.substr(pos + 1);
		this->m.insert(make_pair(key, value));
	}
}