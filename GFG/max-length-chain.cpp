bool comp(val &a, val &b) {
    if (a.second < b.first) return true;
    return a.first < b.first;
}

int maxChainLen(struct val p[], int n) {
    sort(p, p + n, comp);
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[j].second < p[i].first) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}