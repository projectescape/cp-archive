#include <bits/stdc++.h>
using namespace std;

int helper(int pos, vector<int>& dp) {
    if (pos >= dp.size()) return 0;
    if (dp[pos] == -1) {
        dp[pos] = helper(pos + 1, dp) + helper(pos + 2, dp) + helper(pos + 3, dp);
    }
    return dp[pos];
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> dp(n + 1, -1);
        dp[n] = 1;
        cout << helper(0, dp) << endl;
    }
    return 0;
}