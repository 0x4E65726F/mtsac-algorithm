/*  Program: PA_5_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/30/2021	     
    Description: 
        You must define and implement your own Stack class or use the one from 
        the textbook. The Stack class supports standard basic stack operations, 
        and you can implement it with an array or a linked list. You should create 
        a class template Stack in C++ or generic class Stack in Java, but an 
        integer stack would work as well. Set up a function or static method that 
        receives a string representing a postfix expression and it returns an 
        integer result. Your function/method uses a stack to evaluate a postfix 
        expression (see an operand -- push; see an operator – pop twice, evaluate, 
        then push result).

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Stack
{ 
    public:
        Stack() {}
        
        int size()
        {
            return i;
        }

        bool empty()
        {
            if (i == 0)
            {
                return true;
            }
            return false;
        }

        T top()
        {
            if (empty())
            {
                cout << "StackEmpty\n";
                exit(-1);
            }
            return head->n;
        }

        void push(T n)
        {
            Node *cur = new Node;
            cur->n = n;
            cur->next = head;
            head = cur;
            ++i;
        }

        T pop()
        {
            T lost;
            Node *cur;
            if (empty())
            {
                cout << "StackEmpty\n";
                exit(-1);
            }
            lost = head->n;
            cur = head;
            head = head->next;
            delete(cur);
            --i;
            return lost;
        }

    private:
        int i{0};
        struct Node
        {
            T n;
            Node *next;
        } *head{NULL};
};

int func(string str)
{
    Stack<int> expression;
    int value{0};

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            value *= 10;
            value += str[i] - '0';
        }
        else if (str[i] == '+')
        {
            int a{expression.pop()};
            int b{expression.pop()};
            expression.push(b + a);
            ++i;
        }
        else if (str[i] == '-')
        {
            int a{expression.pop()};
            int b{expression.pop()};
            expression.push(b - a);
            ++i;
        }
        else if (str[i] == '*')
        {
            int a{expression.pop()};
            int b{expression.pop()};
            expression.push(b * a);
            ++i;
        }
        else if (str[i] == '/')
        {
            int a{expression.pop()};
            int b{expression.pop()};
            expression.push(b / a);
            ++i;
        }
        else if (str[i] == '^')
        {
            int a{expression.pop()};
            int b{expression.pop()};
            expression.push(pow(b, a));
            ++i;
        }
        else
        { 
            expression.push(value);
            value = 0;
        }
    }
    
    return expression.pop();
}

int main()
{
    cout << func("17 2 3 + / 13 -") << endl;
    cout << func("5 2 3 ^ *") << endl;
    cout << func("2 3 2 ^ ^") << endl;

    cout << "Author: Nero Li\n";
    return 0;
}