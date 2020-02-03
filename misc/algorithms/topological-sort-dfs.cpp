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

    void dfsHelper(T node, unordered_map<T, bool> &visited, list<T> &ordering) {
        visited[node] = true;
        for (auto neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, visited, ordering);
            }
        }
        ordering.push_front(node);
    }

    void dfsTopologicalSort() {
        unordered_map<T, bool> visited;
        list<T> ordering;

        for (auto i : adjList) {
            T node = i.first;
            if (!visited[node]) {
                dfsHelper(node, visited, ordering);
            }
        }
        for (auto element : ordering) {
            cout << element << " --> ";
        }
    }
};

int main() {
    Graph<string> g;
    g.addEdge("english", "programming logic", false);
    g.addEdge("maths", "programming logic", false);
    g.addEdge("programming logic", "HTML", false);
    g.addEdge("programming logic", "python", false);
    g.addEdge("programming logic", "java", false);
    g.addEdge("programming logic", "JS", false);
    g.addEdge("python", "web dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "web dev", false);

    g.dfsTopologicalSort();

    return 0;
}
