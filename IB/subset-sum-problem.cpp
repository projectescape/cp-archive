int helper(int pos, int rem, vector<int> &A, vector<vector<int>> &dp) {
    if (rem == 0) return 1;
    if (rem < 0 || pos >= A.size()) return 0;
    if (dp[pos][rem] == -1) {
        dp[pos][rem] = max(helper(pos + 1, rem, A, dp), helper(pos + 1, rem - A[pos], A, dp));
    }
    return dp[pos][rem];
}

int Solution::solve(vector<int> &A, int B) {
    vector<vector<int>> dp(A.size(), vector<int>(B + 1, -1));
    return helper(0, B, A, dp);
}
