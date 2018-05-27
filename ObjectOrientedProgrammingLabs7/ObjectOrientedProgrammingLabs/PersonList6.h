#pragma once
#include "CheckSymbol.h"
#include "PersonListItem6.h"
#include <iostream>
using namespace std;

namespace Lab6
{
	class PersonList
	{//TODO: Отступы.
		//сделал
		public:
			~PersonList();
			char* CheckPerson(char Name[PersonBase::arraySize]);
			void Add(PersonBase* person);
			void Remove(PersonBase* person);
			int IndexOf(PersonBase* person);
			void RemoveByIndex(int index);
			void Clear();
			int GetCount();
			void Show();
			PersonBase* Find(int index);

		private:
			int _count;
			PersonListItem* _head = nullptr;
			PersonListItem* _tail = nullptr;
			void ShowNodeInConsole(PersonListItem list);		
		};
}