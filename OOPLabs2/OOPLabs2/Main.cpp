
#include "Functions.h"
using namespace std;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
using namespace Lab2;
int main()
{	srand(time(NULL));
//TODO: Почему это всё находится за основной логикой с case-ами?
	int sizeArr = 5;
	int** arr = MultiplyMatrix(sizeArr);
	int m;
	//TODO: Присваивание 1 булю - плохая практика. Буль - это true и false, а не 1 и 0.
	bool menu = 1;
	//TODO: Эта переменная не используется
	int default = 10000;
	//TODO: Меню не информативно, что за таски - я не помню по памяти, лучше расшифровать
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
	//TODO: CheckSymbol дублируется во всех case-ах, это избыточно.
	m = CheckSymbol();
	while (menu == 1)
	{
		cout << "Enter number of function to start\n";
		switch (m)
		{
		case 0:
			menu = 0;
			break;
		case 1:
			PrintHelloWorld();
			m = CheckSymbol();
			break;
		case 2:
			cout << MakeCalculation(2,2);
			m = CheckSymbol();
			break;
		case 3:
			cout << "Result of division = " << Divide(2, 2);
			m = CheckSymbol();
			break;
		case 4:
		{
			double* x1 = new double;
			double* x2 = new double;
			GetRoots(1, 3, 2, x1, x2);
			m = CheckSymbol();
			break;
		}
		case 5:
		{
			double &x3 = *(new double);
			double &x4 = *(new double);
			GetRoots2(1, 3, 2, x3, x4);
			m = CheckSymbol();
			break;
		}
		case 6:
			cout << "Number is  " <<  GetPower(2, 2);	
			m = CheckSymbol();
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
			m = CheckSymbol();
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
			m = CheckSymbol();
			break;
		case 9:
			  GlobalPlusTwo();
			  GlobalMultiplyThree();
			  GlobalEqualsOne();
			m = CheckSymbol();
			break;
		default: cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
		}
	}
	system("pause");
	return 0;
}

