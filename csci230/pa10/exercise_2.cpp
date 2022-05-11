/*  Program: PA_10_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/17/2022	     
    Description: 
        Implement a shortest path algorithm for a graph (preferably 
        Dijkstra's algorithm) using AdjacencyListGraph class from 
        previous PA. Test it out using digraph above. Find the shortest 
        path from B to E using the weights below. Print out the path
        how to get from source vertex to a destination vertex.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "AdjacencyListGraph.h"

using namespace std;

void dijkstra(AdjacencyListGraph G)
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
    G.insertEdge(A, E, 1);
    G.insertEdge(B, A, 1);
    G.insertEdge(B, C, 1);
    G.insertEdge(C, D, 1);
    G.insertEdge(D, E, 1);
    G.insertEdge(E, C, 1);
    cout << "Original Graph:\n";
    G.print();
    cout << endl;

    
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
