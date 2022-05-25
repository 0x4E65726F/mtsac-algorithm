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
#include <queue>
#include "AdjacencyListGraph.h"

using namespace std;
typedef pair<int, Vertex *> PQP;

priority_queue<PQP> replace(priority_queue<PQP> Q, PQP oldElem, PQP newElem)
{
    vector<PQP> allElem;
    priority_queue<PQP> resultPQ;
    int n = Q.size();

    while (!Q.empty())
    {
        if (Q.top().first == oldElem.first && Q.top().second == oldElem.second)
            allElem.push_back(newElem);
        else
            allElem.push_back(Q.top());
        Q.pop();
    }

    for (auto i : allElem)
        resultPQ.push(i);

    return resultPQ;
}

void PrimJarnikMST(AdjacencyListGraph G, Vertex *s)
{
    
    priority_queue<PQP> Q;
    map<Vertex *, int> distance;
    map<Vertex *, Edge *> parent;
    map<Vertex *, PQP> locator;
    for (auto v : G.getVertices())
    {
        if (v == s)
            distance[v] = 0;
        else
            distance[v] = INT_MAX;
        
        parent[v] = NULL;
        PQP l;
        l.first = distance[v];
        l.second = v;
        Q.push(l);
        locator[v] = l;
    }
    
    while (!Q.empty())
    {
        PQP l = Q.top();
        Q.pop();
        Vertex *u = l.second;
        for (auto e : G.incomingEdges(u))
        {
            Vertex *z = G.opposite(u, e);
            int r = e->getElement();
            if (r < distance[z])
            {
                distance[z] = r;
                parent[z] = e;
                PQP newLoc = locator[z];
                newLoc.first = r;
                Q = replace(Q, locator[z], newLoc);
            }
        }
    }
    
    for (auto i : parent)
    {
        if (i.second != NULL)
        {
            cout << i.first->getElement() << "\'s parent is: " << G.opposite(i.first, i.second)->getElement() << endl;
        }
        else
        {
            cout << i.first->getElement() << " is root\n";
        }
    }
    
}

int main()
{
    AdjacencyListGraph G;
/*
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
*/
    Vertex *A = G.insertVertex("A");
    Vertex *B = G.insertVertex("B");
    Vertex *C = G.insertVertex("C");
    Vertex *D = G.insertVertex("D");
    Vertex *E = G.insertVertex("E");
    Vertex *F = G.insertVertex("F");
    G.insertEdge(A, B, 2);
    G.insertEdge(A, C, 8);
    G.insertEdge(A, E, 7);
    G.insertEdge(B, C, 5);
    G.insertEdge(B, D, 7);
    G.insertEdge(C, D, 9);
    G.insertEdge(D, F, 4);
    G.insertEdge(C, E, 8);
    G.insertEdge(E, F, 3);

    cout << "Original Graph:\n";
    G.print();
    cout << endl;

    cout << "MST:\n";
    PrimJarnikMST(G, A);
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
