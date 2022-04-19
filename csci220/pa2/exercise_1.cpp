/*  Program: PA_2_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/02/2021	     
    Description: 
        Write a C++ class that is derived from the 
        Progression class to produce a progression 
        where each value is the absolute value of 
        the difference between the previous two 
        values. You should include a default 
        constructor that starts with 2 and 200 as 
        the first two values and a parametric 
        constructor that starts with a specified 
        pair of numbers as the first two values.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

class Progression 
{
    protected:                              // member data
        long first;				            // first value of the progression
        long cur;				            // current value of the progression

        virtual long firstValue()           // reset and return first value
        {		    
            cur = first;
            return cur;
        }
        virtual long nextValue()		    // advance and return next value
        { 
            return ++cur; 
        }
    public:
        Progression(long f = 0)		        // constructor given first value
        { 
            cur = first = f; 
        }
        void printProgression(int n);		// print the first n values
        virtual ~Progression() { }		    // virtual destructor
        // virtual void print() = 0;        // an example of a pure virtual function
};

void Progression::printProgression(int n) 
{
    std::cout << firstValue();		        // print the first value
    for (int i = 2; i <= n; i++) 
    { 
        std::cout << ' ' << nextValue();	// print values 2 through n
    }
    std::cout << '\n';			            // print end of line
}

class AbsoluteProgression : public Progression
{ 
    protected:
        long second;
        long prev;
        virtual long firstValue()
        {
            cur = first;
            prev = second + first;
            return cur;
        }

        virtual long nextValue()
        {
            long temp = prev;
            prev = cur;
            cur -= temp;
            if (cur < 0)
                cur = -cur;
            return cur;
        }
    public:
        AbsoluteProgression(long f = 2, long s = 200)
        : Progression(f), second(s), prev(second + first) {}       
};

/** Test program */
int main() 
{
    Progression* prog;

    // test AbsoluteProgression
    cout << "Absolute progression with default start values:\n";
    prog = new AbsoluteProgression();
    prog->printProgression(20);
    cout << "Absolute progression with start values 4 and 6:\n";
    prog = new AbsoluteProgression(4, 6);
    prog->printProgression(20);
    cout << "Absolute progression with start values 50 and 48:\n";
    prog = new AbsoluteProgression(50, 48);
    prog->printProgression(20);

    cout << "Modified by: Nero Li\n";
    return 0;
}