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
			Person(char Name[arraySize], char Surname[arraySize], int Age, Sex Sex);
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
			//TODO: ���������� �� �� RSDN!
			char Name[arraySize];
			char Surname[arraySize];
			int Age;
			Sex Sex;
	};
}
