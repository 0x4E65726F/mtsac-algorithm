/*  Program: PA_9_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/10/2022	     
    Description: 
        Set up your own code to represent an undirected graph using 
        Adjacency List. Try the test case below first and then create a
        simple graph with 4 vertices and 6 edges and print it. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include <vector>
#include "AdjacencyListGraph.h"

using namespace std;

class MatrixGraph
{
private:
    vector<vector<int>> Matrix;
public:
    MatrixGraph(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            vector<int> cur;
            for (int j = 0; j < n; ++j)
                cur.push_back(0);
            Matrix.push_back(cur);
        }
    }

    void insert(char a, char b, int edge)
    {
        int i = a - 'A';
        int j = b - 'A';
        Matrix[i][j] = edge;
        Matrix[j][i] = edge;
    }

    void print()
    {
        int n = Matrix.size();

        for (int i = 0; i < n; ++i)
        {
            char c = 'A' + i;
            vector<pair<char, int>> adjacencies;
            for (int j = 0; j < n; ++j)
            {
                if (Matrix[i][j])
                {
                    pair<char, int> cur;
                    cur.first = 'A' + j;
                    cur.second = Matrix[i][j];
                    adjacencies.push_back(cur);
                }
            }
            cout << "Vertex " << c << endl;
            cout << " " << adjacencies.size() << " adjacencies:";
            for (auto a : adjacencies)
                cout << "(" << a.first << ", " << a.second << ")  ";
            cout << endl;
        }
        
    }
};

int main()
{
    AdjacencyListGraph test1;
    vector<Vertex *> v1;
    vector<Edge *> e1;
    v1.push_back(test1.insertVertex("A"));
    v1.push_back(test1.insertVertex("B"));
    v1.push_back(test1.insertVertex("C"));
    e1.push_back(test1.insertEdge(v1[1], v1[0], 100));
    e1.push_back(test1.insertEdge(v1[2], v1[0], 200));
    cout << "First graph by AdjacencyListGraph:\n";
    test1.print();
    cout << endl;

    AdjacencyListGraph test2;
    vector<Vertex *> v2;
    vector<Edge *> e2;
    v2.push_back(test2.insertVertex("A"));
    v2.push_back(test2.insertVertex("B"));
    v2.push_back(test2.insertVertex("C"));
    v2.push_back(test2.insertVertex("D"));
    e2.push_back(test2.insertEdge(v2[0], v2[1], 1));
    e2.push_back(test2.insertEdge(v2[1], v2[2], 2));
    e2.push_back(test2.insertEdge(v2[2], v2[3], 3));
    e2.push_back(test2.insertEdge(v2[3], v2[1], 4));
    e2.push_back(test2.insertEdge(v2[0], v2[2], 5));
    e2.push_back(test2.insertEdge(v2[1], v2[3], 6));
    cout << "Second graph by AdjacencyListGraph\n";
    test2.print();
    cout << endl;

    MatrixGraph test3(3);
    test3.insert('B','A', 100);
    test3.insert('C','A', 200);
    cout << "First graph by MatrixGraph:\n";
    test3.print();
    cout << endl;

    MatrixGraph test4(4);
    test4.insert('A','B', 1);
    test4.insert('B','C', 2);
    test4.insert('C','D', 3);
    test4.insert('D','A', 4);
    test4.insert('A','C', 5);
    test4.insert('B','D', 6);
    cout << "Second graph by MatrixGraph:\n";
    test4.print();
    cout << endl;

    cout << "Modified by: Nero Li\n";

    return 0;
}
