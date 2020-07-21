#include <bits/stdc++.h>
using namespace std;

int helper(int pos, int w, int &maxWeight, vector<int> &value, vector<int> &weight, vector<vector<int>> &dp) {
    if (maxWeight == w) return 0;
    if (pos == value.size()) return 0;
    if (dp[pos][w] == -1) {
        dp[pos][w] = helper(pos + 1, w, maxWeight, value, weight, dp);
        if (w + weight[pos] <= maxWeight) {
            dp[pos][w] = max(dp[pos][w], value[pos] + helper(pos + 1, w + weight[pos], maxWeight, value, weight, dp));
        }
    }
    return dp[pos][w];
}

int main() {
    int T, n, w, temp;
    cin >> T;
    while (T--) {
        cin >> n >> w;
        vector<int> value, weight;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            value.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            cin >> temp;
            weight.push_back(temp);
        }
        vector<vector<int>> dp(n, vector<int>(w, -1));
        cout << helper(0, 0, w, value, weight, dp) << endl;
    }
    return 0;
}