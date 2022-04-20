/*  Program: PA_8_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/26/2022	     
    Description: 
        Implement a standard trie for a set of ASCII strings including 
        a terminating character $ for each word. You might want to look 
        at the trie in zyBook. Create a class that has a constructor 
        that accepts the name of an input file as a parameter (a string), 
        and the class should have an operation that test whether a given 
        string is stored in the trie. The driver should allow user to 
        specify the input data file, output number of words in the trie, 
        and then use a y/n loop to check for a few words (try the 
        following words: honor, honour, government, computer). Output 
        yes or no for each search word. Use the text file usdeclarPC.txt 
        as an input file and you should format the words to lowercase 
        and remove extra characters like comma, periods, etc.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Trie
{
private:
    class Node
    {
    public:
        char elem;
        vector<Node *> child;
        Node *getChild(char c)
        {
            if (child.empty())
                return NULL;
            
            for (auto i : child)
                if (i->elem == c)
                    return i;
            
            return NULL;
        }
    } *head;

    int count;
public:
    Trie(string file)
    {
        count = 0;
        head = new Node;
        head->elem = '\0';
        
        ifstream fin;
        fin.open(file, ios::binary);

        if (!fin)
            return;

        while (!fin.eof())
        {
            string cur;
            fin >> cur;

            string::iterator itr = cur.begin();

            while (itr != cur.end() && !cur.empty())
            {
                if (*itr >= 'A' && *itr <= 'Z')
                    *itr = *itr - 'A' + 'a';
                if (!(*itr >= 'a' && *itr <= 'z'))
                {   
                    cur.erase(itr);
                    itr--;
                }
                itr++;
            }

            if (!cur.empty())
            {
                cur.push_back('$');
                bool newWord = false;
                Node *cursor = head;
                for (char c : cur)
                {
                    if (!cursor->getChild(c))
                    {
                        Node *temp = new Node;
                        temp->elem = c;
                        cursor->child.push_back(temp);
                        cursor = temp;
                        newWord = true;
                    }
                    else
                        cursor = cursor->getChild(c);
                }
                cur.pop_back();
                
                if (newWord)
                    ++count;
            }
        }
    }

    int getNumOfWords()
    {
        return count;
    }

    bool checkWord(string word)
    {
        word.push_back('$');
        Node *cursor = head;
        for (char c : word)
        {
            if (!cursor->getChild(c))
                return false;
            else    
                cursor = cursor->getChild(c);
        }
        
        return true;
    }
};

int main()
{
    Trie test("usdeclarPC.txt");
    vector<string> words = {"honor", "honour", "government", "computer"};

    cout << "Number of words:\t" << test.getNumOfWords() << endl;
    for (string w : words)
        cout << "Check word " << w << ":\t" << (test.checkWord(w) ? "yes" : "no") << endl;
    
    cout << "Author: Nero Li\n";

    return 0;
}
