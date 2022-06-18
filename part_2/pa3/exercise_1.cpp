/*  Program: PA_3_exercise_1
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/15/2022	     
    Description: 
        Implement Insertion Sort and collect data regarding number of 
        key comparisons and data moves for a small list of 10 integer 
        values. You must try a sorted list, a descending list, and a 
        random list. In addition, collect data for a random list of 100
        values.

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

void insertionSort(vector<int> &vec, long long &comparisons, long long &dataMoves)
{
    
    
    for (int i = 1; i < vec.size(); ++i)
    {
        int cur = vec[i];
        for (int j = 0; j < i; ++j)
        {
            ++comparisons;
            if (vec[i] < vec[j])
            {
                vector<int>::iterator a = vec.begin() + i;
                vector<int>::iterator b = vec.begin() + j;
                vec.erase(a);
                vec.insert(b, cur);
                ++dataMoves;
                break;
            }
        }
    }

    
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
    insertionSort(vec, comparisons, dataMoves);
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