/*  Program: PA_1_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 08/24/2021	     
    Description: 
        Write a C++ function or a Java method that 
        takes an array of int values and determines 
        if all the numbers are different from each 
        other (that is they are distinct).Include 
        a driver to test your function/methodwith 
        at least twotest cases:  all values are 
        distinct(5, 7, 2, 6, 4) and two or more 
        values are the same(5, 7, 2, 6, 4, 2).

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

const int SIZE{10000};

bool func(int testArray[SIZE], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        for (int j = i + 1; j < amount; j++)
        {
            if (testArray[i] == testArray[j])
            {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    int testArray[SIZE];
    int amount, i{3};

    while (--i)
    {
        cout << "Input the amount for array: ";
        cin >> amount;
        cout << "Input the integer for array: \n";
        for (int i = 0; i < amount; i++)
        {
            cin >> testArray[i];
        }
        
        if (func(testArray, amount))
        {
            cout << "All values are distinct (" << testArray[0];
        }
        else
        {
            cout << "Two or more values are the same (" << testArray[0];
        }

        for (size_t i = 1; i < amount; i++)
        {
            cout << ", " << testArray[i];
        }
        cout << ")." << endl;
    }
    
    cout << "Author: Nero Li\n";

    return 0;
}
