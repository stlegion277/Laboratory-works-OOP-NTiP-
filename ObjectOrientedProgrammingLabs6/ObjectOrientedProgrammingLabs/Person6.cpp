#pragma once
#include "CheckSymbol.h"
#include "Person6.h"
using namespace std;

namespace Lab6
{
	
	Person::~Person()
	{

	}

	Person::Person(char name[arraySize], char surname[arraySize], unsigned int age, Sex sex)
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
		//сделал
		if (!CheckFirstDigit(nameTemp))
		{
			throw new exception("name");
		}
		strcpy_s(_name, arraySize, nameTemp);
	}

	void Person::SetSurname(char surnameTemp[arraySize])
	{
		if (!CheckFirstDigit(surnameTemp))
		{
			throw new exception("surnname");
		}
		strcpy_s(_surname, arraySize, surnameTemp);

	}
	//TODO: Входной тип данных
	//сделал
	//TODO: Чё сделали-то, почему int знаковый?
	//я думал вы про то что Age с большой
	void Person::SetAge(unsigned int age)
	{
		if (age >= 0)
		{
			_age = age;
		}
	}

	void Person::SetSex(Sex sex)
	{
		_sex = sex;
	}

	bool Person::CheckFirstDigit(char nameTemp[arraySize])
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

	string Person::GetDescription()
	{
		string description = "\nName = " + string(this->GetName()) + "\nSurname = " + string(this->GetSurname());
			
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