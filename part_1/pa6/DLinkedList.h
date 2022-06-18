// Set up for CSCI 220 Fall 21 by T. Vo
// Code from book with a fix for add() operation
// Added print() operation for debugging
#pragma once

#include <string>
#include <iostream>

using namespace std;

typedef string Elem;				// list element type
class DNode {					    // doubly linked list node
private:
    Elem elem;					    // node element value
    DNode* prev;				    // previous node in list
    DNode* next;				    // next node in list
    friend class DLinkedList;		// allow DLinkedList access
};

class DLinkedList {				    // doubly linked list
public:
    DLinkedList();				    // constructor
    ~DLinkedList();				    // destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;		// get front element
    const Elem& back() const;		// get back element
    void addFront(const Elem& e);	// add to front of list
    void addBack(const Elem& e);	// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
    void print() const;             // debugging only by T. Vo
private:					        // local type definitions
    DNode* header;				    // list sentinels
    DNode* trailer;
protected:					        // local utilities
    void add(DNode* v, const Elem& e);		// insert new node before v
    void remove(DNode* v);			// remove node v
};

DLinkedList::DLinkedList() {	    // constructor
    header = new DNode;				// create sentinels
    trailer = new DNode;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}

bool DLinkedList::empty() const		// is list empty?
{
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const	// get front element
{
    return header->next->elem;
}

const Elem& DLinkedList::back() const	// get back element
{
    return trailer->prev->elem;
}

DLinkedList::~DLinkedList() {			// destructor
    while (!empty()) removeFront();		// remove all but sentinels
    delete header;				        // remove the sentinels
    delete trailer;
}

// insert new node before v
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;  u->elem = e;	// create a new node for e
    u->next = v;				        // link u in between v
    u->prev = v->prev;				    // ...and v->prev
//    v->prev->next = v->prev = u;      // a bug!!!
    v->prev->next = u;                  // fixed by T. Vo
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e)	// add to front of list
{
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e)	// add to back of list
{
    add(trailer, e);
}

void DLinkedList::remove(DNode* v) {	// remove node v
    DNode* u = v->prev;				    // predecessor
    DNode* w = v->next;				    // successor
    u->next = w;				        // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront()		    // remove from font
{
    remove(header->next);
}

void DLinkedList::removeBack()		    // remove from back
{
    remove(trailer->prev);
}


void DLinkedList::print() const         // debugging only by T. Vo
{
    DNode* cur = header->next;
    cout << "list: ";
    while (cur != trailer)
    {
        cout << cur->elem << "  ";
        cur = cur->next;
    }
    cout << endl;
}