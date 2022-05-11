/*  Program: PA_10_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/17/2022     
    Description: 
        Implement Transitive Closure for a digraph using 
        AdjacencyListGraph class from previous PA. Test it out on a 
        simple example above (can assume each edge has a weight of 1). 
        Print both original digraph and updated digraph.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "AdjacencyListGraph.h"

using namespace std;

bool areAdjacent(AdjacencyListGraph &G, Vertex *v1, Vertex *v2)
{
    vector<Edge *> out = G.outgoingEdges(v1);
    for (auto i : out)
        if (G.opposite(v1, i)->getElement() == v2->getElement())
            return true;

    return false;
}

void floydWarshall(AdjacencyListGraph &G)
{
    AdjacencyListGraph Gpre(true);
    AdjacencyListGraph Gcur(true);
    vector<Vertex *> v;
    v.push_back(NULL);
    int n = G.numVertices();
    for (auto i : G.getVertices())
        v.push_back(i);
    
    Gpre = G;
    for (int k = 1; k <= n; ++k)
    {
        Gcur = Gpre;
        for (int i = 1; i <= n; ++i)
            if (i != k)
                for (int j = 1; j <= n; ++j)
                    if (j != i && j != k)
                        if (areAdjacent(Gpre, v[i], v[k]) && areAdjacent(Gpre, v[k], v[j]))
                            if (!areAdjacent(Gcur, v[i], v[j]))
                                Gcur.insertEdge(v[i], v[j], k);                               
    }

    Gcur.print();
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

    cout << "Transitive Closure:\n";
    floydWarshall(G);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
