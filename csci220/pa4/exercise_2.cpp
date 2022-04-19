/*  Program: PA_4_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/21/2021	     
    Description: 
        Perform max sum problem.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

long long maxSum(long long x[], long long n)
{
    long long max{0};

    for (long long i = 0; i < n; ++i) 
    {
        long long cur{x[i]};
        
        for (long long j = i + 1; j < n; ++j) 
        {
            cur += x[j];
            if (cur > max)
            {
                max = cur;
            }
        }
    }

    return max;
}

void runningTimeCheck(int n)
{
    long long x[100000];

    srand(time(NULL));
    for (size_t i = 0; i < n; ++i) 
    {
        x[i] = rand() % 20001 - 10000;
    }

    auto start = chrono::high_resolution_clock::now();
    maxSum(x, n);
    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << endl;
}

int main()
{
    /* function check */
    long long x[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    cout << maxSum(x, 10) << endl;

    /* running time check */
    runningTimeCheck(100);
    runningTimeCheck(1000);
    runningTimeCheck(10000);
    runningTimeCheck(100000);
    
    cout << "Author: Nero Li\n";
    return 0;
}
