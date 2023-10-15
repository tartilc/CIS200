#include "stdafx.h"
#include "Cache.h"

class LFUCache : public Cache
{
	int size;

public:
	void addItem(int item);
	int getIndexOfItem(int item);

};