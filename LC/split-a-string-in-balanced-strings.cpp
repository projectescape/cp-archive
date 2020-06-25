class Solution {
   public:
    int balancedStringSplit(string s) {
        if (s.size() == 0) return 0;
        int curr = 0;
        int ans = 0;
        if (s[0] == 'R')
            curr++;
        else
            curr--;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'R')
                curr++;
            else
                curr--;
            if (curr == 0) ans++;
        }
        return ans;
    }
};