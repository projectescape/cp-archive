void comb(string &a, int &pos, vector<string> &ans, string &curr, unordered_map<char, string> &m) {
    if (pos == a.size()) {
        ans.push_back(curr);
        return;
    }
    pos++;
    for (auto c : m[a[pos - 1]]) {
        curr.push_back(c);
        comb(a, pos, ans, curr, m);
        curr.pop_back();
    }

    pos--;
}

vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> m;
    m['0'] = "0";
    m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> ans;
    if (A.size() == 0) return ans;
    int pos = 0;
    string curr = "";
    comb(A, pos, ans, curr, m);
    return ans;
}
