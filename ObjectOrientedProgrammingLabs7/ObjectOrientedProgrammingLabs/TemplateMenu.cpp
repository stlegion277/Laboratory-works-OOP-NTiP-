#include "TemplateMenu.h"
using namespace std;

int MenuForMenu()
{
	srand(time(0));
	int menuNumber;
	while (true)
	{
		cout << endl
			<< "1 ListMenu " << endl
			<< "2 DoubleListMenu" << endl
			<< "3 Person Menu" << endl
			<< "0 Exit" << endl
			<< "Choose wisely: ";
		menuNumber = CheckSymbol();
		system("cls");
		switch (menuNumber)
		{
			case 1:
				ListMenu();
				break;
			case 2:
			{
				TempList<double>* tempList = new TempList<double>();
				DoubleListMenu(tempList, 0);
				break;
			}	
			case 3:
			{
				PersonMenu();
				break;
			}
			case 0:
				return 0;
			default:
				cout << "Enter correct number"; break;
		}
	}
	return 0;
}