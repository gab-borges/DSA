/*
 * Dijkstra's algorithm
 *
 * This well-known shortest path algorithm works with graphs that have non-negative weights.
 * It finds the shortest distance to get from a source node to any node.
 * Dijkstra's algorithm has many useful applications.
 * It works on both directed and undirected graphs.
 *
 * Time: O(E * log V)
 * Space: O(V)
 *
 * The following implementation uses adjacency list representation and a priority queue to 
 * be efficient.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> ii;

class Graph {
    int V;
    vector<vector<ii>> adj_list;

public:
    Graph(int V); //Constructor

    void addEdge(int u, int v, int w); // Adds an edge u <-> v with weight w

    vector<int> dijkstra(int src); // Shortest path function
};

Graph::Graph(int V) {
    this->V = V;
    adj_list.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj_list[u].push_back(make_pair(v, w));
    adj_list[v].push_back(make_pair(u, w)); // Assuming graph is undirected
}

vector<int> Graph::dijkstra (int src) {
    // Vector in which the i-th position will store the minimum distance to get to node i
    vector<int> dist(V, INT_MAX);

    // Priority queue that will store a pair: the first item is the minimum distance to get into the node.
    // the second item is the label of the node. Furthermore, the queue will dynamically take the minimum
    // distance available into the front of the queue
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    // Start the priority queue
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        // u is now the label of the node with current minimum distance from source node
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : adj_list[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    Graph g(5);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 3, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(2, 4, 1);

    vector<int> dist = g.dijkstra(0);

    cout << "Distance to get from node 0 to node 4: " << dist[4] << endl;

    return 0;
}