#pragma once
#include "CheckSymbol.h"
#include "PersonLab5.h"
using namespace std;

namespace Lab5
{
	class PersonListItem
	{
		public:
			PersonListItem(Person* person)
			{
				if (_value != nullptr)
				{
					_value = person;
				}
				
			}

			Person* GetValue();
			PersonListItem* Next = nullptr;
			PersonListItem* Prev = nullptr;
		private:
			Person* _value;
	};
}