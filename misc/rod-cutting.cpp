// Rod cutting to maximize profit
// Piece of length 1 sells for 2, 2 for 3, 3 for 2, 4 for 5

#include <bits/stdc++.h>
using namespace std;

int dp[100];

// Memoization
// int maxProfit(int arr[], int l) {
//     if (dp[l] != -1) {
//         return dp[l];
//     }
//     int ans = 0, temp;
//     for (int i = 1; i <= l; i++) {
//         temp = arr[i] + maxProfit(arr, l - i);
//         ans = max(ans, temp);
//     }
//     dp[l] = ans;
//     return ans;
// }

// Dynaic Prohramming
int maxProfit(int arr[], int l) {
    if (l == 0) return 0;
    int ans;
    for (int i = 1; i <= l; i++) {
        ans = 0;
        for (int j = 1; j <= i; j++) {
            ans = max(ans, dp[i - j] + arr[j]);
        }
        dp[i] = ans;
    }
    return dp[l];
}

int main() {
    int length = 4;
    for (int i = 0; i <= length; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;
    int priceOfLen[100] = {};
    priceOfLen[0] = 0;
    priceOfLen[1] = 1;
    priceOfLen[2] = 3;
    priceOfLen[3] = 2;
    priceOfLen[4] = 5;
    int ans = maxProfit(priceOfLen, length);
    cout << ans << endl;
    return 0;
}