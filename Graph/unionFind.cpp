    /*
     * Union Find (aka Disjoint Set Union (DSU))
     *
     * Data structure that can store the information of a collection
     * of disjoint sets.
     * Thanks to optimizations, it is able to determine which set an item
     * belongs in O(1) time. It is also able to unite two disjoint sets.
     *
     * DSU is used in Kruskal's Algorithm for the Minimum Spanning Tree (MST)
     * problem, as well as for finding all connected components in an undirected
     * graph.
     *
     * Time: O(α(n))
     * Space: O(n)
     *
     * α(n) is the inverse Ackermann function.
     *
     */

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank; 
    int num;

public:
    UnionFind(int n) {
        parent.assign(n, 0);

        // Initializes the single sets
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        rank.assign(n, 0);

        num = n;
    }

    // Optional function: returns the number of disjoint sets
    int numSets() {
        return num;
    }

    // Returns the representative of the set that 'u' belongs
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);

        return parent[u];
    }

    // Unites the sets that 'u' and 'v' belong, by rank
    void Union(int u, int v) {
        num--;
        int u_rep = find(u);
        int v_rep = find(v);

        if (u_rep != v_rep) {
            // Union by rank
            if (rank[u] > rank[v]) {
                parent[v] = u;
            }

            else if (rank[v] > rank[u]) {
                parent[u] = v;
            }

            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

int main() {
    UnionFind obj(10);

    obj.Union(0, 1);
    obj.Union(1, 2);
    obj.Union(3, 4);
    obj.Union(4, 5);

    cout << obj.find(2) << endl;

    cout << obj.find(4) << endl;

    return 0;
}
