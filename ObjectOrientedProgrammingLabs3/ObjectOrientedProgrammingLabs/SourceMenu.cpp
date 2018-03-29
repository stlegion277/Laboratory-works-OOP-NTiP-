#pragma once
#include "CheckSymbol.h"
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"

int main()
{
	srand(time(0));
	int numberMenu;
	while (true)
	{
		cout << endl
		<< "1 Lab 1" << endl
		<< "2 Lab 2" << endl
		<< "3 Lab 3" << endl
		<< "0 Exit" << endl
		<< "Choose wisely: ";
		numberMenu = CheckSymbol();
		system("cls");
		switch (numberMenu)
		{//TODO: Ќеправильное форматирование
			//исправил
			case 1:
				Lab1();
				break;
			case 2:
				Lab2::Lab2(); 
				break;
			case 3:
				Lab3::Lab3(); 
				break;
			case 0:
				return 0;
			default:
				cout << "Enter correct number"; 
				break;
		}
	}
	return 0;
}