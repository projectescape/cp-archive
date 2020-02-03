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
    g.bfs("putin");
    cout << endl;
}
