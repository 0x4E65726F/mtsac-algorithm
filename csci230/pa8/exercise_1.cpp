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

void MatrixChain(vector<int> d)
{
    int n = d.size() - 1;
    string order;
    char c = 'A';
    vector<vector<int>> N(n, vector<int>(n, 0));   
    vector<vector<int>> B(n, vector<int>(n, 0)); 
    vector<pair<int, int>> par(n, pair<int, int>(0, 0));

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
                B[i][j] = k;
            }
        }
    
    cout << "Matrix result:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << N[i][j] << "\t";
        cout << endl;
    }

    cout << "Order of evaluation:\n";
    int ax = 0;
    int bx = 0;
    int ay = n - 1;
    int by = n - 1;
    ++par[bx++].first;
    ++par[ay--].second;
    for (int i = 0; i < n - 2; ++i) 
    {
        if (N[ax][ay] < N[bx][by])
        {
            ++par[ax].first;
            ++par[ay].second;
            --ay;
            --by;
        }
        else
        {
            ++par[bx].first;
            ++par[by].second;
            ++ax;
            ++bx;
        }
    }

    char ch = 'A';
    int count = 0;
    for (auto i : par)
    {
        while (i.first)
        {
            cout << "(";
            --i.first;
        }
        cout << ch;
        ++ch;
        while (i.second)
        {
            cout << ")";
            --i.second;
        }
        if (count < n - 1)
        {
            cout << " * ";
            ++count;
        }
    }
    
    cout << endl;
}


int main()
{
    // 2x10 (A), 10x50 (B), 50x20 (C)
    vector<int> test1 = {2, 10, 50, 20};

    // 10x5 (A), 5x2 (B), 2x20 (C), 20x12 (D), 12x4 (E), and 4x60 (F)
    vector<int> test2 = {10, 5, 2, 20, 12, 4, 60}; 

    MatrixChain(test1);
    MatrixChain(test2);

    cout << "Author: Nero Li\n";

    return 0;
}
