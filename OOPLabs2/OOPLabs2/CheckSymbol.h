#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
inline int CheckSymbol()
{
	string n;
	int m;
	do {
		cin >> n;
		m = atoi(n.c_str());
	} while (m == 0 && m < 0);
	return m;
}