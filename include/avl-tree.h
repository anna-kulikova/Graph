#pragma once

#include "binary_search_tree.h"
//#include "graph.h"
//#include "priority_queue.h"

typedef int KeyType;

class AVL : public bst
{
public:
	AVL() : bst() {};
	~AVL();
	int BalanceFactor(Node*); 
	void SingleRotateRight(Node *&); 
	void SingleRotateLeft(Node*&); 
	void DoubleRotateRight(Node*&); 
	void DoubleRotateLeft(Node*&); 
	void Balance(Node*&);
	void RecursivePush(Node*&, Node*);
	void RecursiveRemove(Node*&, const KeyType&);
	virtual void Push(const KeyType& k)
	{
		if (root == NULL)
		{
			root = new Node(k);
			size++;
			return;
		}
		Node* tr = root;
		Node* tmp = new Node(k);
		RecursivePush(tr, tmp);
		root = tr;
		Balance(root);
		size++;
	};
	virtual void Remove(const KeyType& k)
	{
		if (root == NULL)
			return;
		Node* tr = root;
		if (FindKey(tr, k) == NULL)
			throw
			exception("Element doesn't exist");
		RecursiveRemove(tr, k);
		root = tr;
		Balance(root);
		size--;
	};
};


