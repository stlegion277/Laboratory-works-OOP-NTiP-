#pragma once
#include "CheckSymbol.h"
#include "PersonLab5.h"
using namespace std;

namespace Lab5
{
	//TODO:RSDN
	Person::Person(char Name[arraySize], char Surname[arraySize], int Age, enum Sex Sex)
	{
		SetName(Name);
		SetSurname(Surname);
		SetAge(Age);
		SetSex(Sex);
	}

	void Person::SetName(char nameTemp[arraySize])
	{
		for (int i = 0; i < strlen(nameTemp); i++)
		{
			if (!isdigit(nameTemp[i]) && !isspace(nameTemp[i]))
			{
				strcpy_s(Name, arraySize, nameTemp);
			}				
		}		
	}

	void Person::SetSurname(char surnameTemp[arraySize])
	{
		for (int i = 0; i < strlen(surnameTemp); i++)
		{
			if (!isdigit(surnameTemp[i]) || !isspace(surnameTemp[i]))
			{
				strcpy_s(Surname, arraySize, surnameTemp);
			}
		}		
	}

	void Person::SetAge(int age)
	{
		if (age >= 0)
		{
			Age = age;
		}
	}

	void Person::SetSex(enum Sex sex)
	{
		Sex = sex;
	}

	char* Person::GetName()
	{
		return Name;
	}
	
	char* Person::GetSurname()
	{
		return Surname;
	}

	int Person::GetAge()
	{
		return Age;
	}

	Sex Person::GetSex()
	{
		return Sex;
	}

	bool Person::operator==(const Person& right)
	{
		return(!strcmp(Name, right.Name) &&
			!strcmp(Surname, right.Surname) &&
			Age == right.Age && Sex == right.Sex);
	}
}