#pragma once
#include "CheckSymbol.h"
#include "PersonList6.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	void PersonList::Add(PersonBase* person)
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

	void PersonList::Remove(PersonBase* person)
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

	void PersonList::RemoveByIndex(int index)
	{
		PersonBase* person = Find(index);
		Remove(person);
	}

	int PersonList::IndexOf(PersonBase* person)
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
		int elementCounter = 0;
		while (tempList != nullptr)
		{
			ShowNodeInConsole(*tempList);
			tempList = tempList->Next;
			elementCounter++;
			cout << "\nElement = " << elementCounter << endl;
		}
		if (_head == nullptr || _tail == nullptr )
		{
			cout << "Head and Tail elements are NULL! List is empty!" << endl;

		}
	}

	PersonBase* PersonList::Find(int index)
	{
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
		cout << list.GetValue()->GetDescription();
	}

	PersonList::~PersonList()
	{
		Clear();
	}
}