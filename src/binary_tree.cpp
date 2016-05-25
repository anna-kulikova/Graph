//#include "binary_tree.h"
//
//
//void WorkAroundDirect(Node * node)
//{
//	if (node == 0)
//		return;
//	cout << node->key << " ";
//	WorkAroundDirect(node->left);
//	WorkAroundDirect(node->right);
//}
//
//void WorkAroundReverse(Node *node)
//{
//	if (node == 0)
//		return;
//	WorkAroundReverse(node->left);
//	WorkAroundReverse(node->right);
//	cout << node->key << " ";
//}
//
//void WorkAroundSym(Node *node)
//{
//	if (node == 0)
//		return;
//	WorkAroundSym(node->left);
//	cout << node->key << " ";
//	WorkAroundSym(node->right);
//}
//
//void WorkAround(Node *node)
//{
//	if (node == 0)
//		return;
//	stack<Node*> s;
//	s.push(node);
//	while (!s.empty())
//	{
//		Node *tmp = s.top();
//		cout << tmp->key << " ";
//		s.pop();
//		if (tmp->right != 0)
//			s.push(tmp->right);
//		if (tmp->left != 0)
//			s.push(tmp->left);
//	}
//}
//
//void WorkAroundWidth(Node *node)
//{
//	if (node == 0)
//		return;
//	queue<Node*> q;
//	q.push(node);
//	while (!q.empty())
//	{
//		Node *tmp = q.front();
//		cout << tmp->key << " ";
//		q.pop();
//		if (tmp->left != 0)
//			q.push(tmp->left);
//		if (tmp->right != 0)
//			q.push(tmp->right);
//	}
//}
//
//Node * Copy(Node *node)
//{
//	if (node == 0)
//		return 0;
//	Node *l = Copy(node->left);
//	Node *r = Copy(node->right);
//	Node *root = new Node;
//	root->key = node->key;
//	root->left = l;
//	root->right = r;
//	return root;
//}