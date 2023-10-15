#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int length, lengthx, lengthy;

	cin >> length;

	int *x = new int[length]; //1d array

	cin >> lengthx >> lengthy;

	int **y = new int*[lengthx]; //2d array
	for (int i = 0; i < lengthx; i++)
	{
		y[i] = new int[lengthy];
	}

	for (int i = 0; i < length; i++) //assign 10s
	{
		x[i] = 10;
		cout << x[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < lengthx; i++) //assign 10s
	{
		for (int j = 0; j < lengthy; j++)
		{
			*y[i] = 10;
			cout << *y[i] << " ";
		}
	}

	cout << endl;

	delete[] x; //delete 10s

	for (int i = 0; i < lengthx; i++) //delete 10s
	{
		delete[] y[i];
	}
	delete[] y;

	system("pause");
	return 0;
}