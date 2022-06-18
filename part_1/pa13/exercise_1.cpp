/*  Program: PA_13_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 11/30/2021	     
    Description: 
        Put together heap priority queue and use a test driver to perform 
        some operations to confirm it is working correctly. You can use a 
        PQ with integer as element. Create two PQ objects – one with largest 
        value having highest priority and one with lowest value having 
        highest priority. Be sure to use a comparator for the PQ.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include "HeapPriorityQueue.h"

using namespace std;

template <typename E>
class isLess 
{
public:
    bool operator()(const E& p, const E& q) const
    { 
        return p < q; 
    }
};

template <typename E>
class isMore 
{
public:
    bool operator()(const E& p, const E& q) const
    { 
        return p > q; 
    }
};

int main()
{
    HeapPriorityQueue<int, isLess<int>> test1;
    HeapPriorityQueue<int, isMore<int>> test2;

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
    test1.removeMin();
    cout << endl;

    test2.insert(5);
    test2.insert(4);
    test2.insert(7);
    test2.insert(1);
    cout << test2.min() << ' ';
    test2.removeMin();
    test2.insert(3);
    test2.insert(6);
    cout << test2.min() << ' ';
    test2.removeMin();
    cout << test2.min() << ' ';
    test2.removeMin();
    test2.insert(8);
    cout << test2.min() << ' ';
    test2.removeMin();
    test2.insert(2);
    cout << test2.min() << ' ';
    test2.removeMin();
    cout << test2.min() << ' ';
    test2.removeMin();
    cout << endl;

    cout << "Modified by: Nero Li\n";
    return 0;
}