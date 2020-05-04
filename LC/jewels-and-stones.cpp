class Solution {
   public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> m;
        for (int i = 0; i < S.length(); i++) {
            if (m[S[i]])
                m[S[i]]++;
            else
                m[S[i]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < J.length(); i++) {
            if (m[J[i]]) ans += m[J[i]];
        }
        return ans;
    }
};