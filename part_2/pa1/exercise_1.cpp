/*  Program: PA_1_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 02/15/2022	     
    Description: 
        Use C++ STL unordered_map or Java HashMap to store the following 
        integer keys: 13 21 5 37 15 (reverse the key and use it as a 
        string for the value part so first entry would be <13, "31">). 
        Perform the following operations to make sure it is working 
        properly: search for 10 and 21, remove 20, 37, and then search 
        for 37.

        Input data file small1k.txt, containing a list of 1,000 integer 
        values, to an array and then insert all the pairs <int, reverse 
        key as string> to a new hash map. Collect the time it took to 
        insert 1,000 pairs of values to the hash map and output the time 
        to the screen.

        Input data file large100k.txt, containing a list of 100,000 
        integer values, to an array and then insert all the pairs 
        <int, reverse key as string> to another new hash map. Collect the 
        time it took to insert 100,000 pairs of values to the hash map 
        and output the time to the screen.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;

string changeIntToString(int n)
{
    string s{"\0"};

    while (n > 0)
    {
        s += '0' + n % 10;
        n /= 10;
    }

    return s;
}

void printResult(unordered_map<int, string> m, int n)
{
    if (m.find(n) == m.end())
        cout << "N/A\n";  
    else
        cout << "(" << m.find(n)->first << "," << m.find(n)->second << ")\n";
}

void test()
{
    unordered_map<int, string> m;
    int A[] = {13, 21, 5, 37, 15};

    for (int a : A)
        m[a] = changeIntToString(a);

    printResult(m, 10);
    printResult(m, 21);
    m.erase(20);
    m.erase(37);
    printResult(m, 37);
}

void func(string str)
{
    ifstream fin;
    unordered_map<int, string> m;
    vector<int> v;

    fin.open(str, ios::binary);

    if (!fin)
        return;

    while (!fin.eof())
    {
        int n;
        fin >> n;
        v.push_back(n);
    }

    auto start = chrono::high_resolution_clock::now();

    for (int a : v)
    {
        m[a] = changeIntToString(a);
    }

    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;
}

int main()
{
    test();
    func("small1k.txt");
    func("large100k.txt");    

    cout << "Author: Nero Li\n";

    return 0;
}
