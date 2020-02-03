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

    void bfsTopologicalSort() {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, int> indegree;

        for (auto i : adjList) {
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }

        for (auto i : adjList) {
            T u = i.first;
            for (T v : adjList[u]) {
                indegree[v]++;
            }
        }

        for (auto i : adjList) {
            T node = i.first;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " --> ";
            for (auto neighbour : adjList[node]) {
                if (indegree[neighbour] > 0) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
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

    g.bfsTopologicalSort();

    return 0;
}
