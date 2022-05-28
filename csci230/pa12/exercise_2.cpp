/*  Program: PA_#_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: MM/DD/2022	     
    Description: 
        ----------------------------------------------------------------

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int BUFFER_SIZE{4096};

void printVector(vector<int> vec)
{
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}

void test(string str)
{
    ifstream fin;
    fin.open(str, ios::binary);

    vector<string> fileName;
    int fileCount = 0;
    char fileBuffer[BUFFER_SIZE];
    
    if (!fin)
    {
        cout << "File error\n";
        return;
    }
    
    // Seperate the file 
    fin.read(fileBuffer, BUFFER_SIZE);
    while (fin.gcount() != 0)
    {
        ofstream fout;
        string cur = "file_";
        ++fileCount;
        cur += to_string(fileCount);
        cur += ".bin";
        fileName.push_back(cur);
        fout.open(cur, ios::binary);
        if (!fout)
        {
            cout << "File error\n";
            return;
        }
        fout.write(fileBuffer, BUFFER_SIZE);
        fout.close();
        fin.read(fileBuffer, BUFFER_SIZE);
    }
    fin.close();

    // Sort each single file   
    vector<int> targetVec;
    char intBuffer[sizeof(int)]; 
    for (string str : fileName)
    {
        ifstream fcur;
        fcur.open(str, ios::binary | ios::ate);
        if (!fcur)
        {
            cout << "File error\n";
            return;
        }
        else
        {
            cout << str << " opened\n";
        }

        int value;
        fcur.read(reinterpret_cast<char*>(&value), sizeof(value));
        cout << value;
        
        cout << endl;
        fcur.close();
    }
    
}

int main()
{
    test("filetoSort.bin");

    cout << "Author: Nero Li\n";

    return 0;
}
