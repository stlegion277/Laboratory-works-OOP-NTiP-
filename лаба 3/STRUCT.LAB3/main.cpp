#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "stack.h"
#include "queue2.h"
#include "queue.h"
using namespace std;

int main()
{

	setlocale(0, "");


	char key;
	int value;
	int AssciiValue = 0;
	while (AssciiValue != 27) 
	{

		system("cls");

		cout << "1: Стек " << endl;
		cout << "2: Очередь на базе двух стеков " << endl;
		cout << "3: Кольцевая очередь " << endl;

		cout << endl << "Нажмите\n";
		key = _getch();
		AssciiValue = key;
		switch (AssciiValue)
		{
		case '1':					//информация о стеке
		{
			int AssciiValue1 = 0;
			Stack* stack = CreateStack();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: Информация о стеке " << endl;
				cout << "2: Добавление элемента " << endl;
				cout << "3: Удаление элемента " << endl;

				cout << endl << "Нажмите\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << "Стек: ";
					for (int i = 0; i < stack->length; i++) {
						cout << stack->array[i] << " ";
					}
					cout << endl;
					cout << "Длина Стека: " << stack->length << endl;
					cout << "Длина буфера: " << stack->bufsize << endl;
					system("pause");
					break;

				case '2':

					cout << "Введите добавляемый элемент ";
					cin >> value;
					PushStack(stack, value);
					break;
				case '3':
					if (stack->length > 0)
					{
						int data = PopStack(stack);
						cout << "Полученный элемент = " << data;
						system("pause");
					}
					else
					{
						cout << "Стек пуст" << endl;
						system("pause");
					}
					break;
				}
			}

			DelStack(stack);
			break;
		}
		case '2':					//два стека
		{
			int AssciiValue1 = 0;
			Queue2* queue = CreateQueue2();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: Очередь на базе двух стеков " << endl;
				cout << "2: Добавление в очередь " << endl;
				cout << "3: Извлечение элемента из очереди " << endl;

				cout << endl << "Нажмите\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << "Первый стек \n ";
					for (int i = 0; i < queue->left->length; i++) {
						cout << queue->left->array[i] << " ";
					}
					cout << endl;

					cout << "Второй стек \n ";
					for (int i = 0; i < queue->right->length; i++) {
						cout << queue->right->array[i]<< " ";
					}
					cout << endl;

					system("pause");
					break;

				case '2':

					cout << "Введите добавляемый элемент ";
					cin >> value;
					Enqueue2(queue, value);
					break;


				case '3':
					if (queue->left->length || queue->right->length)
					{
						
						cout << "Полученный элемент = " << Dequeue2(queue) << endl;
						system("pause");
					}
					else
					{
						cout << "Очередь пуста" << endl;
						system("pause");
					}
					break;
				}
			}

			DeleteQueue2(queue);
			break;
		}
		case'3':
		{
			int AssciiValue1 = 0;
			Queue* queue = CreateQueue();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "1: Очередь на базе зацикленного буфера:\n" << endl;
				cout << "2: Добавление в очередь " << endl;
				cout << "3: Извлечение элемента из очереди " << endl;

				cout << endl << "Нажмите\n";
				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					for (int i = 0; i < queue->length; i++) 
					{
						cout << (i + queue->head) % queue->bufsize << " ";
						cout << queue->array[(i + queue->head) % queue->bufsize] << endl;
					}

					cout << "Длина очереди: " << queue->length << endl;
					cout << "размер буфера: " << queue->bufsize << endl;

					cout << "Голова: " << queue->head % queue->bufsize<<endl;
					cout << "хвост " << queue->tail % queue->bufsize << endl;
					

					system("pause");
					break;

				case '2':

					cout << "Введите добавляемый элемент ";
					cin >> value;
					Enqueue(queue, value);
					break;


				case '3':
					if (queue->length)
					{

						cout << "Полученный элемент = " << Dequeue(queue) << endl;
						system("pause");
					}
					else
					{
						cout << "Очередь пуста" << endl;
						system("pause");
					}
					break;
				}
			}

			DeleteQueue(queue);
			break;
		}					//кольцевой буфер
		}
		
	}
}