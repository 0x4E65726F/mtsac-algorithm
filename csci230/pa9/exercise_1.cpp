/*  Program: PA_9_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/10/2022	     
    Description: 
        Set up your own code to represent an undirected graph using 
        Adjacency List. Try the test case below first and then create a
        simple graph with 4 vertices and 6 edges and print it. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include "AdjacencyMapGraph.h"

using namespace std;

int main()
{
    AdjacencyMapGraph test1;
    Vertex *A = test1.insertVertex("A");
	Vertex *B = test1.insertVertex("B");
	Vertex *C = test1.insertVertex("C");
    Edge *e1 = test1.insertEdge(B, A, 100);
    Edge *e2 = test1.insertEdge(C, A, 200);

    cout << "First graph:\n";
    test1.print();
    cout << endl;

    AdjacencyMapGraph test2;
    A = test2.insertVertex("A");
	B = test2.insertVertex("B");
	C = test2.insertVertex("C");
    Vertex *D = test2.insertVertex("D");
    e1 = test2.insertEdge(A, B, 10);
    e2 = test2.insertEdge(B, C, 10);
    Edge *e3 = test2.insertEdge(C, D, 10);
    Edge *e4 = test2.insertEdge(D, A, 10);
    Edge *e5 = test2.insertEdge(D, B, 10);
    Edge *e6 = test2.insertEdge(A, C, 10);

    cout << "Second graph:\n";
    test2.print();
    cout << endl;

    cout << "Author: Nero Li\n";

    return 0;
}
