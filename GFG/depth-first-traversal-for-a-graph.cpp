void helper(vector<int> g[], vector<int>& ans, unordered_map<int, int>& m, int pos) {
    if (m[pos]) return;
    ans.push_back(pos);
    m[pos] = 1;
    for (auto i : g[pos]) {
        helper(g, ans, m, i);
    }
}

vector<int> dfs(vector<int> g[], int N) {
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++) {
        helper(g, ans, m, i);
    }
    return ans;
}