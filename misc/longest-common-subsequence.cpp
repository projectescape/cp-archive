#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b) {
    int dp[a.length() + 5][b.length() + 5];

    for (int i = 0; i <= a.length(); i++) dp[i][0] = 0;
    for (int i = 0; i <= b.length(); i++) dp[0][i] = 0;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main() {
    string a, b;
    cin >> a >> b;
    int ans = lcs(a, b);
    cout << ans << endl;

    return 0;
}