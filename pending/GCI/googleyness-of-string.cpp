// how many times goog appears in a string of length 100
// how many strings of size n kan be made with goog appearing k times
#include <bits/stdc++.h>
using namespace std;

long long dp[1000][1000];

long long ways(long long n, long long k) {
    long long mod = 1000000007;
    if (k <= 0) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    long long ans = 0;
    for (long long j = 1; j <= k; j++) {
        for (long long i = 0; i < (n - k * 3 + 1); i++) {
            ans = ans + ((pow(26, i) % mod) * ways(n - (j * 3) - 1, k - j));
            ans = ans % mod;
        }
    }
    dp[n][k] = ans;
    return dp[n][k];
}

int main() {
    long long n = 100;
    long long k = 7;
    memset(dp, -1, sizeof dp);
    long long ans = ways(n, k);
    cout << ans << endl;
}