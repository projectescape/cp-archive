class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int pSize = p.size(), sSize = s.size();
        vector<int> ans;
        if (pSize > sSize) return ans;
        vector<int> curr(26, 0), pCount(26, 0);
        for (int i = 0; i < pSize; i++) {
            pCount[p[i] - 'a']++;
            curr[s[i] - 'a']++;
        };
        if (pCount == curr) ans.push_back(0);
        for (int i = 1; i <= sSize - pSize; i++) {
            curr[s[i - 1] - 'a']--;
            curr[s[i + pSize - 1] - 'a']++;
            if (curr == pCount) ans.push_back(i);
        }
        return ans;
    }
};