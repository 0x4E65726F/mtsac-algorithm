/*  Program: PA_1_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 08/24/2021	     
    Description: 
        The birthday paradox says that the probability 
        that two people in a room will have the same 
        birthday is more than half as long as the number 
        of people in the room (n), is more than 23. This 
        property is not really a paradox, but many people 
        find it surprising. Design a C++ program that can 
        test this paradox by a series of experiments on 
        randomly generated birthdays, which test this 
        paradox for n = 5,10,15,20,...,100. You should run 
        at least 10 experiments for each value of n and it 
        should output, for each n, the number of experiments 
        for that n, such that two people in that test have 
        the same birthday.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool checkDuplicate(int day[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (day[i] == day[j])
            {
                return true;
            }
        }
    }
    
    return false;
}

void func()
{
    int day[100];

    cout << "N" << setw(20) << "Count out of 10" << endl;
    srand(time(NULL));
    for (int n = 5; n <= 100; n += 5)
    {
        int count{0};
        cout << left << setw(3) << n;
        for (int i = 0; i < 10; ++i) 
        {
            for (int p = 0; p < n; ++p) 
            {
                day[p] = rand() % 365;
            }

            if (checkDuplicate(day, n))
            {
                count++;
            }
        }

        cout << setw(9) << " ";
        cout << count << endl;
    }
}

int main()
{
    func();
    
    cout << "Author: Nero Li\n";

	return 0;
}
