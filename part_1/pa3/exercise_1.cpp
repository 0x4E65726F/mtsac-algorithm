/*  Program: PA_3_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/09/2021	     
    Description: 
        Provide an array implementation to maintain a 
        list of names. The following operations are 
        available: insert rear, insert front, remove 
        a particular element, and print the whole list.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

string arr[10];
size_t n{0};

void insertRear(string name)
{
    arr[n++] = name;
}

void insertFront(string name)
{
    ++n;
    for (size_t i = 1; i < n; ++i) 
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = name;
}

void removeItem(string name)
{
    for (size_t i = 0; i < n; ++i) 
    {
        if (arr[i] == name)
        {
            for (size_t j = i; j < n; ++j) 
            {
                arr[j] = arr[j + 1];
            }
            --n;
            return;
        }
        
    }
}

void print()
{
    for (size_t i = 0; i < n; ++i) 
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() 
{
    insertFront("Jo"); 
    insertFront("Jane");
    insertRear("John");
    insertRear("Kim");
    removeItem("Jo");
    print(); 
    cout << "Author: Nero Li\n";
    return 0;
}