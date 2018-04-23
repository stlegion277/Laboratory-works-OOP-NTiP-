#pragma once
#include "CheckSymbol.h"
#include "PersonLab5.h"
using namespace std;

namespace Lab5
{
	//TODO:RSDN
	Person::Person(char _name[arraySize], char _surname[arraySize], int _age, enum Sex _sex)
	{
		SetName(_name);
		SetSurname(_surname);
		SetAge(_age);
		SetSex(_sex);
	}

	void Person::SetName(char nameTemp[arraySize])
	{
		for (int i = 0; i < strlen(nameTemp); i++)
		{
			if (!isdigit(nameTemp[i]) && !isspace(nameTemp[i]))
			{
				strcpy_s(_name, arraySize, nameTemp);
			}				
		}		
	}

	void Person::SetSurname(char surnameTemp[arraySize])
	{
		for (int i = 0; i < strlen(surnameTemp); i++)
		{
			if (!isdigit(surnameTemp[i]) || !isspace(surnameTemp[i]))
			{
				strcpy_s(_surname, arraySize, surnameTemp);
			}
		}		
	}

	void Person::SetAge(int age)
	{
		if (age >= 0)
		{
			_age = age;
		}
	}

	void Person::SetSex(enum Sex sex)
	{
		_sex = sex;
	}

	char* Person::GetName()
	{
		return _name;
	}
	
	char* Person::GetSurname()
	{
		return _surname;
	}

	int Person::GetAge()
	{
		return _age;
	}

	Sex Person::GetSex()
	{
		return _sex;
	}

	bool Person::operator==(const Person& right)
	{
		return(!strcmp(_name, right._name) &&
			!strcmp(_surname, right._surname) &&
			_age == right._age && _sex == right._sex);
	}
}