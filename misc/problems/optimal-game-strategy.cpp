// Two players are playing a game, both are smart. {7,3,2,5,8,4}(even). Both have to pick from ends only, alternatively. Max margin by which player who plays first wins
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int v[1000];

int maxDiff(int be, int en) {
    if (be > en) {
        return 0;
    }
    if (dp[be][en] != -1) return dp[be][en];
    dp[be][en] = max(v[be] + min(maxDiff(be + 2, en), maxDiff(be + 1, en - 1)), v[en] + min(maxDiff(be + 1, en - 1), maxDiff(be, en - 2)));
    return dp[be][en];
}

int main() {
    int n, t = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t += v[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = maxDiff(0, n - 1);
    cout << ans - (t - ans) << endl;
}