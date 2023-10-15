#include "stdafx.h"

class Cache
{
protected:
	int size;
	int numItem = 0;
	int *dataCache;

public:
	Cache(int cacheSize);
	void setSize(int cacheSize);
	void addItem(int item);
	int getIndexOfItem(int item);
	int getItemAtFront();

};