/*  Program: PA_8_extra_credit
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

bool visited(Tree *cur, Tree *prev)
{
    int i{SIZE - 1};
    while (!cur->child[i] && i >= 0)
    {
        --i;
    }

    if (prev && cur->child[i] == prev)
    {
        return true;
    }
    
    return false;
}

void postOrder(Tree *root)
{
    Tree *cur = root;
    Tree *prev = NULL;
    stack<Tree*> stk;

    stk.push(cur);
    while (!stk.empty())
    {
        cur = stk.top();
        if (noChild(cur) || visited(cur, prev))
        {
            cout << cur->elem << ' ';
            stk.pop();
            prev = cur;
        }
        else
        {
            for (int i = SIZE - 1; i >= 0; --i) 
            {
                if (cur->child[i])
                {
                    stk.push(cur->child[i]);
                }
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
    Tree *G = new Tree;
    Tree *H = new Tree;
    Tree *I = new Tree;
    
    createNewNode(A, 'A', NULL, B, C, D);
    createNewNode(B, 'B', A, NULL, NULL, NULL);
    createNewNode(C, 'C', A, E, F, NULL);
    createNewNode(D, 'D', A, NULL, NULL, NULL);
    createNewNode(E, 'E', C, NULL, NULL, NULL);
    createNewNode(F, 'F', C, NULL, NULL, NULL);

    postOrder(A);

    cout << "Author: Nero Li\n";
    return 0;
}