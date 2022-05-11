/*  Program: PA_10_extra_credit
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/17/2022	     
    Description: 
        Implement Topological Ordering on a DAG using AdjacencyListGraph
        class from previous PA

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "AdjacencyListGraph.h"

using namespace std;

void DFS()
{

}

void topological(AdjacencyListGraph G)
{

}

int main()
{
    AdjacencyListGraph G(true);

    Vertex *A = G.insertVertex("A");
    Vertex *B = G.insertVertex("B");
    Vertex *C = G.insertVertex("C");
    Vertex *D = G.insertVertex("D");
    Vertex *E = G.insertVertex("E");
    G.insertEdge(A, D, 1);
    G.insertEdge(B, A, 1);
    G.insertEdge(B, C, 1);
    G.insertEdge(C, D, 1);
    G.insertEdge(D, E, 1);
    cout << "Original Graph:\n";
    G.print();
    cout << endl;

    cout << "Topological Ordering:\n";
    topological(G);
    cout << endl;

    cout << "Author: Nero Li\n";

    return 0;
}
