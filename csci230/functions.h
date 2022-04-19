#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include <iostream>
#include <array>
#include <string>
#include <climits>
#include <ctime>
#include <fstream>
#include <chrono>

#define WINDOWS true 

void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}

void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(INT_MAX, '\n');
}

int getInt(std::string prompt, bool exitOnError = true)
{
    int rtnVal{0};
    std::cout << prompt;
    std::cin >> rtnVal;
    if (std::cin.fail() && exitOnError)
    {
        exit(-1);
    }
    return rtnVal;
}

void swap(int& a, int& b)
{
    // exp. a = 5, b = 6
    a ^= b; // a = 5 xor 6
    b ^= a; // b = 6 xor (5 xor 6) = 5
    a ^= b; // a = (5 xor 6) xor 5 = 6
}

template<typename T, int size>
void printArray(std::array<T, size> array)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        std::cout << array[i] << std::endl;
    }
}

template<typename T>
T getUserInput(const std::string& prompt)
{
    T input{};
    std::cout << prompt;
    std::cin >> input;

    return input;
}

char toLower(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z')
        ? symbol - 'A' + 'a'
        : symbol;
}

int randRange(const unsigned int& start, const unsigned int& end)
{
    int scalingFactor = end - start + 1;
    return rand() % scalingFactor + start;
}

void seedRandRange(unsigned int seed = time(NULL))
{
    srand(seed);
}

int findDuplicate(int A[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        while (A[i] != i + 1) 
        {
            if (A[i] == A[A[i] - 1]) // A[i] = i + 1
            {
                return A[i];
            }
            int tmp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = tmp;
        }
    }
    
    return -1;
}

void checkFile(std::string inputName, std::string outputName)
{
    std::ifstream fin;
    std::ofstream fout;

    fin.open(inputName, std::ios::binary);
    fout.open(outputName, std::ios::binary);

    auto start = std::chrono::high_resolution_clock::now();

    /*
        Code here
    */

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << std::endl;
    fout << (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * (double)1e-6) << " ms" << std::endl;
}

#endif