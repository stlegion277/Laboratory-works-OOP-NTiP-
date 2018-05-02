#pragma once
#include "Person.h"
#include "DoubleLinkedListLab4.h"
namespace Lab4
{
	struct Node
	{//TODO: Именование не по RSDN //тут тоже вроде все правильно или Node с маленькой?
		//TODO: Как именуются поля структуры?
		// с большой я понял) сделал
		Person Data;	
		Node* Next = NULL; 
		Node* Prev = NULL; 
	};
}
