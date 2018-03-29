#pragma once
#include "CheckSymbol.h"
#include "Node.h"
#include "PersonLab4.h"
#include "List.h"
#include "Sex.h"

using namespace std;
using namespace Lab4;

namespace Lab4
{
	void AddHead(List* list);
	void AddInEnd(List* list);
	void Show(List* list, Node* node);
	Node* GetIndex(int index, List* list);
	void Remove(int index, List* list);
	void Insert(int index, List* list, Person& person);
	void AddHead(List* list);
	void Clear(List* list);
	Person MakeRandomPerson();
	int Lab4();
}