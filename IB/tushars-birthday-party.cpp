int helper(int capacity, int pos, vector<vector<int>> &dp, const vector<int> &weight, const vector<int> &cost) {
    if (capacity == 0) {
        return 0;
    }
    if (capacity < 0 || pos < 0) return INT_MAX;

    if (dp[capacity][pos] == -1) {
        dp[capacity][pos] = INT_MAX;
        int temp = helper(capacity, pos - 1, dp, weight, cost);
        if (temp != INT_MAX) {
            dp[capacity][pos] = min(dp[capacity][pos], temp);
        }
        temp = helper(capacity - weight[pos], pos, dp, weight, cost);
        if (temp != INT_MAX) {
            dp[capacity][pos] = min(dp[capacity][pos], temp + cost[pos]);
        }
    }
    return dp[capacity][pos];
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    vector<vector<int>> dp(*max_element(A.begin(), A.end()) + 1, vector<int>(B.size(), -1));
    int ans = 0;
    for (auto i : A) {
        ans += helper(i, B.size() - 1, dp, B, C);
    }
    return ans;
}
