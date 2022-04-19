/*  Program: PA_4_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/21/2021	     
    Description: 
        Implement the linear Fibonacci version based on pseudocode on page 146 of
        the C++ textbook.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

struct fibPair
{
    int a;
    int b;
};

fibPair LinearFibonacci(int k)
{
    fibPair temp;
    int i, j;

    if (k <= 1)
    {
        temp.a = k;
        temp.b = 0;
    }
    else
    {
        temp = LinearFibonacci(k - 1);
        i = temp.a;
        j = temp.b;
        temp.a = i + j;
        temp.b = i;
    }
    
    return temp;
}

int main()
{
    fibPair result;

    for (int i = 10; i > 0; --i) 
    {
        result = LinearFibonacci(i);
        cout << "k = " << i << ": (" << result.a << ", " << result.b << ")\n";
    }

    cout << "Author: Nero Li\n";
    return 0;
}