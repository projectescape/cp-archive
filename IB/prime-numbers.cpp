vector<int> Solution::sieve(int A) {
    vector<int> dp(A + 1, -1);
    for (int i = 4; i <= A; i += 2) {
        dp[i] = 1;
    }
    for (int i = 3; i <= A / 2; i++) {
        if (dp[i] == 1) continue;
        for (int j = i * 2; j <= A; j += i) {
            dp[j] = 1;
        }
    }
    vector<int> ans;
    for (int i = 2; i <= A; i++) {
        if (dp[i] == -1) ans.push_back(i);
    }
    return ans;
}
