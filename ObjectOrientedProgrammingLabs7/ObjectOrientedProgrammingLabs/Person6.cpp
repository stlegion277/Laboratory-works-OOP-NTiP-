#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	
	PersonBase::~PersonBase()
	{

	}

	PersonBase::PersonBase(char name[arraySize], char surname[arraySize], unsigned int age, Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}

	void PersonBase::SetName(char nameTemp[arraySize])
	{
		if (!CheckFirstDigit(nameTemp))
		{
			throw new exception("name");
		}
		strcpy_s(_name, arraySize, nameTemp);
	}

	void PersonBase::SetSurname(char surnameTemp[arraySize])
	{
		if (!CheckFirstDigit(surnameTemp))
		{
			throw new exception("surnname");
		}
		strcpy_s(_surname, arraySize, surnameTemp);

	}

	void PersonBase::SetAge(unsigned int age)
	{
		if (age >= 0)
		{
			_age = age;
		}
	}

	void PersonBase::SetSex(Sex sex)
	{
		_sex = sex;
	}

	bool PersonBase::CheckFirstDigit(char nameTemp[arraySize])
	{
		for (int i = 0; i < strlen(nameTemp); i++)
		{
			if (isdigit(nameTemp[i]) && isspace(nameTemp[i]))
			{
				return false;
			}
		}
		return true;
	}

	string PersonBase::GetDescription()
	{
		string description = "\nName = " + string(this->GetName()) + 
			"\nSurname = " + string(this->GetSurname());
			
		enum Sex tempSexKey = this->GetSex();
		switch (tempSexKey)
		{//TODO: Отступы!
			//сделал
			case Male:
			{
				description += "\nSex = Male\n";
				break;
			}
			case Female:
			{
				description += "\nSex = Female\n";
				break;
			}
			}
			return description;
	}

	char* PersonBase::GetName()
	{
		return _name;
	}

	char* PersonBase::GetSurname()
	{
		return _surname;
	}

	
	Sex PersonBase::GetSex()
	{
		return _sex;
	}

	bool PersonBase::operator==(const PersonBase& right)
	{
		return(!strcmp(_name, right._name) &&
			!strcmp(_surname, right._surname) &&
			_age == right._age && _sex == right._sex);
	}
}