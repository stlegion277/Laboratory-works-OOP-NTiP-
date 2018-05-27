#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	class PersonListItem
	{
		public:
			PersonListItem(PersonBase* person)
			{
				_value = person;
			}

			PersonBase* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			PersonBase* _value;
	};
}