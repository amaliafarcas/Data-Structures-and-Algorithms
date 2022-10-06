#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <iostream>
using namespace std;

SortedBagIterator::SortedBagIterator(SortedBag& b) : bag(b) {
	this->current = 1;
}
//Theta(1)

TComp SortedBagIterator::getCurrent() {
	if (this->current > this->bag.nrelem)
		throw exception();
	else
	{
		int k = this->current, i=-1;
		while (k > 0)
		{
			i++;
			k -= this->bag.freq[i];
		}
		
		//cout << this->current << " " << this->bag.elem[i] << endl;
		//cout<<current<<" "<< this->bag.elem[i]<<endl;
		return this->bag.elem[i];
	}
}
//Theta(1)

TElem SortedBagIterator::remove()
{
	if (this->current > this->bag.nrelem)
		throw exception();

	TComp c = getCurrent();
	int k = 0;
	for (int i = 0; i < this->bag.unique-1; i++)
	{
		if (this->bag.elem[i] == c)
		{
			if (this->bag.freq[i] == 1)
			{
				for (int j = i; j < this->bag.unique-1; j++)
				{
					this->bag.elem[j] = this->bag.elem[j + 1];
					this->bag.freq[j] = this->bag.freq[j + 1];
				}
				this->bag.nrelem--;
				this->bag.unique--;
			}
			else
			{
				this->bag.freq[i]--;
				this->bag.nrelem--;
			}
			k = 1;
		}
		if (k == 1)
		{
			//this->current++;
			break;
		}
			
	}
	if (k == 0 && this->bag.elem[this->bag.unique - 1] == c)
	{
		if (this->bag.freq[this->bag.unique - 1] == 1)
		{
			this->bag.nrelem--;
			this->bag.unique--;
		}
		else
		{
			this->bag.freq[this->bag.unique - 1]--;
			this->bag.nrelem--;
		}
	}

	//for (int i = 0; i < this->bag.unique; i++)
	//{
	//	cout << "(" << this->bag.elem[i] << ", " << this->bag.freq[i] << ")  ";
	//}
	//cout << endl;
	//cout << this->bag.nrelem << " " << endl;
	return c;
}
//Best case: Theta(1)   Worst case: Theta(nrelem) => Total: O(nrelem)

bool SortedBagIterator::valid() {
	if (this->current <= this->bag.nrelem)
		return true;
	else
		return false;
}
//Theta(1)

void SortedBagIterator::next() {
	if (this->current > this->bag.nrelem)
		throw exception();
	else
	{
		this->current++;
	}
		
}
//Theta(1)

void SortedBagIterator::first() {
	this->current = 1;
}
//Theta(1)
