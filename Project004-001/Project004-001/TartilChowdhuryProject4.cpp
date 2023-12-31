#include "stdafx.h"
#include "iostream"
#include "LRUCache.h"

using namespace std;

int main(int argc, const char * argv[])
{
	int numItems, input;

	Cache* myLRUCache = new LRUCache(5);

	cout << "Enter the number of elements" << endl;
	cin >> numItems;

	for (int i = 0; i < numItems; i++)
	{
		cout << "Add element to cache: " << endl;
		cin >> input;
		myLRUCache->addItem(input);

	}

	system("pause");
	return 0;

}