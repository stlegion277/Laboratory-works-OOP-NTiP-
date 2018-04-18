#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;
inline int CheckSymbol()
{
	string inputData;
	int outputData; 
	do
	{
		cin >> inputData;
		outputData = atoi(inputData.c_str());
	}
	while (outputData == 0 && outputData < 0);
	return outputData;
}