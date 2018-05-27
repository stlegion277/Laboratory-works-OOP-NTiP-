#pragma once
#include "TemplateListItem.h"
#include "PersonLab5.h"
using namespace std;

template <class Type T>
class TempList
{
	private:
		int _count;
		TemplateListItem* _head = nullptr;
		TemplateListItem* _tail = nullptr;
	public:
		void Add(Type T element)
		{
			TemplateListItem<Type T>* tempList = new templateListItem(element);
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

		void Remove(Type T element)
		{
			TemplateListItem<Type T>* tempList = _head;
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
			Type T* person = Find(index);
			Remove(element);
		}

		int IndexOf(Type T element)
		{
			TemplateListItem<Type T>* tempList = _head;
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
			TemplateListItem<Type T>* tempList = _head;
			while (tempList != nullptr)
			{
				TemplateListItem<Type T>* tempNextList = tempList->_next;
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
			TemplateListItem<Type T>* tempList = _head;
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
			TemplatelistItem* tempList = _head;
			int elementCounter = 0;
			while (tempList != nullptr)
			{
				ShowNodeInConsole(*tempList);
				tempList = tempList->Next;
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

		Person* Find(int index)
		{
			if (index < 0)
			{
				return nullptr;
			}
			TemplateListItem<Type T>* tempList = _head;
			int counter = 0;
			while (counter < index)
			{
				if (tempList == nullptr)
				{
					return nullptr;
				}
				tempList = tempList->_next;
				counter++;
			}
			return tempList->GetValue();
		}

		void ShowNodeInConsole(TemplateListItem list)
		{
			cout << list.GetValue()->GetDescription();
		}

		TempLateList()
		{

		}

		~TemplateList()
		{
			Clear();
		}
};