#pragma once
#include "Lab3.h"
#include "CheckSymbol.h"
using namespace std;
namespace Lab3
{
	int GetLength(char * string)
	{
		int length = 0;
		while (string[length] != '\0')
		{
			length++;
		}
		return length;
	}
	Lab3::Person InputPerson()
	{
		Person newPerson;
		cout << "Write name\n ";
		cin >> newPerson.Name;
		cout << "Write surname ";
		cin >> newPerson.Surname;
		cout << "Write sex 0 - Male 1 - Female\n";
		int maleFemale;
		cin >> maleFemale;
		if (maleFemale == 0 && maleFemale == 1)
		{
			switch (maleFemale)
			{
			case 1:
				cout << "MALE "; 
				break;
			case 2:
				cout << "FEMALE";
				break;
			default:
				break;
			}
		}
		return newPerson;
	}
	void PrintPerson(Person person)
	{
		cout << "Sex = " <<person.Sex ;
		cout << "Name = " << person.Name;
		cout << "Surname = " << person.Surname;
	}
	char* Concatenate(char* string1, char* string2)
	{
		char *newChar = new char[200];
		int counter = 0;
		for (int i = 0; i < GetLength(string1) + 1; i++)
		{
			counter++;
			newChar[i] = string1[i];
		}
		for (int i = 0; i < GetLength(string2) + 1; i++)
		{
			counter++;
			newChar[counter] = string2[i];
		}
		newChar[counter] = '\0';
		return newChar;
	}
	char* GetSubString(char* string, int startIndex, int charCount)
	{
		char* stringMassive = new char[123];
		if (startIndex < 0 || charCount + startIndex > GetLength(string))
		{
			return NULL;
		}
		else
		{
			int counter = 0;
			for (int i = startIndex; i < charCount + startIndex; i++)
			{
				stringMassive[counter] = string[i];
				counter++;
			}
			stringMassive[counter] = '\0';
			return stringMassive;
		}
	}
	int	FindSubString(char* string, char* substring)
	{
		int counter = 0;
		if (GetLength(string) < GetLength(substring))
		{
			cout << "Wrong parameters";
		}
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == substring[0])
			{
				counter = i++;
				bool subStringKey = true;
				for (int i = 0; i < GetLength(substring); i++)
				{
					if (counter > GetLength(string))
					{
						cout << "Wrong parameters ";
					}
					if (string[counter] != substring[i])
					{
						subStringKey = false;
					}
					counter++;
				}
				if (subStringKey = true)
				{
					return i - 1;
				}
			}
		}
		if (counter == 0)
		{
			return -1;
		}
	}
	char* UpperCase(char* string)
	{
		char* stringMassive = string;
		while (*string != '\0')
		{
			if (int(*string) >= 97 && int(*string) <= 122)
			{
				*string = char(*string - 32);
			}
			else
			{
				return stringMassive;
			}
		}
		return string;
	}
	char* LowerCase(char* string)
	{
		char* stringMassive = string;
		while (*string != '\0')
		{
			if (int(*string) <= 90 && int(*string) >= 65)
			{
				*string = char(*string + 32);
			}
			else
			{
				return stringMassive;
			}
		}
		return string;
	}
	char* ReplaceTabsOnSpaces(char* string)
	{
		char* newString = new char[90];
		int index = 0;
		int counter = 0;
		int tabulationPointer = 0;
		for (int i = 0; i < GetLength(newString); i++)
		{
			tabulationPointer++;
			if (string[i] == '\t')
			{	
				for (int i = tabulationPointer; i < tabulationPointer + 4; i++)
				{
					newString[counter++] = ':';
				}	
			}
			else
			{
				newString[counter] = string[i];
				counter++;
			}
		}
		newString[counter] = '\0';
		return newString;
	}
	char* ReplaceSpacesOnTabs(char* string)
	{
		char* newString = new char[200];
		int counter = 0;
		int j = 0;
		int k = 0;
		int twoDotsPointer = 0;
		for (int i = 0; i < GetLength(string); i++)
		{
			twoDotsPointer = i;
			if (string[twoDotsPointer] == ':')
			{
				for (int i = twoDotsPointer; i < twoDotsPointer + 1  ; i++)
				{
					if (j != 0 )
					{
						break;
					}
					newString[counter++] = '\t';
					j++;
				}
			}
			else
			{
				newString[counter] = string[i];
				counter++;
			}
		}
		newString[counter] = '\0';
		return newString;
	}
	void SplitFileName(char* source, char* path, char* name, char* extension)
	{
		int dotPointer;
		int slashPointer;
		int endOfStringPointer;
		for (int i = GetLength(source - 1); i >= 0; i--)
		{
			if (source[i] == '.')
			{
				dotPointer = i;
			}
			if (source[i] == '\0')
			{
				endOfStringPointer = i;
			}
		}
		for (int i = 0; source[i] != '\0'; i++)
		{
			if (source[i] == '\\')
			{
				slashPointer = i + 1;
			}
		}
		for (int j = endOfStringPointer; j >= dotPointer; j--)
		{
			extension[j] = source[j];
		}
		int j = 0;
		for (int j = dotPointer; j >= slashPointer; j--)
		{
			name[j] = source[j];
		}
		j = 0;
		for (int j = slashPointer; j < source[0]; j--)
		{
			path[j] = source[j];
		}
	}
	int Lab3()
	{
		enum MenuEnum
		{
			GetLengthEnum = 1,
			ConcatenateEnum,
			GetSubstringEnum,
			FindSubstringEnum,
			UppercaseEnum,
			LowercaseEnum,
			SplitFileNameEnum,
			ReplaceTabsOnSpacesEnum,
			ReplaceSpacesOnTabsEnum,
			PersonStructEnum
		};
		cout << "1. Get length\n";
		cout << "2. Concatenate\n";
		cout << "3. Get substring\n";
		cout << "4. Find substring\n";
		cout << "5. Upper case\n";
		cout << "6. Lower case\n";
		cout << "7. Split filename\n";
		cout << "8. Replace tabs on spaces\n";
		cout << "9. Replace spaces on tabs\n";
		cout << "10. Work with person structure\n";
		cout << "0 Exit\n ";
		cout << "Enter number of function to start\n ";
		int m;
		bool menu = true;
		while (menu == true)
		{
			m = CheckSymbol();
			cout << "Enter number of function to start\n ";
			switch (m)
			{
				case 0:
					menu = 0;
					break;
				case GetLengthEnum:
				{
					char* testMassiveLength = (char*)"LOLKEK";
					GetLength(testMassiveLength);
					break;
			    }
				case ConcatenateEnum:
				{
					char* testMassiveConcatenate = Concatenate(new char[20]{ 'K','E','K','\0' }, 
					new char[20]{ 'L','O','L','\0' });
					for (int i = 0; i < 20; i++)
					{
						cout << testMassiveConcatenate[i];
					}
					cout << endl;
					break;
				}
				case GetSubstringEnum:
				{
					char *testMassiveSubString = (char*)"Hello World!";
					char *anotherTestMassiveSubString = GetSubString(testMassiveSubString, 2, 4);
					for (int i = 0; i < GetLength(testMassiveSubString); i++)
					{
						cout << anotherTestMassiveSubString[i];
					}
					break;
				}
				case FindSubstringEnum:
				{
					char *testMassiveString = (char*)"Lorem ipsum aset amet";
					char *testMassiveSubString = (char*) "Arom";
					cout << " " << FindSubString(testMassiveString, testMassiveSubString);
					break;
				}
				case UppercaseEnum:
				{
					char upperCase[40] = { 'K','E','K','\0' };
					cout << UpperCase(upperCase);
					break;
				}
				case LowercaseEnum:
				{
					char lowerCase[40] = { 'l','o','l','\0' };
					cout << LowerCase(lowerCase) << endl;
					break;
				}
				case SplitFileNameEnum:
				{
					char source[50] = { "d:\\folder\\file.exe" };
					char path[30];
					char extension[5];
					char name[10];
					SplitFileName(source,path,name,extension);
					cout << "source" << source << endl;
					cout << "path" << path << endl;
					cout << "extension = " << extension << endl;
					cout << "name = " << name << endl;
					break;
				}
				case ReplaceTabsOnSpacesEnum:
				{
					char* testMassiveReplaceTabsOnSpaces = (char*)"Cake\t\tis a lie!";
					cout << ReplaceTabsOnSpaces(testMassiveReplaceTabsOnSpaces);
					break;
				}
				case ReplaceSpacesOnTabsEnum:
				{
					char* testMassiveReplaceSpacesOnTabs = (char*)"Cake::::is::a:lie";
					cout << ReplaceSpacesOnTabs(testMassiveReplaceSpacesOnTabs);
					break;
				}
				case PersonStructEnum:
				{
					cout << "Person structure\n  ";
					Person Data = InputPerson();
					PrintPerson(Data);
					break;
				}
				default: 
					cout << "Enter number of function to start ";
					break;
					}
				}
		system("pause");
		return 0;
	}
}
	

