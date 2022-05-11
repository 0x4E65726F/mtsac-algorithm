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

bool areAdjacent(AdjacencyListGraph G, Vertex *v1, Vertex *v2)
{
    if (G.getEdge(v1, v2))
        return false;
    
    return true;
}

AdjacencyListGraph floydWarshall(AdjacencyListGraph G)
{
    AdjacencyListGraph Gpre;
    AdjacencyListGraph Gcur;
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

    return Gcur;
}

int main()
{
    AdjacencyListGraph G(true);
    vector<Vertex *> v;
    vector<Edge *> e;
    v.push_back(G.insertVertex("A"));
    v.push_back(G.insertVertex("B"));
    v.push_back(G.insertVertex("C"));
    v.push_back(G.insertVertex("D"));
    v.push_back(G.insertVertex("E"));
    e.push_back(G.insertEdge(v[0], v[3], 1));
    e.push_back(G.insertEdge(v[0], v[4], 1));
    e.push_back(G.insertEdge(v[1], v[0], 1));
    e.push_back(G.insertEdge(v[1], v[2], 1));
    e.push_back(G.insertEdge(v[2], v[3], 1));
    e.push_back(G.insertEdge(v[3], v[4], 1));
    e.push_back(G.insertEdge(v[4], v[2], 1));
    cout << "Original Graph:\n";
    G.print();
    cout << endl;
    cout << "Transitive Closure:\n";
    floydWarshall(G).print();
    cout << endl;
    cout << "Author: Nero Li\n";

    return 0;
}
