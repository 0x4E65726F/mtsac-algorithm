/*  Program: PA_3_extra_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/09/2021	     
    Description: 
        Add recPrint() operation to exercise 1 to print 
        the list using a recursive function/method.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

string arr[10];
size_t count{0};

void insertRear(string name)
{
    arr[count++] = name;
}

void insertFront(string name)
{
    ++count;
    for (size_t i = 1; i < count; ++i) 
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = name;
}

void removeItem(string name)
{
    for (size_t i = 0; i < count; ++i) 
    {
        if (arr[i] == name)
        {
            for (size_t j = i; j < count; ++j) 
            {
                arr[j] = arr[j + 1];
            }
            --count;
            return;
        }
        
    }
}

void print()
{
    for (size_t i = 0; i < count; ++i) 
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void recPrint(string arr[], size_t i)
{
    if (i != 0)
    {
        recPrint(arr, i - 1);
    }
    
    cout << arr[i] << ' ';
    
    if (i == count)
    {
        cout << endl;
    }
}

int main() 
{
    insertFront("Jo"); 
    insertFront("Jane");
    insertRear("John");
    insertRear("Kim");
    removeItem("Jo");
    recPrint(arr, count);
    //print(); 
    cout << "Author: Nero Li\n";
    return 0;
}