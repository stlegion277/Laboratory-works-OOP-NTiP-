#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
//#include "PersonList6.h"
using namespace std;

namespace Lab6
{
	class PersonListItem
	{
		public:
				PersonListItem(Person* person)
				{
					//TODO: ������� �� ������� ������
					_value = person;
				}

				Person* GetValue();
				PersonListItem* Next = nullptr;
				PersonListItem* Prev = nullptr;
		private:
				Person * _value;
	};
}