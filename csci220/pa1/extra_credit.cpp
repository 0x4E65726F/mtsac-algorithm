/*  Program: PA_1_extra_credit  
    Author: Nero Li
    Class: CSCI 220   
    Date: 08/24/2021	     
    Description: 
        Write an efficient C++ function that takes 
        any integer value i and returns 2^i, as a 
        long value. Your function should not multiply 
        2 by itself i times; there are much faster ways 
        of computing 2^i.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

long func(long i)
{
    return 1 << i;
}

int main()
{  
    cout << "Final answer for 2^3 is " << func(3) << endl;
    cout << "Final answer for 2^20 is " << func(20) << endl;
    cout << "Author: Nero Li\n";

	return 0;
}
