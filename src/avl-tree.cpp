#include "avl-tree.h"

AVL::~AVL()
{
	delete root;
}


int AVL::BalanceFactor(Node* tr)
{
	return GetHeight(tr->right) - GetHeight(tr->left) + 1;
}


void AVL::SingleRotateRight(Node *&node)
{
	Node *n = node;
	Node *n1 = n->left;
	Node *n2 = n1->right;

	n->left = n2;
	n1->right = n;
	n1->parent = n->parent;
	n->parent = n1;
	if (n2 == NULL)
	{
		node = n1;
		return;
	}
	n2->parent = n;
	node = n1;
}


void AVL::SingleRotateLeft(Node *&node)
{
	Node *n = node;
	Node *n1 = n->right;
	Node *n2 = n1->left;

	n->right = n2;
	n1->left = n;
	n1->parent = n->parent;
	n->parent = n1;
	if (n2 == NULL)
	{
		node = n1;
		return;
	}
	n2->parent = n;
	node = n1;
}


void AVL::DoubleRotateRight(Node *&node)
{
	Node *n = node;
	Node *n1 = n->left;
	Node *n2 = n1->right;
	Node *t1 = n1->left;
	Node *t2 = n2->left;
	Node *t3 = n2->right;
	Node *t4 = n->right;
	n2->right = n;
	n2->left = n1;
	n2->parent = n->parent;
	n->parent = n2;
	n1->parent = n2;
	n1->right = t2;
	n->left = t3;
	t2->parent = n1;
	t3->parent = n;
	node = n2;
}


void AVL::DoubleRotateLeft(Node *&node)
{
	Node *n = node;
	Node *n1 = n->right;
	Node *n2 = n1->left;
	Node *t1 = n->left;
	Node *t2 = n2->left;
	Node *t3 = n2->right;
	Node *t4 = n1->right;
	n2->left = n;
	n2->right = n1;
	n2->parent = n->parent;
	n->parent = n2;
	n1->parent = n2;
	n1->left = t3;
	n->right = t2;
	t2->parent = n;
	t3->parent = n1;
	node = n2;
}


void AVL::RecursivePush(Node *& tree, Node* node)
{
	if (node->key < tree->key)
	{
		if (tree->left == NULL)
		{
			tree->left = node;
			node->parent = tree;
		}
		else
			RecursivePush(tree->left, node);
	}
	else
	{
		if (tree->right == NULL)
		{
			tree->right = node;
			node->parent = tree;
		}
		else
			RecursivePush(tree->right, node);
	}
}


void AVL::RecursiveRemove(Node *& tree, const KeyType& k)
{
	if (tree == NULL)
		throw
		exception("Tree doesn't exist");
	if (k < tree->key)
		RecursiveRemove(tree->left, k);
	if (k > tree->key)
		RecursiveRemove(tree->right, k);
	if (k == tree->key)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (tree->parent->right == tree)
				tree->parent->right = NULL;
			else
				tree->parent->left = NULL;
		}
		else if ((tree->right == NULL) && (tree->left != NULL))
		{
			Node* y = tree->left;
			y->parent = tree->parent;
			if (tree->parent->right == tree)
				tree->parent->right = y;
			else
				tree->parent->left = y;
		}
		else if ((tree->left == NULL) && (tree->right != NULL))
		{
			Node* y = tree->right;
			y->parent = tree->parent;
			if (tree->parent->right == tree)
				tree->parent->right = y;
			else
				tree->parent->left = y;
		}
		else
		{
			Node* y = FindMin(tree->right);
			tree->key = y->key;
			y->parent->left = y->right;
			if (y->right != NULL)
				y->right->parent = y->parent;
			delete y;
		}
	}
}


void AVL::Balance(Node*& p)
{
	int c = BalanceFactor(p);
	if (c == 2)
	{
		if (BalanceFactor(p->right) < 0)
			SingleRotateRight(p->right);
		SingleRotateLeft(p);
	}
	if (c == -2)
	{
		if (BalanceFactor(p->left) > 0)
			SingleRotateLeft(p->left);
		SingleRotateRight(p);
	}
	p->balance = BalanceFactor(p);
}
