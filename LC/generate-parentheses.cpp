set<string> givePermutation(set<string> dp[], int n) {
    if (dp[n].size() != 0) return dp[n];
    set<string> sub = givePermutation(dp, n - 1);
    for (auto i : dp[n - 1]) {
        dp[n].insert("(" + i + ")");
    }
    for (int i = 1, j; i <= n / 2; i++) {
        j = n - i;
        for (auto a : dp[i])
            for (auto b : dp[j]) {
                dp[n].insert(a + b);
                dp[n].insert(b + a);
            }
    }

    return dp[n];
}

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        set<string> dp[n + 1];
        dp[1].insert("()");
        givePermutation(dp, n);
        // cout<<dp[n].size();
        vector<string> ans;
        for (auto i : dp[n]) {
            ans.push_back(i);
        }
        return ans;
    }
};