void printCombination(string &digits, unordered_map<char, string> &m, vector<string> &ans, int index = 0, string prev = "") {
    if (index == digits.size()) {
        ans.push_back(prev);
        return;
    }
    for (int i = 0; i < m[digits[index]].size(); i++) {
        printCombination(digits, m, ans, index + 1, prev + m[digits[index]][i]);
    }
    return;
}

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) {
            return ans;
        }
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        printCombination(digits, m, ans);
        return ans;
    }
};