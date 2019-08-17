// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

#include <bits/stdc++.h>
using namespace std;

int calculate(int n, vector<int> dp, vector<int> v) {
    if (n == 0) {
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= v[i] && i + j < n; j++) {
            if (dp[i] == INT_MAX) {
                break;
            }
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    if (dp[n - 1] == INT_MAX) {
        return -1;
    }
    return dp[n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> dp;
        vector<int> v;
        int n, ans;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ans;
            v.push_back(ans);
            dp.push_back(INT_MAX);
        }
        dp[0] = 0;
        ans = calculate(n, dp, v);
        cout << ans << endl;
    }
    return 0;
}