#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, ans;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        vector<int> dp(n, 1);
        ans = 1;
        for (int i = 1, j; i < n; i++) {
            if (v[i] >= v[i - 1]) {
                j = i - 1;
                while (j >= 0 && v[i] >= v[j]) {
                    j -= dp[j];
                }
                dp[i] = i - j;
                ans = max(ans, i - j);
            }
        }
        for (auto &i : dp) cout << i << " ";
        cout << endl;
    }
    return 0;
}