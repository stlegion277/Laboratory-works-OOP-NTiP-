#pragma once
#include "DoubleLinkedListLab4.h"
#include "CheckSymbol.h"

using namespace std;

namespace Lab4
{
	int Lab4()
	{	
		List *list = new List;
		Node* tempList = new Node;
		enum MenuEnum
		{
			AddEnum = 1,
			ShowEnum,
			GetIndexEnum,
			RemoveEnum,
			InsertEnum,
			ClearEnum
		};
		int menuNumber;
		int index;
		//TODO: Плохое именование переменной//исправил (не знал как назвать)
		bool menuExit = true;
		//TODO: Можно не писать//сделал
		while (menuExit)
		{
			system("color f1");
			cout << "1. Add in double linked list\n";
			cout << "2. Show double linked list\n";
			cout << "3. Get element by index\n";
			cout << "4. Remove element by index\n";
			cout << "5. Insert element by index\n";
			cout << "6. Clear the list\n";
			cout << "0 Exit\n ";
			cout << "Enter number of a function to start\n ";
			menuNumber = CheckSymbol();
			switch (menuNumber)
			{
				case 0:
					menuExit = 0;
					break;
				case AddEnum:
				{
					AddInEnd(list);
					Show(list,tempList);
					break;
				}
				case ShowEnum:
				{
					Show(list, tempList);
					break;
				}
				case GetIndexEnum:
				{
					cout << "Enter index of element you want to get" << endl;
					index = CheckSymbol();
					Node* temp = GetIndex(index, list);
					cout << &temp << endl;
					break;
				}
				case RemoveEnum:
				{
					cout << "Enter an index of element you want to remove " << endl;
					index = CheckSymbol();
					Remove(index, list);
					Show(list,tempList);
					break;
				}
				case InsertEnum:
				{
					cout << "Enter an element index" << endl;
					index = CheckSymbol();
					Insert(index, list, Lab4::MakeRandomPerson());
					Show(list, tempList);
					break;
				}
				case ClearEnum:
				{
					Clear(list);
					cout << "List is empty now!" << endl;
					break;
				}
				default: cout << "Enter number of function to start ";
					break;
			}
		}
		system("pause");//TODO: Форматирование!//Сделал!
		return 0;
	}
}