#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <string>
#include <fstream>
class OrderFile
{
public:
	OrderFile();

	// 更新预约函数
	void updateOrder();

	map<int, map<string, string>> m_orderData;

	int m_Size;
	void cutstring(string str);
	map<string, string> m;
};