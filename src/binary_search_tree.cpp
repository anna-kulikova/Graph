#include "binary_search_tree.h"

Node * FindKey(Node *root, int k)
{
	while ((root != 0) && (root->key != k))
	{
		if (k < root->key)
			root = root->left;
		else
			root = root->right;
	}
	if (root == 0)
		throw
		exception("Node doesn't exist");
	return root;
}

Node * FindMin(Node *root)
{
	if (root == 0)
		throw
		exception("Tree is empty");
	while (root->left != 0)
		root = root->left;
	return root;
}

Node * FindMax(Node *root)
{
	if (root == 0)
		throw
		exception("Tree is empty");
	while (root->right != 0)
		root = root->right;
	return root;
}

Node * FindNext(Node *node)
{
	if (node == 0)
		throw
		exception("Tree is empty");
	if (node->right != 0)
		return FindMin(node->right);
	while ((node->parent != 0) && (node->parent->right == node))
		node = node->parent;
	if (node->parent == 0)
		throw
		exception("Next node doesn't exist");
	return node->parent;
}

Node * FindPrevious(Node *node)
{
	if (node == 0)
		throw
		exception("Tree is empty");
	if (node->right != 0)
		return FindMax(node->left);
	while ((node->parent != 0) && (node->parent->left == node))
		node = node->parent;
	if (node->parent == 0)
		throw
		exception("Previous node doesn't exist");
	return node->parent;
}

void Push(Node *&root, Node *node)
{
	if (root == 0)
	{
		root = node;
		return;
	}
	Node *x = root;
	Node *y = new Node();
	while (x != 0)
	{
		y = x;
		if (x->key <= node->key)
			x = x->right;
		else
			x = x->left;
	}
	if (y->key <= node->key)
		y->right = node;
	else
		y->left = node;
	node->parent = y;
}

void Remove(Node *&root, int k)
{
	Node *x = FindKey(root, k);
	if (x == 0)
		return;
	if ((x->right == 0) && (x->left == 0))
	{
		if (x->parent->right == x)
			x->parent->right = 0;
		else
			x->parent->left = 0;
		delete x;
		return;
	}
	if ((x->right != 0) && (x->left == 0))
	{
		Node *y = x->right;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	if ((x->right == 0) && (x->left != 0))
	{
		Node *y = x->left;
		y->parent = x->parent;
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
		delete x;
		return;
	}
	if ((x->right != 0) && (x->left != 0))
	{
		if (x == root) {
			Node* y = root;
			root = FindMin(x->right);
			root->left = x->left;
			root->right = x->right;
			delete y;
			return;
		}
		Node* y = x;
		if (x->parent->left == x) {
			x->parent->left = FindMin(x->right);
		}
		else {
			x->parent->right = FindMin(x->right);
		}

		delete y;
		return;
	}
}

void WorkAroundSearch(Node *node)
{
	if (node == 0)
		return;
	queue<Node*> q;
	q.push(node);
	while (!q.empty())
	{
		Node *tmp = q.front();
		cout << tmp->key << " ";
		q.pop();
		if (tmp->left != 0)
			q.push(tmp->left);
		if (tmp->right != 0)
			q.push(tmp->right);
	}
}

