/*  Program: Lab_Final_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 12/09/2021	     
    Description: 
        Set up MyIntQueue class that supports standard queue operations with int values. The
        class must use two stacks of integers to store data and support stack operations (no
        additional variables in the class). What is the running time for each queue operation?
        You can use your stack class from a PA or one from C++/ Java language. You might
        want to make sure that your implementation would work with the following test case:
        // s is an object of type MyIntQueue
        s.enqueue(5);
        s. enqueue(7);
        x = s.front(); // x is 5
        s. enqueue(1);
        x = s.dequeue(); // x is 5, dequeue() will return a value
        s.enqueue(2);
        x = s.dequeue(); // x is 7
        x = s.dequeue(); // x is 1

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <stack>

using namespace std;

class MyIntQueue
{
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    // Running Time: O(1)
    void enqueue(int n)
    {
        stk1.push(n);
    }
    
    // Running Time: O(n^2)
    int dequeue()
    {
        int n;
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        n = stk2.top();
        stk2.pop();
        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return n;
    }
    
    // Running Time: O(n^2)
    int front()
    {
        int n;
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        n = stk2.top();
        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return n;
    }
};

void requirement1()
{
    int x;
    MyIntQueue s;       // s is an object of type MyIntQueue 

    s.enqueue(5); 
    s.enqueue(7); 
    x = s.front();      // x is 5 
    cout << x << ' ';
    s.enqueue(1); 
    x = s.dequeue();    // x is 5, dequeue() will return a value 
    cout << x << ' ';
    s.enqueue(2); 
    x = s.dequeue();    // x is 7 
    cout << x << ' ';
    x = s.dequeue();    // x is 1
    cout << x << ' ';

    cout << endl;
}

void requirement2()
{
    int a[] = {5, 7, 1, 2, 4};
    int count{5};
    MyIntQueue q1;
    MyIntQueue q2;
    int switcher{1};

    for (int i = 0; i < count; ++i)
    {
        q2.enqueue(a[i]);
    }

    for (int i = 0; i < count; ++i)
    {
        switch (switcher)
        {
        case 1:
            for (int j = 0; j < count - 1 - i; ++j)
            {
                q1.enqueue(q2.dequeue());
            }
            switcher = 2;
            a[i] = q2.dequeue();
            break;

        case 2:
            for (int j = 0; j < count - 1 - i; ++j)
            {
                q2.enqueue(q1.dequeue());
            }
            switcher = 1;
            a[i] = q1.dequeue();
            break;
        
        default:
            break;
        }
    }

    for (int i = 0; i < count; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    requirement1();
    requirement2();

    cout << "Author: Nero Li\n";
    return 0;
}