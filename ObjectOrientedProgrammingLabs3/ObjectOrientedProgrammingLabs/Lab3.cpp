#pragma once
#include "Lab3.h"
#include "CheckSymbol.h"
#include "Person.h"
#include "Sex.h"
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
		cout << "Write sex 1 - Male 0 - Female\n";
		int maleFemale;
		cin >> maleFemale;
		
		do
		{
			maleFemale = CheckSymbol();
		} 
		while ((maleFemale < 0) && (maleFemale > 1));
		
		switch (maleFemale)
		{
			case 1:
				newPerson.Sex = Male;
				break;
			case 0:
				newPerson.Sex = Female;
				break;
			default:
				break;
		}
		return newPerson;
	}

	void PrintPerson(Person& person)
	{
		cout << "Sex = \n" << person.Sex ;
		cout << "Name = \n" << person.Name;
		cout << "Surname = \n" << person.Surname;
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
			if (int(*string) > 'a' && int(*string) < 'a')
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
			if (int(*string) > 'A' && int(*string) < 'Z')
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
		int counter = 1;
		int j = 0;
		for (int i = 0; i < GetLength(newString); counter++)
		{
			if (string[i] == '\t')
			{	
				if (counter % 4 != 0)
				{
					newString[counter] = ':';
				}
				else
				{
					newString[counter] = ':';
					i++;
				}
			}
			else
			{
				newString[counter] = string[i];
				i++;
			}
		}
		newString[counter++] = '\0';
		return newString;
	}
	
	char* ReplaceSpacesOnTabs(char* string)
	{
		char* newString = new char[200];
		int counter = 0;
		bool tabulationTrigger = false;
		int twoDotsPointer = 0;
		for (int i = 0; i < GetLength(string); i++)
		{
			if (string[i] == ':')
			{
				twoDotsPointer = i;
				for (;string[twoDotsPointer] == ':'; )
				{
					if ((twoDotsPointer + 1) % 4 == 0)
					{
						tabulationTrigger = true;
						break;
					}
				twoDotsPointer++;
				}
				if (tabulationTrigger)
				{
					i = twoDotsPointer;
					newString[counter] = 'T';
					tabulationTrigger = false;
					counter++;
				}
				else
				{
					newString[counter++] = string[i];
				}
			}
			else
			{
				newString[counter++] = string[i];
			}
		}
		newString[counter++] = '\0';
		return newString;
	}

	void SplitFileName(char* source, char* path, char* name, char* extension)
	{
		int dotPointerExtension = 0;
		int dotPointerFile = 0;
		int slashPointer = 0;
		for (int i = 0; source[i] != '\0'; i++)
		{
			if (source[i] == '.')
			{
				dotPointerExtension = i;
			}
		}
		for (int i = 0; source[i] != '\0'; i++)
		{
			if (source[i] == '\\')
			{
				slashPointer = i;
			}
		}
		for (int i = 0; source[i] != '\0'; i++)
		{
			if (source[i] == '.')
			{
				dotPointerFile = i;
				break;
			}
		}
		int j = 0;
		for (int i = dotPointerExtension; i < GetLength(source); i++, j++) 
		{
			extension[j] = source[i];
		}
		extension[j++] = '\0';
		j = 0;
		for (int i = slashPointer + 1; i < dotPointerFile; i++, j++)
		{
			name[j] = source[i];
		}
		name[j++] = '\0';
		j = 0;
		for (int i = 0; i < slashPointer; i++, j++)
		{
			path[j] = source[i];

		}
		path[j++] = '\0';
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
		
		int menuNumber;
		bool menu = true;
		while (menu == true)
		{
			menuNumber = CheckSymbol();
			cout << "Enter number of function to start\n ";
			switch (menuNumber)
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
					char source[50] = { "d:\\f old er\\file.txt.cmd" };
					char path[30];
					char extension[5];
					char name[10];
					SplitFileName(source, path, name, extension);
					cout << "source = " << source << endl;
					cout << "path = " << path << endl;
					cout << "extension = " << extension << endl;
					cout << "name = " << name << endl;
					break;
				}
				case ReplaceTabsOnSpacesEnum:
				{
					char* testMassiveReplaceTabsOnSpaces = (char*)" Cake\tis\ta lie!";
					cout << ReplaceTabsOnSpaces(testMassiveReplaceTabsOnSpaces) << endl;
					testMassiveReplaceTabsOnSpaces = (char*)" Cake\t\tis a lie!";
					cout << ReplaceTabsOnSpaces(testMassiveReplaceTabsOnSpaces) << endl;
					testMassiveReplaceTabsOnSpaces = (char*)" \tCake is \tlie!";
					cout << ReplaceTabsOnSpaces(testMassiveReplaceTabsOnSpaces) << endl;
					break;
				}
				case ReplaceSpacesOnTabsEnum:
				{
					char* testMassiveReplaceSpacesOnTabs = (char*)"Cake::::is::a:lie!";
					cout << ReplaceSpacesOnTabs(testMassiveReplaceSpacesOnTabs) << endl;
					testMassiveReplaceSpacesOnTabs = (char*)"Cake::::is::::a:lie!";
					cout << ReplaceSpacesOnTabs(testMassiveReplaceSpacesOnTabs) << endl;
					testMassiveReplaceSpacesOnTabs = (char*)"Cake:is:a:::::::lie!";
					cout << ReplaceSpacesOnTabs(testMassiveReplaceSpacesOnTabs) << endl;
					testMassiveReplaceSpacesOnTabs = (char*)"Cake:is::a:lie!";
					cout << ReplaceSpacesOnTabs(testMassiveReplaceSpacesOnTabs) << endl;
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
	

