/*  Program: PA_4_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/22/2022	     
    Description: 
        Download a small data file small1k.txt containing 1,000 values 
        in random order. In addition, download the large data file 
        large100k.txt containing 100,000 values in random order. Sort 
        the two data files using Quick-Sort-3 ("median of three" as 
        pivot so you need to modify quick sort from exercise 1). For 
        each value in the file, you must create a <key, value> pair and 
        then sort a list of <key, value> pairs. You will have to sort 
        two different lists of <integer, string> pairs and <string, 
        integer> pairs. For instance, you need to create <1234, “1234”> 
        pair and <”1234”, 1234> pair for an input value of 1234 from 
        the file. Output all relevant information below for each input 
        data file. There should be 4 sets of output for the two data 
        files.

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
        return a.first >= b.first;
    }
};

class compForStrKey
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b) const
    {
        return a.first >= b.first;
    }
};

template <typename K, typename V, typename C>
void quickSortStep(std::vector<pair<K, V>>& S, int a, int b, const C &compare, long long &comparisons, long long &dataMoves) 
{
    if (a >= b) return;					                                // 0 or 1 left? done
    int l = a; 						                                    // left edge
    int r = b - 1;					                                    // right edge
    // find median of S[a], S[(a + b) / 2], S[b] and move into last spot
    K medOf3[3] = {S[a].first, S[(a + b) / 2].first, S[b].first};
    K result;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (medOf3[i] < medOf3[j])
            {
                K temp = medOf3[j];
                medOf3[j] = medOf3[i];
                medOf3[i] = temp;
            }
        }
    }

    if (S[a].first == result)
    {
        dataMoves += 3;
        std::swap(S[a], S[b]);
    }
    else if (S[(a + b) / 2].first == result)
    {
        dataMoves += 3;
        std::swap(S[(a + b) / 2], S[b]);
    }
    
    ++dataMoves;
    auto pivot = S[b];
    while (l <= r) 
    {
        while (l <= r && compare(pivot, S[l])) 
        {
            ++comparisons;
            l++;
        }         		
        while (r >= l && compare(S[r], pivot))
        {
            ++comparisons;
            r--; 
        }
        if (l < r)
        {
            dataMoves += 3;
            std::swap(S[l], S[r]);
        }					                                    // both elements found   
    }							                                        // until indices cross
    dataMoves += 3;
    std::swap(S[l], S[b]);				                                // store pivot at l
    quickSortStep<K, V, C>(S, a, l - 1, compare, comparisons, dataMoves);			        // recur on both sides
    quickSortStep<K, V, C>(S, l + 1, b, compare, comparisons, dataMoves);
  }

template <typename K, typename V, typename C>
void quickSort(std::vector<pair<K, V>>& S, const C &compare, long long &comparisons, long long &dataMoves) 
{
    if (S.size() <= 1) return;				                            // already sorted
        quickSortStep<K, V, C>(S, 0, S.size() - 1, compare, comparisons, dataMoves);		// call sort utility
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
    quickSort<int, string, compForIntKey>(vec, compare, comparisons, dataMoves);
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
    quickSort<string, int, compForStrKey>(vec, compare, comparisons, dataMoves);
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
