#include <iostream>
#include <cmath>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

string distinctCharacters(string X)
{
    string C;
    unordered_set<char> U;

    for (char i : X)
        U.insert(i);

    for (char i : U)
        C.push_back(i);

    return C;
}

unordered_map<char, int> char_count;

void computeFrequences(string C, string X)
{
    for (char i : C)
    {
        int count = 0;
        for (char j : X)
            if (i == j)
                ++count;
        char_count.insert(pair<char, int>(i, count));
    }
    
}

int getFrequency(char c)
{
    return char_count[c];
}

int main()
{
    computeFrequences(distinctCharacters("abcbaba"), "abcbaba");
    std::cout << getFrequency('a');
    return 0;
}