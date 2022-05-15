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
#include <stack>
#include "AdjacencyListGraph.h"
#include "HeapPriorityQueue.h"
#include "Entry.h"

using namespace std;

typedef map<Vertex *, int> Map;
typedef pair<Vertex *, int> MPair;
typedef map<Vertex *, Entry<int, Vertex *>> PQTokens;
typedef pair<Vertex *, Entry<int, Vertex *>> TPair;
typedef Entry<int, Vertex *> TEntry;

class comp
{
public:
    bool operator()(TEntry a, TEntry b)
    {
        return (a.key() < b.key());
    }
};

typedef HeapPriorityQueue<TEntry, comp> PQ;

void dijkstra(AdjacencyListGraph G, Vertex *src, Vertex *dest)
{
    Map D;
    Map cloud;
    PQ pq;
    PQTokens pqTokens;
    
    for (Vertex *v : G.getVertices())
    {
        if (v == src)
            D.insert(MPair(v, 0));
        else
            D.insert(MPair(v, INT_MAX));
        pqTokens.insert(TPair(v, pq.insert(TEntry(D[v], v))));
    }
    
    while (!pq.empty())
    {
        TEntry entry = pq.removeMin();
        int key = entry.key();
        Vertex *u = entry.value();
        cloud.insert(MPair(u, key));
        pqTokens.erase(u);
        for (Edge *e : G.outgoingEdges(u))
        {
            Vertex *v = G.opposite(u, e);
            if (cloud.find(v) == cloud.end())
            {
                int wgt = e->getElement();
                if (D[u] + wgt < D[v])
                {
                    D[v] = D[u] + wgt;
                    pq.replace(pqTokens[v], TEntry(D[v], v));
                }
            }
        }
    }

    bool findStart = false;
    bool findEnd = false;
    for (auto i : D)
    {
        if (i.first == src)
            findStart = true;
        if (i.first == dest)
            findEnd = true;
        if (findStart)
            if (findEnd)
            {
                cout << i.first->getElement() << "[" << i.second << "]";
                break;
            }
            else
                cout << i.first->getElement() << "[" << i.second << "] -> ";
    }
    cout << endl;
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
    dijkstra(G, B, E);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
