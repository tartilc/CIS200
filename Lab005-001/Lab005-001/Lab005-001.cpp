#include "stdafx.h"
#include "iostream"

using namespace std;

void Switch(int *x, int *y);

int main()
{
	int a = 5, b = 7;
	cout << "a = " << a << " b = " << b << endl;

	Switch(&a, &b);

	cout << "a = " << a << " b = " << b << endl;

	system("pause");
	return 0;
}

void Switch(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
