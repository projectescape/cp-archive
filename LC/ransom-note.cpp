class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < ransomNote.length(); i++) {
            if (m[ransomNote[i]]) {
                m[ransomNote[i]]++;
            } else {
                m[ransomNote[i]] = 1;
                n++;
            }
        }
        for (int i = 0; i < magazine.length(); i++) {
            if (m[magazine[i]]) {
                if (m[magazine[i]] > 0) {
                    m[magazine[i]]--;
                    if (m[magazine[i]] == 0) {
                        n--;
                        if (n == 0) return true;
                    }
                }
            }
        }
        if (n == 0) return true;
        return false;
    }
};