// Find the longest increasing subsequence, can skip elements

#include <bits/stdc++.h>
using namespace std;

int dp[100];

int longestSub(int a[], int n) {
    if (n == 1) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                // break;
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int k = 0; k < n; k++) {
        cin >> arr[k];
    }
    for (int k = 0; k < n; k++) {
        dp[k] = 1;
    }
    int ans = longestSub(arr, n);
    cout << ans << endl;
}