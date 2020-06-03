int ans(vector<vector<int>>& c, vector<vector<int>>& dp, int c1, int c2, int& n) {
    if ((c1 == n) && (c2 == n)) return 0;

    if (dp[c1][c2] != -1) return dp[c1][c2];
    if (c1 != n) {
        if (c2 != n) {
            dp[c1][c2] = min(ans(c, dp, c1 + 1, c2, n) + c[c1 + c2][0], ans(c, dp, c1, c2 + 1, n) + c[c1 + c2][1]);
            return dp[c1][c2];
        } else {
            dp[c1][c2] = ans(c, dp, c1 + 1, c2, n) + c[c1 + c2][0];
            return dp[c1][c2];
        }
    } else if (c2 != n) {
        dp[c1][c2] = ans(c, dp, c1, c2 + 1, n) + c[c1 + c2][1];
        return dp[c1][c2];
    }
    return 0;
}

class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        int n = c.size() / 2;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return ans(c, dp, 0, 0, n);
    }
};