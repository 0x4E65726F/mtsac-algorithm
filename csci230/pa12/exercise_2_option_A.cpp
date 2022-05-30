/*  Program: PA_12_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 05/31/2022	     
    Description: 
        Option A: Perform Project P-14.1 on page 687 of C++ book 
        in C++ or Java. We will limit to only two of the four 
        algorithms.
        Write a C++ class that simulates the best-fit, worst-fit, first-fit, and nextfit algorithms for memory management. Determine experimentally which
method is the best under various sequences of memory requests.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

const int SIZE = 1024;

int generateNumber()
{
    return (rand() % 15 + 5);
}

int randomSpace()
{
    return (rand() % SIZE);
}

map<int, int> checkAvailableHoles(bool blocks[], bool withOutput = false)
{
    map<int, int> holes;
    bool countingHoleSize = false;
    int holeStartPoint = -1;
    int size = 1;

    int countHoles = 0;
    int countSize = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        if (blocks[i])
        {
            if (!countingHoleSize)
            {
                ++countHoles;
                countingHoleSize = true;
                holeStartPoint = i;
                size = 1;
            }
            else if (i == SIZE - 1)
            {
                ++size;
                countSize += size;
            }
            else
            {
                ++size;
            }
        }
        else
        {
            if (countingHoleSize)
            {
                countSize += size;
                countingHoleSize = false;
                holes[holeStartPoint] = size;
            }
        }
    }

    if (withOutput)
        cout << " - " << countHoles << " block(s) are still available.\n" << " - " << countSize * 4 << " byte(s) of memory still available.\n" << endl;
    

    return holes;
}

void doFit(bool isFirstFit)
{
    bool blocks[SIZE];
    for (int i = 0; i < SIZE; ++i) 
        blocks[i] = false;
    int totalAllocation = 0;
    while (totalAllocation <= (SIZE) / 2)
    {
        int allocationTime = generateNumber();
        int startBlock = randomSpace();
        totalAllocation += allocationTime;
        for (int i = 0; i < allocationTime && i + startBlock < SIZE; ++i) 
            blocks[startBlock + i] = true;
    }

    bool allocationFail = false;
    while (!allocationFail)
    {
        int allocationTime = generateNumber();
        map<int, int> holes = checkAvailableHoles(blocks);
        int holeStartPoint = -1;
        
        if (isFirstFit)
        {
            // main part for first-fit
            for (auto i : holes)
            {
                if (i.second >= allocationTime)
                {
                    holeStartPoint = i.first;
                    break;
                }
            }
        }
        else
        {
            // main part for best-fit
            int minGap = SIZE;
            for (auto i : holes)
            {
                int curGap = i.second - allocationTime;
                if (curGap >= 0 && curGap < minGap)
                {
                    minGap = curGap;
                    holeStartPoint = i.first;
                }
            }
        }
        

        if (holeStartPoint = -1)
        {
            allocationFail = true;
        }
        else
        {
            for (int j = 0; j < allocationTime; ++j) 
                blocks[holeStartPoint + j] = true;
            allocationFail = false;
        }
    }

    if (isFirstFit)
        cout << "For first-fit:\n";
    else
        cout << "For best-fit:\n";
    checkAvailableHoles(blocks, true);
}

int main()
{
    srand(time(NULL));
    
    doFit(false);
    doFit(true);
    
    cout << "Author: Nero Li\n";

    return 0;
}
