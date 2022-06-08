/*  Program: Lab_Final_3
    Author: Nero Li
    Class: CSCI 220   
    Date: 12/09/2021	     
    Description: 
        Given the following DAG, provide a simple matrix to represent it (each entry of the
        matrix would hold a value 0 or 1).

        Provide code to print the above DAG using the following format (there are two edges
        from 0 to 2 and 0 to 3, …, and no edge from 5).

        Vertex      Edges
        0           2 3
        …
        5

        Print one possible topological ordering for the above DAG such as:
            0 2 1 3 4 5

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>

using namespace std;

class MatrixGraph
{
private:
    vector<vector<bool>> Matrix;
public:
    MatrixGraph(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            vector<bool> cur;
            for (int j = 0; j < n; ++j)
                cur.push_back(false);
            Matrix.push_back(cur);
        }
    }

    void insert(int i, int j)
    {
        Matrix[i][j] = true;
    }

    void print()
    {
        cout << "Vertex\tEdges\n";
        
        for (int i = 0; i < Matrix.size(); ++i)
        {
            cout << i << "\t";
            for (int j = 0; j < Matrix.size(); ++j)
                if (Matrix[i][j])
                    cout << j << " ";
            cout << endl;
        }
    }

    void topologicalOrdering()
    {
        vector<bool> explored;

        for (int i = 0; i < Matrix.size(); ++i)
            explored.push_back(false);
        
        for (int i = 0; i < Matrix.size(); ++i)
        {
            if (!explored[i])
            {
                cout << i << " ";
                explored[i] = true;
            }
            
            for (int j = 0; j < Matrix.size(); ++j)
                if (Matrix[i][j])
                {
                    bool canExplore = true;
                    for (int k = 0; k < Matrix.size(); ++k)
                        if (Matrix[k][j])
                            if (!explored[k])
                                canExplore = false;
                    
                    if (canExplore && !explored[j])
                    {
                        cout << j << " ";
                        explored[j] = true;
                    }
                }
        }

        cout << endl;
    }
};

int main()
{
    MatrixGraph G(6);
    G.insert(0, 2);
    G.insert(0, 3);
    G.insert(1, 3);
    G.insert(2, 4);
    G.insert(3, 4);
    G.insert(4, 5);
    G.print();
    cout << endl;
    G.topologicalOrdering();
    cout << endl;

    cout << "Author: Nero Li\n";
    return 0;
}