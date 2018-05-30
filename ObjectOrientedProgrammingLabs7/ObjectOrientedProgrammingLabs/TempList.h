#pragma once
#include "Lab7Menu.h"
using namespace std;

template <class T>
class TempList
{
	private:
		int _count;
		TemplateListItem<T>* _head = nullptr;
		TemplateListItem<T>* _tail = nullptr;
	public:
		void Add(T element)
		{
			TemplateListItem<T>* tempList = new TemplateListItem<T>(element);
			if (_head != nullptr)
			{
				tempList->_prev = _tail;
				_tail->_next = tempList;
				_tail = tempList;
			}
			if (_head == nullptr)
			{
				_head = _tail = tempList;
			}
		}

		void Remove(T element)
		{
			TemplateListItem<T>* tempList = _head;
			while (tempList != nullptr)
			{
				if (tempList->GetValue() == element)
				{
					if (_head == tempList)
					{
						if (tempList->_next == nullptr)
						{
							_head = nullptr;
							_tail = nullptr;
							break;
						}
						_head->_next->_prev = nullptr;
						_head = _head->_next;
						break;
					}

					if (_tail == tempList)
					{
						_tail->_prev->_next = nullptr;
						_tail = _tail->_prev;
						break;
					}

					if (_head != tempList && _tail != tempList)
					{
						tempList->_prev->_next = tempList->_next;
						tempList->_next->_prev = tempList->_prev;
						break;
					}
				}
				tempList = tempList->_next;
			}
		}

		void RemoveByIndex(int index)
		{
			
			T tempElement = Find(index);
			Remove(tempElement);
		}

		int IndexOf(T element)
		{
			TemplateListItem<T>* tempList = _head;
			int index = 0;
			while (tempList != nullptr)
			{
				if (tempList->GetValue() == element)
				{
					cout << "Index of a person = ";
					cout << index;
				}
				index++;
				tempList = tempList->_next;
			}
			cout << "List doesn't have person with this index";
			return -1;
		}

		void Clear()
		{
			TemplateListItem<T>* tempList = _head;
			while (tempList != nullptr)
			{
				TemplateListItem<T>* tempNextList = tempList->_next;
				delete tempList;
				tempList = tempNextList;
			}
			_head = nullptr;
			_tail = nullptr;
			_head = _tail;
		}

		int GetCount()
		{
			int counter = 0;
			TemplateListItem<T>* tempList = _head;
			while (tempList != nullptr)
			{
				tempList = tempList->_next;
				counter++;
			}
			return counter;
		}

		void Show()
		{
			cout << endl;
			TemplateListItem<T>* tempList = _head;
			int elementCounter = 0;
			while (tempList != nullptr)
			{
				ShowNodeInConsole(tempList);
				tempList = tempList->_next;
				elementCounter++;
				cout << "\nElement = " << elementCounter << endl;
			}
			/*if (_head != nullptr)
			{
			cout << "\nHead element\n";
			cout << "_____________\n";
			ShowNodeInConsole(*_head);
			cout << "\nTail element\n";
			cout << "___________\n";
			ShowNodeInConsole(*_tail);
			}*/
			if (_head == nullptr || _tail == nullptr)
			{
				cout << "Head and Tail elements are NULL! List is empty!" << endl;

			}
		}

		T Find(int index)
		{
			if (index < 0)
			{
				cout << "Wrong index";
				Find(index);
			}
			TemplateListItem<T>* tempList = _head;
			int counter = 0;
			while (counter < index)
			{
				if (tempList == nullptr)
				{
					cout << "Empty List";
				}
				tempList = tempList->_next;
				counter++;
			}
			return tempList->_value;
		}

		void ShowNodeInConsole(TemplateListItem<T>* list)
		{
			cout << list->_value;
		}

		TempList::~TempList()
		{
			Clear();
		}

		friend std::ostream& operator<<(std::ostream& os, TempList* list)
		{
			TemplateListItem<T>* tempList = list->_head;
			int i = 0;
			cout << "SubList : ";
			while (tempList != nullptr)
			{
				cout << tempList->GetValue() << "  ";
				tempList = tempList->_next;
			}
			return os;
		}		
};

	static std::ostream& operator << (std::ostream &os, Lab6::Adult* person)
	{
		os << person->GetDescription();
		return os;
	}

	static std::ostream& operator << (std::ostream & os, double* d)
	{
		os << d[0];
		return os;
	}