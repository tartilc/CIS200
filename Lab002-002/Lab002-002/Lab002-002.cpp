#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int inputNum;

	cin >> inputNum;
	cout << endl;

	for (int i = 1; i <= inputNum; i++) {
		int count = 0;
		for (int j = 2; j <= i / 2; j++) {
			if (i%j == 0) {
				count++;
				break;
			}
		}

		if (count == 0 && i != 1)
			cout << i << endl;
	}

	system("pause");
	return 0;
}