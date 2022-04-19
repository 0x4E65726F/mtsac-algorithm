#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>
#include <vector>
#include <list>

using namespace std;

template <typename E, typename C>
class ListPriorityQueue
{
public:
    int size() const;				// number of elements
    bool empty() const;				// is the queue empty?
    void insert(const E& e);		// insert element
    const E& min() const;			// minimum element
    void removeMin();				// remove minimum
private:
    std::list<E> L;				    // priority queue contents
    C isLess;					    // less-than comparator
};



template <typename E>
class Stack
{
private:
    struct Stuff
    {
        int key;
        E value;
    };

    class isLess
    {
    public:
        bool operator()(Stuff p, Stuff q) const
        { 
            return p.key < q.key; 
        }
    };
    
    ListPriorityQueue<Stuff, isLess> pq;
    int key;
public:
    void push(E n)
    {
        Stuff newStuff;
        newStuff.key = key++;
        newStuff.value = n--;
        pq.insert(newStuff);
    }

    E pop()
    {
        E elem;
        elem = pq.min().value;
        pq.removeMin();
        ++n;
        return elem;
    }
};

int main()
{
    

    return 0;
}