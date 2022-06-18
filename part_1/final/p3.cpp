/*  Program: Lab_Final_3
    Author: Nero Li
    Class: CSCI 220   
    Date: 12/09/2021	     
    Description: 
        Implement a C++ class template or Java class generic MyArrayList that uses an array to
        include the following operations: insertRear(e), removeFront(), elementAt(i), empty(),
        and cap(). You must set up a dynamic array with room for up to 10 elements and you
        can assume that there is at least one element when removeFront() is called. There is a
        penalty of 5 points if it is not a C++ class template or Java class generic. What is the
        running time for each operation?

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

template <typename T>
class MyArrayList
{
private:
    T *a;
    int cap;
    int amount;

protected:
    // Running Time: O(n) when array need to expand
    void expandArray()
    {
        if (amount >= cap)
        {
            cap *= 2;
            T *b = a;
            a = new T[cap];
            for (int i = 0; i < amount; ++i)
            {
                a[i] = b[i];
            }
            delete [] b;
        }
    }
public:
    MyArrayList()
    {
        cap = 2;
        amount = 0;
        a = new T[cap];
    };

    // Running Time: O(1)
    void insertRear(T e)
    {
        a[amount++] = e;
        expandArray();
    }

    // Running Time: O(n)
    void removeFront()
    {
        for (int i = 0; i < amount; ++i)
        {
            a[i] = a[i + 1];
        }
        --amount;
    }

    // Running Time: O(1)
    T elementAt(int i)
    {
        return a[i];
    }

    // Running Time: O(1)
    bool empty()
    {
        return amount == 0;
    }

    // Running Time: O(1)
    int size()
    {
        return amount;
    }

    // Running Time: O(n)
    void print()
    {
        for (int i = 0; i < amount; i++)
        {
            cout << a[i] << endl;
        }
    }

    // Running Time: O(n)
    void insertFront(T e)
    {
        for (int i = amount - 1; i > 0; --i)
        {
            a[i] = a[i - 1];
        }
        ++amount;
        expandArray();
        a[0] = e;
    }

    // Running Time: O(1)
    void removeRear()
    {
        --amount;
    }
};

void requirement1()
{
    MyArrayList<int> test;

    cout << test.empty() << ' ';        // Output: 1
    test.insertRear(3);                 // List: 3
    test.insertRear(7);                 // List: 3 7
    cout << test.elementAt(0) << ' ';   // Output: 3
    test.insertRear(4);                 // List: 3 7 4
    test.removeFront();                 // List: 7 4
    test.insertRear(9);                 // List: 7 4 9
    cout << test.elementAt(2) << ' ';   // Output: 9
    test.insertRear(2);                 // List: 7 4 9 2
    test.insertRear(8);                 // List: 7 4 9 2 8
    test.insertRear(6);                 // List: 7 4 9 2 8 6
    test.removeFront();                 // List: 4 9 2 8 6 
    cout << endl;

    for (int i = 0; i < test.size(); ++i)
    {
        cout << test.elementAt(i) << ' ';
    }
    cout << endl;
}

void requirement2()
{
    MyArrayList<string> s;
    s.insertFront("CSCI 140");
    s.insertRear("CSCI 145");
    s.insertRear("CSCI 220");
    s.insertFront("CSCI 110");
    cout << "size(): " << s.size() << endl;
    cout << "empty(): " << (s.empty() ? "True" : "False") << endl;
    cout << "elementAt(2): " << s.elementAt(2) << endl;
    s.removeFront();
    s.removeRear();
    s.print();
}

int main()
{
    requirement1();
    requirement2();

    cout << "Author: Nero Li\n";
    return 0;
}