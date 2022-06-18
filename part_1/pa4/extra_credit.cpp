/*  Program: PA_4_extra_credit  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/21/2021	     
    Description: 
        Perform P-4.1 from C++ textbook.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

long long *prefixAverages1(int x[], int n)
{
    long long A[100000];

    for (int i = 0; i < n; ++i)
    {
        long long a = 0;
        for (int j = 0; j <= i; ++j) 
        {
            a += x[j];
        }
        A[i] = a / (i + 1);
    }
    
    long long *p = A;
    return p;
}

long long *prefixAverages2(int x[], int n)
{
    long long A[100000];
    long long s{0};

    for (int i = 0; i < n; ++i) 
    {
        s += x[i];
        A[i] = s / (i + 1);
    }

    long long *p = A;
    return p;
}

void runningTimeCheck(int n)
{
    int x[100000];

    srand(time(NULL));
    for (size_t i = 0; i < n; ++i) 
    {
        x[i] = rand() % 20001 - 10000;
    }

    auto start1 = chrono::high_resolution_clock::now();
    prefixAverages1(x, n);
    auto end1 = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() * (double)1e-6) << " ms" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    prefixAverages2(x, n);
    auto end2 = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() * (double)1e-6) << " ms" << endl;
}

int main()
{
    long long *p;
    int test[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    int n{10};

    /* function check */
    p = prefixAverages1(test, n);
    for (int i = 0; i < n; ++i) 
    {
        cout << *(p + i) << ' ';
    }
    cout << endl;
    p = prefixAverages2(test, n);
    for (int i = 0; i < n; ++i) 
    {
        cout << *(p + i) << ' ';
    }
    cout << endl;

    /* running time check */
    runningTimeCheck(100);
    runningTimeCheck(1000);
    runningTimeCheck(10000);
    runningTimeCheck(100000);

    cout << "Author: Nero Li\n";
    return 0;
}