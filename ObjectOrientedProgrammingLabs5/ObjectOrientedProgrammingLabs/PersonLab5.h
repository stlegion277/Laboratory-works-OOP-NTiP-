#pragma once
#include "CheckSymbol.h"
#include "Sex.h"
using namespace std;
namespace Lab5
{
	class Person
	{
		public:
			static const int arraySize = 255;
			//TODO: RSDN!
			//сделал
			Person(char name[arraySize], char surname[arraySize], int age, Sex sex);
			void SetName(char nameTemp[arraySize]);
			void SetSurname(char surnameTemp[arraySize]);
			void SetAge(int age);
			void SetSex(Sex Sex);

			char* GetName();
			char* GetSurname();
			int GetAge();
			Sex GetSex();
			bool operator==(const Person& right);
		private:		
			char _name[arraySize];   
			char _surname[arraySize];  
			int _age;
			Sex _sex;
	};
}
