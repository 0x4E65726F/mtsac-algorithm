/*  Program: PA_#_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: MM/DD/2022	     
    Description: 
        ----------------------------------------------------------------

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    // code 

    cout << "Author: Nero Li\n";

    return 0;
}
