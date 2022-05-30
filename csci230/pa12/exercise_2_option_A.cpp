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
    for (int i = 0; i < SIZE; ++i)
    {
        if (!blocks[i])
        {
            if (!countingHoleSize)
            {
                if (withOutput)
                    cout << i << "\t";
                countingHoleSize = true;
                holeStartPoint = i;
                size = 1;
            }
            else if (i == SIZE - 1)
            {
                if (withOutput)
                    cout << ++size << endl;
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
                if (withOutput)
                    cout << size << endl;
                countingHoleSize = false;
                holes[holeStartPoint] = size;
            }
        }
    }

    return holes;
}

void bestFit()
{
    bool blocks[SIZE] = {0};
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
        int cloestRange = SIZE;
        int holeStartPoint = -1;

        for (int i = 0; i < SIZE; ++i)
        {
            if (!blocks[i])
            {
                int curStartPoint = i;
                int curSize = 0;
                while (i < SIZE && !blocks[i])
                {
                    ++curSize;
                    ++i;
                }
                int curRange = curSize - allocationTime;
                if (curRange < 0)
                {
                    continue;
                }
                else if (curRange < cloestRange)
                {
                    cloestRange = curRange;
                    holeStartPoint = curStartPoint;
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
        }
    }

    checkAvailableHoles(blocks);
}

void firstFit()
{
    bool blocks[SIZE] = {0};
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
        int holeStartPoint = -1;
        map<int, int> holes = checkAvailableHoles(blocks);
        for (auto i : holes)
        {
            if (i.second >= allocationTime)
            {
                holeStartPoint = i.first;
                break;
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
        }
    }

    checkAvailableHoles(blocks, true);
}

int main()
{
    srand(time(NULL));
    // bestFit();
    firstFit();
    
    cout << "Author: Nero Li\n";

    return 0;
}
