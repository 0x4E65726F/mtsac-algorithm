/*  Program: Lab_Final_2
    Author: Nero Li
    Class: CSCI 220   
    Date: 12/09/2021	     
    Description: 
        Set up an adaptable priority queue in either C++ or Java as specified below. You should
        test your class like a regular PQ and then try operations like remove(p) and replace(p, e).
        
        Set up HeapAdaptablePQ class in C++ (like AdaptablePriorityQueue class in C++ book,
        but use a heap instead of a sorted list; see HeapAdaptablePriorityQueue class in Java
        book for implementation details).
        // use smallest int as highest priority
        HeapAdaptablePQ<<Entry<int, string>>, Compare1> myAPQ1;

        Set up SortedListAdaptablePQ class in Java (like HeapAdaptablePriorityQueue class in
        Java book, but use a sorted list instead of a heap; see AdaptablePriorityQueue class in
        C++ book for implementation details).
        // use smallest int as highest priority
        SortedListAdaptablePQ <Integer, String> myPQ1 =
        new SortedListAdaptablePQ <>(new Compare1());

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Entry {					                // a (key, value) pair
public:						                    // public functions
    typedef K Key;				                // key type
    typedef V Value;			                // value type

    Entry(const K& k = K(), const V& v = V())	// constructor
        : _key(k), _value(v) { }

    const K& key() const { return _key; }		// get key

    const V& value() const { return _value; }	// get value

    void setKey(const K& k) { _key = k; }		// set key

    void setValue(const V& v) { _value = v; }	// set value

private:						                // private data
    K _key;						                // key
    V _value;					                // value
};

template <typename E>
class VectorCompleteTree 
{
private:					                            // member data
    std::vector<E> V;				                    // tree contents
public:					                                // publicly accessible types
    typedef typename std::vector<E>::iterator Position; // a position in the tree
protected:					                            // protected utility functions
    Position pos(int i)				                    // map an index to a position
      { return V.begin() + i; }
    int idx(const Position& p) const		            // map a position to an index
      { return p - V.begin(); }
public:
    VectorCompleteTree() : V(1) {}		                // constructor
    int size() const				                    { return V.size() - 1; }
    Position left(const Position& p)		            { return pos(2*idx(p)); }
    Position right(const Position& p)		            { return pos(2*idx(p) + 1); }
    Position parent(const Position& p)		            { return pos(idx(p)/2); }
    bool hasLeft(const Position& p) const	            { return 2*idx(p) <= size(); }
    bool hasRight(const Position& p) const 	            { return 2*idx(p) + 1 <= size(); }
    bool isRoot(const Position& p) const	            { return idx(p) == 1; }
    Position root()				                        { return pos(1); }
    Position last()				                        { return pos(size()); }
    void addLast(const E& e)			                { V.push_back(e); }
    void removeLast()				                    { V.pop_back(); }
    void swap(const Position& p, const Position& q)     { E e = *q; *q = *p; *p = e; }
    void erase(const Position& p)                       { V.erase(p); }
};

template <typename E, typename C>
class HeapAdaptablePQ 
{ 
public:
    typedef typename VectorCompleteTree<E>::Position Position;
    int size() const; 				// number of elements
    bool empty() const;  			// is the queue empty?
    void insert(const E& e);		// insert element
    const E& min();				    // minimum element
    void removeMin();				// remove minimum
    void remove(const Position& p);
    Position replace(const Position& p, const E& e);

private: 
    VectorCompleteTree<E> T;		// priority queue contents
    C isLess;					    // less-than comparator
    						        // shortcut for tree position
};

template <typename E, typename C>		// number of elements
int HeapAdaptablePQ<E,C>::size() const
{ 
    return T.size(); 
}

template <typename E, typename C>		// is the queue empty?
bool HeapAdaptablePQ<E,C>::empty() const
{ 
    return size() == 0; 
}

template <typename E, typename C>		// minimum element
const E& HeapAdaptablePQ<E,C>::min() 
{ 
    return *(T.root());                 // return reference to root element
}	

template <typename E, typename C>		// insert element
void HeapAdaptablePQ<E,C>::insert(const E& e) 
{
    T.addLast(e);				        // add e to heap
    Position v = T.last();			    // e's position
    while (!T.isRoot(v))                // up-heap bubbling
    {			    
        Position u = T.parent(v);
        if (!isLess(*v, *u)) break;		// if v in order, we're done
        T.swap(v, u);				    // ...else swap with parent
        v = u;
    }
}

template <typename E, typename C>		// remove minimum
void HeapAdaptablePQ<E,C>::removeMin() 
{
    if (size() == 1)				// only one node?
        T.removeLast();				// ...remove it
    else 
    {
        Position u = T.root();			// root position
        T.swap(u, T.last());			// swap last with root
        T.removeLast();				    // ...and remove last
        while (T.hasLeft(u))            // down-heap bubbling
        { 			
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u);			// v is u's smaller child
            if (isLess(*v, *u))         // is u out of order?
            {			
                T.swap(u, v);			// ...then swap
                u = v;
            }
            else break;				// else we're done
        }
    }
}

template <typename E, typename C>			// remove at position p
void HeapAdaptablePQ<E,C>::remove(const Position& p) 
{ 
    T.erase(p); 
}

template <typename E, typename C>			// replace at position p
typename HeapAdaptablePQ<E,C>::Position
HeapAdaptablePQ<E,C>::replace(const Position& p, const E& e) 
{
    T.erase(p);
    return insert(e);
}

class Compare1
{
public:
    bool operator()(Entry<int, string> p, Entry<int, string> q) const
    { 
        return p.key() < q.key(); 
    }
};

/*
void insertValue(HeapAdaptablePQ<Entry<int, string>, Compare1> PQ, int key, string value)
{
    Entry<int, string> e;
    e.setKey(key);
    e.setValue(value);
    PQ.insert(e);
}
*/

int main()
{
    HeapAdaptablePQ<int, Compare1> test1;

    test1.insert(5);
    test1.insert(4);
    test1.insert(7);
    test1.insert(1);
    cout << test1.min() << ' ';
    test1.removeMin();
    test1.insert(3);
    test1.insert(6);
    cout << test1.min() << ' ';
    test1.removeMin();
    cout << test1.min() << ' ';
    test1.removeMin();
    test1.insert(8);
    cout << test1.min() << ' ';
    test1.removeMin();
    test1.insert(2);
    cout << test1.min() << ' ';
    test1.removeMin();
    cout << test1.min() << ' ';
    /*
    HeapAdaptablePQ<Entry<int, string>, Compare1> myAPQ1;

    insertValue(myAPQ1, 5, "a");
    insertValue(myAPQ1, 4, "b");
    insertValue(myAPQ1, 7, "c");
    insertValue(myAPQ1, 1, "d");
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    insertValue(myAPQ1, 3, "e");
    insertValue(myAPQ1, 6, "f");
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    insertValue(myAPQ1, 8, "g");
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    insertValue(myAPQ1, 2, "h");
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    cout << myAPQ1.min().value() << ' ';
    myAPQ1.removeMin();
    */

    cout << endl;

    cout << "Modified by: Nero Li\n";
    return 0;
}