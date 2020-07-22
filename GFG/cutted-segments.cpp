#include <bits/stdc++.h>
using namespace std;

vector<int> cut(3);
int helper(int l, vector<int>& dp) {
    if (l < 0) return INT_MIN;
    if (dp[l] == -1) {
        dp[l] = INT_MIN;
        for (auto i : cut) {
            if (helper(l - i, dp) >= 0)
                dp[l] = max(dp[l], 1 + helper(l - i, dp));
        }
    }
    return dp[l];
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 3; i++) {
            cin >> cut[i];
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        helper(n, dp);

        cout << dp[n] << endl;
    }
    return 0;
}