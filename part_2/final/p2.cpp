/*  Program: Lab_Final_2
    Author: Nero Li
    Class: CSCI 230   
    Date: 06/09/2022	     
    Description: 
        Given three sorted arrays/vectors of integers with lengths k, m, and n, provide the code to
        perform a three-way merge to merge them into one sorted array/vector in O(k + m + n).
        Here is one test case to try:

        • Array/Vector 1 – 5, 9, 12
        • Array/Vector 2 – 1, 4, 10, 16, 25
        • Array/Vector 3 – 2, 5, 8, 21

        Result:

        • Array/Vector 4 – 1, 2, 4, 5, 5, 8, 9, 10, 12, 16, 21, 25

        New requirements:

        •	Given three unsorted arrays/vectors of names (strings)
        •	Still need to merge three sorted arrays/vectors into one sorted array/vector in O(k + m 
            + n); do not combine the 3 unsorted list and sort it

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50000

using namespace std;

string maxString()
{
    string str;
    for (int i = 0; i < MAX; ++i)
        str.push_back('~');
    
    return str;
}

void printVec(vector<string> vec)
{
    vector<string>::iterator itr = vec.begin();
    cout << "\"" << *itr << "\"";
    ++itr;
    while (itr != vec.end())
    {
        cout << ", \"" << *itr << "\"";
        ++itr;
    }
        
    cout << endl;
}

vector<string> func(vector<string> v1, vector<string> v2, vector<string> v3)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    
    vector<string> v4;
    vector<string>::iterator itr1 = v1.begin();
    vector<string>::iterator itr2 = v2.begin();
    vector<string>::iterator itr3 = v3.begin();

    while (itr1 != v1.end() || itr2 != v2.end() || itr3 != v3.end())
    {
        int minIndex = 0;
        string cur[4];

        cur[0] = maxString();

        if (itr1 == v1.end())
            cur[1] = maxString();
        else
            cur[1] = *itr1;
        
        if (itr2 == v2.end())
            cur[2] = maxString();
        else
            cur[2] = *itr2;

        if (itr3 == v3.end())
            cur[3] = maxString();
        else
            cur[3] = *itr3;

        for (int i = 1; i < 4; ++i)
            if (cur[i] < cur[minIndex])
                minIndex = i;

        if (minIndex == 0)
            break;
        else
            v4.push_back(cur[minIndex]);

        switch (minIndex)
        {
        case 1:
            ++itr1;
            break;

        case 2:
            ++itr2;
            break;

        case 3:
            ++itr3;
            break;
        
        default:
            break;
        }
    }

    return v4;
}

int main()
{
    vector<string> v1 = {"Adam", "Kim", "William", "Bill"};
    vector<string> v2 = {"Bob", "Joann", "Jane", "John", "Tim"};
    vector<string> v3 = {"Michelle", "Candace", "Daniel", "Eric", "Tanya"};
    vector<string> v4 = func(v1, v2, v3);

    cout << "\tArray/Vector 1 - ";
    printVec(v1);
    cout << "\tArray/Vector 2 - ";
    printVec(v2);
    cout << "\tArray/Vector 3 - ";
    printVec(v3);
    cout << "Result:\n";
    cout << "\tArray/Vector 4 - ";
    printVec(v4);
    cout << endl;

    cout << "Author: Nero Li\n";
    return 0;
}