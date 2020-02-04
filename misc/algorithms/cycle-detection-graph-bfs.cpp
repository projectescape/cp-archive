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

    bool isCyclic(T src) {
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while (!q.empty()) {
            T current = q.front();
            q.pop();
            for (auto neighbour : adjList[current]) {
                if (visited[neighbour] == true) {
                    if (parent[current] != neighbour) {
                        return true;
                    }
                    continue;
                }
                visited[neighbour] = true;
                parent[neighbour] = current;
                q.push(neighbour);
            }
        }
        return false;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(1, 2);
    // g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 2);

    if (g.isCyclic(1)) {
        cout << "Cyclic graph";
    } else {
        cout << "Non-Cyclic graph";
    }
    cout << "\n";
}