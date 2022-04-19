/*  Program: PA_2_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 03/08/2022	     
    Description: 
        Perform a comparative analysis that studies the collision rates 
        for various hash codes for character strings, such as various 
        polynomial hash codes for different values of the parameter a. 
        Use a hash table to determine collisions, but only count 
        collisions where different strings map to the same hash code 
        (not if they map to the same location in this hash table). Test 
        these hash codes on text files found on the Internet.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int cyclicShiftHash(string s, int a)
{
    int len = s.size();
    unsigned int h = 0;
    for (int i = 0; i < len; i++) 
    {
        h = (h << a) | (h >> (32 - a));
        h += s[i];
    }
    return (int)h;
}

int polynomialHash(string s, int a) 
{
    int len = s.size();
    int h = 0;
    for (int i = 0; i < len; ++i) 
        h = s[i] + a * h;
    return h;
}

void HashTest(string file, string msg, bool isPoly, int a)
{
    int numOfCollisions = 0;
    int numOfWords = 0;
    unordered_map<int, int> hashCollisionCount; 
    unordered_set<string> wordCheck;
    ifstream fin;
    fin.open(file, ios::binary);

    if (!fin)
        return;

    while (!fin.eof())
    {
        string cur;
        fin >> cur;
        
        if (wordCheck.find(cur) == wordCheck.end())
        {
            int hash = isPoly ? polynomialHash(cur, a) : cyclicShiftHash(cur, a);
            
            if (hashCollisionCount.find(hash) == hashCollisionCount.end())
                hashCollisionCount[hash] = 0;
            else
                ++hashCollisionCount[hash];

            wordCheck.insert(cur);
        }
    }

    for (auto i : hashCollisionCount)
    {
        if (i.second)
            numOfCollisions += i.second; 
    }

    cout << msg << " Hash in Number " << a << " Results\n";
    cout << "- Number of words:\t" << wordCheck.size() << endl;
    cout << "- Number of collisions:\t" << numOfCollisions << endl;
    cout << endl;
    fin.close();
}

int main()
{
    HashTest("usdeclarPC.txt", "Polynomial", true, 39);
    HashTest("usdeclarPC.txt", "Polynomial", true, 40);
    HashTest("usdeclarPC.txt", "Polynomial", true, 41);
    HashTest("usdeclarPC.txt", "Cyclic Shift", false, 1);
    HashTest("usdeclarPC.txt", "Cyclic Shift", false, 5);
    HashTest("usdeclarPC.txt", "Cyclic Shift", false, 13);
    
    cout << "Author: Nero Li\n";

    return 0;
}
