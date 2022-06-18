/*  Program: PA_8_exercise_2
    Author: Nero Li
    Class: CSCI 220   
    Date: 10/21/2021	     
    Description: 
        Provide pseudocode for breadth-first (level order) traversal for general trees.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <queue>

using namespace std;
const int SIZE{3};

struct Tree
{
    char elem;
    Tree *parent;
    Tree *child[SIZE];
}; // Assume maximum child amount is 3

void levelOrder(Tree *root)
{
    Tree *cur = root;
    queue<Tree*> que;

    que.push(cur);
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        cout << cur->elem << ' ';
        for (int i = 0; i < SIZE; ++i) 
        {
            if (cur->child[i])
            {
                que.push(cur->child[i]);
            }
        }
    }
    
    cout << endl;
}

void createNewNode(Tree *p, char elem, Tree *parent, Tree *leftChild, Tree *midChild, Tree *rightChild)
{
    p->elem = elem;
    p->parent = parent;
    p->child[0] = leftChild;
    p->child[1] = midChild;
    p->child[2] = rightChild;
}

int main()
{
    Tree *A = new Tree;
    Tree *B = new Tree;
    Tree *C = new Tree;
    Tree *D = new Tree;
    Tree *E = new Tree;
    Tree *F = new Tree;

    createNewNode(A, 'A', NULL, B, C, D);
    createNewNode(B, 'B', A, E, F, NULL);
    createNewNode(C, 'C', A, NULL, NULL, NULL);
    createNewNode(D, 'D', A, NULL, NULL, NULL);
    createNewNode(E, 'E', B, NULL, NULL, NULL);
    createNewNode(F, 'F', B, NULL, NULL, NULL);

    levelOrder(A);

    cout << "Author: Nero Li\n";
    return 0;
}