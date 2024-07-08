
/*  * Breadth-First Search
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
#include <queue>
using namespace std;

/* */
void bfs(vector<vector<int> >& adjList, int startNode, vector<bool>& visited) {
    queue<int> searchQueue;

    visited[startNode] = true;
    searchQueue.push(startNode);

    while(!searchQueue.empty()) {
        int currentNode = searchQueue.front();
        searchQueue.pop();

        cout << currentNode << " ";

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                searchQueue.push(neighbor);
            }
        }
    }
}

/* */
void addEdge(vector<vector<int> >& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main() {
    int vertices = 11;
    int startNode = 0;

    vector<vector<int> > adjList(vertices);

    addEdge (adjList, 0, 1);
    addEdge (adjList, 0, 2);
    addEdge (adjList, 1, 7);
    addEdge (adjList, 1, 8);
    addEdge (adjList, 2, 3);
    addEdge (adjList, 2, 5);
    addEdge (adjList, 3, 5);
    addEdge (adjList, 3, 6);
    addEdge (adjList, 3, 9);
    addEdge (adjList, 7, 8);
    addEdge (adjList, 7, 10);

    vector<bool> visited(vertices, false);

    bfs (adjList, startNode, visited);
    cout << endl;

    return 0;
}
