#include <bits/stdc++.h>
using namespace std;

class graph {
    unordered_map<int, list<int>> m;
    unordered_map<int, int> dist;

   public:
    void addEdge(int a, int b) {
        m[a].push_back(b);
    }

    int bfs(int a, int b) {
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(a);
        dist[a] = 0;
        visited[a] = true;
        int curr;
        while (!q.empty()) {
            curr = q.front();
            for (auto it = m[curr].begin(); it != m[curr].end(); it++) {
                if (visited[*it]) continue;
                visited[*it] = true;
                dist[*it] = dist[curr] + 1;
                if ((*it) == b) {
                    return dist[*it];
                }
                q.push(*it);
            }
            q.pop();
        }
        return 0;
    }
};

int main() {
    graph g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for (int i = 0; i < 36; i++) {
        for (int j = i + 1; j <= i + 6 && j <= 36; j++) {
            g.addEdge(i, j + board[j]);
        }
    }

    cout << "Shortest distance is " << g.bfs(0, 36) << endl;

    return 0;
}