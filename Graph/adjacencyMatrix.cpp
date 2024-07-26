/*
 * Implementation of a weighted Graph using the
 * adjacency matrix representation.
 *
 * Complexity to initialize the graph:
 * Time: O(V²)
 * Space: O(V²)
 */

#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int V; // Number of vertices
	vector<vector<int>> adj_matrix; // Graph representation

public:
	// Constructor that fills the adj_matrix with zeros
	Graph(int n);

	// Adds an edge with weight 'w', between 'u' to 'v'
	void add_edge(int u, int v, int w);

	// Prints the adjacency matrix
	void print();
};

Graph::Graph(int n) {
	adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
}

Graph::void add_edge(int u, int v, int w) {
	adj_matrix[u][v] = w;
	adj_matrix[v][u] = w; // For undirected graphs
}

Graph::void print() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << adj_matrix[i][j] << " ";

		cout << endl;
	}
}