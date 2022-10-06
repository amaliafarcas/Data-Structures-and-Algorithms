#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r) {
	this->r = r;
	this->nrelem = 0;
	this->unique = 0;
	this->capacity = 1;
	this->elem = new TComp[capacity];
	this->freq = new TComp[capacity];
}
//Theta(1)

void SortedBag::add(TComp e) {

	if (this->nrelem == this->capacity)
	{
		this->capacity *= 2;
		TComp* els = new TComp[this->capacity];
		TComp* fls = new TComp[this->capacity];

		if (this->elem != NULL && this->freq != NULL)
			for (int i = 0; i < this->nrelem; i++)
			{
				els[i] = this->elem[i];
				fls[i] = this->freq[i];
			}

		if (this->elem != NULL)
			delete[] this->elem;
		if (this->freq != NULL)
			delete[] this->freq;
		this->elem = els;
		this->freq = fls;
	}
	
	if (this->nrelem == 0)
	{
		this->elem[unique] = e;
		this->freq[unique] = 1;
		this->nrelem++;
		this->unique++;
	}
	else
	{
		int ok = 0;
		for (int i = 0; i < unique; i++)
			if (this->elem[i] == e)
			{
				ok = 1;
				this->freq[i] += 1;
				this->nrelem++;
			}
		if (ok == 0)
		{
			if (this->nrelem == 1)
			{
				if (r(this->elem[1], e) == 1)
				{
					this->elem[nrelem] = e;
					this->freq[unique] = 1;
					this->nrelem++;
					this->unique++;
				}
				else
				{
					this->elem[nrelem] = this->elem[nrelem - 1];
					this->elem[nrelem-1] = e;
					this->freq[nrelem] = this->freq[nrelem - 1];
					this->freq[nrelem - 1] = 1;
					this->nrelem++;
					this->unique++;
				}
			}
			else
			{
				int i = 0, k = 0;
				while (i < this->unique && k == 0)
				{
					if (i == 0 && r(e, this->elem[i]) == 1)
					{
						for (int j = this->unique; j > i; j--)
						{
							this->elem[j] = this->elem[j - 1];
							this->freq[j] = this->freq[j - 1];
						}
						this->elem[i] = e;
						this->freq[i] = 1;
						k = 1;
					}
					else if (r(this->elem[i], e) == 1 && r(e, this->elem[i + 1]) == 1)
					{

						for (int j = this->unique; j > i; j--)
						{
							this->elem[j] = this->elem[j - 1];
							this->freq[j] = this->freq[j - 1];
						}
						this->elem[i + 1] = e;
						this->freq[i + 1] = 1;
						k = 1;
					}
					i++;
				}
				if (i == this->unique && r(this->elem[i], e) == 1 && k == 0)
				{
					this->elem[i] = e;
					this->freq[i] = 1;
				}
				this->nrelem++;
				this->unique++;
			}
		}
	}
	//for (int i = 0; i < this->unique; i++)
	//{
	//	cout << "(" << this->elem[i] << ", " << this->freq[i] << ")  ";
	//}
	//cout << endl;
}
//Best case: Theta(1)   Worst case: Theta(nrelem) => Total: O(nrelem)

bool SortedBag::remove(TComp e) {
	int k = 0;
	if (this->elem[this->unique - 1] == e)
	{
		if (this->freq[unique - 1] == 1)
		{
			this->nrelem--;
			this->unique--;
		}
		else
		{
			this->freq[unique - 1]--;
			this->nrelem--;
		}
		k = 1;
	}
	int i = 0;
	while (i < this->unique - 1 && k == 0)
	{
		if (this->elem[i] == e)
		{
			if (this->freq[i] == 1)
			{
				k = 1;
				for (int j = i; j < this->unique - 1; j++)
				{
					this->elem[j] = this->elem[j + 1];
					this->freq[j] = this->freq[j + 1];
				}
				this->nrelem--;
				this->unique--;
			}
			else
			{
				k = 1;
				this->freq[i]--;
				this->nrelem--;
			}
		}
		i++;
	}
	//for (int i = 0; i < this->unique; i++)
	//{
	//	cout << "(" << this->elem[i] << ", " << this->freq[i] << ")   ";
	//}
	//cout << endl;
	if (k == 0)
		return false;
	else
		return true;
}
//Best case: Theta(1)   Worst case: Theta(nrelem) => Total: O(nrelem)

bool SortedBag::search(TComp e) const {
	int k = 0;
	int i = this->unique - 1;
	while (i >= 0 && k == 0)
	{
		if (this->elem[i] == e)
			k = 1;
		i--;
	}
	if (k == 0)
		return false;
	else
		return true;
}
//Best case: Theta(1), Worst case: Theta(unique) => Total complexiy: O(unique)

int SortedBag::nrOccurrences(TComp e) const {
	int k = 0;
	for (int i = 0; i< this->unique; i++)
		if (this->elem[i] == e)
			k = this->freq[i];
	//cout << e << " times " << k << endl;
	return k;
}
//Best case: Theta(1), Worst case: Theta(unique) => Total complexiy: O(unique)

int SortedBag::size() const {
	return this->nrelem;
}
//Theta(1)

bool SortedBag::isEmpty() const {
	if (this->nrelem == 0)
		return true;
	else
		return false;
}
//Theta(1)


SortedBagIterator SortedBag::iterator() {
	return SortedBagIterator(*this);
}
//Theta(1)

SortedBag::~SortedBag() {
	delete[] this->elem;
}
//Theta(1)