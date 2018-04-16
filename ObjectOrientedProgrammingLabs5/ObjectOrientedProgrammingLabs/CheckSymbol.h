#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;
inline int CheckSymbol()
{//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
 //TODO: и приведите свой код в соответстие со стандартом
	//исправил
	string inputData;
	int outputData; 
	do
	{
		cout << "Please enter valid value for correct operation of the program \n";
		cin >> inputData;
		if (inputData == "0")
		{
			return 0;
		}
		outputData = atoi(inputData.c_str());
		
	}
	while (outputData == 0);
	return outputData;
}