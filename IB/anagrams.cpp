vector<vector<int>> Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> m;
    string s;
    for (int i = 0; i < A.size(); i++) {
        s = "";
        vector<int> v(26, 0);
        for (auto c : A[i]) {
            v[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            s += to_string(v[i]);
            s += ',';
        }
        m[s].push_back(i + 1);
    }
    vector<vector<int>> ans;
    for (auto i : m) {
        ans.push_back(i.second);
    }
    return ans;
}
