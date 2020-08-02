void dfs(int curr, vector<int> adj[], stack<int> &s, vector<bool> &visited) {
    visited[curr] = true;
    for (auto i : adj[curr]) {
        if (!visited[i]) {
            dfs(i, adj, s, visited);
        }
    }
    s.push(curr);
}

void dfs(int curr, vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited) {
    visited[curr] = true;
    for (auto i : adj[curr]) {
        if (!visited[i]) {
            dfs(i, adj, s, visited);
        }
    }
}

int kosaraju(int V, vector<int> adj[]) {
    stack<int> s;
    vector<bool> visited(V, false);
    vector<vector<int>> inverted(V);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, s, visited);
        }
        for (auto j : adj[i]) {
            inverted[j].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    while (!s.empty()) {
        if (visited[s.top()]) {
            s.pop();
            continue;
        }
        dfs(s.top(), inverted, s, visited);
        ans++;
        s.pop();
    }
    return ans;
}