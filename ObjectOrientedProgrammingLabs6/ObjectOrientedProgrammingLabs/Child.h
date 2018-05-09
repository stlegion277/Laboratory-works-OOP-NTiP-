#pragma once
#include "Person6.h"
#include "Sex.h"
#include "PersonTools6.h"
#include "Adult.h"

namespace Lab6
{
	class Child : public Person
	{
	public:
		~Child();
		Child(char name[Person::arraySize], char surname[Person::arraySize], int age,
			enum Sex sex, Person* mother, Person* father, char school[Person::arraySize]);
		static Child* GetRandomChild();
	
		void SetMother(Person* mother);
		void SetFather(Person* father);
		void SetAge(int age);
		void SetSchool(char* school);

		virtual string GetDescription()override;
		char* GetSchool();
		Person* GetMother();
		Person* GetFather();
		
	private:
		char _school[Person::arraySize];
		Person * _mother = nullptr;
		Person* _father = nullptr;
	};
}
