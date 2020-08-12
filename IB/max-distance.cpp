int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int, int>> p;
    for (int i = 0; i < A.size(); i++) {
        p.push_back({A[i], i});
    }
    sort(p.begin(), p.end());
    int ans = 0, pre = p[0].second;
    for (int i = 1; i < A.size(); i++) {
        ans = max(ans, p[i].second - pre);
        pre = min(pre, p[i].second);
    }
    return ans;
}
