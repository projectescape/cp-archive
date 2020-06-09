class Solution {
   public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> m(26);
        for (int i = 0; i < t.size(); i++) {
            m[t[i] - 'a'].push_back(i);
        }
        int prev = -1;
        bool check;
        for (auto c : s) {
            check = false;
            for (auto i : m[c - 'a']) {
                if (i > prev) {
                    prev = i;
                    check = true;
                    break;
                }
            }
            if (!check) return false;
        }
        return true;
    }
};