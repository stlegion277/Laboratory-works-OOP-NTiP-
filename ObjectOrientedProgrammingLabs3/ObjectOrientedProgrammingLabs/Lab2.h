#pragma once

namespace Lab2
{
	void PrintHelloWorld();
	void GlobalPlusTwo();
	void GlobalMultiplyThree();
	void GlobalEqualsOne();
	double MakeCalculation(int value1, int value2);
	int Divide(int dividend, int divisor);
	int GetRootsPointer(int a, int b, int c, double* x1, double* x2);
	int GetRootsReference(int a, int b, int c, double& x3, double& x4);
	int GetPower(int base, int power);
	void BubbleSort(int intArray[5]);
	//TODO: ���������� ������� ���������� - ������!//��� �� � ���������� ��������� ���?
	//TODO: ��, � ����������
	//������ ���� rows � rows1, � ��� rows0? ��� �� ������ � ������ ������� � � ������ � �������, �������
	//firstMatrixRowsCount
	//secondMatrixRowsCount � �.�.
	//������
	//TODO: �� �������. ����� ������ ��� arr � arr1.
	int** MultiplyMatrix(int firstMatrixRowsCount, int secondMatrixColumnsCount, int secondMatrixRowsCount,
		int firstMatrixColumnsCount, int** resultArray, int** arr, int** arr1);
	int Lab2();
}