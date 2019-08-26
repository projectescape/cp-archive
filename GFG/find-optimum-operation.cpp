// https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

#include <bits/stdc++.h>
using namespace std;

int dp[10005];

int ways(int n) {
    if (n == 1 || n == 0) return n;
    if (dp[n] != -1) return dp[n];
    int temp;
    if (n % 2 == 0) {
        temp = min(1 + ways(n - 1), 1 + ways(n / 2));
    } else {
        temp = 1 + ways(n - 1);
    }
    dp[n] = temp;
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while (t--) {
        int n, ans;
        cin >> n;
        ans = ways(n);
        cout << ans << endl;
    }
    return 0;
}