#pragma once
#include "stdafx.h"

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