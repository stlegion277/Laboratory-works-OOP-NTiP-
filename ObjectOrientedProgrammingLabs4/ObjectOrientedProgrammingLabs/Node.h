#pragma once
#include "Person.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{
		Person Data;	
		Node* Next = NULL; 
		Node* Prev = NULL; 
	};
}
