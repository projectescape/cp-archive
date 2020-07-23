#include <bits/stdc++.h>
using namespace std;

int helper(int s, int e, vector<int>& nums, vector<vector<int>>& dp) {
    if (s > e) {
        return 0;
    } else if (s == e) {
        return nums[s];
    } else if (s - 1 == e) {
        return max(nums[s], nums[e]);
    }
    if (dp[s][e] == -1) {
        dp[s][e] = max(nums[s] + min(helper(s + 2, e, nums, dp), helper(s + 1, e - 1, nums, dp)), nums[e] + min(helper(s, e - 2, nums, dp), helper(s + 1, e - 1, nums, dp)));
    }
    return dp[s][e];
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> nums(n);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << helper(0, n - 1, nums, dp) << endl;
    }
    return 0;
}