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
	//TODO: ������! ����������, ������� � ������ �����.
	string inputData; //n inputdata
	int outputData; //m outputdata
	do
	  {
		cin >> inputData;
		outputData = atoi(inputData.c_str());
	  }
	while (outputData == 0 && outputData < 0);
	return outputData;
}