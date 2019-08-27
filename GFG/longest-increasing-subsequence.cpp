// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) {
    int dp[1005];
    for (int i = 0; i < n + 2; i++) dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + n);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[1005];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << lis(arr, n) << endl;
    }
    return 0;
}