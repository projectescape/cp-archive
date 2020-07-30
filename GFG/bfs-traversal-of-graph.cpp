vector<int> bfs(vector<int> g[], int N) {
    int temp;
    queue<int> q;
    unordered_map<int, bool> m;
    vector<int> ans;
    q.push(0);
    while (!q.empty()) {
        temp = q.front();
        ans.push_back(temp);
        q.pop();
        for (auto i : g[temp]) {
            if (m[i]) {
                continue;
            }
            q.push(i);
            m[i] = true;
        }
    }
    return ans;
}