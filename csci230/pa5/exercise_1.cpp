/*  Program: PA_5_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/05/2022	     
    Description: 
        Modify selection sort to find the kth smallest element (do 
        not sort the whole list).  Output both kth smallest element 
        and number of compares.  Test it with a small file with a few 
        integers first like n = 10 (try k = 1, k = n/2, and k = n) and 
        then try it to find the medians (k = n/2) of the two data 
        files from previous PA, small1k.txt and large100k.txt.   

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int selectionSort(vector<int> vec, int k)
{
    for (int i = 0; i < k; ++i) 
    {
        int min = i;
        for (int j = i; j < vec.size(); ++j)
            if (vec[min] > vec[j])
                min = j;

        if (min != i)
            swap(vec[i], vec[min]);        
    }

    return vec[k - 1];
}

void smallTest()
{
    vector<int> vec = {5, 1, 9, 6, 4, 7, 8, 3, 0, 2};
    int k;

    cout << "For n = 10 test array:\n";

    k = 1;
    cout << "vec[" << k - 1 << "] = " << selectionSort(vec, k) << endl;

    k = vec.size() / 2;
    cout << "vec[" << k - 1 << "] = " << selectionSort(vec, k) << endl;

    k = vec.size();
    cout << "vec[" << k - 1 << "] = " << selectionSort(vec, k) << endl << endl;
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

    k = vec.size() / 2;
    cout << "vec[" << k - 1 << "] = " << selectionSort(vec, k) << endl << endl;
}

int main()
{
    smallTest();
    test("small1k.txt");
    test("large100k.txt");

    cout << "Author: Nero Li\n";

    return 0;
}
