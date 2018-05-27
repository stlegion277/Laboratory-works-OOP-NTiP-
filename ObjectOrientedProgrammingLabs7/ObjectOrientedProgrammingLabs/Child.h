#pragma once
#include "Sex.h"
#include "Adult.h"

namespace Lab6
{
	class Child : public PersonBase
	{
	public:
		~Child();
		Child(char name[PersonBase::arraySize], char surname[PersonBase::arraySize], unsigned int age,
			enum Sex sex, PersonBase* mother, PersonBase* father, char school[PersonBase::arraySize]);
		void SetMother(PersonBase* mother);
		void SetFather(PersonBase* father);
		void SetAge(unsigned int age);
		void SetSchool(char* school);

		virtual string GetDescription()override;
		char* GetSchool();
		PersonBase* GetMother();
		PersonBase* GetFather();
		
	private:
		char _school[PersonBase::arraySize];
		PersonBase* _mother;
		PersonBase* _father;
		// Унаследовано через Person
		virtual unsigned int GetAge() override;
	};
}
