int findPath(int dp[][100], int i = 0, int j = 0) {
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = findPath(dp, i + 1, j) + findPath(dp, i, j + 1);
    return dp[i][j];
}

class Solution {
   public:
    int uniquePaths(int m, int n) {
        int dp[100][100];
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[m - 1][i] = 1;
        }
        return findPath(dp, 0, 0);
    }
};