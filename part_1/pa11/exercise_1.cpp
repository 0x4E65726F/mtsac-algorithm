/*  Program: PA_11_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 11/16/2021	     
    Description: 
        Use AVLTree class in C++ book (modified by me and provided here) 
        and set up a test driver to perform some operations such as insert, 
        erase, and find. Perform the operations in question 1 below (steps 
        1 to 7) and then search for 15, 30, and 8. Print the BST as the final 
        step. Assume that key is an integer and value is a string such as a 
        name (come up with your own names).
    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include "Entry.h"
#include "AVLEntry.h"
#include "AVLTree1.h"

using namespace std;

void findKey(int key,AVLTree<AVLEntry<Entry<int, char>>> test, AVLTree<AVLEntry<Entry<int, char>>>::Iterator itr)
{
    itr = test.find(key);
    if (!(itr == test.end()))
    {
        cout << (*itr).key() << ": " << (*itr).value() << ',' << (*itr).getHeight() << endl;
    }
}

int main()
{
    AVLTree<AVLEntry<Entry<int, char>>> test;
    AVLTree<AVLEntry<Entry<int, char>>>::Iterator itr{NULL};

    test.insert(10, 'a');
    test.insert(20, 'b');
    test.insert(4, 'c');
    test.insert(8, 'd');
    test.insert(15, 'e');
    test.erase(8);
    test.erase(10);

    findKey(15, test, itr);
    findKey(30, test, itr);
    findKey(8, test, itr);

    itr = test.begin();
    while (!(itr == test.end()))
    {
        cout << (*itr).key() << ' ';
        ++itr;
    }
    cout << endl;

    cout << "Modified by: Nero Li\n";
    return 0;
}