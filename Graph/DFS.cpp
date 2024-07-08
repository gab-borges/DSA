
/*  * Depth-First Search
    *
    * V = vertices and E = edges:
    * Time: O(V + E)
    * Space: O(V)
    *
    *
    * This implementation uses the adjacency list
    * representation of graphs.
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/* */
void dfs(vector<list<int> >& graph, int node, vector<bool>& visited) {
	visited[node] = true;
	cout << node << " ";

	for (int i : graph[node])
		if (!visited[i])
			dfs(graph, i, visited);
}

/* */
void addEdge(vector<list<int> >& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a); /* For undirected graphs */
}

int main() {
    int vertices = 11;
    int startNode = 0;

    vector<list<int> > graph(vertices);

    addEdge (graph, 0, 1);
    addEdge (graph, 0, 2);
    addEdge (graph, 1, 7);
    addEdge (graph, 1, 8);
    addEdge (graph, 2, 3);
    addEdge (graph, 2, 5);
    addEdge (graph, 3, 5);
    addEdge (graph, 3, 6);
    addEdge (graph, 3, 9);
    addEdge (graph, 7, 8);
    addEdge (graph, 7, 10);

    vector<bool> visited(vertices, false);

    dfs (graph, startNode, visited);
    cout << endl;

    return 0;
}
