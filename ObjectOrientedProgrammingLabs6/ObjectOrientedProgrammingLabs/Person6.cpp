#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	
	Person::~Person()
	{

	}

	Person::Person(char name[arraySize], char surname[arraySize], int age, enum Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}

	void Person::SetName(char nameTemp[arraySize])
	{
		//TODO:Проверять входные параметры
		//исправил (кого исправили, вы же не показывали мне лабу?)
		//старая TODO которая осталась тут когда лабу переносил
		//TODO: Проверка дублируется ниже!
		//в функцию вынести?
		//TODO: Да
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
	//TODO: Входной тип данных
	//сделал
	//TODO: Чё сделали-то, почему int знаковый?
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