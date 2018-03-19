#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
inline int CheckSymbol()
{//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
 //TODO: и приведите свой код в соответстие со стандартом
	string n;
	int m;
	do {
		cin >> n;
		m = atoi(n.c_str());
	}
	while (m == 0 && m < 0);
	return m;
}