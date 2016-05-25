#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef int KeyType;

class Node
{
public:
	int balance; 
	KeyType key; 
	Node *left; 
	Node *right; 
	Node *parent; 
	Node()
	{ 
		left = NULL;
		right = NULL; 
		parent = NULL;
		balance = 0;
	}
	Node(const KeyType& k)
	{ 
		key = k;
		left = NULL;
		right = NULL;
		parent = NULL;
		balance = 0; 
	}
};


class bst
{
public:
	int size; 
	Node *root;
	bst();
	~bst();
	bst(const bst &);
	Node* Copy(Node*); 
	virtual void Push(Node*&, const Node *); 
	virtual void Remove(Node*&, const KeyType &); 
	Node* FindKey(Node*, const KeyType &); 
	Node* FindMax(Node*); 
	Node* FindMin(Node*); 
	Node* FindNext(Node*, Node*); 
	Node* FindPrevious(Node*, Node*);
	int operator==(const bst&) const;
	int GetSize();
	int GetHeight(Node*);
};

