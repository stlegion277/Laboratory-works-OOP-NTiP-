#pragma once
#include "CheckSymbol.h"
#include "DoubleLinkedListLab4.h"
using namespace std;

namespace Lab4
{
	Person MakeRandomPerson()
	{
		const char* names[] =
		{
			"Mark", "Ben", "Bob", "Kurt", "Stewart" ,"John", "Frank" ,"Bryan","Kek"
		};
		const char* surnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		int name = rand() % 8;
		int surname = rand() % 8;
		Person newPerson;
		strcpy_s(newPerson.Name,names[name]);
		strcpy_s(newPerson.Surname, surnames[surname]);
		newPerson.Sex = Male;
		return newPerson;
	}

	void PrintPerson(const Person &newPerson)
	{
		system("color 01");
		cout << "Name " << newPerson.Name;
		cout << " Surname" << newPerson.Surname;
		cout << "Sex" << newPerson.Sex;
	}

	void AddHead(List* list)
	{
		Node* tempList = new Node;
		tempList->Data = MakeRandomPerson();
		if (list->Head != NULL)
		{
			list->Head->Prev = tempList;
			tempList->Next = list->Head;
			tempList->Prev = NULL;
		}
		if (list->Head == NULL)
		{
			list->Head = list->Tail = tempList;
		}
	}

	void AddInEnd(List* list)
	{
		Node *tempList = new Node;
		tempList->Data = MakeRandomPerson();
		if (list->Head == NULL)
		{
			list->Head = list->Tail = tempList;
		}
		else
		{
			tempList->Prev = list->Tail;
			list->Tail->Next = tempList;
			list->Tail = tempList;
		}
	}

	void Show(List* list, Node* node)
	{
		Node *tempList = list->Tail;
		tempList = list->Head;
		if (list->Head == NULL && list->Tail == NULL)
		{
			cout << "List is empty!\n";
			return;
		}
		while (tempList != NULL)
		{
			cout << "Name = " << tempList->Data.Name << "\n";
			cout << "Surname = " << tempList->Data.Surname << "\n";
			switch (tempList->Data.Sex)
			{
			case Female:
				cout << "Sex = Female \n";
				cout << "-----------------------------------------------\n";
				break;
			case Male:
				cout << "Sex = Male \n";
				cout << "-----------------------------------------------\n";
				break;
			}
			tempList = tempList->Next;
		}
	}

	Node* GetIndex(int index, List* list)
	{
		Node* tempList = list->Head;
		if (list->Head == NULL)
		{
			cout << "List is empty!\n" << endl;
			return NULL;
		}
		if (index < 0)
		{
			cout << "Wrong index\n";
			return NULL;
		}
		for (int i = 0; i <= index; i++)
		{
			if (i == index)
			{
				return tempList;
			}
			tempList = tempList->Next;
		}
		cout << "Index = " << index;

	}

	void Remove(int index, List*& list)
	{
		Node* tempList = list->Head;
		if ((list->Head == NULL) || (list->Tail == NULL))
		{
			cout << "List is empty! \n" << endl;
			return;
		}
		if (index < 0)
		{
			return;
		}
		for (int i = 0; i < index; i++)
		{
			tempList = tempList->Next;
		}
		if (tempList == list->Head)
		{
			list->Head = list->Head->Next;
			list->Head->Prev = NULL;
			delete tempList;
			return;
		}
		if (tempList == list->Tail)
		{
			list->Tail = list->Tail->Prev;
			list->Tail->Next = NULL;
			delete tempList;
			return;
		}
		if (tempList != NULL)
		{
			tempList->Prev->Next = tempList->Next;
			tempList->Next->Prev = tempList->Prev;
			delete tempList;
		}

	}

	void Insert(int index, List* list, Person & person)
	{
		if ((index == 0) && (list->Head == NULL))
		{
			AddInEnd(list);
			return;
		}
		if (index < 0)
		{
			cout << "Enter a valid index ! ";
			return;
		}
		Node* tempPrev = new Node();
		Node* tempCurrent = new Node();
		Node* newNode = new Node();
		newNode->Data = person;
		int tempPosition = 0;
		tempCurrent = list->Head;
		if (list->Head != NULL)
		{
			while ((tempCurrent->Next != NULL) && (tempPosition != index))
			{
				tempPrev = tempCurrent;
				tempCurrent = tempCurrent->Next;
				tempPosition++;
			}
			if (index == 0)
			{
				cout << "Adding at head " << endl;
				AddHead(list);
			}
			else if (tempCurrent->Next == NULL && index == tempPosition + 1)
			{
				cout << "Adding at tail " << endl;
				AddInEnd(list);
			}
			else if (index > tempPosition + 1)
			{
				cout << " Position is out of list's limits " << endl;
			}
			else
			{
				tempPrev->Next = newNode;
				newNode->Next = tempCurrent;
				cout << "Element added at position: " << index << endl;
			}
		}
	}

	void Clear(List* list)
	{
		Node* tempList = new Node;
		while (tempList != NULL)
		{
			Node* tempNextList = tempList->Next;
			delete tempList;
			tempList = tempNextList;
		}
		list->Head = NULL;
		list->Tail = NULL;
		list->Head = list->Tail;
	}
}