#pragma once
#include "DoubleLinkedListLab4.h"
#include "CheckSymbol.h"
using namespace std;
namespace Lab4
{
	Person MakeRandomPerson()
	{
		string names[] = {
			"Mark", "Ben", "Bob", "Kurt", "Stewart" ,"John", "Frank" ,"Bryan","Kek"
		};
		string surnames[] = { "Rothwell", "Jenson", "White", "Shraider",
			"Cranston", "Gray", "Zimmer", "Clinton", "Cheburek"
		};
		int name = rand() % 8;
		int surname = rand() % 8;
		Person newPerson;
		newPerson.Name = names[name];
		newPerson.Surname = surnames[surname];
		newPerson.Sex = Male;
		return newPerson;
	}//TODO: Тут и ниже пустые строки после методов
	void PrintPerson(Person& newPerson)
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
	void AddInEnd(List* list)//TODO: Форматирование не по RSDN тут и ниже
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
	void Show(List* list)
{
	Node *tempList = list->tail;
	tempList = list->head;
	if (list->head == NULL)
	{
		cout << "List is empty!";
	}
	while (tempList != NULL)
	{
		cout << "Name = " << tempList->data.Name << "\n";
		cout << "Surname = " << tempList->data.Surname << "\n";
		switch (tempList->data.Sex)
		{
			case 0:
				cout << "Sex = Female \n";
				cout << "-----------------------------------------------\n"; //TODO: Зачем это здесь (стока ниже)?
				Female;
				break;
			case 1:
				cout << "Sex = Male \n";
				cout << "-----------------------------------------------\n";
				Male;
				break;
		}
		tempList = tempList->next;
	}

}//TODO: Неправильное именование, т.к. гет может быть и по похожему элементу из коллекции
	Node* Get(int index, List* list)
{	
	Node* tempList = list->head;
	if (list->head == NULL)
	{
		cout << "List is empty!" << endl;
		return NULL;
	}
	if (index < 0)
	{
		cout << "Wrong index";
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
}//TODO: Зачем тут нода?
	void Remove(int index, List* list, Node* node)
{
	Node* tempList = list->head;
	if ((list->head == NULL) || (list->tail == NULL))
	{
		cout << "List is empty! " << endl;
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
		list->head->next = list->head;
		list->head->prev = NULL;
		delete tempList;
	}
	else if (list->head != NULL)
	{//TODO: Дублируется ниже
		tempList->prev->next = tempList->next;
		tempList->next->prev = tempList->prev;
		delete tempList;
		return;
	}
	if (tempList == list->tail)
	{
		list->tail->prev = list->tail;
		list->tail->next = NULL;
		delete tempList;
	}
	else if (list->tail != NULL)
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
			else if (index > tempPosition + 1)//TODO: Всё что под if-ом в скобочки
				cout << " Position is out of list's limits " << endl;
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
	int Lab4()
{	
	List *list = new List;
	Node* tempList = new Node;
	enum MenuEnum
	{
		Add = 1,
		Show,
		Get,
		Remove,
		Insert,
		Clear
	};
	system("color f1");
	cout << "1. Add in double linked list\n";
	cout << "2. Show double linked list\n";
	cout << "3. Get element by index\n";
	cout << "4. Remove element by index\n";
	cout << "5. Insert element by index\n";
	cout << "6. Clear the list\n";
	cout << "0 Exit\n ";
	//TODO: Именование
	int m;
	int index = 0;
	bool menu = true;
	while (menu == true)
	{
		cout << "Enter number of a function to start\n ";
		m = CheckSymbol();
		switch (m)
		{
			case 0:
				menu = 0;
				break;
			case Add:
			{//TODO: Зачем тут явно прописывать Lab4 - можно же сократить.
				Lab4::AddInEnd(list);
				Lab4::Show(list);
				break;
			}
			case Show:
			{
				Lab4::Show(list);
				break;
			}
			case Get:
			{
				cout << "Enter index of element you want to get" << endl;
				index = CheckSymbol();
				Node* temp = Lab4::Get(index, list);
				cout << &temp;
				break;
			}
			case Remove:
			{
				cout << "Enter an index of element you want to remove " << endl;
				index = CheckSymbol();
				Lab4::Remove(index, list, tempList);
				Lab4::Show(list);
				break;
			}
			case Insert:
			{
				cout << "Enter an element index" << endl;
				index = CheckSymbol();
				Lab4::Insert(index, list, Lab4::MakeRandomPerson());
				Lab4::Show(list);
				break;
			}
			case Clear:
			{
				Lab4::Clear(list);
				cout << "List is empty now!" << endl;
				break;
			}
			default: cout << "Enter number of function to start ";
				break;
			}
		}
	system("pause");
	return 0;
	}
}
