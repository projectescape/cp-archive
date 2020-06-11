class Solution {
   public:
    int countSubstrings(string s) {
        int ans = 0, i, j, k;
        for (i = 0; i < s.size(); i++) {
            ans += 1;
            for (j = i - 1, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) ans += 1;
        }
        for (i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                ans += 1;
                for (j = i - 2, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) ans += 1;
            } else {
            }
        }
        return ans;
    }
};