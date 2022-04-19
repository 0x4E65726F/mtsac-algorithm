/*  Program: PA_10_exercise_2
    Author: Nero Li
    Class: CSCI 220   
    Date: 11/09/2021	     
    Description: 
        You will implement a simple population database for California counties
        using a simple search tree from exercise 1 to store the database records. 
        Define and implement PopMap class that supports standard map operations 
        using county code as a key for each record (no duplicate keys). Your 
        PopMap class uses binary search tree to store population records. Download 
        the data file p4small.txt, containing a list of a few population records 
        – county code, population in million, and county with state abbreviation 
        (3 fields separated by commas). Build the search tree from the records of
        the input data file by inserting one record at a time to the tree. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
#include "BinaryTree.h"
#include "Entry.h"
#include "RuntimeExceptions.h"

using namespace std;

class PopMap
{
private:
    struct County
    {
        int pop;
        string county;
    };
    SearchTree<Entry<int,County>> countyTree;
    SearchTree<Entry<int,County>>::Iterator itr{NULL};
public:
    // constructor accepts file name and construct search tree
    PopMap(string filename)
    {
        ifstream fin;
        string countyData;

        fin.open(filename, ios::binary);
        while (!fin.eof())
        {
            County newData;
            int code{-1};
            bool gotKey{false};
            newData.pop = -1;
            newData.county = "";
            
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
            countyTree.insert(code, newData);
        }
        countyTree.erase(-1);
    }

    // print appropriate message and data if found
    void find(int code)
    {
        itr = countyTree.find(code);
        if (itr == countyTree.end())
        {
            cout << "Nothing found.\n";
        }
        else
        {
            cout << (*itr).key() << "," << (*itr).value().pop << ",\"" << (*itr).value().county << "\"" << endl;
        }
        
        numberOfNodesExamined("search", countyTree.trace());
        cout << endl;
    }

    // print appropriate message and insert node if not found
    // replace data if found
    void insert(int code, int pop, string county)
    {
        County newData;
        newData.county = county;
        newData.pop = pop;
        
        itr = countyTree.find(code);
        if (itr == countyTree.end())
        {
            cout << "Inserting a new data...\n";
        }
        else
        {
            cout << "Replacing exist data...\n";
        }

        countyTree.insert(code, newData);
        numberOfNodesExamined("insert", countyTree.trace());
        cout << endl;
    }

    // print appropriate message and erase node if found
    void erase(int code)
    {
        itr = countyTree.find(code);
        if (itr == countyTree.end())
        {
            cout << "Nothing found...\n";
            numberOfNodesExamined("erase", countyTree.trace());
        }
        else
        {
            cout << "Found data:\n";
            cout << (*itr).key() << "," << (*itr).value().pop << ",\"" << (*itr).value().county << "\"" << endl;
            countyTree.erase(code);
            cout << "Data erased...\n";
            numberOfNodesExamined("erase", countyTree.trace());
        }
        
        cout << endl;
    }

    // print one record per line using an in-order traversal
    void print()
    {
        itr = countyTree.begin();
        while (!(itr == countyTree.end()))
        {
            cout << (*itr).key() << "," << (*itr).value().pop << ",\"" << (*itr).value().county << "\"" << endl;
            ++itr;
        }
        cout << endl;
    }
protected:
    void numberOfNodesExamined(string op, int num)
    {
        cout << "Number of nodes examined for " << op << ": " << num << endl;  
    }
};

void menu()
{
    cout << "   Operating Menu\n" << endl;
    cout << "1. List all records" << endl;
    cout << "2. Search for record" << endl;
    cout << "3. Insert new record" << endl;
    cout << "4. Delete a record" << endl;
    cout << "5. Exit program" << endl;
    cout << endl;
}

int main()
{
    PopMap p4small("p4small.txt");
    int choice;
    int code;
    int pop;
    string county;
    bool exitCode{true};
    
    menu();
    while (exitCode)
    {
        cout << "Please input your option: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p4small.print();
            break;
        case 2:
            cout << "Please input the code: \n";
            cin >> code;
            p4small.find(code);
            break;
        case 3:
            cout << "Please input the code: \n";
            cin >> code;
            cout << "Please input the population: \n";
            cin >> pop;
            cout << "Please input the county data: \n";
            getline(cin, county);
            getline(cin, county);
            p4small.insert(code, pop, county);
            break;
        case 4:
            cout << "Please input the code: \n";
            cin >> code;
            p4small.erase(code);
            break;
        case 5:
            exitCode = false;
            cout << endl;
            break;
        default:
            break;
        }
    }

    cout << "Modified by: Nero Li\n";
    return 0;
}