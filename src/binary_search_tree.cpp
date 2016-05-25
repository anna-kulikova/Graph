#include "binary_search_tree.h"


bst::bst()
{
	root = NULL;
	size = 0;
};


bst::bst(const bst  &tree)
{
	root = Copy(tree.root);
	size = tree.size;
};


bst ::~bst()
{
	delete root;
};


Node * bst::Copy(Node  *root1)
{
	if (root1 == NULL)
		return NULL;
	Node * l = Copy(root1->left);
	Node * r = Copy(root1->right);
	Node * tr = new Node;
	tr->key = root1->key;
	tr->left = l;
	tr->right = r;
	root = tr;
	return tr;
};


int bst::GetSize()
{
	return size;
}


void bst::Push(Node * &tr, const Node  *node)
{
	KeyType tree = node->key;
	if (tr == NULL)
	{
		tr = new Node;
		tr->key = tree;
		size++;
		return;
	}
	Node * tmp = tr;
	Node * prev = new Node;
	while (tmp != NULL)
	{
		prev = tmp;
		if (tmp->key <= tree)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (prev->key <= tree)
		prev->right = new Node(tree);
	else prev->left = new Node(tree);
	size++;
};


void bst::Remove(Node *& tr, const KeyType &k)
{
	Node * x = FindKey(tr, k);
	if (x == NULL)
		return;
	if ((x->left == NULL) && (x->right == NULL))
	{
		delete x;
		return;
	};
	if ((x->left == NULL) && (x->right != NULL))
	{
		Node * y = x->right;
		y->parent = x->parent;
		if (x->parent == NULL)
		{
			tr = y;
			return;
		}
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		tr = y;
		return;
	}
	if ((x->left != NULL) && (x->right == NULL))
	{
		Node * y = x->left;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	Node * y = FindMin(x->right);
	x->key = y->key;
	y->parent->left = y->right;
	if (y->right != NULL)
		y->right->parent = y->parent;
	delete y;
};


Node * bst::FindKey(Node  *tr, const KeyType &k)
{
	while ((tr != NULL) && (tr->key != k))
	{
		if (k < tr->key)
			tr = tr->left;
		if (k > tr->key)
			tr = tr->right;
	}
	if (tr == NULL)
		return NULL;
	return tr;
};


Node * bst::FindMin(Node  *tr)
{
	if (tr == NULL)
		throw
		exception("Tree is empty");
	while (tr->left != NULL)
		tr = tr->left;
	return tr;
};


Node * bst::FindMax(Node  *tr)
{
	if (tr == NULL)
		throw
		exception("Tree is empty");
	while (tr->right != NULL)
		tr = tr->right;
	return tr;
};


Node * bst::FindNext(Node  *tr, Node  *node)
{
	if (tr == NULL)
		throw
		exception("Tree is empty");
	if (node == NULL)
		throw
		exception("Node is empty");
	node = FindKey(tr, node->key);
	if (node->right != NULL)
		return FindMin(node->right);
	while ((node->parent != NULL) && (node->parent->right == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist");
	return node->parent;
};


Node * bst::FindPrevious(Node  *tr, Node  *node)
{
	if (tr == NULL)
		throw
		exception("Tree is empty");
	if (node == NULL)
		throw
		exception("Node is empty");
	node = FindKey(tr, node->key);
	if (node->right != NULL)
		return FindMax(node->left);
	while ((node->parent != NULL) && (node->parent->left == node))
		node = node->parent;
	if (node->parent == NULL)
		throw
		exception("Parent doesn't exist");
	return node->parent;
}



int bst ::operator==(const bst & a)const
{
	if ((root == NULL) && (a.root == NULL))
		return 1;
	if (size != a.size)
		return 0;
	int *z = new int[size];
	int *b = new int[a.size];
	queue <Node *> q;
	queue <Node *> p;
	q.push(root);
	int tmp1 = 0, tmp2 = 0;
	while (q.empty() == 0)
	{
		Node * tmp = q.front();
		z[tmp1] = tmp->key;
		q.pop();
		if (tmp->left != NULL)
			q.push(tmp->left);
		if (tmp->right != NULL)
			q.push(tmp->right);
		tmp1++;
	}
	p.push(a.root);
	while (p.empty() == 0)
	{
		Node * tmp3 = p.front();
		b[tmp2] = tmp3->key;
		p.pop();
		if (tmp3->left != NULL)
			p.push(tmp3->left);
		if (tmp3->right != NULL)
			p.push(tmp3->right);
		tmp2++;
	}
	for (int i = 0; i<size; i++)
		if (z[i] != b[i])
			return 0;
	return 1;
}




int bst::GetHeight(Node  *tr)
{
	if (tr == NULL)
		return 0;

	int l, r;
	if (tr->left != NULL)
	{
		l = GetHeight(tr->left);
	}
	else
		l = -1;
	if (tr->right != NULL)
	{
		r = GetHeight(tr->right);
	}
	else
		r = -1;
	int max = l > r ? l : r;
	return max + 1;
}

