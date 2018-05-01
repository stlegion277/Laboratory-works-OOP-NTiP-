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
		Child() {};
		~Child();
		Child(char name[Person::arraySize], char surname[Person::arraySize], int age,
		enum Sex sex, Person* Mother, Person* Father, char school[Person::arraySize]);
		static Child* GetRandomChild();
	
		void SetMother(Person* Mother);
		void SetFather(Person* Father);
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
