#pragma once
#include "Adult.h"

namespace Lab6
{
	Adult::Adult(char name[Person::arraySize], char surname[Person::arraySize],
		int age, enum Sex sex, char* workPlace) : Person(name,surname, age, sex)
	{
		SetWorkPlace(workPlace);
		//SetMarriage(marriage);
		SetAge(age);
	};

	void Adult::SetAge(int age)
	{
		if (age >= 18)
		{
			_age = age;
		}
		else
		{
			cout << "It's an adult person, please enter 18+ age!" << endl;
		}
	}

	//void Adult::SetMarriage(Person* marriage)
	//{
	//	_marriage = marriage;
	//}

	void Adult::SetWorkPlace(char* workPlace)
	{
		strcpy_s(_workPlace, arraySize, workPlace);
	}

	string Adult::GetDescription()
	{
		string descriptionAdult = Person::GetDescription();
		descriptionAdult += "Works in = " + string(this->GetWorkPlace());
		descriptionAdult += "\nAge = " + to_string(this->GetAge());
		if (_marriage != nullptr)
		{
			descriptionAdult += "\nMarried with " + string(this->_marriage->GetName()) + " "
				+ string(this->_marriage->GetSurname());
		}
		return descriptionAdult;
	}

	/*Person* Adult::GetMarriage()
	{
		return _marriage;
	}*/

	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	int Adult::GetAge()
	{
		return _age;
	}

	Adult::~Adult()
	{
		delete _marriage;
		delete _workPlace;
	}
}
