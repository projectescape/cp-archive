// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001][6];
int a[2001], b[2001], m, n;
int klcs(int i, int j, int k) {
    if (i == n || j == m) {
        return 0;
    }
    if (dp[i + 1][j + 1][k] != -1) {
        return dp[i + 1][j + 1][k];
    }
    int ans = 0;
    if (a[i] == b[j]) {
        ans = 1 + klcs(i + 1, j + 1, k);
    } else {
        if (k > 0) {
            ans = 1 + klcs(i + 1, j + 1, k - 1);
        }
        ans = max(ans, max(klcs(i + 1, j, k), klcs(i, j + 1, k)));
    }
    dp[i + 1][j + 1][k] = ans;
    return ans;
}

int main() {
    int k, temp;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b[i] = temp;
    }
    memset(dp, -1, sizeof(dp));
    int ans = klcs(0, 0, k);
    cout << ans << "\n";
}
