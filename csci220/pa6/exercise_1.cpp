/*  Program: PA_6_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 10/08/2021	     
    Description: 
        You need to write a program that simulates call lines at a calling center. A 
        line is basically a queue object, and you can assume one customer representative 
        per line. Based on some preliminary estimate, customers are expected to call 
        in random integer intervals of 1 to n minutes (inclusively and two customers 
        are expected to call between that interval so if customer 1 calls at minute 3, 
        then customer 2 is expected to call between minute 4 and 7 when n is 4). Also, 
        it is expected to take a random integer interval of 1 to m minutes to serve 
        each customer. If the call arrival rate is faster than the service rate (n<m), 
        the line will grow indefinitely. Even with a "balanced" rate (n = m), randomness 
        can still possibly cause a long line over a period. You are going to run the 
        calling center simulation with one line (l = 1) for a period of t minutes using 
        the following algorithm (enter input parameters from keyboard and use l = 1, 
        t = 30, n = 4, and m = 4 as test case 0)
        
    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <queue>

using namespace std;

int randRange(const unsigned int& start, const unsigned int& end)
{
    int scalingFactor = end - start + 1;
    return rand() % scalingFactor + start;
}

void func(string str, int l, int t, int n, int m)
{
    ofstream fout;
    queue<int> customerLine[4];
    queue<int> startWaitingTime[4];
    bool serving{false};
    int customerID{1};
    int totalServed{0};
    int callTime{randRange(1, n)};
    int serveEnd{0};
    size_t maxLineSize{0};
    float curWaitTime{0};
    float maxWaitTime{0};
    float totWaitTime{0};
    float avgWaitTime{0};

    fout.open(str, ios::binary);
    --l;

    cout << str << endl;
    for (int i = 1; i <= t; ++i) 
    {
        if (i <= 15 || i >= (t - 15))
        {
            cout << "Minute: " << i << endl;
            fout << "Minute: " << i << endl;
        }
        if (i == callTime)
        {
            if (i <= 15 || i >= (t - 15))
            {
                cout << "Customer #" << customerID << " calls..." << endl;
                fout << "Customer #" << customerID << " calls..." << endl;
            }
            customerLine[l].push(customerID);
            startWaitingTime[l].push(i);
            callTime += randRange(1, n);
            if (customerLine[l].size() > maxLineSize)
            {
                maxLineSize = customerLine[l].size();
            }
            
            ++customerID;
        }
        if (i == serveEnd)
        {
            if (i <= 15 || i >= (t - 15))
            {
                cout << "Service was just completed for a customer..." << endl;
                fout << "Service was just completed for a customer..." << endl;
            }
            serving = false;
            ++totalServed;
        }
        if (!serving && !customerLine[l].empty())
        {
            if (i <= 15 || i >= (t - 15))
            {
                cout << "Start serving customer #" << customerLine[l].front() << "..." << endl;
                fout << "Start serving customer #" << customerLine[l].front() << "..." << endl;
            }
            
            curWaitTime = i - startWaitingTime[l].front();
            if (curWaitTime > maxWaitTime)
            {
                maxWaitTime = curWaitTime;
            }
            totWaitTime += curWaitTime;
            
            customerLine[l].pop();
            startWaitingTime[l].pop();
            serving = true;
            serveEnd = i + randRange(1, m);
        }

        if (customerLine[l].size() > maxLineSize)
        {
            maxLineSize = customerLine[l].size();
        }
        
    }

    avgWaitTime = totWaitTime / totalServed;

    cout << "--------------------Result--------------------" << endl;
    cout << "Number of customers served: " << totalServed << endl;
    cout << "Number of customers left in queue: " << customerLine[l].size() << endl;
    cout << "Maximum number of customers in the line at any time: " << maxLineSize << endl;
    cout << "Longest wait time that a customer experiences before being served: " << maxWaitTime << endl;
    cout << "Average wait time for all customers that were served: " << avgWaitTime << endl;
    
    fout << "--------------------Result--------------------" << endl;
    fout << "Number of customers served: " << totalServed << endl;
    fout << "Number of customers left in queue: " << customerLine[l].size() << endl;
    fout << "Maximum number of customers in the line at any time: " << maxLineSize << endl;
    fout << "Longest wait time that a customer experiences before being served: " << maxWaitTime << endl;
    fout << "Average wait time for all customers that were served: " << avgWaitTime << endl;
    fout << endl << "Author: Nero Li\n";
}

int main()
{
    srand(time(NULL));
    
    func("test_case_0.txt", 1, 30, 4, 4);
    func("test_case_1.txt", 1, 360, 4, 4);
    func("test_case_2.txt", 1, 360, 3, 4);
    func("test_case_3.txt", 1, 360, 5, 4);

    cout << "Author: Nero Li\n";
    return 0;
}