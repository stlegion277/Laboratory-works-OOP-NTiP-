#pragma once
#include "Lab2.h"
#include "CheckSymbol.h"
using namespace std;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
//исправил(давно)
namespace Lab2
{
	int globalVariable = 10;
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
			case '+':
				return value1 + value2;
				break;//TODO //исправил
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
	int GetRootsPointer(int a, int b, int c, double* x1, double* x2)
	{
		double discriminant = b * b - (4 * a * c);
		double squareRoot = sqrt(discriminant);
		if (squareRoot > 0) 
		{
			*x1 = (-b + squareRoot) / (2 * a);
			*x2 = (-b - squareRoot) / (2 * a);
			cout << "Two roots found\n";
			cout << "First root" << *x1 << endl;
			cout << "Second root" << *x2 << endl;
			return 0;
		}
		if (squareRoot < 0) 
		{
			cout << "No roots\n";
			return 1;
		}
		if (squareRoot == 0)
		{
			*x1 = (-b) / (2 * a);
			x2 = NULL;
			cout << "Only one root " << x1;
			return 2;
		}
	}
	int GetRootsReference(int a, int b, int c, double& x1, double& x2)
	{
		double discriminant = b*b - (4 * a * c);
		double squareRoot = sqrt(discriminant);

		if (squareRoot > 0) {
			x1 = (-b + squareRoot) / (2 * a);
			x2 = (-b - squareRoot) / (2 * a);
			cout << "Two roots found\n";
			cout << "First root" << x1 << endl;
			cout << "Second root" << x2 << endl;
			return 0;
		}
		if (squareRoot < 0) {
			cout << "No roots\n";
			return 1;
		}
		if (squareRoot == 0) {
			x1 = (-b) / (2 * a);
			x2 = NULL;
			cout << "Only one root " << x1;
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
	int** MultiplyMatrix(int columns, int rows, int columns1, int rows1, 
		int** resultArray, int** arr, int** arr2)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			resultArray[i][j] = 0;
			for (int z = 0; z < columns1; z++)//TODO //исправил
			{
				resultArray[i][j] = arr[i][j] * arr2[i][j];
			}
		}
	}
		return resultArray;
}
	void FillMatrix(int rows, int columns, int** arr)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}
}
	void MakeMatrix(int rows, int columns,  int ** arr)
	{
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[columns];
		}
	}
	void PrintMatrix(int** arr, int columns, int rows)
	{
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout <<" " << arr[i][j];	
			}
			cout << endl;
		}
	}
	void DeleteMatrix(int sizeArr, int** arr)
	{
		for (int i = 0; i < sizeArr; i++)
		{
			delete[] arr[i];
		}
	}

	int Lab2()
{	
		srand(time(NULL));
		int m;
		bool menu = true;
		cout << "1. Print Hello World!\n";
		cout << "2. MakeCalculation\n";
		cout << "3. Division\n";
		cout << "4. Get roots by pointer\n";
		cout << "5. Get roots by reference\n";
		cout << "6. Getting power of number\n";
		cout << "7. Array sort\n";
		cout << "8. Multiply randomly filles matrixes\n";
		cout << "9. Global variables example\n";
		cout << "0 Exit\n ";
		cout << "Enter number of function to start\n ";
		while (true)
		{
			m = CheckSymbol();
			cout << "Enter number of function to start\n";
		switch (m)
		{
			case 0:
				menu = 0;
				break;
			case 1:
				PrintHelloWorld();	
				break;
			case 2:
				cout << MakeCalculation(2, 2); 
				break;
			case 3:
				cout << "Result of division = " << Divide(2, 2);
				break;
			case 4:
			{
				double* x1 = new double;
				double* x2 = new double;
				GetRootsPointer(1, 3, 2, x1, x2);
				break;
			}
			case 5:
			{
				double &x3 = *(new double);
				double &x4 = *(new double);
				GetRootsReference(1, 3, 2, x3, x4);
				break;
			}
			case 6:
				cout << "Number is  " << GetPower(2, 2); 
				break;
			case 7:
			{
				int intArray[5];
				for (int i = 0; i < 5; i++)
				{
					intArray[i] = rand() % 30;
				}
				BubbleSort(intArray);
				for (int i = 0; i < 5; i++)
				{
					cout << intArray[i] << endl;
				}
				break;
			}
			case 8:
			{
				int rows, columns;
				int rows1, columns1;
				cout << "Enter a number of rows int matrix A\n";
				cin >> rows;
				cout << "Enter a number of columns in matrix A\n";
				cin >> columns;
				cout << "Enter a number of rows in matix B\n";
				cin >> rows1;
				cout << " Enter a number of rows in matrix B\n";
				cin >> columns1;
				if (columns == rows1)
				{
					int rowsRes = rows;
					int columnsRes = columns1;
					int** arr = new int *[rows];
					int** arr1 = new int *[rows1];
					int** resultArray = new int *[rowsRes];
					MakeMatrix(rows, columns, arr);
					MakeMatrix(rows1, columns1, arr1);
					MakeMatrix(rowsRes, columnsRes, resultArray);
					FillMatrix(rows, columns, arr);
					FillMatrix(rows1, columns1, arr1);
					MultiplyMatrix(rows, columns1, rows1, columns, resultArray, arr, arr1);
					PrintMatrix(resultArray,columnsRes,rowsRes);
					cout << "Result";
					break;
				}
			case 9:
				GlobalPlusTwo();
				GlobalMultiplyThree();
				GlobalEqualsOne();
				break;
			default: cout << "Enter number of function to start ";
				break;
				}
			}
			system("pause");
			return 0;
			}
		}
	}