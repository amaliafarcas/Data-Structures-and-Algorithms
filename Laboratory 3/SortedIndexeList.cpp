#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>
#include<vector>

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation
	this->r = r;
	this->asize = 0;
	this->capacity = 3;

	this->elem = new TComp[this->capacity];
	this->next = new int[this->capacity];


	for (int i = 0; i < this->capacity - 1; i++)
		this->next[i] = i + 1;
	this->next[this->capacity - 1] = -1;

	this->head = -1;
	this->firstFree = 0;
}
//Theta(1)

int SortedIndexedList::allocateP()
{
	//cout << "1" << endl;
	// in case of DynArray we would resize the array; here - just return -1
	if (firstFree == -1)
	{
		int nrelem = this->capacity;
		this->capacity *= 2;
		TComp* els = new TComp[this->capacity];
		int* fls = new int[this->capacity];
		//int* fps = new int[this->capacity];

		if (this->elem != NULL && this->next != NULL)
			for (int i = 0; i < nrelem; i++)
			{
				//cout << this->next[i]<<" ";
				els[i] = this->elem[i];
				fls[i] = this->next[i];
			}

		if (this->elem != NULL)
			delete[] this->elem;
		if (this->next != NULL)
			delete[] this->next;
		this->elem = els;
		this->next = fls;
		for (int i = nrelem; i < this->capacity - 1; i++)
			this->next[i] = i + 1;
		firstFree = nrelem;
		this->next[this->capacity - 1] = -1;
	}

	if (this->freedpos.size() == 0)
	{
		//cout << "free";
		int newFreePos = firstFree;
		//cout << firstFree<<" ";
		firstFree = next[firstFree];
		//cout << firstFree << endl;
		return newFreePos;
	}
	else
	{
		int a = this->freedpos.back();
		this->freedpos.pop_back();
		return a;
	}
}
//best case: Theta(1), worst case Theta(capacity) => Average O(capacity)

int SortedIndexedList::getpos(Relation r, TComp e, int& prev, int& current)
{
	while (current > -1)
	{
		if (r(e, this->elem[prev]) && r(this->elem[current], e))
		{
			//cout << "DA" << e << "between " << this->elem[prev] << "prev and " << this->elem[current] << endl;
			//cout << prev << current;
			return prev, current;
		}
		//cout << "prev " << this->elem[prev] << " cr " << this->elem[current] << endl;
		prev = current;
		//cout <<"prev "<< prev;
		current = this->next[current];
	}

	if (r(e, this->elem[prev]))
		return prev, current;
		//cout << "nu" << e << "before " << this->elem[prev] << endl;
	return -1;
}
//bc T(1), wc t(nrelem) => av O(nrelem)

void SortedIndexedList::add(TComp e) {
	int i = allocateP();
	//cout << "add" << i<< endl;
	if (i != -1)
	{
		int prev = this->head;
		int cur = this->next[prev];
		if (r(this->elem[prev], e))
		{
			//cout << "da " << e << "after " << this->elem[prev] << endl;

			//current = -1;
			//return prev, cur;
			//cout << "e";
			this->elem[i] = e;
			this->next[i] = this->head;
			this->head = i;

			this->asize++;
		}
		else {
			prev, cur = getpos(this->r, e, prev, cur);
			if (prev != -1 && cur != -1)
			{
				//cout << "m";
				this->elem[i] = e;
				this->next[prev] = i;
				this->next[i] = cur;

				this->asize++;
			}
			else if (cur == -1 && prev != -1)
			{
				//cout << "b";
				this->elem[i] = e;
				this->next[i] = -1;
				this->next[prev] = i;

				this->asize++;
			}
			else
			{
				//cout << "e";
				this->elem[i] = e;
				this->next[i] = this->head;
				this->head = i;

				this->asize++;
			}
		}
	}
}
//Theta(1)

int SortedIndexedList::size() const {
	return this->asize;
}
//Theta(1)

bool SortedIndexedList::isEmpty() const {
	if (this->asize == 0)
		return true;
	return false;
}
//Theta(1)

TComp SortedIndexedList::getElement(int i) const{
	int j = this->head;
	while (j != -1 && j!=i)
	{
		//cout << "elem " << this->elem[j] << " on pos " << j << endl;
		j = this->next[j];
	}
	if (j != -1)
		return this->elem[i];
	else
		throw exception();
}
//bc T(1), wc t(nrelem) => av O(nrelem)

TComp SortedIndexedList::remove(int i) {
	//cout << endl;
	//printarr();
	//cout << endl << i << endl;
	//if (std::find(this->freedpos.begin(), this->freedpos.end(), i) == this->freedpos.end())
	//	cout << i;
	//std::cout << i << "i" << endl;
	if (i != -1)
	{
		//cout << "str ";
		if (this->asize == 1 && this->head == i)
		{
			this->head = -1;
			this->asize--;
			this->firstFree = 0;
			//cout << this->elem[i];
			return this->elem[i];
		}
		else if (this->head == i)
		{
			this->freedpos.push_back(i);
			this->head = this->next[this->head];
			this->asize--;
			TComp a = this->elem[i];
			this->elem[i] = NULL_TCOMP;
			//cout << a;
			return a;
		}
		else
		{
			int j = this->head;
			while (j != -1 && this->next[j]!=i)
			{
				j = this->next[j];
			}
			//std::cout << j;
			if (j!=-1)
			{
				this->freedpos.push_back(i);
				this->next[j] = this->next[i];
				TComp a = this->elem[i];
				this->elem[i] = NULL_TCOMP;
				this->asize--;
				//cout << a;
				return a;
			}
		}
		throw exception();
		return false;
	}
	else
	{
		//std::cout << "here";
		throw exception();
		return false;
	}
}
//Theta(1)

void SortedIndexedList::empty_list()
{
	//printarr();
	//cout << endl;
	int j = this->head;
	while (j > -1)
	{
		//this->freedpos.push_back(j);
		this->head = this->next[this->head];
		this->asize--;
		this->elem[j] = NULL_TCOMP;

		j = this->next[j];
		/*this->freedpos.push_back(j);
		this->next[this->next[j]] = this->next[j];
		this->elem[this->next[j]] = this->elem[j];
		this->elem[j] = NULL_TCOMP;
		this->asize--;
		j = this->next[j];
		this->head = j;*/
		//printarr();
		//cout << endl;
	}
	this->firstFree = 0;
	//printarr();
	//cout << this->asize;
}
//Theta(1)

int SortedIndexedList::search(TComp e) const {
	int pos = -1;
	int j = this->head;
	while (pos != 0 && j!=-1)
	{
		if (this->elem[j] == e)
			pos = j;
		j = this->next[j];
	}
	//cout << e<<"on"<<pos;
	return pos;
}
//bc T(1), wc t(nrelem) => av O(nrelem)

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}
//Theta(1)

//destructor
SortedIndexedList::~SortedIndexedList() {
	delete[] this->elem;
	delete[] this->next;
}
//Theta(1)

void SortedIndexedList::printarr()
{
	int j = this->head;
	while (j != -1)
	{
		std::cout << "elem " << this->elem[j] << " on pos " << j << endl;
		j = this->next[j];
	}
}
//Theta(nrelem)