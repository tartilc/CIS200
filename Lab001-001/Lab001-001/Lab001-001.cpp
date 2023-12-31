#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu();

int main()
{
	char sel, selUp;

	do {
		displayMenu();

		cin >> sel;

		selUp = toupper(sel);

		switch (selUp)
		{
		case 'D':
			cout << "Delete a substring.\n" << endl;
			break;
		case 'F':
			cout << "Find a string.\n" << endl;
			break;
		case 'I':
			cout << "Insert a string.\n" << endl;
			break;
		case 'R':
			cout << "Replace a substring.\n" << endl;
			break;
		case 'Q':
			cout << "Quit.\n" << endl;
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}

	} while (selUp != 'Q');

	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "List of edit operations:" << endl <<
		"D - Delete a substring." << endl << "F - Find a string." << endl <<
		"I - Insert a string." << endl << "R - Replace a substring." << endl <<
		"Q - Quit" << endl << "Enter D, F, I, R, or Q as your selection:" << endl;
}