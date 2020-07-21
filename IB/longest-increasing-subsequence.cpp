int Solution::lis(const vector<int> &A) {
    if (A.size() == 0) return 0;
    vector<int> dp(A.size(), 1);
    int ans = 1;
    for (int i = 1, j = 0; i < A.size(); i++) {
        for (j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}
