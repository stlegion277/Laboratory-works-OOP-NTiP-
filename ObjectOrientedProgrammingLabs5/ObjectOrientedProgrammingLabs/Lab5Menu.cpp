#pragma once
#include "CheckSymbol.h"
#include "PersonList.h"
#include "PersonTools.h"
#include "PersonLab5.h"
using namespace std;

namespace Lab5
{
	int Lab5()
	{
		Lab5::PersonList* tempList = new Lab5::PersonList();
		int menuNumber;
		int index;
		bool menuExit = true;
		while (menuExit)
		{
			cout << "1. Add in double linked list\n";
			cout << "2. Show double linked list\n";
			cout << "3. Get element by index\n";
			cout << "4. Remove element by index\n";
			cout << "5. Clear the list\n";
			cout << "6. Count all elements\n";
			cout << "7. Enter your person to list\n";
			cout << "0 Exit\n ";
			cout << "Enter number of a function to start\n ";
			menuNumber = CheckSymbol();
			switch (menuNumber)
			{
				case 0:
					menuExit = 0;
					break;
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
					cout << "Enter index of a person: \n";
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
				case 7:
				{
					//TODO: Косячно обрабатывает ввод.
					//исправил
					//TODO: Падает сразу же при вводе строки "епкуыцкпфы"
					cout << "Add your own person to the list" << endl;
					tempList->ReadPerson();

				}
				default: cout << "Enter number of function to start ";
					break;
				}
				
			}
			system("pause");
			return 0;
		}
}