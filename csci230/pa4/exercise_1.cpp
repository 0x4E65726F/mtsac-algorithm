/*  Program: PA_4_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/22/2022	     
    Description: 
        Implement/use Quick Sort from the book and test it on a small 
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

using namespace std;


void quickSortStep(std::vector<int>& S, int a, int b, long long &comparisons, long long &dataMoves) 
{
    if (a >= b) return;					                                // 0 or 1 left? done
    ++dataMoves;
    int pivot = S[b];					                                // select last as pivot
    int l = a; 						                                    // left edge
    int r = b - 1;					                                    // right edge
    while (l <= r) 
    {
        while (l <= r && pivot >= S[l]) 
        {
            ++comparisons;
            l++;
        }         		
        while (r >= l && S[r] >= pivot)
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
    quickSortStep(S, a, l - 1, comparisons, dataMoves);			        // recur on both sides
    quickSortStep(S, l + 1, b, comparisons, dataMoves);
  }

void quickSort(std::vector<int>& S, long long &comparisons, long long &dataMoves) 
{
    if (S.size() <= 1) return;				                            // already sorted
        quickSortStep(S, 0, S.size() - 1, comparisons, dataMoves);		// call sort utility
}


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
                vec.push_back(rand() % (1000 * n));
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

void test(string str, int n, int choice, bool printVec)
{
    vector<int> vec = generateVector(n, choice);
    long long comparisons = 0;
    long long dataMoves = 0;

    cout << str << ":\n";
    
    if (printVec)
        printVector(vec);

    quickSort(vec, comparisons, dataMoves);

    if (printVec)
        printVector(vec);

    cout << "Comparisons:\t" << comparisons << endl;
    cout << "Data moves:\t" << dataMoves << endl;

    cout << endl;
}


int main()
{
    srand(time(NULL));

    test("Sorted list", 10, 0, true);
    test("Descending list", 10, 1, true);
    test("Random list", 10, 2, true);
    test("Large random list", 100, 2, false);

    cout << "Modified by: Nero Li\n";

    return 0;
}
