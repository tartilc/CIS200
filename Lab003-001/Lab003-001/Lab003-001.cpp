#include "stdafx.h"
#include <iostream>
using namespace std;

float average(float x[], int length);

int main()
{
	const int length = 4;

	float array[length];

	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	
	cout << endl << average(array, length) << endl;

	system("pause");
	return 0;
}

float average(float x[], int length)
{
	float sum = 0;
	float avg;

	for (int i = 0; i < length; i++)
	{
		sum += x[i];
	}
	avg = sum / length;
	return avg;
}
