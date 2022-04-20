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
    int n = d.size();
    vector<vector<int>> N(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        N[i][i] = 0;
    

    for (int b = 0; b < n; ++b)
        for (int i = 0; i <= n - b - 1; ++i)
        {
            int j = i + b;
            N[i][j] = INT_MAX;
            for (int k = 0; k < j; ++k) 
            {
                int a = N[i][j];
                int b = N[i][k] + N[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                N[i][j] = a < b ? a : b;
            }
        }
    

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << N[i][j] << "\t";
        cout << endl;
    }
    
    
}

int main()
{
    vector<int> test1 = {2, 10, 10, 50, 50, 20}; 
    MatrixChain(test1);

    cout << "Author: Nero Li\n";

    return 0;
}
