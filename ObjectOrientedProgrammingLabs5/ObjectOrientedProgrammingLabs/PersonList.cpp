#pragma once
#include "CheckSymbol.h"
#include "PersonList.h"
#include "PersonLab5.h"
using namespace std;

namespace Lab5
{
	void PersonList::Add(Person* person)
	{
		PersonListItem* tempList = new PersonListItem(person);
		if (_head != nullptr)
		{
			tempList->Prev = _tail;
			_tail->Next = tempList;
			_tail = tempList;
		}
		if (_head == nullptr)
		{
			_head = _tail = tempList;
		}
	}
	//TODO: Зачем столько пустых строк?
	void PersonList::Remove(Person* person)
	{
			PersonListItem* tempList = _head;
			while (tempList != nullptr)
			{
				if (tempList->GetValue() == person)
				{
					if (_head == tempList)
					{
						if (tempList->Next == nullptr)
						{
							_head = nullptr;
							_tail = nullptr;
							break;
						}
						_head->Next->Prev = nullptr;
						_head = _head->Next;
						break;
					}
					if (_tail == tempList)
					{
						_tail->Prev->Next = nullptr;
						_tail = _tail->Prev;
						break;
					}
					if (_head != tempList && _tail != tempList)
					{
						tempList->Prev->Next = tempList->Next;
						tempList->Next->Prev = tempList->Prev;
						break;
					}
				}
				tempList = tempList->Next;
			}
		}

	void PersonList::RemoveByIndex(unsigned int index)
	{//TODO: А зачем давать возможность удаления по отрицательному индексу, если можно использовать беззнаковое число
		//сделал
		Person* person = Find(index);
		Remove(person);
	}

	int PersonList::IndexOf(Person* person)
	{
		PersonListItem* tempList = _head;
		int index = 0;
		while (tempList != nullptr)
		{
			if (tempList->GetValue() == person)
			{
				cout << "Index of a person = ";
				cout << index;
			}
			index++;
			tempList = tempList->Next;
		}
		cout << "List doesn't have person with this index";
		return -1;
	}

	void PersonList::Clear()
	{
		PersonListItem* tempList = _head;
		while (tempList != nullptr)
		{
			PersonListItem* tempNextList = tempList->Next;
			delete tempList;
			tempList = tempNextList;
		}
		_head = nullptr;
		_tail = nullptr;
		_head = _tail;
	}

	int PersonList::GetCount()
	{
		int counter = 0;
		PersonListItem* tempList = _head;
		while (tempList != nullptr)
		{
			tempList = tempList->Next;
			counter++;
		}
		return counter;
	}

	void PersonList::Show()
	{
		cout << endl;
		PersonListItem* tempList = _head;
		while (tempList != nullptr)
		{
			ShowNodeInConsole(*tempList);
			tempList = tempList->Next;
		}
		if (_head != nullptr)
		{
			cout << "HEAD ELEMENT =\n"; 
			ShowNodeInConsole(*_head);
			cout << "TAIL ELEMENT =\n";
			ShowNodeInConsole(*_tail);
		}
		else
		{
			cout << "Head and Tail elements are NULL! List is empty!" << endl;
				
		}
	}

	Person* PersonList::Find(unsigned int index)
	{//TODO: А зачем давать возможность поиска по отрицательному индексу, если можно использовать беззнаковое число
		//сделал
		if (index < 0)
		{
			return nullptr;
		}
		PersonListItem* tempList = _head;
		int counter = 0;
		while (counter < index)
		{
			if (tempList == nullptr)
			{
				return nullptr;
			}
			tempList = tempList->Next;
			counter++;
		}
		return tempList->GetValue();
	}

	void PersonList::ShowNodeInConsole(PersonListItem list)
	{
		cout << " Surname: " << list.GetValue()->GetSurname() << endl;
		cout << " Name: " << list.GetValue()->GetName() << endl;
		cout << " Age: " << list.GetValue()->GetAge() << endl;
		cout << " Sex: ";
		if (list.GetValue()->GetSex() == Male)
		{
			cout << "Male";
		}
		cout << endl << endl;

	}

	void PersonList::ReadPerson()
	{
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		int tempAge = 0;
		Sex tempSex;
		int sexChoice;
		//TODO: Именование не отражает назначения
		//сделал
		bool phraseCheckFlag = true;
		//TODO: Ниже два дубля. Исправьте.
		while (phraseCheckFlag)
		{
			cout << "Enter person's name" << endl;
			cin >> tempName;
			phraseCheckFlag = !CheckPersonNameSurname(tempName);
		}
		phraseCheckFlag = true;
		while (phraseCheckFlag)
		{
			cout << "Enter person's surname" << endl;
			cin >> tempSurname;
			phraseCheckFlag = !CheckPersonNameSurname(tempSurname);
		}
		do
		{
			cout << "Enter person's age" << endl;
			cout << "Your person can't be older than 130 years or younger than 0" << endl;
			tempAge = CheckSymbol();
		} 
		while (tempAge <= 0 || tempAge > 130);
		
		do
		{
			cout << "Please enter person's sex" << endl;
			cout << "0 - Female, 1 - Male" << endl;
			sexChoice = CheckSymbol();
		} 
		while ((sexChoice < 0) && (sexChoice > 1));
		switch (sexChoice)
		{//TODO: Не по RSDN! 
			//сделал
			case 0:
				tempSex = Female;
				break;
			case 1:
				tempSex = Male;
				break;
			default:
				break;
		}
		this->Add(new Person(tempName, tempSurname, tempAge, tempSex));
	}
	//TODO: Зачем пустой конструктор?
	//убрал
	PersonList::~PersonList()
	{
		Clear();
	}
	//TODO: Почему CheckPerson?
	//сделал
	bool PersonList::CheckPersonNameSurname(char tempName[Person::arraySize])
	{
		bool checkNameSurname = true;
		for (int i = 0; i < strlen(tempName); i++)
		{
			if ((isdigit(tempName[i])) || (isspace(tempName[i])))
			{
				checkNameSurname = false;
				break;
			}
		}
		return checkNameSurname;
	}
}