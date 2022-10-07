# Data-Structures-and-Algorithms
## Laboratory 1

##### ADT  SortedBag – having  elements  of  type TComp,represented  using a  dynamic  array  of <element,   frequency>   pairs(or   two   dynamic   arrays),   sorted   using   a   relation  on   the elements.

- Implement  in  C++  the  given container(ADT)  using  a given  representation  and  a dynamic  arrayas a data structure. You are not allowed to use the vectorfrom STL or from any other library.

#### Obs:
- Since your implementationwill use dynamic allocation, it is a good practice to implement a destructor,  copy  constructor  and  assignment  operator  as  well  (even  if  they  are  not  on  the interface).
- You are not allowed to use  the functionsmemcpyand realloc, becauseit is not  safe to use memcpy and realloc on memory  that  was  allocated with new. Also, if the  memory location contains  objects,  undefined  behavior  can  occur. Theimplementation  might  still  work  with these functions, but it is not a good practice to use them.
- If you need auxiliary functions, fell free  to add them to the interface of the ADT,  but  make them private.

## Laboratory 2

##### ADT  SortedMultiMap –using  a  DLL  with  (key,  value)  pairs  ordered  based  on  a  relation  on the keys. A key can appear in multiple pairs.

- Implement in C++ the given container(ADT) using a given representation and a linked list with dynamic allocationas a data  structure. You are not  allowed to use the listfrom STL or from any other library.

## Laboratory 3

##### ADT SortedList (interface with TPozition = Integer, SortedIndexedList) –using a SLLAwhere elements are ordered based on a relation.

- Implement  in  C++  the  given container(ADT)  using  a  given  representation  and  a linked  list on arrayas a data structure. You are not allowed to use the vectoror listfrom STL or from any other library.


## Laboratory 4

##### ADT Bag–using a hashtable with separate chaining in which the elements are stored. If an element appears multiple times, it will be stored multiple times in the hashtable.

- Implement in C++ the given container(ADT) using a given representation and a hashtable with a given  collision  resolution(separate  chaining,  coalesced  chaining,  open  addressing)as  a  data  structure. You are not allowed to use any container or data structurefrom STL or from any other library.

#### Obs:
- Do not implement a separate class for the hashtable (or dynamic array, or anything), implement the container directly!
- The  hashtable  has  to  be  dynamic:  no  matter  what  collision  resolution  has to  be  used,  set  a threshold for αand resize and rehash the table when the actual load factor is higher than α.

## Laboratory 5

##### ADT SortedList – using a BST with linked representation with dynamic allocation. Every node of the BST will retain the number of elements to the left of the node as well.

- Implement  in  C++  the  given container(ADT)  using  a  given  representation  and  a binary  search tree  (BST)as  a  data  structure.  You  are  not  allowed  to  use any container  or  data  structurefrom  STL or from any other library.

#### Obs:
- Do  not  implement  a  separate  class  for  the binary  search  tree(or  for  the  dynamic  array), implement the container directly!

