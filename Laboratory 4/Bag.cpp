#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <list>

using namespace std;

Bag::Bag() {

	this->numbers = 0;
	this->table = new Node * [this->sizeTable]; 
	for (int i = 0; i < this->sizeTable; i++)
		this->table[i] = NULL; 
}
//Theta(sizeTable)

void Bag::displayTable() const
{
	for (int i = 0; i < this->sizeTable; i++)
	{ // visit every node in table
		cout << "Slot " << i << ": ";
		Node* current = table[i];
		while (current != NULL)
		{
			cout << "(" << current->elem[0] << ") ";
			current = current->next;
		}
		cout << endl;
	}
	cout << endl;
}

int Bag::MaxFreq() const
{
	if (isEmpty())
		return 0;
	list <TElem> seen;
	int nr = 0;
	int maxnroc=0;
	int i = 0;
	//displayTable();
	Node* current = table[i];
	while (current == NULL && i < sizeTable)
	{
		i++;
		current = table[i];
	}
	while (i<this->sizeTable)
	{
		if (current == NULL)
		{
			//cout << "b i= "<<i ;
			break;
		}
		//cout << current->elem[0]<<" ";
		auto it = std::find(seen.begin(), seen.end(), current->elem[0]);
		if (it == seen.end())
		{
			seen.push_back(current->elem[0]);
			int m = nrOccurrences(current->elem[0]);
			if (m > maxnroc)
			{
				maxnroc = m;
				nr = 1;
			}
			else if (m == maxnroc)
				nr++;
		}
		if (current->next != NULL)
		{
			current = current->next;
		}
		else if (current->next == NULL)
		{
			i++;
			current = table[i];
			while (current == NULL && i < sizeTable)
			{
				i++;
				current = table[i];
				//cout << " i: "<<i;
			}
		}
		
	}
	return nr;
}
//Theta(NrElem)

void Bag::add(TElem elem) {

	/*if (this->numbers > this->sizeTable*2)
	{                    
		tableDoubling(); 
	}*/

	int index = this->HashFunction(elem); 
	
	Node* newNode = new Node();     
	newNode->elem = new TElem;
	newNode->elem[0] = elem;
	newNode->next = NULL;

	if (table[index] == NULL)
	{                          
		table[index] = newNode; 
	}
	else
	{                                    
		Node* next = table[index]; 
		newNode->next = next;
		table[index] = newNode;
	}
	this->numbers++;
}
//Theta(1)

//void Bag::tableDoubling()
//{
//	//int size_orig = this->sizeTable; // size_orig represents the original size of table
//	sizeTable *= 2;            // double the size of table
//	reHashing(sizeTable); // create new table with new larger size
//}
//
//void Bag:: tableShrinking()
//{
//	//int size_orig = this->sizeTable; // size_orig represents the original size of table
//	this->sizeTable /= 2;            // shrink the size of table
//	reHashing(sizeTable); // create new table with new smaller size
//}
//
//void Bag::reHashing(int size_orig)
//{
//	Node** newtable = new Node *[sizeTable]; // allocate memory for new table
//	for (int i = 0; i < sizeTable; i++)
//	{                    // initializetion
//		newtable[i] = NULL; // ensure every node in slot points to NULL
//	}
//
//	for (int i = 0; i < size_orig; i++)
//	{ // visit every node in the original table
//
//		Node* curr_orig = table[i], // curr_orig: current node in original table
//			* prev_orig = NULL;      // prev_orig: following curr_orig
//
//		while (curr_orig != NULL)
//		{ // traversal in list of each slot in original table
//			prev_orig = curr_orig->next; // curr_orig will be directly move to new table
//										 // need prev_orig to keep pointer in original table
//
//			int index = HashFunction(curr_orig->elem[0]); // get index of slot in new table
//
//			// push_front(), do not allocate new memory space for data
//			// directly move node in original table to new table
//			if (newtable[index] == NULL)
//			{ // means newtable[index] is empty
//				newtable[index] = curr_orig;
//				newtable[index]->next = NULL; // equivalent to curr_orig->next = 0;
//			}
//			// if there is no initialization for newtable, segmentation faults might happen
//			// because newtable[index] might not point to NULL
//			// but newtable[index] is empty
//			else
//			{                                       // if newtable[index] is not empty
//				Node* next = newtable[index]->next; // push_front()
//				newtable[index]->next = curr_orig;
//				curr_orig->next = next;
//			}
//			curr_orig = prev_orig; // visit the next node in list in original table
//		}
//	}
//	delete[] table;         // release memory of original table
//	this->table = newtable; // point table of object to new table
//}

bool Bag::remove(TElem elem) {

	int index = this->HashFunction(elem); 
	Node* current = table[index],  
		* previous = NULL;

	while (current != NULL && current->elem[0] != elem)
	{
		previous = current;      
		current = current->next; 
	}                            
								
	if (current == NULL)
	{ 
		return false;
	}
	else
	{
		if (previous == NULL)
		{                                 
			table[index] = current->next;
		}                                 
		else
		{                                   
			previous->next = current->next; 
		}                                   
		delete current;
		current = 0;
		this->numbers--;
		//if (numbers < sizeTable / 4)
		//{                     // consider load factor
		//	tableShrinking(); // if n/m < 4, then shrink the table
		//}
		return true;
	}
}
//B: Theta(1), W: Theta(nrElem) => O: O(nrElem)

bool Bag::search(TElem elem) const {

	int index = HashFunction(elem);
	Node* current = table[index];  
	while (current != NULL)
	{ 
		if (current->elem[0] == elem)
			return true;
		current = current->next;
	}
	return false;
}
//B: Theta(1), W: Theta(nrElem) => O: O(nrElem)

int Bag::nrOccurrences(TElem elem) const {

	int index = HashFunction(elem);
	Node* current = table[index];  
	int nroc = 0;
	while (current != NULL)
	{ 
		if (current->elem[0] == elem)
			nroc++;
		current = current->next;
	}
	return nroc;
}
//Theta(nrElem)

int Bag::size() const {
	return this->numbers;
}
//Theta(1)

bool Bag::isEmpty() const {
	if (this->numbers == 0)
		return true;
	return false;
}
//Theta(1)

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}
//Theta(1)

Bag::~Bag() {
	for (int i = 0; i < this->sizeTable; i++)
	{                             
		Node* current = table[i];
		while (current != NULL)
		{ 
			Node* previous = current;
			current = current->next;
			delete previous;
			previous = 0;
		}
	}
	delete[] table;
}
//Theta(nrElem)
