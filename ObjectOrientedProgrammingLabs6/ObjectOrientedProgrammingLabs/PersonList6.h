#pragma once
#include "CheckSymbol.h"
#include "PersonListItem6.h"
#include <iostream>
using namespace std;

namespace Lab6
{
	class PersonList
	{
	public:
		PersonList() {};
		~PersonList();
		char* CheckPerson(char Name[Person::arraySize]);
		void Add(Person* person);
		void Remove(Person* person);
		int IndexOf(Person* person);
		void RemoveByIndex(int index);
		void Clear();
		int GetCount();
		void Show();
		Person* Find(int index);


	private:
		int _count;
		PersonListItem* _head = nullptr;
		PersonListItem* _tail = nullptr;
		void ShowNodeInConsole(PersonListItem list);
		
	};
}