#pragma once
#include "Functions.h"
using namespace std;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
namespace Lab2
{	int globalVariable = 10;
	void PrintHelloWorld()
	{
		cout << "Hello World!\n";
	}
	void GlobalPlusTwo()
	{
		globalVariable += 2;
		cout << "  global variable =  " << globalVariable;
	}
	void GlobalMultiplyThree()
	{
		globalVariable *= 3;
		cout << "  global variable =  " << globalVariable;
	}
	void GlobalEqualsOne()
	{
		globalVariable = 1;
		cout << "  global variable =  " << globalVariable;
	}
	double MakeCalculation(int value1, int value2)
	{
		char key;
		cout << "Enter mathematic operation (+, -, *, /, %): ";
		key = getchar();
		while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
		{
			cout << "\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):";
			key = getchar();
		}
		switch (key)
		{
		case '-':
			return value1 - value2;
			break;
		case '+':
			return value1 + value2;
			break;
		case '*':
			return value1 * value2;
			break;
		case '/':
			return value1 / value2;
			break;
		case '%':
			return value1 % value2;
			break;
		default:
			return 0;
			break;
		}
	}
	int Divide(int dividend, int divisor)
	{
		int result;
		result = dividend / divisor;
		return result;
		system("pause");
	}
	int GetRoots(int a, int b, int c, double* x1, double* x2)
	{
		double discriminant = b*b - (4 * a * c);
		double squareRoot = sqrt(discriminant);
		if (squareRoot > 0) {
			*x1 = (-b + squareRoot) / (2 * a);
			*x2 = (-b - squareRoot) / (2 * a);
			cout << "Two roots found\n";
			cout << "First root" << *x1 << endl;
			cout << "Second root" << *x2 << endl;
			return 0;
		}
		if (squareRoot < 0) {
			cout << "No roots\n";
			return 1;
		}
		if (squareRoot == 0) {
			*x1 = (-b) / (2 * a);
			x2 = NULL;
			cout << "Only one root " << x1;
			return 2;
		}
	}
	//TODO: Зачем тут делать именование х3 и х4? Это всё те же х1 и х2.
	//TODO: Также неудачное именвание. Функции различаются передачей по ссылке и указателю, 
	//TODO: что можно было отразить в названии функции
	int GetRoots2(int a, int b, int c, double& x3, double& x4)
	{
		double discriminant = b*b - (4 * a * c);
		double squareRoot = sqrt(discriminant);

		if (squareRoot > 0) {
			x3 = (-b + squareRoot) / (2 * a);
			x4 = (-b - squareRoot) / (2 * a);
			cout << "Two roots found\n";
			cout << "First root" << x3 << endl;
			cout << "Second root" << x4 << endl;
			return 0;
		}
		if (squareRoot < 0) {
			cout << "No roots\n";
			return 1;
		}
		if (squareRoot == 0) {
			x3 = (-b) / (2 * a);
			x4 = NULL;
			cout << "Only one root " << x3;
			return 2;
		}
	}
	int GetPower(int base, int power)
	{
		if (power == 0) return 1;
		if (power > 0)
		{
			return (base * GetPower(base, power - 1));
		}
		if (power < 0)
		{
			return (1 / (base*GetPower(base, power - 1)));
		}
	}
	void BubbleSort(int intArray[5])
	{
		int tmp;
		for (int i = 0; i < 5; ++i)
		{
			int pos = i;
			tmp = intArray[i];
			for (int j = i + 1; j < 5; ++j)
			{
				if (intArray[j] < tmp)
				{
					pos = j;
					tmp = intArray[j];
				}
			}
			intArray[pos] = intArray[i];
			intArray[i] = tmp;
		}
	}
	int** MultiplyMatrix(int sizeArr)
	{
		int** resultArray = new int*[sizeArr];
		int** arr = new int*[sizeArr];
		int** arr2 = new int*[sizeArr];
		for (int i = 0; i < sizeArr; i++)
		{
			arr[i] = new int[sizeArr];
			arr2[i] = new int[sizeArr];
			resultArray[i] = new int[sizeArr];
		}
//TODO: В тексте много дублирования кода
					//TODO: Уменьшите дублирование.
		for (int i = 0; i < sizeArr; i++)
			for (int j = 0; j < sizeArr; j++)
				arr[i][j] = rand() % 20;
		for (int i = 0; i < sizeArr; i++)
			for (int j = 0; j < sizeArr; j++)
				arr2[i][j] = rand() % 20;
		for (int i = 0; i < sizeArr; i++)
			for (int j = 0; j < sizeArr; j++)
			{
				resultArray[i][j] = 0;
				for (int z = 0; z < sizeArr; z++)
					resultArray[i][j] = arr[i][j] * arr2[i][j];
			}
		return resultArray;
	}
}