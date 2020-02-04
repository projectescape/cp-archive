#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    unordered_map<T, list<T>> adjList;

   public:
    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }

    void print() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto entry : i.second)
                cout << entry << ", ";
            cout << endl;
        }
    }

    bool dfsHelper(T node, unordered_map<T, bool> &visited, T parent) {
        for (T neighbour : adjList[node]) {
            if (visited[neighbour] == true) {
                if (neighbour == parent) continue;
                return true;
            }
            visited[neighbour] = true;
            if (dfsHelper(neighbour, visited, node) == true) return true;
        }
        return false;
    }

    bool isCyclic(T src) {
        unordered_map<T, bool> visited;
        visited[src] = true;
        return dfsHelper(src, visited, src);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(1, 2);
    // g.addEdge(1, 4);
    g.addEdge(3, 4);
    // g.addEdge(3, 2);
    g.addEdge(1, 3);

    if (g.isCyclic(1)) {
        cout << "Cyclic graph";
    } else {
        cout << "Non-Cyclic graph";
    }
    cout << "\n";
}