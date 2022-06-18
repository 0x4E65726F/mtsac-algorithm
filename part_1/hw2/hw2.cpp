#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>
#include <vector>
#include <list>

using namespace std;
/*
typedef int Elem;                                               // list base element type
class NodeList                                                  // node-based list
{
private:
    struct Node                                                 // a node of the list
    { 
        Elem elem;                                              // element value
        Node* prev;                                             // previous in list
        Node* next;                                             // next in list
    };

public:
    class Iterator                                              // an iterator for the list
    {
    public:
        Elem& operator*();                                      // reference to the element
        bool operator==(const Iterator& p) const;               // compare positions
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();                                 // move to next position
        Iterator& operator--();                                 // move to previous position
        friend class NodeList;                                  // give NodeList access
    private:
        Node* v;                                                // pointer to the node
        Iterator(Node* u);                                      // create from node
    };

public:
    NodeList();                                                 // default constructor
    int size() const;                                           // list size
    bool empty() const;                                         // is the list empty?
    Iterator begin() const;                                     // beginning position
    Iterator end() const;                                       // (just beyond) last position
    void insertFront(const Elem& e);                            // insert at front
    void insertBack(const Elem& e);                             // insert at rear
    void insert(const Iterator& p, const Elem& e);              // insert e before p
    void eraseFront();                                          // remove first
    void eraseBack();                                           // remove last
    void erase(const Iterator& p);                              // remove p

private:                                                        // data members
    int n;                                                      // number of items
    Node* header;                                               // head-of-list sentinel
    Node* trailer;                                              // tail-of-list sentinel
};

class NodeSequence : public NodeList {
public:
    void print();
    Iterator atIndex(int i);
    int indexOf(Elem n);
};

NodeList::Iterator::Iterator(Node* u)                           // constructor from Node*
{ v = u; }

Elem& NodeList::Iterator::operator*()                           // reference to the element
{ return v->elem; }

bool NodeList::Iterator::operator==(const Iterator& p) const    // compare positions
{ return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator& p) const    // compare positions
{ return v != p.v; }

NodeList::Iterator& NodeList::Iterator::operator++()            // move to next position
{ v = v->next; return *this; }

NodeList::Iterator& NodeList::Iterator::operator--()            // move to previous position
{ v = v->prev; return *this; }

NodeList::NodeList()                                            // constructor
{ 
    n = 0;                                                      // initially empty
    header = new Node;                                          // create sentinels
    trailer = new Node;
    header->next = trailer;                                     // have them point to each other
    trailer->prev = header;
}

int NodeList::size() const                                      // list size
{ return n; }

bool NodeList::empty() const                                    // is the list empty?
{ return (n == 0); }

NodeList::Iterator NodeList::begin() const                      // begin position is first item
{ return Iterator(header->next); }

NodeList::Iterator NodeList::end() const                        // end position is just beyond last
{ return Iterator(trailer); }

void NodeList::insert(const Iterator& p, const Elem& e) 
{
    Node* w = p.v;                                              // p’s node
    Node* u = w->prev;                                          // p’s predecessor
    Node* v = new Node;                                         // new node to insert
    v->elem = e;
    v->next = w; w->prev = v;                                   // link in v before w
    v->prev = u; u->next = v;                                   // link in v after u
    n++;
}

void NodeList::insertFront(const Elem& e)                       // insert at front
{ insert(begin(), e); }

void NodeList::insertBack(const Elem& e)                        // insert at rear
{ insert(end(), e); }

void NodeList::erase(const Iterator& p)                         // remove p
{
    Node* v = p.v;                                              // node to remove
    Node* w = v->next;                                          // successor
    Node* u = v->prev;                                          // predecessor
    u->next = w; w->prev = u;                                   // unlink p
    delete v;                                                   // delete this node
    n--;                                                        // one fewer element
}

void NodeList::eraseFront()                                     // remove first
{ erase(begin()); }

void NodeList::eraseBack()                                      // remove last
{ erase(--end()); }

void NodeSequence::print()
{
    Iterator cur{begin()};
    while (cur != end())
    {
        cout << *cur << ' ';
        ++cur;
    }
    cout << endl;
}

NodeSequence::Iterator NodeSequence::atIndex(int i) 
{
    Iterator cur{begin()};
    while (i--)
    {
        ++cur;
    }
    return cur;
}

int NodeSequence::indexOf(Elem n) 
{
    Iterator cur{begin()};
    int i = 0;
    while (*cur != n) 
    {
        ++cur; 
        ++i;
    }
    return i;
}

// R-6.3
void func(int arr[], int size, int d)
{
    for (int i = 0; i < d; ++i)
    {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; --j)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
}

// R-6.18
bool findNum(NodeSequence S, int n, int k)
{
    --n;
    if (n == 0 && S.indexOf(n) != k)
    {
        return false;
    }
    else if (S.indexOf(n) == k)
    {
        return true;
    }
    else
    {
        return findNum(S, n, k);
    }
}

// C-7.7
struct Tree
{
    char elem;
    Tree *parent;
    list<Tree*> child;
};

void indentedParentheticRepresentation(Tree *root, int t)
{
    Tree *cur = root;
    list<Tree*> curChild = cur->child;
    
    for (int i = 1; i < t; ++i)
    {
        cout << '\t';
    }
    cout << cur->elem;

    if (curChild.empty())
    {
        cout << endl;
        return;
    }
    
    cout << " (" << endl;

    while (!curChild.empty())
    {
        indentedParentheticRepresentation(curChild.front(), t + 1);
        curChild.pop_front();
    }
    
    for (int i = 1; i < t; ++i)
    {
        cout << '\t';
    }
    cout << ')' << endl;
}

// C-6.13

vector<int> vec;
const int n{10};

int randomInteger(int n)
{
    return rand() % n;
}

void randomDeck()
{
    for (int i = 0; i < n; ++i) 
    {
        int j{randomInteger(n)};
        int t;
        t = vec[i];
        vec[i] = vec[j];
        vec[j] = t;
    }
}
*/
struct Tree
{
    char elem;
};

void levelOrder(Tree *tree[], int n)
{
    queue<int> que;
    int cur;

    que.push(0);
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        cout << tree[cur] << ' ';
        if (tree[2 * cur])
        {
            que.push(2 * cur);
        }
        if (tree[2 * cur + 1])
        {
            que.push(2 * cur + 1);
        }
    }
    
    cout << endl;
}

int main()
{
    

    return 0;
}