// For Checking if a grpah is Stringly Connected or not

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

    void dfsHelper(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited) {
        visited[node] = true;

        for (auto neighbour : adjList[node]) {
            if (visited[neighbour]) continue;
            dfsHelper(neighbour, adjList, visited);
        }
    }

    bool kosaraju() {
        unordered_map<int, bool> visited;
        for (auto node : adjList) {
            visited[node.first] = false;
        }

        dfsHelper(1, adjList, visited);

        for (auto node : adjList) {
            if (visited[node.first] == false) return false;
        }

        unordered_map<int, list<int>> adjListReverse;

        for (auto node : adjList) {
            for (auto neighbour : node.second) {
                adjListReverse[neighbour].push_back(node.first);
            }
            visited[node.first] = false;
        }

        dfsHelper(1, adjListReverse, visited);
        for (auto node : adjList) {
            if (visited[node.first] == false) return false;
        }

        return true;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4, false);
    g.addEdge(4, 5);

    // g.addEdge(6, 5);

    cout << "Graph is " << (g.kosaraju() ? "connected" : "disconnected") << endl;

    return 0;
}