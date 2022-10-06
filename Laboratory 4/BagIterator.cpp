#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>

using namespace std;

BagIterator::BagIterator(const Bag& c): bag(c)
{	
	if (c.isEmpty())
	{
		current = NULL;
		current_index = NULL;
	}
	else
	{
		current_index = 0;
		while (current_index < c.sizeTable)
		{
			current = c.table[current_index];
			if (current != NULL)
				break;
			current_index++;
		}
	}
}
//B: Theta(1), W: Theta(nrElem) => O: O(nrElem)

void BagIterator::first() {
	if (bag.isEmpty())
	{
		current = NULL;
		current_index = NULL;
	}
	else
	{
		current_index = 0;
		while (current_index < bag.sizeTable)
		{
			current = bag.table[current_index];
			if (current != NULL)
				break;
			current_index++;
		}
	}
}
//B: Theta(1), W: Theta(nrElem) => O: O(nrElem)

void BagIterator::next() {

	if (this->current == NULL && this->current_index == bag.sizeTable)
		throw exception();
	if (this->current != NULL && this->current_index < bag.sizeTable)
	{
		if (this->current->next == NULL)
		{
				current_index++;
				while (bag.table[current_index] == NULL && current_index < bag.sizeTable)
				{
					current_index++;
				}
				
				if (current_index < bag.sizeTable)
					current = bag.table[current_index];
				else
					current = NULL;
		}
		else
		{
			current = current->next;
		}
	}
	if (bag.isEmpty())
	{
		current_index = bag.sizeTable;
		throw exception();
	}
}
//B: Theta(1), W: Theta(nrElem) => O: O(nrElem)

bool BagIterator::valid() const {
	return current != NULL && current_index < bag.sizeTable;
}
//Theta(1)

TElem BagIterator::getCurrent() const
{
	if (current == NULL || current_index >= bag.sizeTable)
		throw exception();
	else
	{
		return TElem(current->elem[0]);
	}
}
//Theta(1)
