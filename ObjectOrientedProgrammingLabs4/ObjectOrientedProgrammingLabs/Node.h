#pragma once
#include "Person.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: »менование не по RSDN //тут тоже вроде все правильно или Node с маленькой?
		//TODO:  ак именуютс€ пол€ структуры?
		Person data;	
		Node* next = NULL; 
		Node* prev = NULL; 
	};
}
