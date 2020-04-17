void markIsland(vector<vector<char>>& grid, vector<vector<bool>>& dp, int i, int j) {
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0' || dp[i][j] == false) {
        return;
    }
    dp[i][j] = false;

    markIsland(grid, dp, i + 1, j);
    markIsland(grid, dp, i - 1, j);
    markIsland(grid, dp, i, j + 1);
    markIsland(grid, dp, i, j - 1);
    return;
}

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<bool>> dp(grid.size(), vector<bool>(grid[0].size(), true));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && dp[i][j] == true) {
                    ans++;
                    markIsland(grid, dp, i, j);
                }
            }
        }
        return ans;
    }
};