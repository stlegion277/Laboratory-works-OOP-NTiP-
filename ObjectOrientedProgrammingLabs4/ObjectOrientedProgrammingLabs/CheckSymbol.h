#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;
inline int CheckSymbol()
{//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
 //TODO: � ��������� ���� ��� � ����������� �� ����������
	//��������
	string n;
	int m;
	do
	{
		cin >> n;
		if (n == "0")
		{
			return 0;
		}
		m = atoi(n.c_str());
	}
	while (m == 0);
	return m;
}