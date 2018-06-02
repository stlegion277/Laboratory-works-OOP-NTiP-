#include "stdafx.h"


int main()
{
	int m;
	bool menu = 1;
	int default = 10000;

	printf("1. First task\n");
	printf("2. Second task\n");
	printf("3. Third task\n");
	printf("4. Fourth task\n");
	printf("5. Fifth task\n");
	printf("6. Sixth task\n");
	printf("7. Seventh task\n");
	printf("8. Eighth task\n");
	printf("9. Ninth task\n");
	printf("10. Tenth task\n");
	printf("11. Eleventh task\n");
	printf("12. Twelfth task\n");
	printf("13. Thriteenth task\n");
	printf("0 Exit\n ");
	printf("Enter number of function to start\n ");
	m = CheckSymbol();
	while (menu == 1)
	{	printf("Enter number of function to start\n ");
		switch (m)
		{
		case 0:
			menu = 0; 
			break;
		case 1:
			HelloWorld();
			m = CheckSymbol();
			break;
		case 2:
			NumbersSumm();
			m = CheckSymbol();
			break;
		case 3:
			NumbersDivision();			
			m = CheckSymbol();
			break;
		case 4:
			ReadingInput();
			m = CheckSymbol();
			break;
		case 5:
			PointerExample();
			m = CheckSymbol();
			break;
		case 6:
			ExampleIf();		
			m = CheckSymbol();
			break;
		case 7:
			ExampleElseIf();
			m = CheckSymbol();
			break;
		case 8:
			ExampleElseIf();
			m = CheckSymbol();
			break;
		case 9:
			PredfixCycle();
			m = CheckSymbol();
			break;
		case 10:
			PostfixCycle();
			m = CheckSymbol();
			break;
		case 11:
			IterativeCycle();
			m = CheckSymbol();
			break;
		case 12:
			ConvertingTypes();
			m = CheckSymbol();
			break;
		case 13:
			BreakExample();
			m = CheckSymbol();
			break;
		default: cout << "Enter number of function to start ";
			m = CheckSymbol();
			break;
			}
		}
}