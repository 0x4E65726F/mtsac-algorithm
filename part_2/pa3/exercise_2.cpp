/*  Program: PA_2_exercise_2
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/15/2022	     
    Description: 
        Implement/use Merge Sort from the book and test it on a small 
        list of 10 random integer values first. Collect data regarding 
        number of key comparisons and data moves for a small list of 10 
        integer values. You must try a sorted list, a descending list,
        and a random list. In addition, collect data for a random list 
        of 100 values.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

vector<int> generateVector(int n, int choice)
{
    vector<int> vec;
    
    for (int i = 0; i < n; ++i)
    {
        switch (choice)
        {
            case 0:
                vec.push_back(i);
                break;
            case 1:
                vec.push_back(n - 1 - i);
                break;
            default:
                vec.push_back(rand() % n);
                break;  
        }
    }
    
    return vec;
}

void printVector(vector<int> vec)
{
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}

void merge(vector<int> &vec, long long &comparisons, long long &dataMoves, vector<int> a, vector<int> b)
{
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        ++comparisons;
        if (a[i] < b[j])
            vec.push_back(a[i++]);
        else
        {
            ++dataMoves;
            vec.push_back(b[j++]);
        }
    }

    while (i < a.size() || j < b.size())
    {
        if (i < a.size())
            vec.push_back(a[i++]);
        else
            vec.push_back(b[j++]);
    }
}

void mergeSort(vector<int> &vec, long long &comparisons, long long &dataMoves)
{
    if (vec.size() <= 1)
        return;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (i < vec.size() / 2)
            a.push_back(vec[i]);
        else
            b.push_back(vec[i]);
    }

    mergeSort(a, comparisons, dataMoves);
    mergeSort(b, comparisons, dataMoves);
    vec.clear();
    merge(vec, comparisons, dataMoves, a, b);
}

void test(string str, int n, int choice, bool checkTime, bool printVec)
{
    vector<int> vec = generateVector(n, choice);
    long long comparisons = 0;
    long long dataMoves = 0;

    cout << str << ":\n";
    
    if (printVec)
        printVector(vec);

    auto start = chrono::high_resolution_clock::now();
    mergeSort(vec, comparisons, dataMoves);
    auto end = chrono::high_resolution_clock::now();

    if (printVec)
        printVector(vec);

    cout << "Comparisons:\t" << comparisons << endl;
    cout << "Data moves:\t" << dataMoves << endl;
    if (checkTime)
        cout << "Time used:\t" << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;

    cout << endl;
}

int main() 
{
    srand(time(NULL));

    test("Sorted list", 10, 0, false, true);
    test("Descending list", 10, 1, false, true);
    test("Random list", 10, 2, false, true);
    test("Large random list", 100, 2, false, false);

    test("1000 random list", 1000, 2, true, false);
    test("10000 random list", 10000, 2, true, false);
    test("100000 random list", 100000, 2, true, false);

    cout << "Author: Nero Li\n";

    return 0;    
}