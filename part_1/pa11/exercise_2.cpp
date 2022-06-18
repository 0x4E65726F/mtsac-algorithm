/*  Program: PA_11_exercise_2
    Author: Nero Li
    Class: CSCI 220   
    Date: 11/16/2021	     
    Description: 
        You will implement a better population database for California counties
        using an AVL tree from exercise 1 to store the database records. Define 
        and implement PopBetterMap class that supports standard map operations 
        using county code as a key for each record (no duplicate keys). Your 
        PopBetterMap class uses an AVL tree to store population records. Download 
        the data file p4small.txt, containing a list of a few population records 
        – county code, population in million, and county with state abbreviation 
        (3 fields separated by commas). Build the AVL tree from the records of the
        input data file by inserting one record at a time to the tree. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Entry.h"
#include "AVLEntry.h"
#include "AVLTree1.h"

using namespace std;

class PopBetterMap
{
private:
    struct County
    {
        int pop;
        string county;
    };
    AVLTree<AVLEntry<Entry<int, County>>> countyTree;
    AVLTree<AVLEntry<Entry<int, County>>>::Iterator itr{NULL};
public:
    // constructor accepts file name and construct search tree
    PopBetterMap(string filename)
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
        cout << endl;
    }

    // print appropriate message and erase node if found
    void erase(int code)
    {
        itr = countyTree.find(code);
        if (itr == countyTree.end())
        {
            cout << "Nothing found...\n";
        }
        else
        {
            cout << "Found data:\n";
            cout << (*itr).key() << "," << (*itr).value().pop << ",\"" << (*itr).value().county << "\"" << endl;
            countyTree.erase(code);
            cout << "Data erased...\n";
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

    // Draw the tree (key only)
    void draw()
    {
        countyTree.draw();
    }
};

void menu()
{
    cout << "   Operating Menu\n" << endl;
    cout << "1. List all records" << endl;
    cout << "2. Search for record" << endl;
    cout << "3. Insert new record" << endl;
    cout << "4. Delete a record" << endl;
    cout << "5. Draw the tree" << endl;
    cout << "6. Exit program" << endl;
    cout << endl;
}

int main()
{
    PopBetterMap p4small("p4small.txt");
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
            p4small.draw();
            break;
        case 6:
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