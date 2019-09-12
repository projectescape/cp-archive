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
    void bfs(T src) {
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T node = q.front();
            cout << node << " ";
            q.pop();
            for (T neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void bfs_dist(T src) {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;

        for (auto i : adjList) {
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        q.push(src);
        parent[src] = src;

        while (!q.empty()) {
            T node = q.front();
            cout << node << " ";
            q.pop();
            for (T neighbour : adjList[node]) {
                if (dist[neighbour] == INT_MAX) {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        for (auto i : adjList) {
            T node = i.first;
            cout << "Distance of " << node << " from " << src << " = " << dist[node] << endl;
        }
    }
};

int main() {
    Graph<string> g;
    g.addEdge("putin", "trump", false);
    g.addEdge("putin", "modi", false);
    g.addEdge("putin", "pope", false);
    g.addEdge("modi", "trump", true);
    g.addEdge("modi", "yogi", true);
    g.addEdge("yogi", "prabhu", false);
    g.addEdge("prabhu", "modi", false);
    g.print();
    g.bfs_dist("putin");
    cout << endl;
}
