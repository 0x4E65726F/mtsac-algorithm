/*  Program: PA_4_extra_credit  
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/22/2022     
    Description: 
        Perform exercise 2 and collect data for either merge sort, heap
        sort, or Shell sort (pick one).

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

class compForIntKey
{
public:
    bool operator()(pair<int, string> a, pair<int, string> b) const
    {
        return a.first < b.first;
    }
};

class compForStrKey
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b) const
    {
        return a.first < b.first;
    }
};

template <typename K, typename V, typename C>
void merge(vector<pair<K, V>> &vec, vector<pair<K, V>> a, vector<pair<K, V>> b, const C &compare, long long &comparisons, long long &dataMoves)
{
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        ++comparisons;
        ++dataMoves;
        if (compare(a[i], b[j]))
            vec.push_back(a[i++]);
        else 
            vec.push_back(b[j++]);
    }

    while (i < a.size() || j < b.size())
    {
        ++dataMoves;
        if (i < a.size())
            vec.push_back(a[i++]);
        else
            vec.push_back(b[j++]);
    }
}

template <typename K, typename V, typename C>
void mergeSort(vector<pair<K, V>> &vec, const C &compare, long long &comparisons, long long &dataMoves)
{
    if (vec.size() <= 1)
        return;

    vector<pair<K, V>> a;
    vector<pair<K, V>> b;

    for (int i = 0; i < vec.size(); ++i)
    {
        ++dataMoves;
        if (i < vec.size() / 2)
            a.push_back(vec[i]);
        else
            b.push_back(vec[i]);
    }

    mergeSort<K, V, C>(a, compare, comparisons, dataMoves);
    mergeSort<K, V, C>(b, compare, comparisons, dataMoves);
    vec.clear();
    merge<K, V, C>(vec, a, b, compare, comparisons, dataMoves);
}

void testIntKey(string str)
{
    vector<pair<int, string>> vec;
    ifstream fin;
    fin.open(str, ios::binary);

    if(!fin)
        return;
    else
        cout << "For \"" << str << "\":\n";

    while (!fin.eof())
    {
        pair<int, string> newPair;
        int n;

        fin >> n;
        newPair.first = n;
        newPair.second = to_string(n);
        vec.push_back(newPair);
    }

    cout << "- Number of Values:\t\t" << vec.size() << endl;
    cout << "- Key Data Type:\t\tInteger\n";
    long long comparisons = 0;
    long long dataMoves = 0;
    compForIntKey compare;

    auto start = chrono::high_resolution_clock::now();
    mergeSort<int, string, compForIntKey>(vec, compare, comparisons, dataMoves);
    auto end = chrono::high_resolution_clock::now();
    cout << "- Number of Key Compares:\t" << comparisons << endl;
    cout << "- Number of Data Moves:\t\t" << dataMoves << endl;
    cout << "- Time:\t\t\t\t" << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;

    cout << "- First 5 Entries:\n";
    for(int i = 0; i < 5; ++i)
        cout << "\t<" << vec[i].first << ", \"" << vec[i].second << "\">\n";
    cout << "- Last 5 Entries:\n";
    for(int i = vec.size() - 6; i < vec.size(); ++i)
        cout << "\t<" << vec[i].first << ", \"" << vec[i].second << "\">\n";
    
    cout << endl;
}

void testStrKey(string str)
{
    vector<pair<string, int>> vec;
    ifstream fin;
    fin.open(str, ios::binary);

    if(!fin)
        return;
    else
        cout << "For \"" << str << "\":\n";

    while (!fin.eof())
    {
        pair<string, int> newPair;
        int n;

        fin >> n;
        newPair.second = n;
        newPair.first = to_string(n);
        vec.push_back(newPair);
    }

    cout << "- Number of Values:\t\t" << vec.size() << endl;
    cout << "- Key Data Type:\t\tString\n";
    long long comparisons = 0;
    long long dataMoves = 0;
    compForStrKey compare;

    auto start = chrono::high_resolution_clock::now();
    mergeSort<string, int, compForStrKey>(vec, compare, comparisons, dataMoves);
    auto end = chrono::high_resolution_clock::now();
    cout << "- Number of Key Compares:\t" << comparisons << endl;
    cout << "- Number of Data Moves:\t\t" << dataMoves << endl;
    cout << "- Time:\t\t\t\t" << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;

    cout << "- First 5 Entries:\n";
    for(int i = 0; i < 5; ++i)
        cout << "\t<\"" << vec[i].first << "\", " << vec[i].second << ">\n";
    cout << "- Last 5 Entries:\n";
    for(int i = vec.size() - 6; i < vec.size(); ++i)
        cout << "\t<\"" << vec[i].first << "\", " << vec[i].second << ">\n";
    
    cout << endl;
}

int main()
{
    testIntKey("small1k.txt");
    testStrKey("small1k.txt");
    testIntKey("large100k.txt");
    testStrKey("large100k.txt");

    cout << "Modified by: Nero Li\n";

    return 0;
}
