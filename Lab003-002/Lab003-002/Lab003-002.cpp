#include "stdafx.h"
#include <iostream>

using namespace std;

int Sum(int array[3][2], int length, int width);

int main()
{	
	const int MAX_ROWS = 3;
	const int MAX_COLUMNS = 2;

	int A[MAX_ROWS][MAX_COLUMNS] = { { 3, 2 },{ 4, 5 },{ 3, 2 } };

	cout << Sum(A, MAX_ROWS, MAX_COLUMNS) << endl;

	system("pause");
	return 0;
}

int Sum(int array[3][2], int length, int width)
{
	int sum = 0;

	for (int i = 0; i<length; i++)
	{
		for (int j = 0; j<width; j++)
		{
			sum += array[i][j];
		}
	}

	return sum;
}