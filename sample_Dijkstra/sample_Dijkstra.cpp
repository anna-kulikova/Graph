#include "graph.h"
#include "priority_queue.h"

typedef int typ;

void main()
{
	cout << "Enter the number of vertices" << endl;
	int n;
	cin >> n;

	cout << "Enter the number of edges" << endl;
	int m;
	cin >> m;
	Graph *graph = new Graph(n, m);
	typ *P = new typ(n); 
	for (int i = 0; i <= n; i++)
		P[i] = 0;
	cout << "Enter min and max value" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph->CreateGraph(min, max);
	system("cls");

	cout << "Graph: " << endl << endl;
	graph->Print();

	cout << "Enter the first vertice" << endl;
	int a;
	cin >> a;
	typ *dist = graph->d(a, P);

	cout << "Result:  " << endl << endl;

	for (int i = 0; i<n;i++)
		cout << i << ' ';
	cout << "- vertices" << endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HEAP)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ';
	cout << "- shortest ways" << endl << endl;
	for (int i = 0;i<n;i++)
		cout << P[i] << ' ';
	cout << "- previous vertices " << endl << endl;

}
