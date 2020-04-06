// set<string> givePermutation(set<string> dp[], int n) {
//     if (dp[n].size() != 0) return dp[n];
//     set<string> sub = givePermutation(dp, n - 1);
//     for (auto i : dp[n - 1]) {
//         dp[n].insert("(" + i + ")");
//     }
//     for (int i = 1, j; i <= n / 2; i++) {
//         j = n - i;
//         for (auto a : dp[i])
//             for (auto b : dp[j]) {
//                 dp[n].insert(a + b);
//                 dp[n].insert(b + a);
//             }
//     }

//     return dp[n];
// }

// class Solution {
//    public:
//     vector<string> generateParenthesis(int n) {
//         set<string> dp[n + 1];
//         dp[1].insert("()");
//         givePermutation(dp, n);
//         // cout<<dp[n].size();
//         vector<string> ans;
//         for (auto i : dp[n]) {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };

void generate(vector<string>& ans, int open, int close, string s) {
    if (open == 0 && close == 0) {
        ans.push_back(s);
    }
    if (open != 0)
        generate(ans, open - 1, close, s + "(");
    if (close > open)
        generate(ans, open, close - 1, s + ")");
}

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, n, n, "");
        return ans;
    }
};