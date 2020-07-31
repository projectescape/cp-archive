vector<int> topoSort(int V, vector<int> adj[]) {
    int temp;
    vector<int> deg(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto j : adj[i]) {
            deg[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto i : adj[temp]) {
            deg[i]--;
            if (deg[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}
