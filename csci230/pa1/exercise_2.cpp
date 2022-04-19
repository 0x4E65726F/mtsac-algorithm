/*  Program: PA_1_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 08/24/2021	     
    Description: 
        Put together the C++ HashMap in the book (Chain Hashing; may 
        want to eliminate the third template parameter and add a hash 
        function) or Java ChainHashing (Java book) with N = 11 and test 
        it out with the same data and test cases from above. You might 
        want to come up with all relevant test cases to confirm that C++ 
        HashMap or Java ChainHashing is working correctly.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include "HashMap.h"

using namespace std;

string changeIntToString(int n)
{
    string s{"\0"};

    while (n > 0)
    {
        s += '0' + n % 10;
        n /= 10;
    }

    return s;
}

void printResult(HashMap<int, string> m, int n)
{
    if (m.find(n) == m.end())
        cout << "N/A\n";  
    else
        cout << "(" << (*(m.find(n))).key() << "," << (*(m.find(n))).value() << ")\n";
    
}

void eraseNumber(HashMap<int, string> &m, int n)
{
    try
    {
        m.erase(n);
        cout << "Erased " << n << endl;
    }
    catch(NonexistentElement& e)
    {
        cout << e.getError() << endl; 
    } 
}

void test()
{
    HashMap<int, string> m(11);
    int A[] = {13, 21, 5, 37, 15};

    for (int a : A)
        m.put(a, changeIntToString(a));

    printResult(m, 10);
    printResult(m, 21);
    eraseNumber(m, 20);
    eraseNumber(m, 37);
    printResult(m, 37);
}

void func(string str, int size)
{
    ifstream fin;
    HashMap<int, string> m(size);
    vector<int> v;

    fin.open(str, ios::binary);

    if(!fin)
        return;

    while (!fin.eof())
    {
        int n;
        fin >> n;
        v.push_back(n);
    }

    auto start = chrono::high_resolution_clock::now();

    for (int a : v)
    {
        m.put(a, changeIntToString(a));
    }

    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;
}

int main()
{
    test();
    func("small1k.txt", 2000);
    func("large100k.txt", 200000);    

    cout << "Modified by: Nero Li\n";

    return 0;
}
