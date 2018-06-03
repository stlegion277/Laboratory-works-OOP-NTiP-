#pragma once
#include "CheckSymbol.h"
#include "DoubleLinkedListLab4.h"
using namespace std;

namespace Lab4
{
	Person MakeRandomPerson()
	{
		string names[] =
		{
			"Mark", "Ben", "Bob", "Kurt", "Stewart" ,"John", "Frank" ,"Bryan","Kek"
		};
		string surnames[] =
		{
			"Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		int name = rand() % 8;
		int surname = rand() % 8;
		Person newPerson;
		newPerson.Name = names[name];
		newPerson.Surname = surnames[surname];
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
		tempList->data = MakeRandomPerson();
		if (list->head != NULL)
		{
			list->head->prev = tempList;
			tempList->next = list->head;
			tempList->prev = NULL;
		}
		if (list->head == NULL)
		{
			list->head = list->tail = tempList;
		}
	}

	void AddInEnd(List* list)
	{
		Node *tempList = new Node;
		tempList->data = MakeRandomPerson();
		if (list->head == NULL)
		{
			list->head = list->tail = tempList;
		}
		else
		{
			tempList->prev = list->tail;
			list->tail->next = tempList;
			list->tail = tempList;
		}
	}

	void Show(List* list, Node* node)
	{
		Node *tempList = list->tail;
		tempList = list->head;
		if (list->head == NULL && list->tail == NULL)
		{
			cout << "List is empty!\n";
			return;
		}
		while (tempList != NULL)
		{
			cout << "Name = " << tempList->data.Name << "\n";
			cout << "Surname = " << tempList->data.Surname << "\n";
			switch (tempList->data.Sex)
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
			tempList = tempList->next;
		}
	}

	Node* GetIndex(int index, List* list)
	{
		Node* tempList = list->head;
		if (list->head == NULL)
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
			tempList = tempList->next;
		}
		cout << "Index = " << index;

	}

	void Remove(int index, List*& list)
	{
		Node* tempList = list->head;
		if ((list->head == NULL) || (list->tail == NULL))
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
			tempList = tempList->next;
		}
		if (tempList == list->head)
		{
			list->head = list->head->next;
			list->head->prev = NULL;
			delete tempList;
			return;
		}
		if (tempList == list->tail)
		{
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			delete tempList;
			return;
		}
		if (tempList != NULL)//TODO: Дублирование //исправил (заменил код)
		{
			tempList->prev->next = tempList->next;
			tempList->next->prev = tempList->prev;
			delete tempList;
		}

	}

	void Insert(int index, List* list, Person & person)
	{
		if ((index == 0) && (list->head == NULL))
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
		newNode->data = person;
		int tempPosition = 0;
		tempCurrent = list->head;
		if (list->head != NULL)
		{
			while ((tempCurrent->next != NULL) && (tempPosition != index))
			{
				tempPrev = tempCurrent;
				tempCurrent = tempCurrent->next;
				tempPosition++;
			}
			if (index == 0)
			{
				cout << "Adding at head " << endl;
				AddHead(list);
			}
			else if (tempCurrent->next == NULL && index == tempPosition + 1)
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
				tempPrev->next = newNode;
				newNode->next = tempCurrent;
				cout << "Element added at position: " << index << endl;
			}
		}
	}

	void Clear(List* list)
	{
		Node* tempList = new Node;
		while (tempList != NULL)
		{
			Node* tempNextList = tempList->next;
			delete tempList;
			tempList = tempNextList;
		}
		list->head = NULL;
		list->tail = NULL;
		list->head = list->tail;
	}
}