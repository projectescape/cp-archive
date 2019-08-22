// Friends have to go in party can go either alone or in pair. Find no of ways they can go
#include <bits/stdc++.h>
using namespace std;

int dp[100];

int ways(int n) {
    if (n == 1 || n == 0) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = max(ways(n - 1), (n - 1) + ways(n - 2));
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << ways(n) << endl;
}