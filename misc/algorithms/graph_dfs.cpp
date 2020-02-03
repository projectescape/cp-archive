#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    map<T, list<T> > adjList;

   public:
    void addEdge(T u, T v, bool bidirect = true) {
        adjList[u].push_back(v);
        if (bidirect) {
            adjList[v].push_back(u);
        }
    }
    void print() {
        for (auto obj : adjList) {
            cout << obj.first << "->";
            for (auto entry : obj.second) {
                cout << entry << ", ";
            }
            cout << endl;
        }
    }
    void dfsHelper(T node, map<T, bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        // Neighbour of current not visited yet
        for (T neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(T src) {
        map<T, bool> visited;
        dfsHelper(src, visited);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, true);
    g.addEdge(1, 2, true);
    g.addEdge(4, 2, true);
    g.addEdge(4, 0, true);
    g.addEdge(4, 3, true);
    g.addEdge(2, 3, true);
    g.addEdge(5, 3, true);
    g.print();
    g.dfs(0);
    cout << endl;
}
