#include <iostream>
#include <vector>
using namespace std;

/*
	*	Implementation of a directed weighted Graph using the
	*	Adjacency Matrix representation.
	*
	* Considering V as the number of vertices, the complexities
	*	to initialize the graph are:
	* Time Complexity: O(V²)
	*	Space Complexity: O(V²) 
*/

class Graph {
	private:
		vector<vector<int> > adj_matrix;
		int	num_vertices;

	public:
		// Initializes the matrix filled with zeros of a graph with 'n' nodes.
		Graph(int n) {
			adj_matrix = vector<vector<int> >(n, vector<int>(n, 0));
		}

		// Adds an edge with weight 'w', from 'u' to 'v'
		void add_edge(int u, int v, int w) {
			adj_matrix[u][v] = w;
		}

		// Prints the adjacency matrix
		void print() {
			for (int i = 0; i < num_vertices; i++) {
				for (int j = 0; j < num_vertices; j++)
					std::cout << adj_matrix[i][j] << " ";
				std::cout << "\n";
			}
		}
};
