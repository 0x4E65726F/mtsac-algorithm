#ifndef BINARY_TREE_H
#define BINARY_TREE_H
// Modified for CSCI 220 Fall 13
// Updated Fall 21

#include <list>
#include <queue>

using namespace std;
  
typedef int Elem;
class LinkedBinaryTree 
{
    protected:
        struct Node // a node of the tree
        {					
            Elem    elt;					// element value
            Node*   par;					// parent
            Node*   left;					// left child
            Node*   right;					// right child
            Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
        };
    public:
        class Position // position in the tree
        {					
            private:
                Node* v;						// pointer to the node
            public:
                Position(Node* _v = NULL) : v(_v) { }		// constructor
                Elem& operator*()					// get element
                    { return v->elt; }
                Position left() const				// get left child
                    { return Position(v->left); }
                Position right() const				// get right child
                    { return Position(v->right); }
                Position parent() const				// get parent
                    { return Position(v->par); }
                bool isRoot() const				// root of the tree?
                    { return v->par == NULL; }
                bool isExternal() const				// an external node?
                    { return v->left == NULL && v->right == NULL; }
                friend class LinkedBinaryTree;			// give tree access
        };
        typedef list<Position> PositionList;		// list of positions
    public:
        LinkedBinaryTree();					// constructor
        int size() const;					// number of nodes
        bool empty() const;					// is tree empty?
        Position root() const;				// get the root
        PositionList positions(int choice) const;  			// list of nodes
        void addRoot();					// add root to empty tree
        void expandExternal(const Position& p, Elem &e);		// expand external node
        Position removeAboveExternal(const Position& p);	// remove p and parent
        // housekeeping functions omitted...
    protected: 						// local utilities
        void preorder(Node* v, PositionList& pl) const;	// preorder utility
        void inorder(Node* v, PositionList& pl) const;
        void postorder(Node* v, PositionList& pl) const;
        void levelorder(Node* v, PositionList& pl) const;
    private:
        Node* _root;					// pointer to the root
        int n;						// number of nodes
};

LinkedBinaryTree::PositionList LinkedBinaryTree::positions(int choice) const  // list of all nodes
{
    PositionList pl;
    switch (choice)
    {
    case 1:
        preorder(_root, pl);					// preorder traversal
        break;
    
    case 2:
        inorder(_root, pl);
        break;
    
    case 3:
        postorder(_root, pl);
        break;

    case 4:
        levelorder(_root, pl);
        break;
    
    default:
        break;
    }

    return PositionList(pl);				// return resulting list
}
							
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const  // preorder traversal
{
    pl.push_back(Position(v));				// add this node
    if (v->left != NULL)					// traverse left subtree
        preorder(v->left, pl);
    if (v->right != NULL)					// traverse right subtree
        preorder(v->right, pl);
}

void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)
        inorder(v->left, pl);
    pl.push_back(Position(v));
    if (v->right != NULL)
        inorder(v->right, pl);
}

void LinkedBinaryTree::levelorder(Node* v, PositionList& pl) const
{
    Node *cur = v;
    queue<Node*> que;

    que.push(cur);
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        pl.push_back(Position(cur));
        if (cur->left)
        {
            que.push(cur->left);
        }
        if (cur->right)
        {
            que.push(cur->right);
        }
    }
}

void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)
        postorder(v->left, pl);
    if (v->right != NULL)
        postorder(v->right, pl);
    pl.push_back(Position(v));
}

LinkedBinaryTree::LinkedBinaryTree()			// constructor
    : _root(NULL), n(0) { }
int LinkedBinaryTree::size() const			// number of nodes
    { return n; }
bool LinkedBinaryTree::empty() const			// is tree empty?
    { return size() == 0; }
LinkedBinaryTree::Position LinkedBinaryTree::root() const // get the root
    { return Position(_root); }
void LinkedBinaryTree::addRoot()			// add root to empty tree
    { _root = new Node; n = 1; }

							// expand external node
void LinkedBinaryTree::expandExternal(const Position& p, Elem &e) 
{
    Node* v = p.v;					// p's node
    v->left = new Node;					// add a new left child
    v->left->par = v;					// v is its parent
    v->right = new Node;				// and a new right child
    v->right->par = v;					// v is its parent
    v->elt = e;
    n += 2;						// two more nodes
}

LinkedBinaryTree::Position				// remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) 
{
    Node* w = p.v;  Node* v = w->par;			// get p's node and parent
    Node* sib = (w == v->left ?  v->right : v->left);
    if (v == _root) // child of root?
    {					
        _root = sib;					// ...make sibling root
        sib->par = NULL;
    }
    else 
    {
        Node* gpar = v->par;				// w's grandparent
        if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;					// delete removed nodes
    n -= 2;						// two fewer nodes
    return Position(sib);
}

#endif