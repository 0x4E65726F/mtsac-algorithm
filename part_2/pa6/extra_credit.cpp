/*  Program: PA_6_extra_credit  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/12/2022     
    Description: 
         Implement the find/union partition structure as a tree-based 
         approach. Use Partition.java and Position.java from Java 
         textbook as a guide to create your own code, add a driver to 
         test it for n operations (make cluster/set, find, and union).

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename E>
class Partition
{
    public:
        class Locator
        {
            public:
                E elem;
                int size;
                Locator *parent;
                Locator(int elem)
                {
                    this->elem = elem;
                    size = 1;
                    parent = this;
                }

                int getElement()
                { 
                    return elem; 
                }
        }; 

    public:
        Locator *makeSet(E e)
        {
            return new Locator(e);
        }

        Locator *find(Locator *p)
        {
            Locator *loc = p;
            if (loc->parent != loc)
            {
                loc->parent = find(loc->parent);
            }
            return loc->parent;
        }

        void makeUnion(Locator *A, Locator *B)
        {
            Locator *a = find(A);
            Locator *b = find(B);
            if (a != b)
            {
                if (a->size > b->size)
                {
                    b->parent = a;
                    a->size += b->size;
                }
                else
                {
                    a->parent = b;
                    b->size += a->size;
                }
            }
        }
};

int main()
{
    Partition<int> test;
    vector<Partition<int>::Locator*> arr;
    const int SIZE = 12;

    for (int i = 1; i <= SIZE; ++i)
        arr.push_back(test.makeSet(i));
        
 
    test.makeUnion(arr[3], arr[0]);
    test.makeUnion(arr[3], arr[6]);
  
    test.makeUnion(arr[8], arr[1]);
    test.makeUnion(arr[8], arr[5]);
    test.makeUnion(arr[2], arr[8]);

    test.makeUnion(arr[10], arr[4]);
    test.makeUnion(arr[11], arr[4]);
    test.makeUnion(arr[9], arr[4]);
    test.makeUnion(arr[7], arr[4]);

    cout << "A = {1, 4, 7}\n";
    cout << "B = {2, 3, 6, 9}\n";
    cout << "C = {5, 8, 10, 11, 12}\n";

    for (int i = 1; i <= SIZE; ++i)
        cout << i << ": " << test.find(arr[i - 1])->getElement() << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
