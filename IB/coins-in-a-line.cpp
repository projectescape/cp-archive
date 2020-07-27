int helper(vector<int> &A, vector<vector<int>> &dp, int s, int e) {
    if (s > e) return 0;
    if (dp[s][e] == -1) {
        dp[s][e] = max(A[s] + min(helper(A, dp, s + 2, e), helper(A, dp, s + 1, e - 1)), A[e] + min(helper(A, dp, s, e - 2), helper(A, dp, s + 1, e - 1)));
    }
    return dp[s][e];
}

int Solution::maxcoin(vector<int> &A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    return helper(A, dp, 0, A.size() - 1);
}
