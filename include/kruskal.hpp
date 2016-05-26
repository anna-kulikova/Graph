#pragma once

#include "priority_queue.hpp"
#include "binary_search_tree.hpp"
#include "disjoint_set.hpp"
#include "d-heap.hpp"
#include "table.hpp"
#include "graph.hpp"

using namespace std;

template <class KeyType>
class Algorithm
{
public:
	static Graph<KeyType>* Kruskal(Graph<KeyType>*&, Priority_queue<KeyType>*&);
};



template <class KeyType>
Graph<KeyType>* Algorithm<KeyType>::Kruskal(Graph<KeyType>*& gr, Priority_queue<KeyType>*& queue)
{
	int n = gr->GetCount();
	int m = gr->GetRealSize();
	Graph<KeyType> *tree = new Graph<KeyType>(n, m);
	Disjoint_set<KeyType> *set = new Disjoint_set<KeyType>(n);
	for (int i = 0; i < n; i++)
		set->CreateSet(i);
	for (int i = 0; i < m;i++)
		queue->Push(gr->GetEdge(i)->weight);
	int EdgeSize = 0;
	int x = 0;
	KeyType tmp;
	while (EdgeSize < n - 1)
	{
		tmp = queue->Top();
		queue->Pop();
		int u = gr->GetEdge(x)->from;
		int v = gr->GetEdge(x)->to;
		KeyType newweight = tmp;
		int An = set->FindSet(u);
		int Ak = set->FindSet(v);
		if (An != Ak)
		{
			set->UnionSet(An, Ak);
			tree->Push(u, v, newweight);
			EdgeSize++;
		}
		x++;
	}

	return tree;
};