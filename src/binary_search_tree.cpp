#include "binary_search_tree.h"

Node* bst:Copy(Node *node){
	if (node == 0)
		return 0;
	Node *l = Copy(node->left);
	Node *r = Copy(node->right);
	Node *tmp = new Node;
	tmp->key = node->key;
	tmp->left = l;
	tmp->right = r;
	return tmp;
}
void bst:recursiveRemove(Node* node){
	if (node == NULL) return;
	recursiveRemove(node->left);
	recursiveRemove(node->right);
	delete node;
}

Node * bst:FindKey(int k)
{
	Node* root1 = root;
	while ((root1 != 0) && (root1->key != k))
	{
		if (k < root1->key)
			root1 = root1->left;
		else
			root1 = root1->right;
	}
	if (root1 == 0)
		throw
		exception("Node doesn't exist");
	return root1;
}

Node * bst:FindMin()
{
	Node* root1 = root;
	if (root1 == 0)
		throw
		exception("Tree is empty");
	while (root1->left != 0)
		root1 = root1->left;
	return root1;
}

Node * bst:FindMax()
{
	Node* root1 = root;
	if (root1 == 0)
		throw
		exception("Tree is empty");
	while (root1->right != 0)
		root1 = root1->right;
	return root1;
}

Node * bst:FindNext(Node *node)
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

Node * bst:FindPrevious(Node *node)
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

void bst:Push(Node *node)
{
	Node* root1 = root;
	if (root1 == 0)
	{
		root1 = node;
		return;
	}
	Node *x = root1;
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
	root = root1;
}

void bst:Remove(int k)
{
	Node* root1 = this->root;
	Node *x = FindKey(root1, k);
	if (x == 0)
		return;
	if ((x->right == 0) && (x->left == 0))
	{
		if (x->parent->right == x)
			x->parent->right = 0;
		else
			x->parent->left = 0;
		delete x;
		root = root1;
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
		root = root1;
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
		root = root1;
		return;
	}
	if ((x->right != 0) && (x->left != 0))
	{
		if (x == root1) {
			Node* y = root1;
			root1 = FindMin(x->right);
			root1->left = x->left;
			root1->right = x->right;
			delete y;
			root = root1;
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
		root = root1;
	}
}

void bst:WorkAroundSearch(Node *node)
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

