
#include "Functions.h"
using namespace std;
//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: � ��������� ���� ��� � ����������� �� ����������
using namespace Lab2;
int main()
{	srand(time(NULL));
//TODO: ������ ��� �� ��������� �� �������� ������� � case-���?
	int sizeArr = 5;
	int** arr = MultiplyMatrix(sizeArr);
	int m;
	//TODO: ������������ 1 ���� - ������ ��������. ���� - ��� true � false, � �� 1 � 0.
	bool menu = 1;
	//TODO: ��� ���������� �� ������������
	//TODO: ���� �� ������������, ��� �� ����� - � �� ����� �� ������, ����� ������������
	cout << "1. First task\n";
	cout << "2. Second task\n";
	cout << "3. Third task\n";
	cout << "4. Fourth task\n";
	cout << "5. Fifth task\n";
	cout << "6. Sixth task\n";
	cout << "7. Seventh task\n";
	cout << "8. Eighth task\n";
	cout << "9. Ninth task\n";
	cout << "0 Exit\n ";
	cout << "Enter number of function to start\n ";
	//TODO: CheckSymbol ����������� �� ���� case-��, ��� ���������.
	
	while (menu == 1)
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
			cout << MakeCalculation(2,2);
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
			cout << "Number is  " <<  GetPower(2, 2);	
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
			for (int i = 0; i < sizeArr; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
			arr = NULL;
			arr = MultiplyMatrix(sizeArr);
			for (int i = 0; i < sizeArr; i++)
			{
				for (int j = 0; j < sizeArr; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}		
			break;
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

