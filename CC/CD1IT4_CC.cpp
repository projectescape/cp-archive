// https://www.codechef.com/problems/CD1IT4
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1000000007;
ll dp[1001][1001];

ll paths(int m, int n) {
    if (dp[0][0] == -1) return 0;
    if (dp[m - 1][n - 1] == -1) return 0;
    for (int i = 0; i < m; i++) {
        if (dp[i][0] == -1) break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (dp[0][i] == -1) break;
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] == -1) continue;
            dp[i][j] = 0;
            if (dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            if (dp[i][j - 1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
            // dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    memset(dp, 0, sizeof dp);
    int i, j;
    for (int k = 0; k < p; k++) {
        cin >> i >> j;
        dp[i - 1][j - 1] = -1;
    }
    ll ans = paths(m, n);
    cout << ans << endl;
}