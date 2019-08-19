// https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>
#include <climits>
using namespace std;

int a[1000];
long long dp[1000][1000];

long long sum(int s, int e) {
    long long ans = 0;
    for (int i = s; i <= e; i++) {
        ans = (ans + a[i]) % 100;
    }
    return ans;
}

long long solveMix(int s, int e) {
    if (s >= e) return 0;
    if (dp[s][e] != -1) return dp[s][e];

    dp[s][e] = INT_MAX;

    for (int k = s; k < e; k++) {
        dp[s][e] = min(dp[s][e], solveMix(s, k) + solveMix(k + 1, e) + sum(s, k) * sum(k + 1, e));
    }
    return dp[s][e];
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        cout << solveMix(0, n - 1) << endl;
    }
}