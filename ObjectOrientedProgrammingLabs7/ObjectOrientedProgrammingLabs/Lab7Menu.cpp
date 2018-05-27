#pragma once
#include "Lab7Menu.h"
using namespace std;
using namespace Lab5;

int ListMenu()
{
	TempList<TempList<double>*> *tempList = new TempList<TempList<double>*>();
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
		cout << "7. Enter your person to list\n";
		cout << "8. Add child to the list\n";
		cout << "9. Add adult to the lit\n";
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
				index = CheckSymbol();
				tempList->IndexOf();
				cout << &tempList << endl;
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

int DoubleListMenu(TempList<double>* tempList, int element)
{

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
		cout << "7. Enter your person to list\n";
		cout << "8. Add child to the list\n";
		cout << "9. Add adult to the lit\n";
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

				tempList->Add(new TempList<double*>*);
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
				Person* person = tempList->Find(CheckSymbol());
				if (person != nullptr)
				{
					cout << "Found person: " << endl;
					cout << " Surname: " << person->GetSurname() << endl;
					cout << " Name: " << person->GetName() << endl;
					cout << " Age: " << person->GetAge() << endl;
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



int PersonMenu()
{
	TempList<Person*>* tempList = new TempList<Lab5::Person*>();
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
				tempList->Add(Lab5::PersonTools::MakeRandomPerson());
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
				Person* person = tempList->Find(CheckSymbol());
				if (person != nullptr)
				{
					cout << "Found person: " << endl;
					cout << " Surname: " << person->GetSurname() << endl;
					cout << " Name: " << person->GetName() << endl;
					cout << " Age: " << person->GetAge() << endl;
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
			default:
			{
				cout << "Enter number of function to start ";
				break;
			}
		}
	}

	system("pause");
	return 0;

}


