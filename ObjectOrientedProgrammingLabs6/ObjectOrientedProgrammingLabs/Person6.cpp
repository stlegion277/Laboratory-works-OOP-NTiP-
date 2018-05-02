#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	
	Person::~Person()
	{

	}
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
		//TODO:Проверять входные параметры
		//исправил (кого исправили, вы же не показывали мне лабу?)
		//TODO: Проверка дублируется ниже!
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
	//TODO: Входной тип данных
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

	string Person::GetDescription()
	{
		string description = "\nName = " + string(this->GetName()) + "\nSurname = " + string(this->GetSurname()) 
			+ "\nAge = " + to_string(this->GetAge());
		enum Sex tempSexKey = this->GetSex();
		switch (tempSexKey)
		{
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