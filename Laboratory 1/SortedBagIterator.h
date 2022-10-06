#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	SortedBag& bag;
	SortedBagIterator(SortedBag& b);

	int current;

public:
	TComp getCurrent();
	TElem remove();
	bool valid();
	void next();
	void first();
};

