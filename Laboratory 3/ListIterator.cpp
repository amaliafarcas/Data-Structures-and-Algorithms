#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	this->current = list.head;
}
//Theta(1)

void ListIterator::first(){
	this->current = list.head;
}
//Theta(1)

void ListIterator::next(){
	if (current != -1)
		current = list.next[current];
	else
		throw exception();
}
//Theta(1)

bool ListIterator::valid() const{
	if (this->current != -1)
		return true;
	return false;
}
//Theta(1)

TComp ListIterator::getCurrent() const{
	if (this->current == -1)
		throw exception();
	else
		return list.elem[current];
}
//Theta(1)


