#pragma once
#include "Sex.h"
#include "Adult.h"

namespace Lab6
{
	class Child : public Person
	{
	public:
		~Child();
		Child(char name[Person::arraySize], char surname[Person::arraySize], unsigned int age,
			enum Sex sex, Person* mother, Person* father, char school[Person::arraySize]);
		void SetMother(Person* mother);
		void SetFather(Person* father);
		void SetAge(unsigned int age);
		void SetSchool(char* school);

		virtual string GetDescription()override;
		char* GetSchool();
		Person* GetMother();
		Person* GetFather();
		
	private:
		char _school[Person::arraySize];
		Person * _mother;
		Person* _father;
		// Унаследовано через Person
		virtual int GetAge() override;
	};
}
