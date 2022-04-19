/*  Program: PA_6_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/12/2022 	     
    Description: 
        Set up a class named IntSet that keeps track a set of int values 
        from 0 to 999 and you can perform basic operations like creating 
        a set (constructor that accepts an array of int values), 
        insert(e), remove(e), find(e), and print(). Set up three 
        methods/functions to perform union, intersection, and difference 
        of two sets and return the new set as shown below.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 1000;

class IntSet
{
    private:
        vector<int> set;

    public:
        IntSet(vector<int> newSet = {})
        {
            sort(newSet.begin(), newSet.end());

            for (int i : newSet)
                if (set.empty() || i != *set.end())
                    set.push_back(i);
        }

        void insert(int e)
        {
            for (int i : set)
                if (e == i)
                    return;
            set.push_back(e);
        }

        void remove(int e)
        {
            vector<int>::iterator itr = set.begin();
            while (itr != set.end())
            {
                if (*itr == e)
                {
                    set.erase(itr);
                    return;
                }
                itr++;
            }
        }

        bool find(int e)
        {
            for (int i : set)
                if (i == e)
                    return true;

            return false;
        }

        void print()
        {
            for (int i : set)
                cout << i << ' ';
            cout << endl;
        }
};

IntSet setUnion(IntSet s1, IntSet s2)
{
    IntSet s3;

    for (int i = 0; i < SIZE; ++i)
        if (s1.find(i) || s2.find(i))
            s3.insert(i);
    
    return s3;
}

IntSet setInter(IntSet s1, IntSet s2)
{
    IntSet s3;

    for (int i = 0; i < SIZE; ++i)
        if (s1.find(i) && s2.find(i))
            s3.insert(i);

    return s3;
}

IntSet setDiff(IntSet s1, IntSet s2)
{
    IntSet s3;

    for (int i = 0; i < SIZE; ++i)
        if (s1.find(i) && !s2.find(i))
            s3.insert(i);

    return s3;
}

int main()
{
    vector<int> v1 = {1, 4, 6};
    vector<int> v2 = {2, 4, 8, 10};
    IntSet s1(v1);
    IntSet s2(v2);
    IntSet s3;

    s3 = setUnion(s1, s2);
    s3.print();

    s3 = setInter(s1, s2);
    s3.print();

    s3 = setDiff(s1, s2);
    s3.print();

    cout << "Author: Nero Li\n";

    return 0;
}
