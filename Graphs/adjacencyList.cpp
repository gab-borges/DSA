/*
 * Implementation of a weighted graph using the
 * adjacency list representation.
 *
 * Complexity to initialize the graph:
 * Time: O(V + E)
 * Space: O(V + E) 
 */

#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
	int V; // Number of vertices
	vector<vector<pair<int, int> > > adj_list; // Graph representation

public:
	// Adds an edge with weight 'w', from 'u' to 'v'
	void add_edge(int u, int v, int w);

	// Prints the adjacency list
	void print();
};

void Graph::add_edge(int u, int v, int w) {
	adj_list[u].push_back({v, w});
	adj_list[v].push_back({u, w}); // For undirected graphs
}

void Graph::print() {
	for (auto i : adj_list) {
		cout << i.first << " -> ";

		for (auto j : i.second)
			cout << j.first << ", " << j.second << "  ";

		cout << endl;
	}
}