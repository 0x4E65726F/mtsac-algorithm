/*  Program: PA_12_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/31/2022	     
    Description: 
        Option B: Perform file I/O of 100,000 random integers with 
        three options below and collect times (3 different times 
        for input and 3 different times for output). 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE{100000};

int generateNumber()
{
    return (rand() % INT_MAX);
}

void txtOneVal(string str)
{
    ofstream file;

    file.open(str, ios::binary);
    for (int i = 0; i < SIZE; ++i) 
        file << generateNumber() << ' ';

    file.close();
}

void binOneVal(string str)
{
    ofstream file;

    file.open(str, ios::binary);
    int value;
    for (int i = 0; i < SIZE; ++i) 
    {
        value = generateNumber();
        file.write(reinterpret_cast<char*>(&value), sizeof(int));
    }

    file.close();
}

void bin256Val(string str)
{
    ofstream file;

    file.open(str, ios::binary);
    int value[256];

    for (int i = 0; i < SIZE / 256; ++i) 
    {
        for (int j = 0; j < 256; ++j) 
            value[j] = generateNumber();
        file.write(reinterpret_cast<char*>(&value), sizeof(int) * 256);
    }

    file.close();
}

void readFile(string str, bool isTxt = false)
{
    int vec[SIZE];
    ifstream file;
    file.open(str, ios::binary);

    if (!file)
    {
        cout << "File error\n";
        return;
    }

    if (isTxt)
    {
        int i = 0;
        while (!file.eof())
        {
            int n;
            file >> n;
            vec[i++] = n;
        }
        
    }
    else
        file.read(reinterpret_cast<char*>(vec), sizeof(int) * SIZE);

    cout << "In file " << str << ":\n";
    for (int i = 0; i < 5; ++i)
        cout << "vec[" << i << "] = " << vec[i] << endl;
    cout << endl;
}

int main()
{
    srand(time(NULL));
    vector<string> str;
    str.push_back("randomInTxt.txt");
    str.push_back("randomInBin.bin");
    str.push_back("randomIn256Bin.bin");

    txtOneVal(str[0]);
    binOneVal(str[1]);
    bin256Val(str[2]);

    readFile(str[0], true);
    readFile(str[1]);
    readFile(str[2]);

    cout << "Author: Nero Li\n";

    return 0;
}
