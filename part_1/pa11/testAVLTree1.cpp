// Created for CSCI 220 Fall 21
#include <iostream>
#include <string>
#include "Entry.h"
#include "AVLEntry.h"
#include "AVLTree1.h"

using namespace std;

int main()
{

	AVLTree<AVLEntry<Entry<int, string>>> myTree;
	AVLTree<AVLEntry<Entry<int, string>>>::Iterator iter(NULL);

	int key;

	myTree.insert(5, "abc");
	myTree.insert(7, "xyz");
	myTree.insert(9, "aaa");
	myTree.insert(7, "new");

	// test iterator's begin()
	cout << "inorder traversal:\n";
	iter = myTree.begin();
	while (!(iter == myTree.end()))
	{
		cout << (*iter).key() << " " << (*iter).value() << endl;
		++iter;
	}


	return 0;
}