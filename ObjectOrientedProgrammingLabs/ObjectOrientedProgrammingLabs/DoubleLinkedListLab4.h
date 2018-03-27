#pragma once
#include "CheckSymbol.h"
#include "Node.h"
#include "PersonLab4.h"
#include "List.h"
#include "Sex.h"
namespace Lab4
{ 
void AddHead(List* list);
void AddInEnd(List* list);
void Show(List* list);
Node* Get(int index, List* list);
void Remove(int index, List* list, Node* node);
void Insert( int index, List* list, Person & person);
void AddHead(List* list);
void Clear(List* list);
Person MakeRandomPerson();
int Lab4();
}