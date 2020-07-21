#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int helper(int pos, vector<int>& dp) {
    if (pos > n) return INT_MAX;
    if (dp[pos] == -1) {
        dp[pos] = INT_MAX;
        for (auto i : coins) {
            dp[pos] = min(dp[pos], helper(pos + i, dp));
        }
        dp[pos]++;
    }
    return dp[pos];
}

int main() {
    //code
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        helper(0, dp);
        stack<int> s;
        for (int i = 0, curr = 0; i <= n; i++) {
            if (dp[i] == dp[curr] - 1) {
                s.push(i - curr);
                curr = i;
            }
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    return 0;
}