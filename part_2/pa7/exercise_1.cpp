/*  Program: PA_7_exercise_1  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/19/2022	     
    Description: 
        Try Brute Force pattern matching, BM pattern matching, and KMP 
        pattern matching on various T and P and then modify the code to 
        count the number of comparisons.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>

using namespace std;

int BruteForceMatch(string T, string P)
{
    int n = T.size();
    int m = P.size();

    for (int i = 0; i <= n - m; ++i)
    {
        int j = 0;
        while (j < m && T[i + j] == P[j])
            ++j;
        if (j == m)
            return i;
    }

    return -1;
}

/* Code from Book */
/** Simplified version of the Boyer-Moore algorithm. Returns the index of
 *  the leftmost substring of the text matching the pattern, or -1 if none.
 */
                                        // construct function last
std::vector<int> buildLastFunction(const string& pattern) 
{
    const int N_ASCII = 128;			// number of ASCII characters
    int i;
    std::vector<int> last(N_ASCII);		// assume ASCII character set
    for (i = 0; i < N_ASCII; i++)		// initialize array
        last[i] = -1;
    for (i = 0; i < pattern.size(); i++) {
        last[pattern[i]] = i;			// (implicit cast to ASCII code)
    }
    return last;
}

int BMmatch(const string& text, const string& pattern) 
{
    std::vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;
    if (i > n - 1)				// pattern longer than text?
        return -1;				// ...then no match
    int j = m - 1;
    do 
    {
        if (pattern[j] == text[i])
        if (j == 0) return i;			// found a match
        else {					// looking-glass heuristic
            i--; j--;				// proceed right-to-left
        }
        else {					// character-jump heuristic
            i = i + m - std::min(j, 1 + last[text[i]]);
            j = m - 1;
        }
    } while (i <= n - 1);
    return -1;					// no match
}

std::vector<int> computeFailFunction(const string& pattern) 
{
    std::vector<int> fail(pattern.size()); 
    fail[0] = 0;
    int m = pattern.size();
    int j = 0;
    int i = 1;
    while (i < m) {
        if (pattern[j] == pattern[i]) {		// j + 1 characters match
            fail[i] = j + 1;
            i++;  j++;
        }
        else if (j > 0)				// j follows a matching prefix
            j = fail[j - 1];
        else {					// no match
            fail[i] = 0;
            i++;
        }
    }
    return fail;
}
                            // KMP algorithm
int KMPmatch(const string& text, const string& pattern) 
{
    int n = text.size();
    int m = pattern.size();
    std::vector<int> fail = computeFailFunction(pattern);
    int i = 0;					// text index
    int j = 0;					// pattern index
    while (i < n) {
        if (pattern[j] == text[i]) {
            if (j == m - 1)
                return i - m + 1;			// found a match
            i++;  j++;
        }
        else if (j > 0) j = fail[j - 1];
        else i++;
    } 
    return -1;					// no match
}
/* Code from Book */

void testCase(string T, string P)
{
    cout << "Text:\t\t" << T << endl;
    cout << "Pattern:\t" << P << endl;
    cout << "Brute:\t\t" << BruteForceMatch(T, P) << endl;
    cout << "BM:\t\t" << BMmatch(T, P) << endl;
    cout << "KMP:\t\t" << KMPmatch(T, P) << endl;
    cout << endl;
}

void fileCase(string str)
{
    ifstream fin;
    fin.open(str, ios::binary);
    string T("\0");
    string P("\0");
    
    if (!fin)
    {
        cout << "No File\n";
        return;
    }   
    else
    {
        while (!fin.eof())
        {
            string temp;
            getline(fin, temp);
            T += temp;
            T += "\n";
        }
    }
    cout << "TextSrc:\t" << str << endl;
    cout << "Pattern:\t";
    cin >> P;
    cout << "Brute:\t\t" << BruteForceMatch(T, P) << endl;
    cout << "BM:\t\t" << BMmatch(T, P) << endl;
    cout << "KMP:\t\t" << KMPmatch(T, P) << endl;
    cout << endl;

}

int main()
{
    testCase("a pattern matching algorithm", "rithm");
    testCase("a pattern matching algorithm", "rithn");
    testCase("GTTTATGTAGCTTACCTCCTCAAAGCAATACACTGAAAA", "CTGA");
    testCase("GTTTATGTAGCTTACCTCCTCAAAGCAATACACTGAAAA", "CTGG");

    fileCase("usdeclarPC.txt");
    fileCase("usdeclarPC.txt");
    fileCase("humanDNA.txt");
    fileCase("humanDNA.txt");
    cout << "Modified by: Nero Li\n";

    return 0;
}
