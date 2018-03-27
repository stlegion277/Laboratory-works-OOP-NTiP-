#pragma once
#include "PersonLab4.h"
#include "DoubleLinkedListLab4.h"
#include "CheckSymbol.h"
namespace Lab4
{
	struct Node
	{
		Person data;	
		Node* next = NULL; 
		Node* prev = NULL; 
	};
}