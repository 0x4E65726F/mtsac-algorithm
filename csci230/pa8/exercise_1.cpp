/*  Program: PA_8_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/26/2022	     
    Description: 
        Implement the MCP algorithm and print out resulting table as 
        well as the minimum number of operations. Try B x C x D with B 
        a 2x10 matrix, C a 10x50 matrix, and D a 50x20 matrix. Try 
        another test case with 10x5 (A), 5x2 (B), 2x20 (C), 20x12 (D), 
        12x4 (E), and 4x60 (F).


    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <vector>

using namespace std;

void printOrder(vector<vector<int>> S, int i, int j)
{
    if (i == j)
    {
        char c = 'A' + i;
        cout << c;
    }
    else
    {
        cout << "(";
        printOrder(S, i, S[i][j]);
        printOrder(S, S[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChain(vector<int> d)
{
    int n = d.size() - 1;
    string order;
    char c = 'A';
    vector<vector<int>> N(n, vector<int>(n, 0));   
    vector<vector<int>> S(n, vector<int>(n, 0));

    for (int b = 1; b < n; ++b)
        for (int i = 0; i <= n - b - 1; ++i)
        {
            int j = i + b;
            N[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) 
            {
                int a = N[i][j];
                int b = N[i][k] + N[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                N[i][j] = a < b ? a : b;
                S[i][j] = k;
            }
        }
    
    cout << "Matrix result:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << N[i][j] << "\t";
        cout << endl;
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << S[i][j] << "\t";
        cout << endl;
    }

    cout << "Order of evaluation:\n";
    printOrder(S, 0, n - 1);
    cout << endl;
}


int main()
{
    /*
    // 2x10 (A), 10x50 (B), 50x20 (C)
    vector<int> test1 = {2, 10, 50, 20};

    // 10x5 (A), 5x2 (B), 2x20 (C), 20x12 (D), 12x4 (E), and 4x60 (F)
    vector<int> test2 = {10, 5, 2, 20, 12, 4, 60}; 

    MatrixChain(test1);
    MatrixChain(test2);
    */

    // 1x2, 2x3, 3x4
    vector<int> test = {1,2,3,4};
    MatrixChain(test);
    cout << "Author: Nero Li\n";

    return 0;
}
