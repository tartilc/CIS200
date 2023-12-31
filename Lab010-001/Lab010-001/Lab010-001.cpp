#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "iomanip"
#include "stdlib.h"
#include "stack"
#include "string"

using namespace std;

int main()
{
	int cont = 1;

	string str;

	double op1, op2;

	stack<double> num;

	cout << "Enter expression: " << endl;

	while (cont)
	{
		cin >> str;

		if (str.compare("stop") == 0) {
			cont = 0;
			continue;
		}
		else if (str.compare("+") == 0) {
			op1 = num.top();
			num.pop();
			op2 = num.top();
			num.pop();
			num.push(op1 + op2);
		}
		else if (str.compare("*") == 0)
		{
			op1 = num.top();
			num.pop();
			op2 = num.top();
			num.pop();
			num.push(op1 * op2);
		}
		else if (str.compare("-") == 0)
		{
			op1 = num.top();
			num.pop();
			op2 = num.top();
			num.pop();
			num.push(op2 - op1);
		}
		else if (str.compare("/") == 0)
		{
			op1 = num.top();
			num.pop();
			op2 = num.top();
			num.pop();
			num.push(op2 / op1);
		}
		else if (str.compare("=") == 0)
		{
			cout << fixed << showpoint << setprecision(5) << num.top();
		}
		else
		{
			num.push(atof(str.c_str()));
		}
	}

	system("pause");
	return 0;
}