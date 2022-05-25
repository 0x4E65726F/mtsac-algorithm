/*  Program: PA_#_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: MM/DD/2022	     
    Description: 
        ----------------------------------------------------------------

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "AdjacencyListGraph.h"

using namespace std;

void kruskal(AdjacencyListGraph G)
{
    
}

int main()
{
    AdjacencyListGraph G;

    Vertex *A = G.insertVertex("A");
    Vertex *B = G.insertVertex("B");
    Vertex *C = G.insertVertex("C");
    Vertex *D = G.insertVertex("D");
    Vertex *E = G.insertVertex("E");
    G.insertEdge(A, B, 3);
    G.insertEdge(A, D, 5);
    G.insertEdge(A, E, 5);
    G.insertEdge(B, C, 4);
    G.insertEdge(C, D, 2);
    G.insertEdge(D, E, 5);
    G.insertEdge(C, E, 3);
    cout << "Original Graph:\n";
    G.print();
    cout << endl;

    cout << "Transitive Closure:\n";
    kruskal(G);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;

    cout << "Author: Nero Li\n";

    return 0;
}
