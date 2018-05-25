#pragma once
#include "Lab6Menu.h"
using namespace std;

namespace Lab6
{
	int Lab6()
	{
		Lab6::PersonList* tempList = new Lab6::PersonList();
		int menuNumber;
		int index;

		bool menuExit = true;
		while (menuExit)
		{
			cout << "\n1. Add child to the list\n";
			cout << "2. Show double linked list\n";
			cout << "3. Get element by index\n";
			cout << "4. Remove element by index\n";
			cout << "5. Clear the list\n";
			cout << "6. Count all elements\n";
			cout << "7. Add adult to the lit\n";
			cout << "0 Exit\n ";
			cout << "Enter number of a function to start\n ";
			menuNumber = CheckSymbol();
			switch (menuNumber)
			{
			case 0:
				menuExit = false;
				break;
			case 1:
			{
				//TODO: Падает после добавления нескольких персон
				cout << "Add child to the list" << endl;
				tempList->Add(PersonTools::MakeRandomChild());
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
				PersonBase* person = tempList->Find(CheckSymbol());
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

				tempList->Add(PersonTools::MakingMarriage());
			}
			default:
				cout << "Enter number of function to start ";
				break;
			}
		}
		system("pause");
		return 0;
	}
}