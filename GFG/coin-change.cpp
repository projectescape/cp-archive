// https://practice.geeksforgeeks.org/problems/coin-change/0

#include <bits/stdc++.h>
using namespace std;

int ways(int m, int n, int arr[]) {
    int dp[n + 2];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp[i] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + arr[i] <= n)
                dp[j + arr[i]] = dp[j + arr[i]] + dp[j];
            else
                break;
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        sort(arr, arr + m);
        cin >> n;
        cout << ways(m, n, arr) << endl;
    }
}