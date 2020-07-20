int solve(int pos, vector<int>& dp) {
    if (dp[pos] == -1) {
        dp[pos] = solve(pos + 1, dp) + solve(pos + 2, dp);
    }
    return dp[pos];
}

int Solution::climbStairs(int A) {
    if (A < 3) return A;
    vector<int> dp(A, -1);
    if (A)
        dp[A - 1] = 1;
    if (A > 1)
        dp[A - 2] = 2;
    return solve(0, dp);
}
