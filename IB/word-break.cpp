int helper(int pos, vector<int> &dp, unordered_map<string, bool> &m, string &A) {
    if (pos == A.size()) return 1;
    if (dp[pos] == -1) {
        string temp = "";
        dp[pos] = 0;
        for (int i = pos; i < A.size(); i++) {
            temp += A[i];
            if (m[temp] && helper(i + 1, dp, m, A)) {
                dp[pos] = 1;
                break;
            }
        }
    }
    return dp[pos];
}

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string, bool> m;
    vector<int> dp(A.size(), -1);
    for (auto i : B) {
        m[i] = true;
    }
    return helper(0, dp, m, A);
}
