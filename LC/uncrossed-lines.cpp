int calcMax(vector<int>& A, vector<int>& B, unordered_map<int, vector<int>>& m, vector<vector<int>>& dp, int pos, int reach) {
    if (reach >= B.size() || pos >= A.size()) return 0;
    if (dp[pos][reach] != -1) return dp[pos][reach];
    dp[pos][reach] = calcMax(A, B, m, dp, pos + 1, reach);
    if (m.find(A[pos]) != m.end()) {
        for (auto r : m[A[pos]]) {
            if (r > reach)
                dp[pos][reach] = max(dp[pos][reach], 1 + calcMax(A, B, m, dp, pos + 1, r));
        }
    }
    return dp[pos][reach];
}

class Solution {
   public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < B.size(); i++) {
            m[B[i]].push_back(i + 1);
        }
        vector<vector<int>> dp(A.size(), vector<int>(B.size() + 1, -1));
        return calcMax(A, B, m, dp, 0, 0);
    }
};