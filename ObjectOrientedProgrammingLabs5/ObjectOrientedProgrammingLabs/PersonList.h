#pragma once
#include "CheckSymbol.h"
#include "PersonLab5.h"
#include "PersonListItem.h"
using namespace std;

namespace Lab5
{
	class PersonList
	{
		public:
			//TODO: Зачем пустой конструктор?
			//сделал
			~PersonList();
			void ReadPerson();
			void Add(Person* person);
			void Remove(Person* person);
			int IndexOf(Person* person);
			void RemoveByIndex(unsigned int index);
			void Clear();
			int GetCount();
			void Show();
			Person* Find(unsigned int index);
		private:
			bool CheckForKirillica(char _name[Person::arraySize]);
			bool CheckFirstSymbol(char _name[Person::arraySize]);
			int _count;
			PersonListItem* _head = nullptr;
			PersonListItem* _tail = nullptr;
			void ShowNodeInConsole(PersonListItem list);
	};
}