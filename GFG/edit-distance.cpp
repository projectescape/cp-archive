#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, temp, i, j;
    cin >> T;
    string a, b;
    while (T--) {
        cin >> temp >> temp;
        cin >> b >> a;
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, INT_MAX));
        for (i = 0; i <= a.size(); i++) {
            dp[i][0] = i;
        }
        for (i = 0; i <= b.size(); i++) {
            dp[0][i] = i;
        }
        for (i = 1; i <= a.size(); i++) {
            for (j = 1; j <= b.size(); j++) {
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
    return 0;
}