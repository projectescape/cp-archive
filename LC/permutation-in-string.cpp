class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> toFind(26, 0), found(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            toFind[s1[i] - 'a']++;
            found[s2[i] - 'a']++;
        }
        if (toFind == found) return true;
        for (int i = 1; i <= s2.size() - s1.size(); i++) {
            found[s2[i - 1] - 'a']--;
            found[s2[i + s1.size() - 1] - 'a']++;
            if (toFind == found) return true;
        }
        return false;
    }
};