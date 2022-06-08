/*  Program: Lab_Final_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 12/09/2021	     
    Description: 
        Given a large data file of positive integers up to 1 million values, your task is to quickly
        determine if an input value x is in the file and there is also a value y in the file that
        satisfies x + y = t. For the sake of simplicity, we will assume that the values in the file
        are unique. You need to do this look up very efficiently in O(1) so a hash map is needed.
        Design a solution that uses a hash map to solve this problem. Hint: input values and
        store them in a hash map first. Here are two test cases to help you with this problem:
            Input file: large100k.txt from project 2 (unique values from 1 to 100000)

            Input x: 5<Enter>
            Input t: 100<Enter>
            Yes

            Input x: 5<Enter>
            Input t: 10000000<Enter>
            No

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

void func(unordered_set<int> s)
{
    int x;
    int t;

    cout << "Input x: ";
    cin >> x;
    cout << "Input t: ";
    cin >> t;

    int y = t - x;
    
    if (s.find(x) == s.end() || s.find(y) == s.end())
        cout << "No\n" << endl;
    else
        cout << "Yes\n" << endl;

}

int main()
{
    unordered_set<int> s;
    string file = "large100k.txt";

    ifstream fin;
    fin.open(file, ios::binary);

    if (!fin)
    {
        cout << "err\n";
        exit(-1);
    }

    while (!fin.eof())
    {
        int n;
        fin >> n;
        s.insert(n);
    }
    
    func(s);
    func(s);

    cout << "Author: Nero Li\n";
    return 0;
}