/*  Program: PA_6_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 10/08/2021	     
    Description: 
        Provide a linked implementation of a deque and name it LinkedDeque (use 
        doubly linked list). It can be a template/generic class, or you can set 
        it up with a certain data type like string. Use a test_1 driver to try out 
        your LinkedDeque by adding and removing values from both ends. Try the 
        following test_1 cases: insert front, insert front, insert rear, remove rear, 
        remove rear, size, and front item.
        
    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <exception>

using namespace std;

class RuntimeException { // generic run-time exception
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

class DequeEmpty : public RuntimeException {
public:
    DequeEmpty(const string& err) : RuntimeException(err) { }
};

template <typename T>
class LinkedDeque
{
public:
    LinkedDeque()
    : head(NULL), tail(NULL), amount(0) {}

    bool empty()
    {
        return ((amount == 0) ? true : false);
    }

    int size()
    {
        return amount;
    }
    
    T front()
    {
        errCheck();
        return head->n;
    }

    T rear()
    {
        errCheck();
        return tail->n;
    }

    void insertFront(T n)
    {
        Node *newNode = new Node;
        newNode->n = n;
        newNode->prev = NULL;
        if (empty())
        {
            newNode->next = NULL;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++amount;
    }

    void insetRear(T n)
    {
        Node *newNode = new Node;
        newNode->n = n;
        newNode->next = NULL;
        if (empty())
        {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++amount;
    }

    T removeFront()
    {
        errCheck();
        T n;
        Node *del = head;
        n = head->n;
        head = head->next;
        delete(del);
        --amount;
        return n;
    }

    T removeRear()
    {
        errCheck();
        T n;
        Node *del = tail;
        n = tail->n;
        tail = tail->prev;
        delete(del);
        --amount;
        return n;
    }

private:
    struct Node
    {
        T n;
        Node *prev;
        Node *next;
    } *head, *tail;
    int amount;

    void errCheck()
    {
        if (amount == 0)
            throw DequeEmpty("No elements in the queue.");
    }
};

int main()
{
    LinkedDeque<string> test_1;
    LinkedDeque<string> test_2;

    test_1.insertFront("Second");
    test_1.insertFront("First");
    test_1.insetRear("Third");
    cout << test_1.removeRear() << endl;
    cout << test_1.removeRear() << endl;
    cout << test_1.size() << endl;
    cout << test_1.front() << endl;
    
    test_2.insetRear("Fourth");
    test_2.insetRear("Fifth");
    test_2.insertFront("Third");
    test_2.insertFront("Second");
    test_2.insertFront("First");
    cout << test_2.size() << endl;
    cout << test_2.removeFront() << endl;
    cout << test_2.removeFront() << endl;
    cout << test_2.removeFront() << endl;
    cout << test_2.removeFront() << endl;
    cout << test_2.rear() << endl;

    cout << "Author: Nero Li\n";
    return 0;
}