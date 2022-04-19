#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include <iostream>
#include <array>
#include <string>
#include <climits>
#include <ctime>

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

#endif