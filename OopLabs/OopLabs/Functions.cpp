#include "Functions.h"
#include "stdafx.h"

void HelloWorld()
{
	printf("Hello, World!\n");

}


void NumbersSumm()
{
	int a;
	a = 5;
	int b = 3;
	printf("\n Variable a equals %d", a);
	printf("\n Variable b equals %d", b);
	printf("\n Summ of a and b equals %d\n", a + b);

}

void NumbersDivision()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	printf("Float variables division: %f \n", z / y);
	printf("Integer variables division: %d \n", a / b);

}


void ReadingInput()
{
	int a;
	int b;
	printf("---Program for integer summation---");
	printf("\n\n Enter first integer value: ");
	scanf_s("%d", &a);
	printf(" Enter second integer value: ");
	scanf_s("%d", &b);
	printf(" \n Summ of %d and %d equals %d \n", a, b, a + b);

}


void PointerExample()
{
	int value;
	int* pointer;
	int anotherValue;
	value = 5;
	pointer = &value;
	anotherValue = *pointer;
	printf("Value, stored in pointer: %d \n", anotherValue);
	printf("Address in pointer: %p \n", pointer);
	printf("Value in pointer: %d \n", *pointer);


}


int ExampleIf()
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

void ExampleElseIf()
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


void PredfixCycle()
{
	int a = 0;
	while (a < 5)
	{
		printf("Value is %d now \n", a);
		a++;
	}
}

void PostfixCycle()
{
	int a = 0;
	do
	{
		printf("Value is %d now \n", a);
		a++;
	} while (a < 5);

}

void IterativeCycle()
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

void ConvertingTypes()
{
	int a = 5;
	int b = 3;
	float z;
	z = a;
	printf("Value of z is %f \n", z);
	a = z;
	a = (int)z;
	printf("Value of a is %d \n", a);
	z = a / b;
	printf("Value of z is %f \n", z);
	z = ((float)a) / b;
	printf("Value of z is %f \n", z);

}

void BreakExample()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			printf("I is more or equal A! Break of cycle");
			break;
		}
	}
	printf("\n A is %d \n", a);

}





