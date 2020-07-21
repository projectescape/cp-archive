int helper(int s, int e, vector<vector<int>> &dp, string &A) {
    if (s == e) return 1;
    if (s > e) return 0;
    if (dp[s][e] == -1) {
        if (A[s] == A[e]) {
            dp[s][e] = 2 + helper(s + 1, e - 1, dp, A);
        } else {
            dp[s][e] = max(helper(s + 1, e, dp, A), helper(s, e - 1, dp, A));
        }
    }
    return dp[s][e];
}

int Solution::solve(string A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    return helper(0, A.size() - 1, dp, A);
}
