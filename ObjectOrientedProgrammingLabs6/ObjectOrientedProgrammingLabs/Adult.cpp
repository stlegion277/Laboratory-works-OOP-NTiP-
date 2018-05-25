#pragma once
#include "Adult.h"

namespace Lab6
{
	Adult::Adult(char name[PersonBase::arraySize], char surname[PersonBase::arraySize],
		int age, enum Sex sex, char* workPlace) : PersonBase(name, surname, age, sex)
	{
		SetWorkPlace(workPlace);
		SetAge(age);
	};
	//TODO Unsigned
	//сделал
	void Adult::SetAge(unsigned int age)
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

	void Adult::SetWorkPlace(char* workPlace)
	{
		//TODO: Проверка?
		//сделал
		if (_workPlace != nullptr)
		{
			strcpy_s(_workPlace, arraySize, workPlace);
		}

	}

	string Adult::GetDescription()
	{
		string descriptionAdult = PersonBase::GetDescription();
		descriptionAdult += "Works in = " + string(this->GetWorkPlace());
		descriptionAdult += "\nAge = " + to_string(this->GetAge());
		if (_marriage != nullptr)
		{
			descriptionAdult += "\nMarried with " + string(this->_marriage->GetName()) + " "
				+ string(this->_marriage->GetSurname());
		}
		return descriptionAdult;
	}

	char* Adult::GetWorkPlace()
	{
		return _workPlace;
	}

	unsigned int Adult::GetAge()
	{
		return _age;
	}

	Adult::~Adult()
	{
		delete _marriage;
		delete _workPlace;
	}
}
