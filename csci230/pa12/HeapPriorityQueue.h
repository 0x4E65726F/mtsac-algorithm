#ifndef HPQ_H
#define HPQ_H

#include <list>
#include <vector>

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
    void swap(const Position& p, const Position& q)     { E e = *q; *q = *p; *p = e; }

    // New function added for CSCI 230 PA10
    Position removeLast()				                
    { 
        Position p = V.end();
        p--;
        V.pop_back(); 
        return p;
    }
    void remove(E e)
    {
        Position p = V.begin();
        for (auto i : V)
        {
            if (i == e)
            {
                V.erase(p);
                return;
            }
            p++;
        }
        
    }
};

template <typename E, typename C>
class HeapPriorityQueue 
{ 
public:
    int size() const; 				// number of elements
    bool empty() const;  			// is the queue empty?
    E insert(const E& e);		// insert element
    const E& min();				    // minimum element
    E removeMin();				// remove minimum

    // New function added for CSCI 230 PA10
    void replace(const E& oldElem, const E& newElem)
    {
        vector<E> allElem;
        while (!empty())
        {
            if (min().first == oldElem.first && min().second == oldElem.second)
                allElem.push_back(newElem);
            else
                allElem.push_back(min());
            removeMin();
        }
        
        for (auto i : allElem)
            insert(i);
    }
private: 
    VectorCompleteTree<E> T;		// priority queue contents
    C isLess;					    // less-than comparator
    						        // shortcut for tree position
    typedef typename VectorCompleteTree<E>::Position Position;
};

template <typename E, typename C>		// number of elements
int HeapPriorityQueue<E,C>::size() const
{ 
    return T.size(); 
}

template <typename E, typename C>		// is the queue empty?
bool HeapPriorityQueue<E,C>::empty() const
{ 
    return size() == 0; 
}

template <typename E, typename C>		// minimum element
const E& HeapPriorityQueue<E,C>::min() 
{ 
    return *(T.root());                 // return reference to root element
}	

template <typename E, typename C>		// insert element
E HeapPriorityQueue<E,C>::insert(const E& e) 
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

    return e;
}

template <typename E, typename C>		// remove minimum
E HeapPriorityQueue<E,C>::removeMin() 
{
    Position p;
    if (size() == 1)				// only one node?
        p = T.removeLast();				// ...remove it
    else 
    {
        Position u = T.root();			// root position
        T.swap(u, T.last());			// swap last with root
        p = T.removeLast();				    // ...and remove last
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

    return *p;
}

#endif