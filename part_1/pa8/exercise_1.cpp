/*  Program: PA_8_exercise_1  
    Author: Nero Li
    Class: CSCI 220   
    Date: 10/21/2021	     
    Description: 
        Provide pseudocode for either preorder traversal or post-order traversal for
        general trees without recursion.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <stack>

using namespace std;
const int SIZE{3};

struct Tree
{
    char elem;
    Tree *parent;
    Tree *child[SIZE];
    bool visited;
}; // Assume maximum child amount is 3

bool noChild(Tree *cur)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (cur->child[i])
        {
            return false;
        }
    }
    
    return true;
}

void preOrder(Tree *root)
{
    Tree *cur = root;
    stack<Tree*> stk;

    while (!stk.empty() || cur)
    {
        if (cur)
        {
            cur->visited = true;
            cout << cur->elem << ' ';
            stk.push(cur);
            cur = cur->child[0];
        }
        else
        {
            cur = stk.top();
            if (cur->child[1] && !cur->child[1]->visited)
            {
                cur = cur->child[1];
            }
            else
            {
                stk.pop();
                cur = cur->child[2];
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
    p->visited = false;
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

    preOrder(A);

    cout << "Author: Nero Li\n";
    return 0;
}