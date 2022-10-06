#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator; 
class Bag {

private:
	
	struct Node
	{
		TElem* elem;
		Node* next;
	};

	int sizeTable = 10;
	int numbers;

	/*int HashFunction(TElem elem)
	{
		return elem % this->sizeTable;
	}*/

	Node** table;
	//struct HashTable
	//{

	//};

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	void displayTable() const;

	//void tableDoubling();
	//void tableShrinking();
	//void reHashing(int size_orig);

	int HashFunction(TElem elem) const
	{
		int abs;
		if (elem < 0)
			abs = 0 - elem;
		else
			abs = elem;
		return abs % this->sizeTable;
	}

	int MaxFreq() const;

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};