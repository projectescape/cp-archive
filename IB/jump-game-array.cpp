int helper(vector<int> &A, vector<int> &dp, int pos) {
    if (pos >= A.size()) return 1;
    if (dp[pos] == -1) {
        dp[pos] = 0;
        for (int i = 1; i <= A[pos]; i++) {
            if (helper(A, dp, pos + i)) {
                dp[pos] = 1;
                break;
            }
        }
    }
    return dp[pos];
}

int Solution::canJump(vector<int> &A) {
    vector<int> dp(A.size(), -1);
    dp[A.size() - 1] = 1;
    return helper(A, dp, 0);
}
