int calcSum(vector<vector<int>>& dp, vector<vector<int>>& grid, int i = 0, int j = 0) {
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = min(calcSum(dp, grid, i + 1, j), calcSum(dp, grid, i, j + 1)) + grid[i][j];
    return dp[i][j];
}

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];
        }
        return calcSum(dp, grid);
    }
};