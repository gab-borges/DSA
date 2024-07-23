/*
 * How to detect a cycle in a graph.
 * 
 * Two versions: directed and undirected.
 *
 * Time: O(V + E) in both.
 * The graph has to be connected.
*/

#include <bits/stdc++.h>
using namespace std;

/* Using DFS for directed graphs */
bool detectCycleDFS (vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& recStack) {
    visited[node] = true;
    recStack[node] = true;

	for (int i : graph[node]) {
		if (!visited[i] && detectCycleDFS(graph, i, visited, recStack))
            return true;
    
        else if (recStack[i])
            return true;
    }

    recStack[node] = false;
    return false;
}

/* Using DFS for undirected graphs */
bool detectCycleDFS_U (vector<vector<int>>& graph, int node, vector<bool>& visited, int parent) {
    visited[node] = true;

    for (int i : graph[node]) {
        if (!visited[i]) {
            if (detectCycleDFS_U(graph, i, visited, node))
                return true;
        }
                
        else if (i != parent)
            return true;
    }

    return false;
}

void addEdge(vector<vector<int>>& graph, int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a); //for undirected graphs
}

int main() {
    int vertices = 3;
    int startNode = 0;

    vector<vector<int>> graph(vertices);

    addEdge (graph, 0, 1);
    addEdge (graph, 1, 2);
    addEdge (graph, 0, 2);

    vector<bool> visited(vertices, false);

    //vector<int> recStack(graph.size() + 1);
    //cout << detectCycleDFS(graph, startNode, visited, recStack) << endl;

    cout << detectCycleDFS_U (graph, startNode, visited, -1) << endl;

    return 0;
}
