#pragma once
#include "Child.h"

namespace Lab6
{
	

	Child::~Child()
	{

	}

	Child::Child(char name[Person::arraySize], char surname[Person::arraySize], int age,
		enum Sex sex, Person * Mother, Person * Father, char school[arraySize])
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		SetMother(Mother);
		SetFather(Father);
	}

	void Child::SetMother(Person * Mother)
	{
		_mother = Mother;
	}

	void Child::SetFather(Person * Father)
	{
		_father = Father;
	}

	void Child::SetAge(int age)
	{
		if (age < 18)
		{
			Age = age;
		}
		else
		{
			Age = rand() % 17;
		}
		
	}

	void Child::SetSchool(char* school)
	{
		strcpy_s(_school, arraySize, school);
	}

	string Child::GetDescription()
	{
		string descriptionChild = Person::GetDescription();
		descriptionChild += "\nStudies in = " + string(this->GetSchool());
		if (_father != nullptr)
		{
			descriptionChild += "\nFATHER" + string(this->GetFather()->GetDescription());
		}
		else if (_mother != nullptr)
		{
			descriptionChild += "\nMOTHER" + string(this->GetMother()->GetDescription());
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

	Child* Child::GetRandomChild()
	{
		const char* femaleChildNames[] =
		{
			"Arseniya", "Lidiya", "Anya", "Mariya",
			"Elena", "Louisa", "Sabina", "Viktoriya"
		};
		const char* femaleChildSurnames[] =
		{
			"Morozova", "Makarova", "Semenova", "Pakhomova",
			"Grigoryeva", "Avdeeva", "Guryeva", "Vikander"
		};
		const char* maleChildNames[] =
		{
			"Vladimir", "Vyacheslav", "Aleksey", "Aleksandr",
			"Svyatoslav" ,"Vsevolod", "Maksim" ,"Leonid","Kek"
		};
		const char* maleChildSurnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		const char* childSchools[] =
		{
			"№5 school-lyceum", "№66 school", "№2 school for gifted children "
		};
		const int initialsRand = 8;
		const int ageRand = 90;
		const int schoolsRand = 3;
		//TODO: Вынести магические числа в константы
		//исправил (Вроде)
		int name = rand() % initialsRand;
		int surname = rand() % initialsRand;
		int tempAge = rand() % ageRand;
		Person* tempMother;
		Person* tempFather;
		char tempChildSchools[Person::arraySize];
		char tempName[Person::arraySize];
		char tempSurname[Person::arraySize];
		enum Sex tempSex = enum Sex(rand() % 2);
		if (rand() % 2)
		{
			tempMother = PersonTools::MakeRandomPerson((enum Sex)0);
		}
		else
		{
			tempMother = nullptr;
		}
		if (rand() % 2)
		{
			tempFather = PersonTools::MakeRandomPerson((enum Sex)1);
		}
		else
		{
			tempFather = nullptr;
		}
		
		if (tempSex == 0)
		{
			strcpy_s(tempName, femaleChildNames[rand() % initialsRand]);
			strcpy_s(tempSurname, femaleChildSurnames[rand() % initialsRand]);
		}
		else
		{
			strcpy_s(tempName, maleChildNames[rand() % initialsRand]);
			strcpy_s(tempSurname, maleChildSurnames[rand() % initialsRand]);
		}
		return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather, tempChildSchools);
	}

}
