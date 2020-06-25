class Solution {
   public:
    string freqAlphabets(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '2') {
                if (i + 2 < s.size() && s[i + 2] == '#') {
                    ans += ((s[i] - '0') * 10 + s[i + 1] - '1' + 'a');
                    i += 2;
                    continue;
                }
            }
            ans += (s[i] - '1' + 'a');
        }
        return ans;
    }
};