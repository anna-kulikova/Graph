#include "kruskal.hpp"

typedef float KeyType;

void main()
{
	int q;
	cout << "Choose the priority queue" << endl << "1. Based on d-heap" << endl << "2. Based on binary search tree" << endl << "3. Based on sort table" << endl;
	cin >> q;
	system("cls");
	int n;
	cout << "Enter the number of vertices" << endl;
	cin >> n;
	cout << "Enter the number of edges" << endl;
	int m;
	cin >> m;
	Graph<KeyType> *graph = new Graph<KeyType>(n, m);
	int type;
	cout << "Choose the type of input" << endl << "1. Random input" << endl << "2. Manual input" << endl;
	cin >> type;
	switch (type)
	{
	case 1:
	{
		cout << "Enter min and max value" << endl;
		KeyType min, max;
		cin >> min;
		cin >> max;
		graph->CreateGraph(min, max);
		break;
	}
	case 2:
	{
		for (int i = 0; i<m;i++)
		{
			cout << "Enter the 'from' vertice, 'to' vertice and weight" << endl;
			int f, t;
			KeyType w;
			cin >> f;
			cin >> t;
			cin >> w;
			graph->Push(f, t, w);
		}
		break;
	}
}

	system("cls");

	cout << "Graph " << endl << endl;
	graph->Print();
	Graph<KeyType> *res = new Graph<KeyType>(n, m);
	graph->Sort();
	Priority_queue<KeyType>* queue;
	int tmp2 = 0;
	if (q == 1)
		tmp2 = n;
	if (q == 3)
		tmp2 = m;
	Create_queue<KeyType>::CreateQueue(queue, q, tmp2);
	res = Algorithm<KeyType>::Kruskal(graph, queue);
	cout << endl << endl;
	res->Print();
}
