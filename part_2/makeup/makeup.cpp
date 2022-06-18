/*  Program: Makeup_assignment 
    Author: Nero Li
    Class: CSCI 230   
    Date: 06/02/2022	     
    Description: 
        Given a data file of integer values, write a program to find 
        the total number of inversions. If value i comes before value 
        j in the file and value i is larger than value j then it is an 
        inversion. We need to count all such pairs in the file and 
        output it to the screen.  This count would tell us how closely 
        the file is sorted

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

void merge(vector<int> &vec, vector<int> &a, vector<int> &b, long long &count, bool withOutput)
{
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
        {
            if (withOutput)
                for (int k = i; k < a.size(); ++k)
                    cout << "(" << a[k] << ", " << b[j] << ")\n";
            count += a.size() - i;
            vec.push_back(b[j++]);
        }
        else
            vec.push_back(a[i++]);   
    }

    while (i < a.size() || j < b.size())
    {
        if (i < a.size())
            vec.push_back(a[i++]);
        else
            vec.push_back(b[j++]);
    }
}

void mergeInversion(vector<int> &vec, long long &count, bool withOutput)
{
    if (vec.size() <= 1)
        return;

    vector<int> a;
    vector<int> b;

    int i = vec.size() / 2;
    vector<int>::iterator mid = vec.begin() + i;

    a.assign(vec.begin(), mid);
    b.assign(mid, vec.end());

    mergeInversion(a, count, withOutput);
    mergeInversion(b, count, withOutput);
    vec.clear();
    merge(vec, a, b, count, withOutput);
}

long long simpleInversion(vector<int> vec, bool withOutput = false)
{
    long long count{0};

    for (int i = 0; i < vec.size(); ++i) 
        for (int j = i + 1; j < vec.size(); ++j) 
            if (vec[i] > vec[j])
            {
                if (withOutput)
                    cout << "(" << vec[i] << ", " << vec[j] << ")\n";
                ++count;
            }
    
    return count;
}

void testSimple(string str, bool checkTime = true, bool withOutput = false)
{
    vector<int> vec;
    ifstream fin;
    long long count = 0;
    fin.open(str, ios::binary);

    if (!fin)
    {
        cout << "err\n";
        return;
    }
    
    while (!fin.eof())
    {
        int value;
        fin >> value;
        vec.push_back(value);
    }
    
    cout << "Simple Inversion for " << str << ":\n";

    auto start = chrono::high_resolution_clock::now();
    count = simpleInversion(vec, withOutput);
    auto end = chrono::high_resolution_clock::now();

    cout << "Inversion count: \t" << count << endl;

    if (checkTime)
        cout << "Time used:\t\t" << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;

    cout << endl;
    fin.close();
}

void testMerge(string str, bool checkTime = true, bool withOutput = false)
{
    vector<int> vec;
    ifstream fin;
    long long count = 0;
    fin.open(str, ios::binary);

    if (!fin)
    {
        cout << "err\n";
        return;
    }
    
    while (!fin.eof())
    {
        int value;
        fin >> value;
        vec.push_back(value);
    }
    
    cout << "Merge Inversion for " << str << ":\n";

    auto start = chrono::high_resolution_clock::now();
    mergeInversion(vec, count, withOutput);
    auto end = chrono::high_resolution_clock::now();

    cout << "Inversion count: \t" << count << endl;

    if (checkTime)
        cout << "Time used:\t\t" << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;

    cout << endl;
    fin.close();
}

int main()
{
    testSimple("test.txt", false, true);
    testSimple("small1k.txt");
    testSimple("large100k.txt");

    testMerge("test.txt", false, true);
    testMerge("small1k.txt");
    testMerge("large100k.txt");

    cout << "Author: Nero Li\n";

    return 0;
}
