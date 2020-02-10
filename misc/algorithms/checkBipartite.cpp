#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adjList;

   public:
    void addEdge(int a, int b, bool bidir = true) {
        adjList[a].push_back(b);
        if (bidir)
            adjList[b].push_back(a);
    }

    bool isBipartite() {
        unordered_map<int, char> color;
        unordered_map<int, bool> visited;
        visited[1] = true;
        color[1] = 'r';

        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neighbour : adjList[node]) {
                if (color[neighbour] == color[node]) {
                    return false;
                }
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    color[neighbour] = (color[node] == 'r' ? 'b' : 'r');
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 2);

    cout << "Graph is " << (g.isBipartite() ? "" : "not ") << "Bipartite\n";
    return 0;
}