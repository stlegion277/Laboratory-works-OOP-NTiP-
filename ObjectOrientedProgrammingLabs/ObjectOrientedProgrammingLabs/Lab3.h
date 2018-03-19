#pragma once
using namespace std;

namespace Lab3
{	enum Sex { Male, Female };
	struct Person {
		char Surname[40];
		char Name[20];
		Sex Sex;
	};
	int GetLength(char * string);
	char *Concatenate(char* string1, char* string2);
	char* GetSubString(char* string, int startIndex, int charCount);
	int FindSubString(char* string, char* substring);
	char* UpperCase(char* string);
	char* LowerCase(char* string);
	char* ReplaceTabsOnSpaces(char* string);
	char* ReplaceSpacesOnTabs(char* string);
	void SplitFileName(char* source, char* path, char* name, char* extension);
	void PrintPerson(Person person);
	Person InputPerson();
	int Lab3();
}

