/*  Program: PA_5_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/05/2022	     
    Description: 
        Implement the randomized quick select algorithm to find kth 
        smallest element as discussed in lecture/book.  Output both kth 
        smallest element and number of compares.  Test it with a small 
        file with a few integers first like n = 10 (try k = 1, k = n/2, 
        and k = n) and then try it to find the medians (k = n/2) of the 
        two data files from previous PA, small1k.txt and large100k.txt.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

int depth;

int quickSelect(vector<int> S, int k, int deep = 0)
{
    if (deep > depth)
        depth = deep;
    
    if (S.size() == 1)
        return S[0];

    int pivot = rand() % S.size();
    
    vector<int> L;
    vector<int> E;
    vector<int> G;

    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] < S[pivot])
            L.push_back(S[i]);
        else if (S[i] == S[pivot])
            E.push_back(S[i]);
        else
            G.push_back(S[i]);
    }

    if (k <= L.size())
        return quickSelect(L, k, deep + 1);
    else if (k <= (L.size() + E.size()))
        return S[pivot];
    else
        return quickSelect(G, k - L.size() - E.size(), deep + 1);
}

void smallTest()
{
    vector<int> vec = {5, 1, 9, 6, 4, 7, 8, 3, 0, 2};
    int k;

    cout << "For n = 10 test array:\n";

    k = 1;
    depth = 0;
    cout << "vec[" << k - 1 << "] = " << quickSelect(vec, k) << endl;
    cout << "Depth: " << depth << endl << endl;

    k = vec.size() / 2;
    depth = 0;
    cout << "vec[" << k - 1 << "] = " << quickSelect(vec, k) << endl;
    cout << "Depth: " << depth << endl << endl;

    k = vec.size();
    depth = 0;
    cout << "vec[" << k - 1 << "] = " << quickSelect(vec, k) << endl;
    cout << "Depth: " << depth << endl << endl;
}

void test(string str)
{
    vector<int> vec;
    ifstream fin;
    int k;

    fin.open(str, ios::binary);

    if(!fin)
        return;
    else
        cout << "For \"" << str << "\":\n";

    while (!fin.eof())
    {
        int n;

        fin >> n;
        vec.push_back(n);
    }

    depth = 0;
    k = vec.size() / 2;
    auto start = chrono::high_resolution_clock::now();
    cout << "vec[" << k - 1 << "] = " << quickSelect(vec, k) << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Depth: " << depth << endl;
    cout << "Time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl << endl;
}

int main()
{
    srand(time(NULL));

    smallTest();
    test("small1k.txt");
    test("large100k.txt");

    cout << "Author: Nero Li\n";

    return 0;
}
