/*  Program: PA_5_extra_credit  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/30/2021	     
    Description: 
        Set up a function or static method that receives a string representing an
        infix expression and it returns an equivalent postfix expression. Your 
        function/methoduses a stack to convert an infix expression to a postfix 
        expression.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

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

string func(string infix)
{
    Stack<char> symbol;
    string postfix{""};

    for (size_t i = 0; i < infix.size(); ++i)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
            if (infix[i + 1] == ' ' || infix[i + 1] == '\0')
            {
                postfix += ' ';
            }
        }
        else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
        {
            symbol.push(infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (symbol.top() != '(')
            {
                postfix += symbol.pop();
                postfix += ' ';
            }
            symbol.pop();
        }
        else if (infix[i] == ']')
        {
            while (symbol.top() != '[')
            {
                postfix += symbol.pop();
                postfix += ' ';
            }
            symbol.pop();
        }
        else if (infix[i] == '}')
        {
            while (symbol.top() != '{')
            {
                postfix += symbol.pop();
                postfix += ' ';
            }
            symbol.pop();
        }
        else if (infix[i] == '^')
        {  
            symbol.push(infix[i++]);
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            while (!symbol.empty() && (symbol.top() == '^' || symbol.top() == '*' || symbol.top() == '/'))
            {
                postfix += symbol.pop();
                postfix += ' ';
            }
            
            symbol.push(infix[i++]);
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            while (!symbol.empty() && (symbol.top() == '^' || symbol.top() == '*' || symbol.top() == '/' || symbol.top() == '+' || symbol.top() == '-'))
            {
                postfix += symbol.pop();
                postfix += ' ';
            }
            
            symbol.push(infix[i++]);
        }
        
    }
    
    while (!symbol.empty())
    {
        postfix += symbol.pop();
        postfix += ' ';
    }

    return postfix;
}

int main()
{
    cout << func("17 / ( 2 + 3 ) - 13") << endl;
    cout << func("5 * 2 ^ 3") << endl;
    cout << func("2 ^ 3 ^ 2") << endl;

    cout << "Author: Nero Li\n";
    return 0;
}