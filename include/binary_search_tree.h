#pragma once

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	Node *parent;
};

Node * FindKey(Node *root, int k);
Node * FindMin(Node *root);
Node * FindMax(Node *root);
Node * FindNext(Node *node);
Node * FindPrevious(Node *node);
void Push(Node *&root, Node *node);
void Remove(Node *&root, int k);
void WorkAroundSearch(Node *node);
