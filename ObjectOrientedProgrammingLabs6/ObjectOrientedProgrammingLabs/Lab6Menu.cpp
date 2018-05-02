#pragma once
#include "CheckSymbol.h"
#include "PersonList6.h"
#include "PersonTools6.h"
#include "Person6.h"
#include "Adult.h"
#include "Child.h"
using namespace std;

namespace Lab6
{
	int Lab6()
	{
		Lab6::PersonList* tempList = new Lab6::PersonList();
		int menuNumber;
		int index;
		//TODO: Именование!
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
				//TODO: Добавить ручной ввод
				tempList->Add(Lab6::PersonTools::MakeRandomPerson());
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
			case 7:
			{
				cout << "Add your own person to the list" << endl;
				tempList->ReadPerson();

			}
			case 8:
			{
				cout << "Add child to the list" << endl;
				tempList->Add(Child::GetRandomChild());
				
			}
			case 9:
			{
				Adult* adult1 = Lab6::Adult::GetRandomAdult();
				/*cout << "Add adult to the list" << endl;
				tempList->Add(Adult::GetRandomAdult());*/
				tempList->Add(adult1);
				
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