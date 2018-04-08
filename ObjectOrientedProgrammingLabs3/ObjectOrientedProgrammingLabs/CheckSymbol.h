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
	//TODO: Нифига! Именование, отступы и всякое такое.
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