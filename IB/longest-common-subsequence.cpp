int helper(int a, int b, string &A, string &B, vector<vector<int>> &dp) {
    if (a >= A.size() || b >= B.size()) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    if (A[a] == B[b]) {
        dp[a][b] = 1 + helper(a + 1, b + 1, A, B, dp);
    } else {
        dp[a][b] = max(helper(a + 1, b, A, B, dp), helper(a, b + 1, A, B, dp));
    }
    return dp[a][b];
}

int Solution::solve(string A, string B) {
    vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
    return helper(0, 0, A, B, dp);
}
