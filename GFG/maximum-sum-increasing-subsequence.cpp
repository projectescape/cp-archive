#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, temp, ans;
    cin >> T;
    while (T--) {
        cin >> n;
        if (!n) {
            cout << 0 << endl;
            continue;
        }
        vector<int> dp(n), nums(n);
        for (int i = 0; i < n; i++) {
            cin >> temp;
            dp[i] = nums[i] = temp;
        }
        ans = dp[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], nums[i] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}