int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < 2 && i < n; i++) {
        dp[i] = max(A[0][i], A[1][i]);
    }
    if (n > 1)
        dp[1] = max(dp[1], dp[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i], max(dp[i - 1], dp[i - 2] + max(A[0][i], A[1][i])));
    }
    return dp[n - 1];
}
