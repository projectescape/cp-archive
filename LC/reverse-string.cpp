class Solution {
   public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; j > i; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};