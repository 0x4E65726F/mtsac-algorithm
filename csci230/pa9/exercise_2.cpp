/*  Program: PA_9_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/10/2022	     
    Description: 
        Implement either DFS or BFS using your graph class from exercise 
        1. You can set up DFS(G, v) like the book (perform DFS on a 
        graph) or G.DFS(v) where DFS() is a member of Graph class (use 
        similar set up for BFS). For C++, you can use Decorator.h and 
        DFS.h and use GaphAlgorithms.java for Java. Print out the 
        vertices and discovery/forward edges in the order that they were 
        visited (should be vertex, discovery edge, vertex, etc.). Try 
        the following graph and start out with vertex A.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "AdjacencyListGraph.h"
#include "DFS.h"

using namespace std;


int main()
{
    AdjacencyListGraph g;
    Vertex *A = g.insertVertex("A");
	Vertex *B = g.insertVertex("B");
	Vertex *C = g.insertVertex("C");
    Vertex *D = g.insertVertex("D");
    Vertex *E = g.insertVertex("E");
    Edge *e1 = g.insertEdge(A, B, 1);
    Edge *e2 = g.insertEdge(B, C, 2);
    Edge *e3 = g.insertEdge(C, D, 3);
    Edge *e4 = g.insertEdge(D, E, 4);
    Edge *e5 = g.insertEdge(A, D, 5);
    cout << "Current graph:\n";
    g.print();

    DFS dfs(&g);
    cout << "DFS Traversal start from A:\n";
    dfs.dfsTraversal(A);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
