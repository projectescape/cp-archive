// https://www.spoj.com/problems/HOLI/
// DFS pigeon hole
// As it is tree, shortest path can be obtained both by bfs and dfs

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph {
    map<T, list<pair<T, int>>> adjList;
    int num = 1;

   public:
    void addEdge(T u, T v, int dist, bool bidirect = true) {
        num++;
        adjList[u].push_back({v, dist});
        if (bidirect) {
            adjList[v].push_back({u, dist});
        }
    }
    void print() {
        for (auto obj : adjList) {
            cout << obj.first << "->";
            for (auto entry : obj.second) {
                cout << entry.first << "-" << entry.second << ", ";
            }
            cout << endl;
        }
    }

    int countChildren(T node, T parent, int *children, int &distance,int cost) {
        if (children[node] != 0) return children[node];
        int childrenCount = 1;
        for (auto neighbour : adjList[node]) {
            if (neighbour.first != parent) {

                childrenCount += countChildren(neighbour.first, node, children, distance,neighbour.second);
            }
        }
        children[node] = childrenCount;

        distance += cost * min(num - children[node], children[node]);
        return childrenCount;
    }

    int maxDistance() {
        // Find No of children of all nodes
        int distance = 0;
        int children[num + 1] = {0};
        for (auto neighbour : adjList[1]) {
            countChildren(neighbour.first, 1, children, distance,neighbour.second);
        }
        return 2 * distance;
    }
};

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        Graph<int> g;

        int n;
        cin >> n;
        int x, y, z;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y >> z;
            g.addEdge(x, y, z);
        }
        cout << "Case #" << i + 1 << ": " << g.maxDistance() << endl;
    }
    return 0;
}
