#pragma once 

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


template <class KeyType>
class Edge
{
public:
	Edge(int, int, KeyType);
	int from;
	int to;
	KeyType weight;
};

template <class KeyType>
class Graph
{
private:
	int n; //number of vertices
	int m; //number of edges
	Edge<KeyType>** edges;
	int current;
public:
	Graph(int, int);
	~Graph();
	void CreateGraph(KeyType, KeyType);
	void Push(int, int, KeyType);
	void Remove(int, int);
	int GetCount(); //vertices
	int GetEdgeSize();
	int GetRealSize();
	Edge<KeyType>*  GetEdge(int);
	KeyType GetWeight(int, int);
	void Print();
	int FindEdge(int, int);
	void Create(int&, int&);
	bool Scan(int, int*);
	void Sort();
	/*KeyType* Dijkstra(int, KeyType*&);*/
};

template <class KeyType>
Edge<KeyType>::Edge(int f, int t, KeyType w)
{
	from = f;
	to = t;
	weight = w;
}

template <class KeyType>
Graph<KeyType>::Graph(int v, int e)
{
	if (v < 0)
		throw
		exception("Incorrect vertice"); //test
	else
		n = v;
	if ((e < 0) || (e > n * (n - 1) / 2))
		throw
		exception("Incorrect edge"); //test
	else
		m = e;
	current = 0;
	edges = new Edge<KeyType>*[m];
}

template <class KeyType>
Graph<KeyType>::~Graph()
{
	for (int i = 0; i < current; i++)
		delete edges[i];
	delete[] edges;
}

template <class KeyType>
void Graph<KeyType>::Push(int f, int t, KeyType w)
{
	if (current == m)
		throw
		exception("Graph is full"); //test
	if (f == t)
		throw
		exception("Loops are prohibited"); //test
	if ((f > n) || (t > n))
		throw
		exception("There are no such vertices"); //test
	edges[current] = new Edge<KeyType>(f, t, w);
	current++; //test
}

template <class KeyType>
void Graph<KeyType>::Create(int &f, int &t)
{
	do
	{
		f = rand() % n;
		t = rand() % n;
	} while ((f == t) || (FindEdge(f, t) != -1));
}

template <class KeyType>
void Graph<KeyType>::CreateGraph(KeyType f, KeyType t)
{
	if (f > t)
		throw
		exception("Incorrect distance"); //test
	int u, v;
	KeyType newweight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		Create(u, v);
		newweight = f + static_cast <KeyType> (rand()) / (static_cast <KeyType> (RAND_MAX / (t - f)));
		edges[i] = new Edge<KeyType>(u, v, newweight);
		current++;
	}
}

template <class KeyType>
int Graph<KeyType>::GetCount()
{
	return n;
}

template <class KeyType>
int Graph<KeyType>::GetEdgeSize()
{
	return m;
}

template <class KeyType>
int Graph<KeyType>::GetRealSize()
{
	return current;
}

template <class KeyType>
KeyType Graph<KeyType>::GetWeight(int f, int t)
{
	if ((f < 0) || (f > n) || (t < 0) || (t > n))
		throw
		exception("Incorrect vertices"); //test
	for (int i = 0; i < current; i++)
		if ((edges[i]->from == f) && (edges[i]->to == t) || (edges[i]->from == t) && (edges[i]->to == f))
			return edges[i]->weight;
	return 0;
}

template <class KeyType>
void Graph<KeyType>::Print()
{
	cout << "From  to " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < current; j++)
			if (edges[j]->from == i)
				cout << edges[j]->from << " " << edges[j]->to << "(" << edges[j]->weight << ")" << endl;
}

template <class KeyType>
Edge<KeyType>* Graph<KeyType>::GetEdge(int x)
{
	return edges[x];
}

template <class KeyType>
void Graph<KeyType>::Remove(int f, int t)
{
	int tmp = FindEdge(f, t);
	if (tmp == -1)
		throw
		exception("Edge doesn't exist"); //test
	delete edges[tmp];
	edges[tmp] = edges[current - 1];
	current--; //test
}

template <class KeyType>
int Graph<KeyType>::FindEdge(int f, int t)
{
	for (int i = 0; i < current; i++)
	{
		if ((edges[i]->from == f) && (edges[i]->to == f) || (edges[i]->from == t) && (edges[i]->to == t))
			return -1;
		if ((edges[i]->from == f) && (edges[i]->to == t) || (edges[i]->to == f) && (edges[i]->from == t))
			return i;
	}
	return -1;

}

template <class KeyType>
void Graph<KeyType>::Sort()
{
	Edge<KeyType> *tmp = new Edge<KeyType>(0, 0, 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = m - 1; j > i; j--)
		{
			if (edges[j]->weight < edges[j - 1]->weight)
			{
				tmp = edges[j];
				edges[j] = edges[j - 1];
				edges[j - 1] = tmp;
			}
		}
	}
}

template <class KeyType>
bool Graph<KeyType>::Scan(int f, int* b)
{
	bool res = false;
	for (int i = 0;i < n; i++)
		if (b[i] == f)
			res = true;
	return res;
}

//template <class KeyType>
//KeyType* Graph<KeyType>::Dijkstra(int s, KeyType *&way)
//{
//	if ((s < 0) || (s >= n))
//		throw 
//		exception ("Error");	
//	KeyType **graph = new KeyType*[n];
//	for (int i = 0; i < n; i++)
//		graph[i] = new KeyType[n];
//	for (int i = 0;i < n; i++)
//		for (int j = 0;j < n; j++)
//			graph[i][j] = -1;
//	for (int i = 0;i < n; i++)
//		for (int j = 0;j < m; j++)
//		{
//			if ((edges[j]->from == i) || (edges[j]->to == i))
//			{
//				graph[edges[j]->from][edges[j]->to] = edges[j]->weight;
//				graph[edges[j]->to][edges[j]->from] = edges[j]->weight;
//			}
//		}
//
//	KeyType *dist = new KeyType[n]; 
//	int *vis = new int[n]; 
//	for (int i = 0; i < n; i++)
//		vis[i] = -1;
//	vis[0] = s;
//	int path;
//	int w, min;
//	for (int i = 0; i < n; i++) 
//	{                       
//		if (graph[s][i] == -1)
//			dist[i]=MAX_KeyType;
//			else dist[i]=graph[s][i];
//	}
//	for (int i=1; i<n-1; i++) 
//	{
//		min=MAX_KeyType;
//		for (int k=0; k<n; k++) {
//			if (dist[k] < min && k!=s && !visit(k, vis) ) 
//			{
//				w=k;
//				min=dist[k];
//			}
//		}
//		if (min == MAX_KeyType) break;
//		vis[i]=w;
//		for (int j=0; j < n; j++) {
//			if (!visit(j,vis) && graph[w][j] != -1 && (dist[w]+graph[w][j])<=dist[j]) 
//			{
//				P[j]=w;
//				dist[j]=dist[w]+graph[w][j];
//			}
//		}
//	}
//
//	dist[s] = 0;
//	return dist;
//}
//
