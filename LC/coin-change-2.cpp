// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//    public:
//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));

//         function<int(int, int)> ans = [&](int amount, int pos) {
//             if (amount == 0) return 1;
//             if (pos >= coins.size() || amount < 0) return 0;
//             if (dp[amount][pos] != -1) return dp[amount][pos];
//             dp[amount][pos] = 0;
//             for (int i = amount; i >= 0; i -= coins[pos]) {
//                 dp[amount][pos] += ans(i, pos + 1);
//             }
//             return dp[amount][pos];
//         };
//         return ans(amount, 0);
//     }
// };

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};