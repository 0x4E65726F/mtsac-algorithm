/*  Program: PA_12_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/31/2022	     
    Description: 
        Option C: Implement the simple external sorting using algorithm 
        from the “external sorting” section of the Shaffer book (simple 
        merge with no replacement selection). You will sort a binary 
        file with 100,000 integers and assume a block size is 4KB. 
        Output first 5 values and last 5 values when you are done.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int BUFFER_SIZE{4000};

void seperateFile(string str)
{
    ifstream fin;
    fin.open(str, ios::binary);
    
    if (!fin)
    {
        cout << "File error\n";
        return;
    }
    
    fin.seekg(0, ios::end);
    int totalNum = fin.tellg() / sizeof(int);
    char fileBuffer[sizeof(int)];
    fin.close();

    fin.open(str, ios::binary);
    ofstream fout;
    fout.open("firstHalf.bin", ios::binary);
    for (int i = 0; i <= totalNum / 2; ++i)
    {
        fin.read(fileBuffer, sizeof(int));
        if (fin.gcount() != 0)
            fout.write(fileBuffer, sizeof(int));
    }
    fout.close();

    fout.open("secondHalf.bin", ios::binary);
    for (int i = 0; i <= totalNum / 2; ++i)
    {
        fin.read(fileBuffer, sizeof(int));
        if (fin.gcount() != 0)
            fout.write(fileBuffer, sizeof(int));
    }
    fout.close();
    fin.close(); 
}

void sortFile(string str1, string str2)
{
    ifstream fin1;
    ifstream fin2;
    ofstream fout1;
    ofstream fout2;
    int inBuffer1[BUFFER_SIZE / sizeof(int)];
    int inBuffer2[BUFFER_SIZE / sizeof(int)];
    int outBuffer1[BUFFER_SIZE / sizeof(int)];
    int outBuffer2[BUFFER_SIZE / sizeof(int)];

    fin1.open(str1, ios::binary);
    fin2.open(str2, ios::binary);
    fout1.open("processOdd1.bin", ios::binary);
    fout2.open("processOdd2.bin", ios::binary);

    if (!fin1 || !fin2)
    {
        cout << "File error\n";
        return;
    }

    int runCount = 1;
    fin1.read(reinterpret_cast<char*>(&inBuffer1), BUFFER_SIZE);
    fin2.read(reinterpret_cast<char*>(&inBuffer2), BUFFER_SIZE);
    while (fin1.gcount() != 0 && fin2.gcount() != 0)
    {
        
        fout1.write(reinterpret_cast<char*>(&outBuffer1), BUFFER_SIZE);
        fout2.write(reinterpret_cast<char*>(&outBuffer2), BUFFER_SIZE);
        fin1.read(reinterpret_cast<char*>(&inBuffer1), BUFFER_SIZE);
        fin2.read(reinterpret_cast<char*>(&inBuffer2), BUFFER_SIZE);
    }
}

void sortFile(string str)
{
    ifstream fin;
    ofstream fout;
    vector<int> vec;

    fin.open(str, ios::binary);
    int value = 0;
    fin.read(reinterpret_cast<char*>(&value), sizeof(int));
    while (fin.gcount() != 0)
    {
        vec.push_back(value);
        fin.read(reinterpret_cast<char*>(&value), sizeof(int));
    }
    fin.close();

    sort(vec.begin(), vec.end());

    fout.open(str, ios::binary);
    fout.clear();
    for (int i : vec)
        fout.write(reinterpret_cast<char*>(&i), sizeof(int));
    fout.close();
}

void mergeFile(string str1, string str2)
{
    ifstream fin1;
    ifstream fin2;
    ofstream fout;

    fin1.open(str1, ios::binary);
    fin2.open(str2, ios::binary);
    fout.open("result.bin", ios::binary);

    int i;
    int j;
    fin1.read(reinterpret_cast<char*>(&i), sizeof(int));
    fin2.read(reinterpret_cast<char*>(&j), sizeof(int));

    while (fin1.gcount() && fin2.gcount())
    {
        int k;
        if (i < j)
        {
            k = i;
            fin1.read(reinterpret_cast<char*>(&i), sizeof(int));
        }
        else
        {
            k = j;
            fin2.read(reinterpret_cast<char*>(&j), sizeof(int));
        }
        fout.write(reinterpret_cast<char*>(&k), sizeof(int));
    }

    while (fin1.gcount())
    {
        fout.write(reinterpret_cast<char*>(&i), sizeof(int));
        fin1.read(reinterpret_cast<char*>(&i), sizeof(int));
    }
    
    while (fin2.gcount())
    {
        fout.write(reinterpret_cast<char*>(&j), sizeof(int));
        fin2.read(reinterpret_cast<char*>(&j), sizeof(int));
    }
    
    fin1.close();
    fin2.close();
    fout.close();
}

void printFinalResult(string str)
{
    vector<int> vec;
    ifstream file;
    file.open(str, ios::binary);
    
    if (!file)
    {
        cout << "err\n";
        return;
    }
    file.seekg(0, ios::end);
    int totalNum = file.tellg() / sizeof(int);
    file.close();

    file.open(str, ios::binary);

    int value = 0;
    file.read(reinterpret_cast<char*>(&value), sizeof(int));
    while (file.gcount() != 0)
    {
        vec.push_back(value);
        file.read(reinterpret_cast<char*>(&value), sizeof(int));
    }

    for (int i = 1; i <= vec.size(); ++i)
        if (i <= 5 || i > vec.size() - 5)
            cout << "vec[" << i - 1 << "] = " << vec[i - 1] << endl;
    
}

int main()
{
    seperateFile("filetoSort.bin");
    sortFile("firstHalf.bin");
    sortFile("secondHalf.bin");
    mergeFile("firstHalf.bin", "secondHalf.bin");
    printFinalResult("result.bin");

    cout << "Author: Nero Li\n";

    return 0;
}
