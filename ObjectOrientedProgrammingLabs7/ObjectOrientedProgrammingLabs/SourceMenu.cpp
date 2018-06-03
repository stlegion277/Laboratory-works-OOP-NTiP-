#pragma once
#include "CheckSymbol.h"
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "DoubleLinkedListLab4.h"
#include "Lab5Menu.h"
#include "Lab6Menu.h"
#include "TemplateMenu.h"

int main()
{
	srand(time(0));
	int menuNumber;
	while (true)
	{
		
		cout << endl
		<< "1 Lab 1" << endl
		<< "2 Lab 2" << endl
		<< "3 Lab 3" << endl
		<< "4 Lab 4" << endl
		<< "5 Lab 5" << endl
		<< "6 Lab 6" << endl
		<<" 7 Lab 7" <<endl
		<< "0 Exit" << endl
		<< "Choose wisely: ";
		menuNumber = CheckSymbol();
		system("cls");
		switch (menuNumber)
		{
			case 1:
				Lab1(); 
				break;
			case 2:
				Lab2::Lab2();
				break;
			case 3:
				Lab3::Lab3();
				break;
			case 4:
				Lab4::Lab4(); 
				break;
			case 5:
				Lab5::Lab5();
				break;
			case 6:
				Lab6::Lab6();
			case 7:
				MenuForMenu();
			case 0:
				return 0;
			default:
				cout << "Enter correct number"; break;
			}
		}
			return 0;
}