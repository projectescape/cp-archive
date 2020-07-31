int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    for (auto i : A) m[i]++;
    if (B == 0) {
        for (auto i : m) {
            if (i.second > 1) return 1;
        }
        return 0;
    }
    for (auto i : A) {
        if (m[i - B] || m[i + B]) return 1;
    }
    return 0;
}
