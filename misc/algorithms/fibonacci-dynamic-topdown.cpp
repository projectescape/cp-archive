#include <bits/stdc++.h>
using namespace std;

long long dp[1000];
long long fib(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for (int curNum = 2; curNum <= n; curNum++) {
        dp[curNum] = dp[curNum - 1] + dp[curNum - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    long long ans = fib(n);
    cout << ans << endl;
}