int helper(int a, vector<int>& dp) {
    if (dp[a] == -1) {
        dp[a] = 0;
        for (int i = 0; i < a; i++) {
            dp[a] += (helper(i, dp) * helper(a - i - 1, dp));
        }
    }
    return dp[a];
}

int Solution::numTrees(int A) {
    vector<int> dp(A + 1, -1);
    dp[0] = dp[1] = 1;
    return helper(A, dp);
}
