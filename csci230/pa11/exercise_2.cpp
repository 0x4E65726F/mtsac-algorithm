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
#include "AdjacencyListGraph.h"

using namespace std;

class Flights
{
private:
    AdjacencyListGraph G;
    map<string, Vertex *> airport;
    vector<string> dest;
    vector<int> price;

    void cheapestFlight(Vertex *start, Vertex *end)
    {

    }

    void cheapestRoundTrip(Vertex *start, Vertex *end)
    {

    }

    void airportDFS(Vertex *start)
    {

    }

    void fewestStop(Vertex *start, Vertex *end)
    {

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
            int n;

            while (p--)
            {
                fin >> cur;
                dest.push_back(cur);
                if (airport.find(cur) == airport.end())
                    airport.insert(pair<string, Vertex *>(cur, G.insertVertex(cur)));
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
                    break;

                case '1':
                    cout << "Start from: ";
                    cin >> first;
                    cout << "Go to: ";
                    cin >> second;
                    cheapestFlight(airport[first], airport[second]);
                    break;

                case '2':
                    cout << "Start from: ";
                    cin >> first;
                    cout << "Go to: ";
                    cin >> second;
                    cheapestRoundTrip(airport[first], airport[second]);
                    break;

                case '3':
                    cout << "Start from: ";
                    cin >> first;
                    airportDFS(airport[first]);
                    break;

                case '4':
                    cout << "Start from: ";
                    cin >> first;
                    cout << "Go to: ";
                    cin >> second;
                    fewestStop(airport[first], airport[second]);
                    break;
                
                default:
                    quit = true;
            }
            cout << "----------------------------------------------------------------------------\n";
        }
    }
};

int main()
{
    // code 

    cout << "Author: Nero Li\n";

    return 0;
}
