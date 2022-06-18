/*  Program: PA_5_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/30/2021	     
    Description: 
        You must use either existing C++ stack class or Java Stack class to solve 
        the "Balancing Symbols" problem. The symbols are (), [], and {}, and each 
        opening symbol must have a corresponding closing symbol as well as in correct 
        order. Ignore operands and arithmetic operators since they are not relevant 
        to our problem. You can assume each token is separated by spaces.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <stack>

using namespace std;

bool func(char str[])
{
    stack<char> braces;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            braces.push(str[i]);
            break;
        case ')':
            if (braces.top() == '(')
            {
                braces.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (braces.top() == '[')
            {
                braces.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (braces.top() == '{')
            {
                braces.pop();
            }
            else
            {
                return false;
            }
            break;  
        default:
            break;
        }
    }
    
    if (braces.size() != 0)
    {
        return false;
    }
    
    return true;
}

int main()
{
    char str1[] = {"{ ( a + b ) * c1 }"};
    char str2[] = {"{ ( a + b ) * c1 ]"};
    char str3[] = {"( ( a + b ) * c1 } / 15 )"};
    char str4[] = {"( ( ( ( ( ( ( ( [ [ [ { { } } ] ] ] ) ) ) ) ) ) ) )"};
    char str5[] = {"( [ ) ]"};

    cout << str1 << " - " << (func(str1) ? "valid" : "invalid") << endl;
    cout << str2 << " - " << (func(str2) ? "valid" : "invalid") << endl;
    cout << str3 << " - " << (func(str3) ? "valid" : "invalid") << endl;
    cout << str4 << " - " << (func(str4) ? "valid" : "invalid") << endl;
    cout << str5 << " - " << (func(str5) ? "valid" : "invalid") << endl;
    
    cout << "Author: Nero Li\n";
    return 0;
}