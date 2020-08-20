class Solution {
   public:
    int characterReplacement(string s, int k) {
        if (s.size() < 1) return 0;
        unordered_map<char, int> m;
        int j = 1;
        char c = s[0];
        m[c]++;
        int ans = 1;
        m['a'] = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c == 'a') {
                c = s[j];
            }
            for (; j < s.size() && (s[j] == c || j - i - m[c] < k); j++) {
                m[s[j]]++;
                if (m[s[j]] > m[c]) {
                    c = s[j];
                }
            }
            ans = max(ans, j - i);
            m[s[i]]--;
            if (m[s[i]] == 0) {
                m.erase(s[i]);
            }
            if (c == s[i]) {
                c = 'a';
                for (auto i : m) {
                    if (i.second > m[c]) {
                        c = i.first;
                    }
                }
            }
        }
        return ans;
    }
};