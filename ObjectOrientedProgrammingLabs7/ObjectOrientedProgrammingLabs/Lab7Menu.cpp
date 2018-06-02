#pragma once
#include "Lab7Menu.h"
using namespace std;
using namespace Lab6;

void ListMenu()
{
	TempList<TempList<double>*>* tempList = new TempList<TempList<double>*>();
	int menuNumber;
	int index;
	bool menu = true;
	while (menu)
	{
		cout << "1. Add element\n";
		cout << "2. Show double linked list\n";
		cout << "3. Get element by index\n";
		cout << "4. Remove element by index\n";
		cout << "5. Clear the list\n";
		cout << "6. Count all elements\n";
		cout << "0 Exit\n ";
		cout << "Enter number of a function to start\n ";
		menuNumber = CheckSymbol();
		switch (menuNumber)
		{
			case 0:
				menu = 0;
				break;
			case 1:
			{

				tempList->Add(new TempList<double>);
				tempList->Show();
				break;
			}
			case 2:
			{
				tempList->Show();
				break;
			}
			case 3:
			{

				cout << "Enter index of element you want to get" << endl;
				int index = CheckSymbol();
				tempList->Find(index);
				DoubleListMenu(tempList->Find(index), index);
				break;
			}
			case 4:
			{
				cout << "Enter an index of element you want to remove " << endl;
				index = CheckSymbol();
				tempList->RemoveByIndex(index);
				tempList->Show();
				break;
			}
			case 5:
			{
				tempList->Clear();
				cout << "List is empty now!" << endl;
				break;
			}
			case 6:
			{
				cout << "Number of elements in list == ";
				cout << tempList->GetCount() << endl;
				break;

			}
		}
	}
}

void DoubleListMenu(TempList<double>* tempList, int element)
{

	int menuNumber;
	int index;
	bool menu = true;
	while (menu)
	{
		cout << "1. Add element in double linked list\n";
		cout << "2. Show double linked list\n";
		cout << "3. Get element by index\n";
		cout << "4. Remove element by index\n";
		cout << "5. Clear the list\n";
		cout << "6. Count all elements\n";
		cout << "0 Exit\n ";
		cout << "Enter number of a function to start\n ";
		menuNumber = CheckSymbol();
		switch (menuNumber)
		{
			case 0:
			{
				menu = 0;
				break;
			}
			case 1:
			{
				double* tempElement = new double(CheckSymbol());
				tempList->Add(*tempElement);
				tempList->Show();
				break;
			}
			case 2:
			{
				tempList->Show();
				break;
			}
			case 3:
			{
				cout << "\n Enter index of a person: \n";
//TODO: Зачем это здесь?
				//сделал
				int index;
				index = CheckSymbol();
				tempList->Find(index);
				double tempSearchedElement = tempList->Find(index);
				double* tempElement = &tempSearchedElement;
				break;
			}
			case 4:
			{
				cout << "Enter an index of element you want to remove " << endl;
				index = CheckSymbol();
				tempList->RemoveByIndex(index);
				tempList->Show();
				break;
			}
			case 5:
			{
				tempList->Clear();
				cout << "List is empty now!" << endl;
				break;
			}
			case 6:
			{
				cout << "Number of persons in list == ";
				cout << tempList->GetCount() << endl;
				break;

			}
		}

	}  
}



void PersonMenu()
{
	TempList<Lab6::Adult*>* tempList = new TempList<Lab6::Adult*>();
	int menuNumber;
	int index;
	bool menu = true;
	while (menu)
	{
		cout << "1. Add RANDOM person in double linked list\n";
		cout << "2. Show double linked list\n";
		cout << "3. Get element by index\n";
		cout << "4. Remove element by index\n";
		cout << "5. Clear the list\n";
		cout << "6. Count all elements\n";
		cout << "0 Exit\n ";
		cout << "Enter number of a function to start\n ";
		menuNumber = CheckSymbol();
		switch (menuNumber)
		{
			case 0:
			{
				menu = 0;
				break;
			}
			case 1:
			{
				tempList->Add(Lab6::PersonTools::MakeRandomAdult(Male));
				tempList->Add(Lab6::PersonTools::MakeRandomAdult(Female));
				tempList->Show();
				break;
			}
			case 2:
			{
				tempList->Show();
				break;
			}
			case 3:
			{
				cout << "\n Enter index of a person: \n";
				Adult* person = tempList->Find(CheckSymbol());
				if (person != nullptr)
				{
					cout << "Found person: " << endl;
					cout << " Surname: " << person->GetSurname() << endl;
					cout << " Name: " << person->GetName() << endl;//TODO: Почему закоменчено? Не работает?
					 //была в private не могла наследоваться вот я и закоментил, а так все работает
					cout << " Sex: ";
					if (person->GetSex() == Male)
					{
						cout << "Male";
					}
					cout << endl << endl;
				}
				else
				{
					cout << "Person not found" << endl;
				}
				break;
//TODO: Зачем это здесь?//сделал
			}
			case 4:
			{
				cout << "Enter an index of element you want to remove " << endl;
				index = CheckSymbol();
				tempList->RemoveByIndex(index);
				tempList->Show();
				break;
			}
			case 5:
			{
				tempList->Clear();
				cout << "List is empty now!" << endl;
				break;
			}
			case 6:
			{
				cout << "Number of persons in list == ";
				cout << tempList->GetCount() << endl;
				break;

			}			
			default:
			{
				cout << "Enter number of function to start ";
				break;
			}
		}
	}
	system("pause");
}


