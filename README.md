# mtsac-algorithm
## 02222022
```
	Searching
		hash map
		skip list: logn

	map ADT - Entry <k, v>
		Array/Vector
			Sorted
				find O(logn)
				insert: O(n)
				remove: O(n)
			Unsorted
				find O(n)
				insert: O(1)
				remove: O(n)
		Linked list
			Sorted
				find: O(n)
				insert: O(n)
				remove: O(n)
		BST(Simple): O(n)
		balanced BST: O(logn) -> O(1)
			AVL
			RB
			
	Hashing
		find <k, v> -> Use k to determine the address
		hash function - h(k) = x
		hash table
			[0][1][2][][][][][][][][]...[N - 1]
			
		key - 0 to 999				0 to 9999
		table size(N) = 1000		size(N) = 1000
		k % 1000					k % 1000 -> collision
		Seperate chaining
		Open addressing
			linear problems
			
	need good load factors
		n / N, 8 / 13
		good hash function
		
	S.C. good result up to lf 0.75
	L.P. up to 0.25
	P.H. up to 0.5

	expected performance
	open addressing
		1 / (1 - alpha) ~ 2
		
	C++ map
		ordered map - class map (balance BST logn)
		unordered map - class unorderedmap (hashing, expected average O(1))
```
## 03012022
```
	unordered vs ordered maps<k, v>
		HashTable
			average O(1)
			cannot obtain a sorted list
		Balanced BST O(logn)
		Sorted List
			Obtain a sorted list
		set<k>
		like an ordered map w/o value
			C++ STL set
		
	Skip list
		- a list of sorted linked list
		
	Dictionary ADT
		- Same as Map ADT
		- add findAll(k)
		- hash map impl.
			- seperate chaining
				insert/put
				always insert new entry
				findAll(k)
				O(1 + s)
			- open addressing (x)
		- Balance BST
			insert same O(logn)
			findAll(k) O(logn + s)
		- Sorted array/vector
			insert O(n)
			findAll(k) O(logn + s)
```			
## 03172022
```
	Some descriple sorting properties
		- In-place - no extra memory
			- merge sort (F)
			- insertion sort (T)
			- quick sort (depend)
		- Predictable performance
			- merge sort O(nlogn)
			- selection sort O(n^2)
		- Stable
			- shell sort (F)
			- insertion sort (can be)
			- merge sort (T)
			- quick sort (depend)
```		
## 03082022
```
	Divide-and-conquer Strategy
		Divide into 2 sections
		Recursion - solve each section the same way
		COunquer - combine the 2 sections into one section
```		
## 03222022
```
	quickSelect(S, k)
		if |S| is 1
			return first element of S'
		pick a pivot - random pivot or middle value (median of 3)
		partition S into L, E, G
		if k <= |L|
			quickSelect(L, k)
		else if k <= |L| + |E|
			return an element in E
		else
			quickSelect(G, k - (|L|+|E|))
```		
## 04052022
```
	- clistinct sets
		makeSet(e) - a new set w/ one element
		union(a, b) - combine into a new set, destroy old set
		find(p) - position of one element, return which set
``
		