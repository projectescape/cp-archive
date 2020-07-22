#include <bits/stdc++.h>
using namespace std;

int helper(int amount, int pos, vector<int> &nums, vector<vector<int>> &dp) {
    if (amount < 0) return 0;
    if (amount == 0) return 1;
    if (pos < 0) return 0;
    if (dp[amount][pos] == -1) {
        dp[amount][pos] = helper(amount, pos - 1, nums, dp) || helper(amount - nums[pos], pos - 1, nums, dp);
    }
    return dp[amount][pos];
}

int main() {
    int T, n, sum;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> nums;
        sum = 0;
        for (int i = 0, j; i < n; i++) {
            cin >> j;
            nums.push_back(j);
            sum += j;
        }
        if (sum & 1) {
            cout << "NO" << endl;
            continue;
        }
        sum /= 2;
        vector<vector<int>> dp(sum + 1, vector<int>(nums.size(), -1));
        if (helper(sum, nums.size() - 1, nums, dp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}