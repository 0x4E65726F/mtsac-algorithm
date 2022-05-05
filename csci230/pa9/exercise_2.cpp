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
#include "AdjacencyMapGraph.h"
#include "DFS.h"

using namespace std;


int main()
{
    AdjacencyMapGraph test1;
    Vertex *A = test1.insertVertex("A");
	Vertex *B = test1.insertVertex("B");
	Vertex *C = test1.insertVertex("C");
    Edge *e1 = test1.insertEdge(B, A, 100);
    Edge *e2 = test1.insertEdge(C, A, 200);

    DFS dfs(&test1);
    dfs.dfsTraversal(A);

    cout << "Modified by: Nero Li\n";

    return 0;
}
