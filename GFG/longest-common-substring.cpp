// https://practice.geeksforgeeks.org/problems/longest-common-substring/0

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubString(int a, int b, string c, string d, int dp[][105]) {
    int ans = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (c[i - 1] == d[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string c, d;
        cin >> c >> d;
        int dp[105][105];
        memset(dp, 0, sizeof dp);
        cout << longestCommonSubString(a, b, c, d, dp) << endl;
    }

    return 0;
}