/*  Program: PA_7_exercise_2  
    Author: Nero Li
    Class: CSCI 230   
    Date: 04/19/2022    
    Description: 
        Implement a compression scheme that is based on Huffman coding. 
        Write a program that allows user to compress a text file. Given 
        a normal input text file, you need to generate the compressed 
        text file. You should utilize a class named HuffmanCoding with 
        an appropriate interface. 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "HeapPriorityQueue.h"
#include "LinkedBinaryTree.h"
#include "Entry.h"

using namespace std;

class HuffmanCoding
{
    private:
        class isLess 
        {
        public:
            bool operator()(const Entry<int, LinkedBinaryTree>& p, const Entry<int, LinkedBinaryTree>& q) const
            { 
                return p.key() < q.key(); 
            }
        };

        string outFile;
        string X;
        unordered_map<char, int> char_count;
        HeapPriorityQueue<Entry<int, LinkedBinaryTree>, isLess> Q;
        int totalBit = 0;
        string codeBuffer = "\0";
        LinkedBinaryTree resultTree;

        string distinctCharacters(string X)
        {
            string C;
            unordered_set<char> U;

            for (char i : X)
                U.insert(i);

            for (char i : U)
                C.push_back(i);

            sort(C.begin(), C.end());
            return C;
        }

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

        void addNode(LinkedBinaryTree T, LinkedBinaryTree::Position v, LinkedBinaryTree::Position p)
        {
            T.expandExternal(p, *v);

            if (*(v.left()))
                addNode(T, v.left(), p.left());
            if (*(v.right()))
                addNode(T, v.right(), p.right());
        }

        LinkedBinaryTree join(LinkedBinaryTree T1, LinkedBinaryTree T2)
        {
            LinkedBinaryTree T;
            LinkedBinaryTree::Position v;
            LinkedBinaryTree::Position p;
            T.addRoot();
            p = T.root();
            int temp = 1;
            T.expandExternal(p, temp);

            v = T1.root();
            p = p.left();
            addNode(T, v, p);

            v = T2.root();
            p = p.parent();
            p = p.right();
            addNode(T, v, p);

            return T;
        }

        void findCode(string &str, string cur, LinkedBinaryTree::Position p, char c)
        {
            if (*p == (int)c)
            {
                str += cur;
                return;
            }
            string newCur = cur;
            if (*(p.left()) && *(p.left()) >= 0)
            {
                newCur += "0";
                findCode(str, newCur, p.left(), c);
            }
            newCur = cur;
            if (*(p.right()) && *(p.right()) >= 0)
            {
                newCur += "1";
                findCode(str, newCur, p.right(), c);
            }
        }
    public:
        HuffmanCoding(string inFile, string outFile)
        {
            ifstream fin;
            fin.open(inFile, ios::binary);
            this->outFile = outFile;

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
                    X += temp;
                }
            }

            string C = distinctCharacters(X);
            computeFrequences(C, X);

            for (char c : C)
            {
                int temp = c;
                LinkedBinaryTree T;
                LinkedBinaryTree::Position p;
                T.addRoot();
                p = T.root();
                T.expandExternal(p, temp);

                Entry<int, LinkedBinaryTree> E;
                E.setKey(getFrequency(c));
                E.setValue(T);
                Q.insert(E);
            }

            while (Q.size() > 1)
            {
                int f1 = Q.min().key();
                LinkedBinaryTree T1 = Q.min().value();
                Q.removeMin();

                int f2 = Q.min().key();
                LinkedBinaryTree T2 = Q.min().value();
                Q.removeMin();

                LinkedBinaryTree T;
                T = join(T1, T2);

                Entry<int, LinkedBinaryTree> E;
                E.setKey(f1 + f2);
                E.setValue(T);
                Q.insert(E);
            }

            resultTree = Q.min().value();

            ofstream fout;
            fout.open(outFile, ios::binary);

            for (char c : C)
            {
                string temp = "\0";
                string code = "\0";
                if ((int)c == 13)
                    temp += "\\n";
                else
                {
                    temp += c;
                    temp += " ";
                }
                temp += " ";
                findCode(code, "\0", resultTree.root(), c);
                totalBit += code.size() * getFrequency(c);
                
                cout << temp << code << endl;
                fout << temp << code << endl;
            }

            for (char c : X)
            {
                string code = "\0";
                findCode(code, "\0", resultTree.root(), c);
                codeBuffer += code;
            }
            
            
            cout << "*****\n";
            fout << "*****\n";
            cout << "Number of characters: " << X.size() << endl;
            fout << "Number of characters: " << X.size() << endl;
            cout << "Number of bits: " << totalBit << endl;
            fout << "Number of bits: " << totalBit << endl;
            cout << codeBuffer << endl;
            fout << codeBuffer << endl;
        }
};

int main()
{
    HuffmanCoding H("moneyIn.txt", "moneyOut.txt"); 

    cout << "Modified by: Nero Li\n";

    return 0;
}
