
/*
	*	Implementation of a directed weighted Graph using the
	*	Adjacency List representation.
	*
	*	Considering 'V' as the number of vertices, and 'E' as 
	*	the number of edges, the complexities to initialize the
	*	graph are:
	*	Time Complexity: O(V+E)
	*	Space Complexity: O(V+E) 
*/

#include <iostream>
#include <list>
#include <map>
using namespace std;


class Graph {
  private:
    int num_vertices;
    map<int, list<pair<int, int> > > adj_list;

	public:
		// Adds an edge with weight 'w', from 'u' to 'v'
		void add_edge(int u, int v, int w) {
			adj_list[u].push_back({v, w});
		}

		// Prints the adjacency list
		void print() {
			for (auto i : adj_list) {
				cout << i.first << " -> ";

				for (auto j : i.second)
					cout << j.first << ", " << j.second << "  ";

				cout << endl;
			}
		}
};
