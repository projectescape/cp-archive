#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    map<T, list<T> > l;

   public:
    void addEdge(T u, T v, bool bidirect = true) {
        l[u].push_back(v);
        if (bidirect) {
            l[v].push_back(u);
        }
    }
    void print() {
        for (auto obj : l) {
            cout << obj.first << "->";
            for (auto entry : obj.second) {
                cout << entry << ", ";
            }
            cout << endl;
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
}
