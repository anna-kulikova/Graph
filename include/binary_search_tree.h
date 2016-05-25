#pragma once

#include <iostream>
#include <queue>

using namespace std;

typedef int KeyType;
struct Node
{
	KeyType key;
	Node *left;
	Node *right;
	Node *parent;

	Node(void) : left(NULL), right(NULL), parent(NULL) {}
	Node(const KeyType& data) : key(data), left(NULL), right(NULL), parent(NULL) {}
};

class bst {
	Node* root;
	Node* Copy(Node *node);
	void recursiveRemove(Node*);
public:
	bst() {}
	bst(const bst& tree) { root = Copy(tree.root);}
	~bst(void) { recursiveRemove(root);}

	Node* GetRoot (void)const {return root;}
	Node * FindKey(Node *root, int k);
	Node * FindMin(Node *root);
	Node * FindMax(Node *root);
	Node * FindNext(Node *node);
	Node * FindPrevious(Node *node);

	void Push(Node *node);
	void Remove(KeyType k);
	void WorkAroundSearch(Node *node);

};

