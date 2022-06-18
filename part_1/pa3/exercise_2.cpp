/*  Program: PA_3_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/09/2021	     
    Description: 
        Provide a linked list implementation to maintain a 
        list of names. The following operations are 
        available: insert rear, insert front, remove 
        a particular element, and print the whole list.        

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

struct Node
{
    string str;
    Node *next = NULL;
};

Node *head{NULL};

void insertRear(string name)
{
    Node *cur{head};
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new Node;
    cur->next->str = name;
    cur->next->next = NULL;
}

void insertFront(string name)
{
    Node *cur = new Node;
    cur->str = name;
    cur->next = head;
    head = cur;
}

void removeItem(string name)
{
    Node *cur{head};
    if (cur->str == name)
    {
        head = cur->next;
        delete cur;
        return;
    }
    
    while (cur->next != NULL)
    {
        if (cur->next->str == name)
        {
            Node *old = cur->next;
            cur->next = old->next;
            delete old;
            return;
        }
        cur = cur->next;
    }
}

void print()
{
    Node *cur{head};
    while (cur != NULL)
    {
        cout << cur->str << ' ';
        cur = cur->next;
    }
    cout << endl;
}

int main() 
{
    insertFront("Jo"); 
    insertFront("Jane");
    insertRear("John");
    insertRear("Kim");
    removeItem("Jo");
    print(); 
    cout << "Author: Nero Li\n";
    return 0;
}