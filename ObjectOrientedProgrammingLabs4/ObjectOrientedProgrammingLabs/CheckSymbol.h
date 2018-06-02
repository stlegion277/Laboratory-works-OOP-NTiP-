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
		if (inputData == "0")
		{
			return 0;
		}
		outputData = atoi(inputData.c_str());
	}
	while (outputData == 0);
	return outputData;
}