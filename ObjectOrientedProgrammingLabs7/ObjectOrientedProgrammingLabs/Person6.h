#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab6
{
	class PersonBase
	{
		public:
			PersonBase() {};
			~PersonBase();
			static const int arraySize = 255;
			PersonBase(char name[arraySize], char surname[arraySize], unsigned int age, Sex sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(unsigned int age);
			void SetSex(Sex sex);
			bool CheckFirstDigit(char tempname[arraySize]);

			virtual string GetDescription();
			char* GetName();
			char* GetSurname();
			virtual unsigned int  GetAge() = 0;
			Sex GetSex();
			bool operator==(const PersonBase& right);
		protected:
			Sex _sex;
			unsigned int _age;
			char _name[arraySize];
			char _surname[arraySize];
	};
}
