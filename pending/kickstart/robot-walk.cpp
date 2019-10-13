// kick start dp
// LDDRULDUUDRDLU
#include <bits/stdc++.h>
using namespace std;
string a;
int dp[1000];

int ways(int be) {
    int size = a.length();
    if (be >= size) {
        return 1;
    }
    if (dp[be] != -1) return dp[be];
    dp[be] = 0;
    if (be + 1 < size) {
        if (a[be] == 'R' || a[be] == 'L') {
            if (a[be + 1] == 'R' || a[be + 1] == 'L')
                dp[be] += ways(be + 1);
        }
        if (a[be] == 'U' || a[be] == 'D') {
            if (a[be + 1] == 'U' || a[be + 1] == 'D')
                dp[be] += ways(be + 1);
        }
        if (a[be] == 'U' || a[be] == 'D') {
            if (a[be + 1] == 'R' || a[be + 1] == 'L') {
                dp[be] += ways(be + 2);
                dp[be] += ways(be + 1);
            }
        }
        if (a[be + 1] == 'U' || a[be + 1] == 'D') {
            if (a[be] == 'L' || a[be] == 'R') {
                dp[be] += ways(be + 2);
                dp[be] += ways(be + 1);
            }
        }
    }
    return dp[be];
}

int main() {
    cin >> a;
    memset(dp, -1, sizeof dp);
    int ans = ways(0);
    cout << ans << endl;
}