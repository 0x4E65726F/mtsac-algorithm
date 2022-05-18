/*  Program: PA_11_exercise
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/24/2022	     
    Description: 
        Modify exercise 1 to include additional features and you can 
        just submit exercise 2 since it includes all features of 
        exercise 1. Additional graph processing algorithms such as 
        shortest paths can be added to this class or another class such 
        as GraphAlgorithms.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include "AdjacencyListGraph.h"
#include "HeapPriorityQueue.h"
#include "Entry.h"

using namespace std;

class Flights
{
private:
    AdjacencyListGraph G;
    map<string, Vertex *> airport;
    vector<string> dest;
    vector<double> price;

    class comp
    {
    public:
        bool operator()(Entry<double, Vertex *> a, Entry<double, Vertex *> b)
        {
            return (a.key() < b.key());
        }
    };

    class comp2
    {
    public:
        bool operator()(Entry<int, Vertex *> a, Entry<int, Vertex *> b)
        {
            return (a.key() < b.key());
        }
    };

    void cheapestFlight(Vertex *src, Vertex *dest)
    {
        map<Vertex *, double> D;
        map<Vertex *, double> cloud;
        map<Vertex *, Vertex *> prev;
        HeapPriorityQueue<Entry<double, Vertex *>, comp> pq;
        map<Vertex *, Entry<double, Vertex *>> pqTokens;
        
        for (Vertex *v : G.getVertices())
        {
            if (v == src)
                D.insert(pair<Vertex *, double>(v, 0));
            else
                D.insert(pair<Vertex *, double>(v, INT_MAX));
            pqTokens.insert(pair<Vertex *, Entry<double, Vertex *>>(v, pq.insert(Entry<double, Vertex *>(D[v], v))));
        }
        
        while (!pq.empty())
        {
            Entry<double, Vertex *> entry = pq.removeMin();
            double key = entry.key();
            Vertex *u = entry.value();
            cloud.insert(pair<Vertex *, double>(u, key));
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
                        pq.replace(pqTokens[v], Entry<double, Vertex *>(D[v], v));
                        prev[v] = u;
                    }
                }
            }
        }
        cout << "Path:\t\t\t";
        stack<Vertex *> output;
        Vertex *cur = dest;
        while (cur != src)
        {
            output.push(cur);
            cur = prev[cur];
        }
        cout << src->getElement();
        while (!output.empty())
        {
            cout  << " -> " << output.top()->getElement();
            output.pop();
        }
        cout << endl;
        
        cout << "Cost:\t\t\t$" << cloud[dest] << endl;
    }

    void cheapestRoundTrip(Vertex *start, Vertex *end)
    {

    }

    void airportDFS(Vertex *start)
    {

    }

    void fewestStop(Vertex *src, Vertex *dest)
    {
        map<Vertex *, int> D;
        map<Vertex *, int> cloud;
        map<Vertex *, Vertex *> prev;
        HeapPriorityQueue<Entry<int, Vertex *>, comp2> pq;
        map<Vertex *, Entry<int, Vertex *>> pqTokens;
        
        for (Vertex *v : G.getVertices())
        {
            if (v == src)
                D.insert(pair<Vertex *, int>(v, 0));
            else
                D.insert(pair<Vertex *, int>(v, INT_MAX));
            pqTokens.insert(pair<Vertex *, Entry<int, Vertex *>>(v, pq.insert(Entry<int, Vertex *>(D[v], v))));
        }
        
        while (!pq.empty())
        {
            Entry<int, Vertex *> entry = pq.removeMin();
            int key = entry.key();
            Vertex *u = entry.value();
            cloud.insert(pair<Vertex *, int>(u, key));
            pqTokens.erase(u);
            for (Edge *e : G.outgoingEdges(u))
            {
                Vertex *v = G.opposite(u, e);
                if (cloud.find(v) == cloud.end())
                {
                    int wgt = 1;
                    if (D[u] + wgt < D[v])
                    {
                        D[v] = D[u] + wgt;
                        pq.replace(pqTokens[v], Entry<int, Vertex *>(D[v], v));
                        prev[v] = u;
                    }
                }
            }
        }
        cout << "Path:\t\t\t";
        stack<Vertex *> output;
        Vertex *cur = dest;
        while (cur != src)
        {
            output.push(cur);
            cur = prev[cur];
        }
        cout << src->getElement();
        while (!output.empty())
        {
            cout  << " -> " << output.top()->getElement();
            output.pop();
        }
        cout << endl;

        cout << "Stops:\t\t\t" << cloud[dest] << endl;
    }

public:
    Flights(string str)
    {
        ifstream fin;
        fin.open(str, ios::binary);
        
        if (!fin)
            return;

        while (!fin.eof())
        {
            string cur;
            int p{2};
            double n;

            while (p--)
            {
                fin >> cur;
                if (!cur.empty())
                {
                    dest.push_back(cur);
                    if (airport.find(cur) == airport.end())
                        airport.insert(pair<string, Vertex *>(cur, G.insertVertex(cur)));
                }
            }
            
            fin >> n;
            price.push_back(n);
        }
        
        for (int i = 0, j = 0; i < dest.size(); i += 2, ++j)
            G.insertEdge(airport[dest[i]], airport[dest[i + 1]], price[j]);
    }

    void controlPanel()
    {
        bool quit{false};
        char choice{'Q'};
        
        while (!quit)
        {
            cout << "----------------------------------------------------------------------------\n";
            cout << "0. Display all flights\n";
            cout << "1. Find a cheapest flight from one airport to another airport\n";
            cout << "2. Find a cheapest roundtrip from one airport to another airport\n";
            cout << "3. Find an order to visit all airports starting from an airport\n";
            cout << "4. Find a flight with fewest stops from one airport to another airport\n";
            cout << "Q. Exit\n";
            cout << "----------------------------------------------------------------------------\n";
            cout << "Your choice: ";
            cin >> choice;
            cout << "----------------------------------------------------------------------------\n";
            string first;
            string second;
            switch(choice)
            {
                case '0':
                    G.print();
                    system("pause");
                    break;

                case '1':
                    cout << "Start from:\t\t";
                    cin >> first;
                    cout << "Go to:\t\t\t";
                    cin >> second;
                    cheapestFlight(airport[first], airport[second]);
                    cout << "----------------------------------------------------------------------------\n";
                    system("pause");
                    break;

                case '2':
                    cout << "Start from:\t\t";
                    cin >> first;
                    cout << "Go to:\t\t\t";
                    cin >> second;
                    cheapestRoundTrip(airport[first], airport[second]);
                    cout << "----------------------------------------------------------------------------\n";
                    system("pause");
                    break;

                case '3':
                    cout << "Start from:\t\t";
                    cin >> first;
                    airportDFS(airport[first]);
                    cout << "----------------------------------------------------------------------------\n";
                    system("pause");
                    break;

                case '4':
                    cout << "Start from:\t\t";
                    cin >> first;
                    cout << "Go to:\t\t\t";
                    cin >> second;
                    fewestStop(airport[first], airport[second]);
                    cout << "----------------------------------------------------------------------------\n";
                    system("pause");
                    break;
                
                default:
                    quit = true;
            }
        }
    }
};

int main()
{
    Flights test("PA11Flights.txt");
    test.controlPanel();

    cout << "Author: Nero Li\n";

    return 0;
}
