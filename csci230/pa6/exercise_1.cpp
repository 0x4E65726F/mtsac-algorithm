/*  Program: PA_6_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/12/2022 	     
    Description: 
        Use classes Merge, UnionMerge, IntersectMerge, and SubtractMerge 
        from C++ book to perform basic set operations. Set up a driver 
        to test the three set operations: union, intersection, and 
        difference. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "Merge.h"

using namespace std;

void test()
{
    list<int> a = {1, 2, 3, 5, 7, 9};   // 1 2 3   5   7   9
    list<int> b = {1, 3, 4, 5, 6, 8};   // 1   3 4 5 6   8
    list<int> result;

    UnionMerge<int> test1;
    test1.merge(a, b, result);
    for (int i : result)
        cout << i << ' ';
    cout << endl;

    result.clear();
    IntersectMerge<int> test2;
    test2.merge(a, b, result);
    for (int i : result)
        cout << i << ' ';
    cout << endl;

    result.clear();
    SubtractMerge<int> test3;
    test3.merge(a, b, result);
    for (int i : result)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    test();

    cout << "Modified by: Nero Li\n";

    return 0;
}
