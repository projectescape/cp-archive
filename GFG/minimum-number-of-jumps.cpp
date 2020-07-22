#include <bits/stdc++.h>
using namespace std;

int helper(int pos, vector<int> &nums, vector<int> &dp) {
    if (pos == nums.size() - 1) return 0;
    if (dp[pos] == -1) {
        dp[pos] = INT_MAX;
        int temp;
        for (int i = 1; i <= nums[pos] && i + pos < nums.size(); i++) {
            temp = helper(pos + i, nums, dp);
            if (temp != INT_MAX)
                dp[pos] = min(dp[pos], 1 + temp);
        }
    }
    return dp[pos];
}

int main() {
    int T, n, temp;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> nums, dp(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> temp;
            nums.push_back(temp);
        }
        temp = helper(0, nums, dp);
        cout << (temp == INT_MAX ? -1 : temp) << endl;
    }
    return 0;
}