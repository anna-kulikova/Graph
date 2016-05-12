#pragma once

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
};

void WorkAroundDirect(Node * node);
void WorkAroundReverse(Node *node);
void WorkAroundSym(Node *node);
void WorkAround(Node *node);
void WorkAroundWidth(Node *node);
Node * Copy(Node *node);
