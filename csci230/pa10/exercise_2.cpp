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
#include <map>
#include "AdjacencyListGraph.h"
#include "HeapPriorityQueue.h"

using namespace std;

class comp
{
public:
    bool operator()(pair<int, Vertex *> a, pair<int, Vertex *> b)
    {
        return (a.first < b.first);
    }
};

typedef map<Vertex *, int> DM;
typedef pair<Vertex *, int> DMPair;
typedef map<Vertex *, VectorCompleteTree<pair<int, Vertex *>>::Position> EM;
typedef pair<Vertex *, VectorCompleteTree<pair<int, Vertex *>>::Position> EMPair;
typedef HeapPriorityQueue<pair<int, Vertex *>, comp> PQ;
typedef pair<int, Vertex *> PQPair;
typedef VectorCompleteTree<pair<int, Vertex *>>::Position Entry;

void dijkstra(AdjacencyListGraph G, Vertex *v)
{
    DM D;
    EM E;
    PQ Q;
    Entry l;

    for (auto i : G.getVertices())
    {
        if (i == v)
            D.insert(DMPair(i, 0));
        else
            D.insert(DMPair(i, INT_MAX));
    }
    
    l = Q.insert(PQPair(D[v], v));
    E.insert(EMPair(v, l));

    while (!Q.empty())
    {
        l = Q.removeMin();
    }
    
}

int main()
{
    AdjacencyListGraph G(true);

    Vertex *A = G.insertVertex("A");
    Vertex *B = G.insertVertex("B");
    Vertex *C = G.insertVertex("C");
    Vertex *D = G.insertVertex("D");
    Vertex *E = G.insertVertex("E");
    G.insertEdge(A, D, 5);
    G.insertEdge(A, E, 10);
    G.insertEdge(B, A, 3);
    G.insertEdge(B, C, 4);
    G.insertEdge(C, D, 2);
    G.insertEdge(D, E, 3);
    G.insertEdge(E, C, 6);
    cout << "Original Graph:\n";
    G.print();
    cout << endl;

    cout << "Path from B to E:\n";
    dijkstra(G, B);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
