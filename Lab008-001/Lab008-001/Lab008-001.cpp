#include "stdafx.h"
#include "iostream"
using namespace std;

template<class T> T maxfunc(const T* array, int size)
{
	T max = array[0];

	for (int i = 1; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	return max;
};


int main()
{
	int ints[] = { 4, 1, 13, 3, 2 };
	double doubles[] = { 1.1, 4.1, 8.1, 5.2, 2.3, 2 };
	char letters[] = { 'A', 'B', 'a', 'c', 'd', 'E', 'f' };

	const int intsSize = sizeof ints / sizeof ints[0];
	cout << "Maximum int is " << maxfunc(ints, intsSize) << endl;

	const int doublesSize = sizeof doubles / sizeof doubles[0];
	cout << "Maximum double is " << maxfunc(doubles, doublesSize) << endl;

	const int lettersSize = sizeof letters / sizeof letters[0];
	cout << "Maximum integer is " << maxfunc(letters, lettersSize) << endl;

	system("pause");
	return 0;
}