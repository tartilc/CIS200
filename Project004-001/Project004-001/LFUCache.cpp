#include "stdafx.h"
#include "LFUCache.h"
#include "iostream"

using namespace std;

void LFUCache::addItem(int item)
{
	int index = getIndexOfItem(item);

	if (index == -1)
	{
		if (numItem == size)
		{
			if (getItemAtFront() != item)
			{
				index = 0;

				for (int i = index; i < numItem; i++)
				{
					dataCache[i] = dataCache[i + 1];

				}

				dataCache[numItem - 1] = item;

			}
		}
		else {
			dataCache[numItem] = item;

			numItem++;

		}
	}
	else {
		if (getItemAtFront() != item)
		{
			for (int i = index; i < numItem; i++)
			{
				dataCache[i] = dataCache[i + 1];

			}

			dataCache[numItem - 1] = item;

		}
	}

	for (int i = numItem - 1; i >= 0; i--)
	{
		cout << dataCache[i] << " ";

	}

	cout << endl;

};

int LFUCache::getIndexOfItem(int item)
{
	for (int i = 0; i < numItem; i++)
	{
		if (item == dataCache[i])
		{
			return i;

		}
	}

	return -1;

};