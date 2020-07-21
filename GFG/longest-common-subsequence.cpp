#include <bits/stdc++.h>
using namespace std;

string A, B;
int helper(int a, int b, vector<vector<int>> &dp) {
    if (a >= A.size() || b >= B.size()) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    if (A[a] == B[b]) {
        dp[a][b] = 1 + helper(a + 1, b + 1, dp);
    } else {
        dp[a][b] = max(helper(a + 1, b, dp), helper(a, b + 1, dp));
    }

    return dp[a][b];
}

int main() {
    int T, temp;
    cin >> T;
    while (T--) {
        cin >> temp >> temp;
        cin >> A >> B;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
        cout << helper(0, 0, dp) << endl;
    }

    return 0;
}