/*  Program: PA_2_exercise_2  
    Author: Nero Li
    Class: CSCI 220   
    Date: 09/02/2021	     
    Description: 
        Game Information: Load scores from a text file.
        Provide two classes, GameEntry and GameScore, 
        to maintain a list of top scores.
        

    I certify that the code below is my own work.
	
	Exception(s): Progression

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class GameEntry
{
    private:
        string name;
        int score;
        string date;
    public:
        GameEntry(string name, int score, string date)
        : name(name), score(score), date(date) 
        {
            if (score < 0)
            {
                score = 0;
            }
        }

        void setName(string str)
        {
            name = str;
        }

        void setScore(int n)
        {
            score = n;
            if (score < 0)
            {
                score = 0;
            }
        }

        void setDate(string str)
        {
            date = str;
        }

        string getName()
        {
            return name;
        }

        int getScore()
        {
            return score;
        }

        string getDate()
        {
            return date;
        }

        bool operator<(GameEntry *other)
        {
            return score < other->score;
        }

        ~GameEntry();
};

class GameScore
{
    private:
        string name;
        GameEntry *gamer[10];
        int size;

        void sort()
        {
            for (int i = 0; i < size - 1; ++i) 
            {
                for (int j = 0; j < size - 1 - i; ++j) 
                {
                    if (gamer[j] < gamer[j+1])
                    {
                        GameEntry *temp{gamer[j+1]};
                        gamer[j+1] = gamer[j];
                        gamer[j] = temp;
                    }
                    
                }
            }
        }

    public:
        GameScore(string name)
        : name(name), size(0) {}

        void setName(string str)
        {
            name = str;
        }
        
        string getName()
        {
            return name;
        }

        void add(GameEntry *new_gamer)
        {
            gamer[size++] = new_gamer;
        }

        void print()
        {
            sort();
            cout << "Name: " << getName() << endl;
            for (int i = 0; i < size; ++i) 
            {
                cout << left << setw(3) << i + 1;
                cout << left << setw(9) << gamer[i]->getName();
                cout << left << setw(6) << gamer[i]->getScore();
                cout << left << setw(12) << gamer[i]->getDate();
                cout << endl;
            }
        }
};

int main() 
{
    ifstream file;
    string gameName;
    string player;
    int score;
    string date;

    file.open("pacman.txt", ios::binary);
    getline(file, gameName);
    GameScore g1(gameName);
    
    file >> player >> score >> date;
    GameEntry *e1 = new GameEntry(player, score, date);
    g1.add(e1);

    file >> player >> score >> date;
    GameEntry *e2 = new GameEntry(player, score, date);
    g1.add(e2);

    file >> player >> score >> date;
    GameEntry *e3 = new GameEntry(player, score, date);
    g1.add(e3);

    file >> player >> score >> date;
    GameEntry *e4 = new GameEntry(player, score, date);
    g1.add(e4);
    
    g1.print();

    cout << "Author: Nero Li\n";
    return 0;
}