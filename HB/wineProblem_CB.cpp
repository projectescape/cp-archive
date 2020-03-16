// can only sell one bottle each year only from the ends. Profit from that bottle is bottle cost*year of sell. Maximize profit.
#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int cnt = 0;

// memoization method
// int maxProfit(int arr[], int be, int en, int year=1) {
//     cnt++;
//     if (be > en) {
//         return 0;
//     }

//     if (dp[be][en] != -1) {
//         return dp[be][en];
//     }

//     int q1 = arr[be] * year + maxProfit(arr, be + 1, en, year + 1);
//     int q2 = arr[en] * year + maxProfit(arr, be, en - 1, year + 1);
//     int ans = max(q1, q2);
//     dp[be][en] = ans;
//     return ans;
// }

// DP method
int maxProfit(int arr[], int n) {
    int dp[100][100] = {};
    int year = n;
    for (int i = 0; i < n; i++) {
        dp[i][i] = year * arr[i];
    }
    --year;
    for (int len = 2; len <= n; len++) {
        int srt = 0;
        int end = n - len;
        while (srt <= end) {
            int endWindow = srt + len - 1;
            dp[srt][endWindow] = max(
                arr[srt] * year + dp[srt + 1][endWindow],
                arr[endWindow] * year + dp[srt][endWindow - 1]);
            ++srt;
        }
        --year;
    }
    return dp[0][n - 1];
}

int main() {
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = maxProfit(arr, n);
    cout << ans << endl
         << cnt << endl;
}