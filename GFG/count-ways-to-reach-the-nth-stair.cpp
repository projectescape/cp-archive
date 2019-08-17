// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0

#include <bits/stdc++.h>
using namespace std;

int giveSteps(int n, int dp[]) {
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = (giveSteps(n - 1, dp) + giveSteps(n - 2, dp)) % ((int)1e9 + 7);
    return dp[n];
}

int main() {
    int dp[(int)1e5 + 100] = {0};
    dp[0] = 1;
    dp[1] = 1;
    int t;
    cin >> t;
    while (t--) {
        int ans = 0, n;
        cin >> n;
        if (n < 2)
            ans = n;
        else
            ans = giveSteps(n, dp);

        cout << ans << endl;
    }
    return 0;
}