#pragma once
#include "Child.h"

namespace Lab6
{
	Child::~Child()
	{
		delete _school;
		delete _mother;
		delete _father;
	}

	Child::Child(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], unsigned int age,
		enum Sex sex, PersonBase * mother, PersonBase * father, char school[arraySize]) : PersonBase(name, surname, age, sex)
	{
		SetMother(mother);
		SetFather(father);
	}

	void Child::SetMother(PersonBase* mother)
	{	
		//TODO: Проверка на входные данные (ниже тоже)
		_mother = mother;	
	}

	void Child::SetFather(PersonBase * father)
	{
		_father = father;	
	}

	void Child::SetAge(unsigned int age)
	{
		if (age < 18)
		{
			_age = age;
		}
		else
		{
			_age = rand() % 17;
			_age = age;
		}
		
	}

	void Child::SetSchool(char* school)
	{
		strcpy_s(_school, arraySize, school);
	}

	string Child::GetDescription()
	{
		string descriptionChild = PersonBase::GetDescription();
		descriptionChild += "Studies in = " + string(this->GetSchool());
		descriptionChild += "\nAge = " + to_string(this->GetAge());
		if (_father != nullptr)
		{
			descriptionChild += "\nFATHER = " + string(this->GetFather()->GetDescription());
		}
		else if (_mother != nullptr)
		{
			descriptionChild += "\nMOTHER = " + string(this->GetMother()->GetDescription());
		}
		else
		{
			descriptionChild += "\nChild is an orphan :(\n";
		}
		return descriptionChild;
	}

	char* Child::GetSchool()
	{
		return _school;
	}

	PersonBase* Child::GetMother()
	{
		return _mother;
	}

	PersonBase* Child::GetFather()
	{
		return _father;
	}

	//TODO: unsigned
	//сделал
	unsigned int Child::GetAge()
	{
		return _age;
	}
}
