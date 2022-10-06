#include <assert.h>

#include "ListIterator.h"
#include "SortedIndexedList.h"

using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

bool condition1(TComp e) {
    if (e%2==0) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
	SortedIndexedList list = SortedIndexedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());

    list.add(7);
    list.add(2);
    list.add(9);
    list.add(4);
    list.add(5);
    list.add(10);
    assert(list.size() == 6);
    list.filter(condition1);
    assert(list.size() == 3);
    list.empty();
    assert(list.isEmpty());

    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
}

