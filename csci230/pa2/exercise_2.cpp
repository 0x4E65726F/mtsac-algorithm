/*  Program: PA_2_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: MM/DD/2022	     
    Description: 
        Create a program to collect some data about chain hashing that 
        you worked on in previous PA. You would be able to enter the 
        name of input data file and a load factor. Each input data file 
        will have N records and the first value in the file will tell 
        you how many records are in the file. You would need to use N 
        and the load factor to determine the size of the hash table. Do 
        not rehash the table like the version in the book (i.e., need to 
        modify the code from the book). The first value of each record 
        will be the key (county/state code as integer type) and 
        remaining items on each record will be the value (population and 
        county/state). After all the entries are inserted to the table, 
        print the table size, average number of probes, and maximum 
        number of probes for the worst case. It would take at least one 
        probe for each insertion (checking initial location). Therefore, 
        it would be two probes if second location is examined.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include "HashMap.h"

using namespace std;

struct County
{
    int pop;
    string county;
};

int findPrime(int n)
{
    int ans = n;
    while (true)
    {
        bool notPrime = false;
        for (int i = 2; i < ans; ++i)
        {
            if (ans % i == 0)
            {
                ++ans;
                notPrime = true;
                break;
            }
        }
        
        if (!notPrime)
            break;
    }
    return ans;
}

void hashTest(string str, double lf = -1)
{
    ifstream fin;
    fin.open(str, ios::binary);
    
    if (!fin)
        return;

    int n;
    fin >> n;
    int N;
    if (lf == -1)
        N = findPrime(n);
    else
        N = findPrime(n / lf);
    HashMap<int, County> countyMap(N);

    while (!fin.eof())
    {
        County newData;
        string countyData;
        bool gotKey = false;
        int code = -1;
        getline(fin, countyData);

        for (int i = 0; i < countyData.size(); ++i)
        {
            if (countyData[i] == ',')
            {
                gotKey = true;
            }
            else if (countyData[i] >= '0' && countyData[i] <= '9')
            {
                if (gotKey)
                {
                    if (newData.pop == -1)
                    {
                        newData.pop = countyData[i] - '0';
                    }
                    else
                    {
                        newData.pop *= 10;
                        newData.pop += countyData[i] - '0';
                    }
                }
                else
                {
                    if (code == -1)
                    {
                        code = countyData[i] - '0';
                    }
                    else
                    {
                        code *= 10;
                        code += countyData[i] - '0';
                    }
                }
            }
            else if (countyData[i] == '\"')
            {
                ++i;
                while (countyData[i] != '\"')
                {
                    newData.county += countyData[i];
                    ++i;
                }
            }
        }
        countyMap.put(code, newData);
    }

    cout << "For " << str;
    if (lf != -1)
        cout << " with load factor " << lf;
    cout << endl;
    cout << "- Table size:\t\t\t" << N << endl;
    cout << "- Average number of probes:\t" << countyMap.getAvgNum() << endl;
    cout << "- Maximum number of probes:\t" << countyMap.getMaxNum() << endl;
    cout << endl;
}

int main()
{
    hashTest("popSmall.txt"); 
    hashTest("popLarge.txt", 0.25); 
    hashTest("popLarge.txt", 0.5);
    hashTest("popLarge.txt", 0.75);
    hashTest("popLarge.txt", 0.9);

    cout << "Modified by: Nero Li\n";

    return 0;
}
