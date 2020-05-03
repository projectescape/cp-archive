int calcTrees(vector<int> &dp, int n) {
    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    for (int i = 0; i < n; i++) {
        dp[n] += (calcTrees(dp, i) * calcTrees(dp, n - 1 - i));
    }
    return dp[n];
}

class Solution {
   public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;

        return calcTrees(dp, n);
    }
};