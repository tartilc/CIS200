#include "stdafx.h"
#include "Cache.h"

class LRUCache : public Cache
{
	int size;

public:
	LRUCache(int cacheSize);
	void addItem(int item);
	int getIndexOfItem(int item);

};