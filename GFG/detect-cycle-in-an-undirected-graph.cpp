bool helper(vector<int> g[], unordered_map<int, bool> &m, int curr, int parent) {
    m[curr] = true;
    for (auto i : g[curr]) {
        if (m[i]) {
            if (i != parent) {
                return true;
            }
        } else {
            if (helper(g, m, i, curr)) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int V) {
    unordered_map<int, bool> m;
    for (int i = 0; i < V; i++) {
        if (!m[i]) {
            if (helper(g, m, i, -1)) return true;
        }
    }
    return false;
}