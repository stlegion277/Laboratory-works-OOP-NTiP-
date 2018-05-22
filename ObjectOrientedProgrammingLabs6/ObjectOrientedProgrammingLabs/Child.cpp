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

	Child::Child(char name[Person::arraySize], char surname[Person::arraySize], unsigned int age,
		enum Sex sex, Person * mother, Person * father, char school[arraySize]) : Person(name, surname, age, sex)
	{
		SetMother(mother);
		SetFather(father);
	}

	void Child::SetMother(Person* mother)
	{	
		_mother = mother;	
	}

	void Child::SetFather(Person * father)
	{
		_father = father;	
	}
	//TODO: Беззнаковый
	//сделал
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
		string descriptionChild = Person::GetDescription();
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

	Person* Child::GetMother()
	{
		return _mother;
	}

	Person* Child::GetFather()
	{
		return _father;
	}

	int Child::GetAge()
	{
		return _age;
	}
}
