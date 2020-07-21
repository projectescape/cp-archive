#include <bits/stdc++.h>
using namespace std;

int n;

int helper(int pos, vector<int>& dp) {
    if (pos > n) {
        return INT_MAX;
    }
    if (dp[pos] == -1) {
        dp[pos] = 1 + min(helper(pos * 2, dp), helper(pos + 1, dp));
    }
    return dp[pos];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        cout << 1 + helper(1, dp) << endl;
    }
    return 0;
}