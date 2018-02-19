// ConsoleApplication14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;



void helloWorld()
{
	printf("Hello, World!\n");

}


void numbersSumm()
{
	int a; // Объявление целочисленной переменной
	a = 5; // Инициализация переменной значением
	int b = 3; // Допустимо одновременное объявление и инициализация
	printf("\n Variable a equals %d", a); // Вывод значения переменной на экран
	printf("\n Variable b equals %d", b); // Значение переменной подставится вместо %d
	printf("\n Summ of a and b equals %d\n", a + b); // Можно выводить сразу

}

void numbersDivision()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	printf("Float variables division: %f \n", z / y);
	printf("Integer variables division: %d \n", a / b);

}


void readingInput()
{
	int a;
	int b;
	// Вывод текстового сообщения, поясняющего назначение программы
	// является правилом хорошего тона и помогает пользователю
	// разобраться в вашей программе
	printf("---Program for integer summation---");
	// Всегда поясняйте пользователю, какие данные ему нужно ввести
	printf("\n\n Enter first integer value: ");
	scanf_s("%d", &a); // Чтение значения переменной с клавиатуры
	printf(" Enter second integer value: ");
	scanf_s("%d", &b);
	printf(" \n Summ of %d and %d equals %d \n", a, b, a + b);

}


void pointerExample()
{
	int value;
	int* pointer; // Объявление указателя на целочисленный тип данных
	int anotherValue;
	value = 5;
	pointer = &value; // Операция взятия адреса переменной
					  // pointer может хранить адрес только
					  // целочисленной переменной
	anotherValue = *pointer; // Операция разыменования
							 // Вывод значения, полученного при разыменовании указателя
	printf("Value, stored in pointer: %d \n", anotherValue);
	// Вывод адреса, который хранится в указателе
	printf("Address in pointer: %p \n", pointer);
	// Вывод результата разыменования указателя
	printf("Value in pointer: %d \n", *pointer);


}


int exampleIf()
{
	int a;
	printf("Enter value for check on even/odd: ");
	scanf_s("%d", &a);
	if (a % 2 == 0)
	{
		printf("\n Value %d is even! \n", a);
	}
	else
	{
		printf("\n Value %d is odd! \n", a);
	}

	return 0;
}

void exampleElseIf()
{
	int a;
	printf("Enter value for check on even/odd: ");
	scanf_s("%d", &a);
	if (a % 5 == 0)
	{
		printf("\n Value %d multiples 5! \n", a);
	}
	else if (a % 2 == 0)
	{
		printf("\n Value %d multiples 2! \n", a);
	}
	else
	{
		printf("\n Value %d doesn`t multiply 5 or 2! \n", a);
	}
}


void predfixCycle()
{
	int a = 0;
	while (a < 5) // условный цикл с пред-условием
	{
		printf("Value is %d now \n", a);
		a++;
	}
}

void postfixCycle()
{
	int a = 0;
	do // условный цикл с пост-условием
	{
		printf("Value is %d now \n", a);
		a++;
	} while (a < 5);

}

void iterativeCycle()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		printf("Iteration #%d \n", i);
	}
	printf("\n\n");
	for (int i = 0; i < a; i++)
	{
		a--;
		printf("Iteration #%d Value is %d \n", i, a);
	}
}

void convertingTypes()
{
	int a = 5;
	int b = 3;
	float z;
	// Неявное приведение типов
	z = a;
	printf("Value of z is %f \n", z);
	// Ошибка - невозможное приведение типов!
	a = z;
	// Явное приведение типов
	a = (int)z;
	printf("Value of a is %d \n", a);
	// Неявное приведение результата деления
	// целочисленных переменных
	z = a / b;
	printf("Value of z is %f \n", z);
	// Явное приведение а к float и неявное b к float
	// для выполнения деления
	z = ((float)a) / b;
	printf("Value of z is %f \n", z);

}

void breakExample()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			printf("I is more or equal A! Break of cycle");
			break; // этот оператор досрочно завершает цикл
		}
	}
	printf("\n A is %d \n", a);

}


int CheckSymbol()
{
	string n;
	int m;
	do {
		cin >> n;
		m = atoi(n.c_str());
	} while (m == 0 && m < 0);
	return m;
}



int main()
{
	int m;
	bool menu = 1;
	int default = 10000;

	cout << endl << "1. First task" << endl
		<< "2. Second task" << endl
		<< "3. Third task" << endl
		<< "4. Fourth task" << endl
		<< "5. Fifth task" << endl
		<< "6. Sixth task" << endl
		<< "7. Seventh task" << endl
		<< "8. Eighth task" << endl
		<< "9. Ninth task" << endl
		<< "10. Tenth task" << endl
		<< "11. Eleventh task" << endl
		<< "12. Twelfth task" << endl
		<< "13. Thriteenth task" << endl
		<< "0 Exit " << endl
		<< "Enter number of function to start ";
	m = CheckSymbol();

	while (menu == 1)
		switch (m)
		{
		case 0:

			menu = 0; break;

		case 1:
		{
			helloWorld();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 2:
		{
			numbersSumm();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 3:
		{
			numbersDivision();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 4:
		{
			readingInput();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 5:
		{
			pointerExample();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 6:
		{
			exampleIf();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 7:
		{
			exampleElseIf();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 8:
		{
			exampleElseIf();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 9:
		{
			predfixCycle();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 10:
		{
			postfixCycle();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 11:
		{
			iterativeCycle();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 12:
		{
			convertingTypes();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
		case 13:
		{
			breakExample();
			cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}

		{
		default: cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;

		}
		}
}









