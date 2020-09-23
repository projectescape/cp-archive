#include <bits/stdc++.h>
using namespace std;

int helper(string &A, string &B, vector<vector<int>> &dp, int a, int b) {
    if (a >= A.size() || b >= B.size()) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    if (A[a] == B[b]) {
        return dp[a][b] = 1 + helper(A, B, dp, a + 1, b + 1);
    }
    return dp[a][b] = max(helper(A, B, dp, a + 1, b), helper(A, B, dp, a, b + 1));
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));

        cout << A.size() + B.size() - helper(A, B, dp, 0, 0) << endl;
    }
    return 0;
}